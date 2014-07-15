#Junto Function()
DROP FUNCTION IF EXISTS check_param_user;
CREATE FUNCTION check_param_user( log TEXT , password TEXT)
	RETURNS TINYINT(1)
BEGIN
        
        DECLARE var_existe INT DEFAULT 0;

        SELECT COUNT(*) INTO var_existe FROM user u WHERE u.login = log and u.keypass = password;

        IF var_existe > 0 THEN
                RETURN 1;
        ELSE
        		call add_to_log(log, "Erreur connection" , "Tentative de connection avec un mauvais couple d'id"  );
        		RETURN 0;
        END IF; 
 
END|


DROP FUNCTION IF EXISTS check_user_admin;
CREATE FUNCTION check_user_admin( log TEXT , idPro TEXT)
	RETURNS TINYINT(1)
BEGIN
        
    DECLARE result INT DEFAULT 0;

	SELECT count(*) INTO result FROM user Inner join userinproject up on user.id = up.idUser inner join project pr on up.idProject = pr.id where pr.id = idPro and up.admin = 1 and user.login = log;

    IF result > 0 THEN
            RETURN 1;
    ELSE
            RETURN 0;
    END IF; 
 
END|

DROP FUNCTION IF EXISTS insert_new_project;
CREATE FUNCTION insert_new_project( nom TEXT , descr TEXT , log TEXT)
	RETURNS TINYINT(1)
BEGIN

	DECLARE lastID INT DEFAULT 0 ;
	DECLARE rowAffected INT DEFAULT 0 ;
	DECLARE userExiste INT DEFAULT 0;
	DECLARE idLog INT  DEFAULT NULL ;
	DECLARE CONTINUE HANDLER FOR 1062 
		BEGIN
				call add_to_log(log, "Duplicate values in project" , "try to duplicate name values" );
				RETURN 0;
		END;

    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à crée un projet n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT id INTO idLog FROM user WHERE login = log ; 

    #Creation nouveau projet
    INSERT INTO project (id, name, description) VALUES (NULL, nom, descr);
    
    SET lastID = LAST_INSERT_ID();
    SET rowAffected = ROW_COUNT();

    IF rowAffected = 0 THEN
    	call add_to_log(log, "INSERT error" , "erreur lors de la création du projet");
    	RETURN 0 ;
	END IF;

    #Ajout du lien avec son créateur (admin)

    INSERT INTO userinproject (id, idUser, idProject, admin) VALUES (NULL, idLog, lastID , 1 );

	SET rowAffected = ROW_COUNT();
    
    IF rowAffected = 0 THEN
    	call add_to_log(log, "INSERT error" , "erreur lors de l'affectation du projet");
    	DELETE FROM project WHERE id = lastID ;
    	RETURN 0 ;
	END IF; 

	RETURN 1;
 
END|



DROP FUNCTION IF EXISTS test;
CREATE FUNCTION test( nom TEXT , descr TEXT , log TEXT)
	RETURNS TINYINT(1)
BEGIN

	DECLARE lastID INT DEFAULT 0 ;
	DECLARE rowAffected INT DEFAULT 0 ;
	DECLARE existe INT DEFAULT 0;
	DECLARE idLog INT  DEFAULT NULL ;
	DECLARE EXIT HANDLER FOR 1062 ;

    SELECT count(*) INTO existe FROM user WHERE login = log ; 
    IF existe > 0 THEN
    	RETURN 1 ;
    ELSE
    	RETURN 0 ;
	END IF; 

 
END|


CREATE PROCEDURE add_to_log(IN log TEXT , IN title TEXT , IN message TEXT )
BEGIN
       
	INSERT INTO log (id, login, title, message) VALUES (NULL, log, title, message);	

END|

DROP FUNCTION IF EXISTS del_project;
CREATE FUNCTION del_project( log TEXT , nomPro TEXT)
	RETURNS TINYINT(1)
BEGIN
        
    DECLARE result INT DEFAULT 0;
    DECLARE userExiste INT DEFAULT 0;
    DECLARE proExiste INT DEFAULT 0;
    DECLARE isAdmin INT DEFAULT 0;
    DECLARE idLog INT  DEFAULT NULL ;
    DECLARE idPro INT  DEFAULT NULL ;
    DECLARE rowAffected INT DEFAULT 0 ;

	SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à crée un projet n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO proExiste FROM project WHERE name = nomPro; 
    IF proExiste < 1 THEN
    	call add_to_log(log, "Le projet n'existe pas" , "Le projet n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT id INTO idPro FROM project WHERE name = nomPro; 	

	SELECT id INTO idLog FROM user WHERE login = log ; 

	SELECT check_user_admin(log , idPro) INTO isAdmin;

	IF isAdmin < 1 THEN
    	call add_to_log(log, "Non admin" , "Tentative de suppression sans les droits administrateur" );
    	RETURN 0 ;
	END IF; 

	DELETE FROM project WHERE id = idPro;

	SET rowAffected = ROW_COUNT();

    IF rowAffected = 0 THEN
    	call add_to_log(log, "Delete error" , "erreur lors de la suppression du projet");
    	RETURN 0 ;
    ELSE
    	RETURN 1 ;
	END IF;


 
END|


DROP FUNCTION IF EXISTS del_user_project;
CREATE FUNCTION del_user_project( log TEXT , logToDel TEXT , idPro TEXT)
	RETURNS TINYINT(1)
BEGIN
        
    DECLARE result INT DEFAULT 0;
    DECLARE userExiste INT DEFAULT 0;
    DECLARE proExiste INT DEFAULT 0;
    DECLARE isAdmin INT DEFAULT 0;
    DECLARE idLog INT  DEFAULT NULL ;
    DECLARE idLogToDel INT  DEFAULT NULL ;
    DECLARE rowAffected INT DEFAULT 0 ;

	SELECT count(*) INTO proExiste FROM project WHERE id = idPro ; 
    IF proExiste < 1 THEN
    	call add_to_log(log, "Le projet n'existe pas" , "Le projet n'existe pas");
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "Utilisateur inexistant" , "L'utilisateur n'existe pas");
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO userExiste FROM user WHERE login = logToDel ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "Utilisateur inexistant" , "L'utilisateur à supprimer n'existe pas");
    	RETURN 0 ;
	END IF; 

	SELECT id INTO idLog FROM user WHERE login = log ; 
	SELECT id INTO idLogToDel FROM user WHERE login = logToDel ; 
	
	SELECT check_user_admin(log , idPro) INTO isAdmin;

	IF isAdmin < 1 THEN
    	call add_to_log(log, "Non admin" , "Tentative de suppression sans les droits administrateur" );
    	RETURN 0 ;
	END IF; 

	SELECT check_user_admin(logToDel , idPro) INTO isAdmin;

	IF isAdmin > 0 THEN
    	call add_to_log(log, "Try to delete Admin" , "Impossible de supprimer l'utilisateur administrateur du projet" );
    	RETURN 0 ;
	END IF; 
	
	# Fin des verifications
	# ________________________________________________________



	DELETE FROM userinproject WHERE idProject = idPro and idUser = idLogToDel ;

	SET rowAffected = ROW_COUNT();

    IF rowAffected = 0 THEN
    	call add_to_log(log, "Delete error" , "Erreur lors de la suppression du lien ray");
    	RETURN 0 ;
    ELSE
    	RETURN 1 ;
	END IF;


 
END|

DROP FUNCTION IF EXISTS insert_people_to_project;
CREATE FUNCTION insert_people_to_project( log TEXT , logToADD TEXT , idPro TEXT)
	RETURNS TINYINT(1)
BEGIN
        
    DECLARE result INT DEFAULT 0;
    DECLARE userExiste INT DEFAULT 0;
    DECLARE userAndProjectExiste INT DEFAULT 0;
    DECLARE proExiste INT DEFAULT 0;
    DECLARE isAdmin INT DEFAULT 0;
    DECLARE idLog INT  DEFAULT NULL;
    DECLARE idLogToADD INT  DEFAULT NULL;
    DECLARE rowAffected INT DEFAULT 0 ;

	SELECT count(*) INTO proExiste FROM project WHERE id = idPro ; 
    IF proExiste < 1 THEN
    	call add_to_log(log, "Le projet n'existe pas" , "Le projet n'existe pas");
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "Utilisateur inexistant" , "L'utilisateur n'existe pas");
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO userExiste FROM user WHERE login = logToADD ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "Utilisateur inexistant" , "L'utilisateur à ajouté n'existe pas");
    	RETURN 0 ;
	END IF; 

	SELECT id INTO idLog FROM user WHERE login = log ; 
	SELECT id INTO idLogToADD FROM user WHERE login = logToADD ; 
	
	SELECT check_user_admin(log , idPro) INTO isAdmin;

	IF isAdmin < 1 THEN
    	call add_to_log(log, "Non admin" , "Tentative d'ajout sans les droits administrateur" );
    	RETURN 0 ;
	END IF; 

	SELECT COUNT(*) INTO userAndProjectExiste FROM userinproject WHERE idUser = idLogToADD AND idProject = idPro ;
	
	IF userAndProjectExiste > 0 THEN
    	call add_to_log(log, "Couple already exist" , "le couple idUser et idProject existe déjà");
    	RETURN 0 ;
	END IF; 

	# Fin des verifications
	# ________________________________________________________

	INSERT INTO userinproject (id, idUser, idProject, admin) VALUES (NULL , idLogToADD , idPro , '0');

	SET rowAffected = ROW_COUNT();

    IF rowAffected = 0 THEN
    	call add_to_log(log, "Insert error" , "Erreur lors de l'ajout d'un utilisateur au projet.");
    	RETURN 0 ;
    ELSE
    	RETURN 1 ;
	END IF;
 
END|

