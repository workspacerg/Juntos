DROP FUNCTION IF EXISTS add_Message;
CREATE FUNCTION add_Message( log TEXT , msg TEXT , receiver TEXT , idPro TEXT) 
	RETURNS tinyint(1)
BEGIN

	DECLARE rowAffected INT DEFAULT 0 ;
	DECLARE userExiste INT DEFAULT 0;
	DECLARE proExiste INT DEFAULT 0;

	DECLARE idLog 	INT  DEFAULT NULL ;
	DECLARE idUser 	INT  DEFAULT NULL ;


    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à crée un projet n'existe pas" );
    	RETURN 0 ;
	END IF; 


	SELECT count(*) INTO userExiste FROM user WHERE login = receiver ; 
    IF userExiste < 1  THEN
    	call to_log(log, "Receveur du message" , "Le receveur du message n'existe pas." );
    	RETURN 0 ;
	END IF;

	SELECT count(*) INTO proExiste FROM project WHERE id = idPro ; 
    IF proExiste < 1 THEN
    	call add_to_log(log, "Le projet n'existe pas" , "Le projet n'existe pas");
    	RETURN 0 ;
	END IF; 


	SELECT id INTO idLog 	FROM user WHERE login 	= log ;
	SELECT id INTO idUser 	FROM user WHERE login 	= receiver ;  


	INSERT INTO `juntos`.`message` (`id`, `senderId`, `receiverId`, `message`, `projectID`, `date`) 
	VALUES (NULL, idLog, idUser, msg, idPro, CURRENT_TIMESTAMP);

	RETURN 1;
 
END |