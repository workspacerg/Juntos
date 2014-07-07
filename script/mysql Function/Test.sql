
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


	RETURN 1;
 
END|