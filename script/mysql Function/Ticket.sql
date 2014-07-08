
select add_ticket( "rgabel" , "mon titre" , "madescr" , "rgabel" , "ouvert" , "1") 

DROP FUNCTION IF EXISTS add_ticket;
CREATE FUNCTION add_ticket( log TEXT , titre TEXT , descr TEXT , userToAssign TEXT , etatAvancement TEXT , idPro TEXT) 
	RETURNS tinyint(1)
BEGIN

	DECLARE rowAffected INT DEFAULT 0 ;
	DECLARE userExiste INT DEFAULT 0;
	DECLARE proExiste INT DEFAULT 0;

	DECLARE idLog 	INT  DEFAULT NULL ;
	DECLARE idUser 	INT  DEFAULT NULL ;
	DECLARE idEtat 	INT  DEFAULT NULL ;

	DECLARE userOK TINYINT(1) DEFAULT 0 ;

    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à crée un projet n'existe pas" );
    	RETURN 0 ;
	END IF; 


	SELECT count(*) INTO userExiste FROM user WHERE login = userToAssign ; 
    IF userExiste < 1 && userToAssign != "" THEN
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

	

	IF userToAssign = "" THEN
		Set userToAssign = NULL ;
		Set userOK = 0 ;
	END IF ;

	SELECT id INTO idLog 	FROM user WHERE login 	= log ;
	SELECT id INTO idUser 	FROM user WHERE login 	= userToAssign ; 
	SELECT id INTO idEtat 	FROM etat WHERE name 	= etatAvancement ; 


	INSERT INTO  task (
	`id` ,
	`idProject` ,
	`name` ,
	`description` ,
	`createBy` ,
	`dateLog` ,
	`dateDone` ,
	`dateAssignTo` ,
	`assignToUser` ,
	`idType` ,
	`Etat`
	)
	VALUES (
	NULL ,  idPro,  titre,  descr,  idLog, 
	CURRENT_TIMESTAMP , NULL , NULL ,  idUser,  '1',  idEtat
	);

	IF userOK = 1 THEN
		UPDATE  `task` SET `dateAssignTo` =  CURRENT_TIMESTAMP WHERE  `id` = LAST_INSERT_ID();
	END IF;

	IF idEtat > 4 THEN
		UPDATE  `task` SET `dateDone` =  CURRENT_TIMESTAMP WHERE  `id` = LAST_INSERT_ID();
	END IF;

	RETURN 1;
 
END |
