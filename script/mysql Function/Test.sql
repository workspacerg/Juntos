
DROP FUNCTION IF EXISTS del_test;
CREATE FUNCTION del_test( log TEXT , idTt TEXT, idPro TEXT)
	RETURNS TINYINT(1)
BEGIN

	DECLARE idLog 	INT  DEFAULT NULL ;

	DECLARE userExiste 	INT DEFAULT 0;

	# Les verifications

    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à supprimer le test n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT id INTO idLog FROM user WHERE login 	= log ;


	DELETE FROM testunitaire WHERE id = idTt ;
	call add_to_log(log, "Utilisateur" , "Vient de supprimer le test unitaire n° " );


	RETURN 1;
 
END|


DROP FUNCTION IF EXISTS add_test;
CREATE FUNCTION add_test( log TEXT , titre TEXT , descr TEXT , pIn TEXT , pOut TEXT, idPro TEXT)
	RETURNS TINYINT(1)
BEGIN

	DECLARE rowAffected INT DEFAULT 0 ;
	DECLARE userExiste INT DEFAULT 0;
	DECLARE proExiste INT DEFAULT 0;

	DECLARE idLog 	INT  DEFAULT NULL ;



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

	SELECT count(*) INTO proExiste FROM project WHERE id = idPro ; 
    IF proExiste < 1 THEN
    	call add_to_log(log, "Le projet n'existe pas" , "Le projet n'existe pas");
    	RETURN 0 ;
	END IF; 

	# Selection des différents id

	SELECT id INTO idLog 	FROM user WHERE login 	= log ;

	INSERT INTO `juntos`.`testunitaire` 
	(
		`id`, 
		`name`, 
		`projectId`, 
		`desciption`, 
		`paramIn`, 
		`paramOut`, 
		`resultat`, 
		`valideur`) 
	VALUES (NULL, titre, idPro, descr, pIn, pOut, 0, NULL);


	RETURN 1;
 
END|









select upd_test( "rgabel" , "titre" , "descr" , "pIn" , "pOut", 1 , 5 , "1")
DROP FUNCTION IF EXISTS upd_test;
CREATE FUNCTION upd_test(log TEXT , titre TEXT , descr TEXT , pIn TEXT , pOut TEXT, valid INT , idTest INT, idPro TEXT)
	RETURNS TINYINT(1)
BEGIN

	DECLARE rowAffected INT DEFAULT 0 ;
	DECLARE userExiste INT DEFAULT 0;
	DECLARE proExiste INT DEFAULT 0;
	DECLARE testExiste INT DEFAULT 0;

	DECLARE idLog 	INT  DEFAULT NULL ;

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

	SELECT count(*) INTO proExiste FROM project WHERE id = idPro ; 
    IF proExiste < 1 THEN
    	call add_to_log(log, "Le projet n'existe pas" , "Le projet n'existe pas");
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO testExiste FROM testunitaire WHERE id = idTest ; 
    IF testExiste < 1 THEN
    	call add_to_log(log, "Le ticket n'éxiste pas" , "l'idTicket es inexistant");
    	RETURN 0 ;
	END IF; 

	# Selection des différents id

	SELECT id INTO idLog 	FROM user WHERE login 	= log ;

	UPDATE `juntos`.`testunitaire` 
	SET 
		`name` = titre, 
		`desciption` = descr, 
		`paramIn` = pIn,
		`paramOut` = pOut, 
		`resultat` = valid, 
		`valideur` = idLog 
	WHERE `testunitaire`.`id` = idTest;

	RETURN 1;
 
END|