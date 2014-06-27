#Fonction mysql tâches

#selection de tout les éléments d'un projet



DROP FUNCTION IF EXISTS del_task;
CREATE FUNCTION del_task( log TEXT , idTd TEXT, idPro TEXT)
	RETURNS TINYINT(1)
BEGIN

	DECLARE idLog 	INT  DEFAULT NULL ;

	DECLARE isAdmin 	INT DEFAULT 0;
	DECLARE isCreate 	INT DEFAULT 0;
	DECLARE userExiste 	INT DEFAULT 0;

	# Les verifications

    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à crée un projet n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT id INTO idLog FROM user WHERE login 	= log ;

	# Verife si admin ou createur du ticket

	SELECT count(*) INTO isCreate FROM todo	 WHERE id = 2 AND idCreateur = 2 ; 
	
	SELECT check_user_admin(log , idPro) INTO isAdmin;
    

    IF isAdmin < 1 && isCreate <1 THEN
    	call add_to_log(log, "Suppression impossible " , "Vous êtes ni admin du projet, ni créateur de la tâche ");
    	RETURN 0 ;
	END IF; 

	DELETE FROM todo WHERE id = idTd ;

	# Selection des différents id


	RETURN 1;
 
END|

DROP FUNCTION IF EXISTS add_task;
CREATE FUNCTION add_task( log TEXT , titre TEXT , descr TEXT , dev TEXT , etatAvancement TEXT , dateFin TEXT , idPro TEXT)
	RETURNS TINYINT(1)
BEGIN

	DECLARE rowAffected INT DEFAULT 0 ;
	DECLARE userExiste INT DEFAULT 0;
	DECLARE proExiste INT DEFAULT 0;

	DECLARE idLog 	INT  DEFAULT NULL ;
	DECLARE idUser 	INT  DEFAULT NULL ;
	DECLARE idEtat 	INT  DEFAULT NULL ;

	DECLARE userOK TINYINT(1) DEFAULT 0 ;
	DECLARE CONTINUE HANDLER FOR 1062 
		BEGIN
				call add_to_log(log, "Titre déjà présent" , "try to duplicate name values" );
				RETURN 0;
		END;

	# Les verifications

    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à crée un projet n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO userExiste FROM user WHERE login = dev ; 
    IF userExiste < 1 && dev != "" THEN
    	call add_to_log(log, "user n'existe pas" , "L'utilisateur assigné n'existe pas" );
    	RETURN 0 ;
    ELSE
    	Set userOK = 1;
	END IF;

	SELECT count(*) INTO proExiste FROM project WHERE id = idPro ; 
    IF proExiste < 1 THEN
    	call add_to_log(log, "Le projet n'existe pas" , "Le projet n'existe pas");
    	RETURN 0 ;
	END IF; 

	# Selection des différents id

	IF dev = "" THEN
		Set dev = NULL ;
		Set userOK = 0 ;
	END IF ;

	SELECT id INTO idLog 	FROM user WHERE login 	= log ;
	SELECT id INTO idUser 	FROM user WHERE login 	= dev ; 
	SELECT id INTO idEtat 	FROM avancementTodo WHERE nom 	= etatAvancement ; 

INSERT INTO `juntos`.`todo` 
(
	`id`, 
	`titre`, 
	`description`, 
	`idProjet`, 
	`idCreateur`, 
	`idDeveloppeur`, 
	`dateCreation`, 
	`dateModification`, 
	`dateFinalisation`, 
	`idAvancement`) 
VALUES 
(
	NULL, titre, descr, idPro, idLog, idUser, CURRENT_TIMESTAMP, CURRENT_TIMESTAMP, dateFin, idEtat
);

	IF idEtat = 7 THEN
		UPDATE  `todo` SET dateFinalisation =  CURRENT_TIMESTAMP WHERE  `id` = LAST_INSERT_ID();
	END IF;

	RETURN 1;
 
END|