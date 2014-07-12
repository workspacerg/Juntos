
select add_journal( "rgabel", "ray" , "1", "action TEXT" )

DROP FUNCTION IF EXISTS add_journal;
CREATE FUNCTION add_journal( log TEXT , user TEXT , idPro TEXT , action TEXT )
	RETURNS TINYINT(1)
BEGIN

	DECLARE rowAffected INT DEFAULT 0;
	DECLARE userExiste INT DEFAULT 0;
	DECLARE proExiste INT DEFAULT 0;

	DECLARE idLog 	INT  DEFAULT NULL ;
	DECLARE idUser 	INT  DEFAULT NULL ;

	# Les verifications

    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "log existe pas " );
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO userExiste FROM user WHERE login = user ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "user n'existe pas" , "user n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO proExiste FROM project WHERE id = idPro ; 
    IF proExiste < 1 THEN
    	call add_to_log(log, "Le projet n'existe pas" , "Le projet n'existe pas");
    	RETURN 0 ;
	END IF; 

	# Selection des différents id

	SELECT id INTO idLog 	FROM user WHERE login 	= log ;
	SELECT id INTO idUser 	FROM user WHERE login 	= user ;

	INSERT INTO `juntos`.`journal` 
	(`id`, `idUser`, `idProjet`, `idUserToContact`, `date`, `action`) 
	VALUES 
	(NULL, idLog , idPro , idUser , CURRENT_TIMESTAMP, action);


	RETURN 1;
 
END|