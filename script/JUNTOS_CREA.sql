-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Mer 16 Juillet 2014 à 00:12
-- Version du serveur :  5.6.17
-- Version de PHP :  5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `juntos`
--

DELIMITER $$
--
-- Procédures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_to_log`(IN log TEXT , IN title TEXT , IN message TEXT )
BEGIN
       
INSERT INTO log (id, login, title, message) VALUES (NULL, log, title, message);

END$$

--
-- Fonctions
--
CREATE DEFINER=`root`@`localhost` FUNCTION `add_journal`( log TEXT , user TEXT , idPro TEXT , action TEXT ) RETURNS tinyint(1)
BEGIN

	DECLARE rowAffected INT DEFAULT 0;
	DECLARE userExiste INT DEFAULT 0;
	DECLARE proExiste INT DEFAULT 0;

	DECLARE idLog 	INT  DEFAULT NULL ;
	DECLARE idUser 	INT  DEFAULT NULL ;

	

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

	

	SELECT id INTO idLog 	FROM user WHERE login 	= log ;
	SELECT id INTO idUser 	FROM user WHERE login 	= user ;

	INSERT INTO `juntos`.`journal` 
	(`id`, `idUser`, `idProjet`, `idUserToContact`, `date`, `action`) 
	VALUES 
	(NULL, idLog , idPro , idUser , CURRENT_TIMESTAMP, action);


	RETURN 1;
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `add_Message`( log TEXT , msg TEXT , receiver TEXT , idPro TEXT) RETURNS tinyint(1)
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
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `add_task`( log TEXT , titre TEXT , descr TEXT , dev TEXT , etatAvancement TEXT , dateFin TEXT , idPro TEXT) RETURNS tinyint(1)
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
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `add_test`( log TEXT , titre TEXT , descr TEXT , pIn TEXT , pOut TEXT, idPro TEXT) RETURNS tinyint(1)
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
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `add_ticket`( log TEXT , titre TEXT , descr TEXT , userToAssign TEXT , etatAvancement TEXT , idPro TEXT) RETURNS tinyint(1)
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
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `check_param_user`( log TEXT , password TEXT) RETURNS tinyint(1)
BEGIN
        
        DECLARE var_existe INT DEFAULT 0;

        SELECT COUNT(*) INTO var_existe FROM user u WHERE u.login = log and u.keypass = password;

        IF var_existe > 0 THEN
                RETURN 1;
        ELSE
        call add_to_log(log, "Erreur connection" , "Tentative de connection avec un mauvais couple d'id"  );
        RETURN 0;
        END IF; 
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `check_user_admin`( log TEXT , idPro TEXT) RETURNS tinyint(1)
BEGIN
        
    DECLARE result INT DEFAULT 0;

	SELECT count(*) INTO result FROM user Inner join userinproject up on user.id = up.idUser inner join project pr on up.idProject = pr.id where pr.id = idPro and up.admin = 1 and user.login = log;

    IF result > 0 THEN
            RETURN 1;
    ELSE
            RETURN 0;
    END IF; 
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `del_project`( log TEXT , nomPro TEXT) RETURNS tinyint(1)
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


 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `del_task`( log TEXT , idTd TEXT, idPro TEXT) RETURNS tinyint(1)
BEGIN

	DECLARE idLog 	INT  DEFAULT NULL ;

	DECLARE isAdmin 	INT DEFAULT 0;
	DECLARE isCreate 	INT DEFAULT 0;
	DECLARE userExiste 	INT DEFAULT 0;

	

    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à crée un projet n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT id INTO idLog FROM user WHERE login 	= log ;

	

	SELECT count(*) INTO isCreate FROM todo	 WHERE id = 2 AND idCreateur = 2 ; 
	
	SELECT check_user_admin(log , idPro) INTO isAdmin;
    

    IF isAdmin < 1 && isCreate <1 THEN
    	call add_to_log(log, "Suppression impossible " , "Vous êtes ni admin du projet, ni créateur de la tâche ");
    	RETURN 0 ;
	END IF; 

	DELETE FROM todo WHERE id = idTd ;

	


	RETURN 1;
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `del_test`( log TEXT , idTt TEXT, idPro TEXT) RETURNS tinyint(1)
BEGIN

	DECLARE idLog 	INT  DEFAULT NULL ;

	DECLARE userExiste 	INT DEFAULT 0;

	

    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à supprimer le test n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT id INTO idLog FROM user WHERE login 	= log ;


	DELETE FROM testunitaire WHERE id = idTt ;
	call add_to_log(log, "Utilisateur" , "Vient de supprimer le test unitaire n° " );


	RETURN 1;
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `del_ticket`( log TEXT , idTk TEXT, idPro TEXT) RETURNS tinyint(1)
BEGIN

	DECLARE idLog 	INT  DEFAULT NULL ;

	DECLARE isAdmin 	INT DEFAULT 0;
	DECLARE isCreate 	INT DEFAULT 0;
	DECLARE userExiste 	INT DEFAULT 0;

	

    SELECT count(*) INTO userExiste FROM user WHERE login = log ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "log n'existe pas" , "Le compte cherchant à crée un projet n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT id INTO idLog FROM user WHERE login 	= log ;


	

	SELECT count(*) INTO isCreate FROM task tk WHERE id = idTk AND createBy = idLog ; 
	SELECT check_user_admin(log , idPro) INTO isAdmin;
    

    IF isAdmin < 1 && isCreate <1 THEN
    	call add_to_log(log, "Suppression impossible " , "Vous êtes ni admin du projet, ni créateur du ticket ");
    	RETURN 0 ;
	END IF; 

	DELETE FROM task WHERE id = idTk ;

	


	RETURN 1;
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `del_user_project`( log TEXT , logToDel TEXT , idPro TEXT) RETURNS tinyint(1)
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






DELETE FROM userinproject WHERE idProject = idPro and idUser = idLogToDel ;

SET rowAffected = ROW_COUNT();

    IF rowAffected = 0 THEN
    call add_to_log(log, "Delete error" , "Erreur lors de la suppression du lien ray");
    RETURN 0 ;
    ELSE
    RETURN 1 ;
END IF;


 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `insert_new_project`( nom TEXT , descr TEXT , log TEXT) RETURNS tinyint(1)
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

    
    INSERT INTO project (id, name, description) VALUES (NULL, nom, descr);
    
    SET lastID = LAST_INSERT_ID();
    SET rowAffected = ROW_COUNT();

    IF rowAffected = 0 THEN
    call add_to_log(log, "INSERT error" , "erreur lors de la création du projet");

    RETURN 0 ;
END IF;

    

    INSERT INTO userinproject (id, idUser, idProject, admin) VALUES (NULL, idLog, lastID , 1 );

SET rowAffected = ROW_COUNT();
    
    IF rowAffected = 0 THEN
    call add_to_log(log, "INSERT error" , "erreur lors de l'affectation du projet");
    DELETE FROM project WHERE id = lastID ;
    RETURN 0 ;
END IF; 

RETURN 1;
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `insert_people_to_project`( log TEXT , logToADD TEXT , idPro TEXT) RETURNS tinyint(1)
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




INSERT INTO userinproject (id, idUser, idProject, admin) VALUES (NULL , idLogToADD , idPro , '0');

SET rowAffected = ROW_COUNT();

    IF rowAffected = 0 THEN
    call add_to_log(log, "Insert error" , "Erreur lors de l'ajout d'un utilisateur au projet.");
    RETURN 0 ;
    ELSE
    RETURN 1 ;
END IF;
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `test`( nom TEXT , descr TEXT , log TEXT) RETURNS tinyint(1)
BEGIN

DECLARE lastID INT DEFAULT 0 ;
DECLARE rowAffected INT DEFAULT 0 ;
DECLARE existe INT DEFAULT 0;
DECLARE idLog INT  DEFAULT NULL ;

    SELECT count(*) INTO existe FROM user WHERE login = log ; 
    IF existe > 0 THEN
    RETURN 1 ;
    ELSE
    RETURN 0 ;
END IF; 

 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `upd_task`(log TEXT , userCreate TEXT , titre TEXT , descr TEXT , userToAssign TEXT , etatAvancement TEXT , idTk TEXT) RETURNS tinyint(1)
BEGIN


	DECLARE userExiste INT DEFAULT 0;
	DECLARE tkExiste INT DEFAULT 0;

	DECLARE idLog 	INT  DEFAULT NULL ;
	DECLARE idUser 	INT  DEFAULT NULL ;
	DECLARE idEtat 	INT  DEFAULT NULL ;

	DECLARE oldAssignId 	INT  DEFAULT NULL ;
	DECLARE oldEtatId	 	INT  DEFAULT NULL ;

	DECLARE userOK TINYINT(1) DEFAULT 0 ;
	DECLARE nameAssign VARCHAR(50) ;
	DECLARE rowAffected INT DEFAULT 0 ;

	

    SELECT count(*) INTO userExiste FROM user WHERE login = userCreate ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "user admin n'existe pas" , "Le créateur n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO userExiste FROM user WHERE login = userToAssign ; 
    IF userExiste < 1 && userToAssign != ""  THEN
    	call add_to_log(log, "user n'existe pas" , "L'utilisateur assigné n'existe pas" );
    	RETURN 0 ;
    ELSE
    	Set userOK = 1;
	END IF;


	SELECT count(*) INTO tkExiste FROM todo WHERE id = idTk ; 
    IF tkExiste < 1 THEN
    	call add_to_log(log, "La tâche n'existe pas" , "La tâche n'existe pas");
    	RETURN 0 ;
	END IF; 

	

	SELECT id INTO idLog 	FROM user WHERE login 	= userCreate ;
	SELECT id INTO idUser 	FROM user WHERE login 	= userToAssign ; 
	SELECT id INTO idEtat 	FROM avancementTodo WHERE nom 	= etatAvancement ; 

	SELECT assignToUser INTO oldAssignId 	FROM task WHERE id = idtk ;
	SELECT etat 	INTO oldEtatId 		FROM task WHERE id = idtk ;



UPDATE `juntos`.`todo` 
SET 
	`titre` = titre, 
	`description` = descr, 
	`idCreateur` = idLog, 
	`idDeveloppeur` = idUser, 
	`dateModification` = CURRENT_TIMESTAMP, 
	`dateFinalisation` = '2016-01-23 00:00:00', 
	`idAvancement` = idEtat 
WHERE `todo`.`id` = idTk;



	
	

	IF idEtat = 7 THEN
		UPDATE  `todo` SET `dateFinalisation` =  CURRENT_TIMESTAMP  WHERE `id` = idTk;
	END IF;




	RETURN 1;
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `upd_test`(log TEXT , titre TEXT , descr TEXT , pIn TEXT , pOut TEXT, valid INT , idTest INT, idPro TEXT) RETURNS tinyint(1)
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
 
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `upd_ticket`(log TEXT , userCreate TEXT , titre TEXT , descr TEXT , userToAssign TEXT , etatAvancement TEXT , idTk TEXT) RETURNS tinyint(1)
BEGIN


	DECLARE userExiste INT DEFAULT 0;
	DECLARE tkExiste INT DEFAULT 0;

	DECLARE idLog 	INT  DEFAULT NULL ;
	DECLARE idUser 	INT  DEFAULT NULL ;
	DECLARE idEtat 	INT  DEFAULT NULL ;

	DECLARE oldAssignId 	INT  DEFAULT NULL ;
	DECLARE oldEtatId	 	INT  DEFAULT NULL ;

	DECLARE userOK TINYINT(1) DEFAULT 0 ;
	DECLARE nameAssign VARCHAR(50) ;
	DECLARE rowAffected INT DEFAULT 0 ;

	

    SELECT count(*) INTO userExiste FROM user WHERE login = userCreate ; 
    IF userExiste < 1 THEN
    	call add_to_log(log, "user admin n'existe pas" , "Le créateur n'existe pas" );
    	RETURN 0 ;
	END IF; 

	SELECT count(*) INTO userExiste FROM user WHERE login = userToAssign ; 
    IF userExiste < 1 && userToAssign != ""  THEN
    	call add_to_log(log, "user n'existe pas" , "L'utilisateur assigné n'existe pas" );
    	RETURN 0 ;
    ELSE
    	Set userOK = 1;
	END IF;



	SELECT count(*) INTO tkExiste FROM task WHERE id = idTk ; 
    IF tkExiste < 1 THEN
    	call add_to_log(log, "Le ticket n'existe pas" , "Le ticket n'existe pas");
    	RETURN 0 ;
	END IF; 

	

	SELECT id INTO idLog 	FROM user WHERE login 	= userCreate ;
	SELECT id INTO idUser 	FROM user WHERE login 	= userToAssign ; 
	SELECT id INTO idEtat 	FROM etat WHERE name 	= etatAvancement ; 

	SELECT assignToUser INTO oldAssignId 	FROM task WHERE id = idtk ;
	SELECT etat 	INTO oldEtatId 		FROM task WHERE id = idtk ;



	UPDATE task 
	SET 
	`name` = titre, 
	`description` = descr, 
	`createBy` = idLog,  
	`assignToUser` = idUser, 
	`Etat` = idEtat ,
	`dateAssignTo` = CURRENT_TIMESTAMP
	WHERE `task`.`id` = idTk;


	

	IF oldEtatId != idEtat && idEtat > 4 THEN
		UPDATE  `task` SET `dateDone` =  CURRENT_TIMESTAMP WHERE  `id` = idTk;
	END IF;
	
	

	IF idEtat < 5 THEN
		UPDATE  `task` SET `dateDone` =  NULL WHERE  `id` = idTk;
	END IF;




	RETURN 1;
 
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Structure de la table `avancementtodo`
--

CREATE TABLE IF NOT EXISTS `avancementtodo` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `nom` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Contenu de la table `avancementtodo`
--

INSERT INTO `avancementtodo` (`id`, `nom`) VALUES
(1, 'crée'),
(2, 'assigné'),
(4, 'en cours'),
(5, 'à tester'),
(6, 'validé'),
(7, 'Terminé');

-- --------------------------------------------------------

--
-- Structure de la table `etat`
--

CREATE TABLE IF NOT EXISTS `etat` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Contenu de la table `etat`
--

INSERT INTO `etat` (`id`, `name`) VALUES
(1, 'ouvert'),
(2, 'accepté'),
(3, 'confirmé'),
(4, 'affecté'),
(5, 'résolu'),
(6, 'fermé'),
(7, 'rejeté');

-- --------------------------------------------------------

--
-- Structure de la table `journal`
--

CREATE TABLE IF NOT EXISTS `journal` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `idUser` int(10) unsigned NOT NULL,
  `idProjet` int(10) unsigned NOT NULL,
  `idUserToContact` int(10) unsigned DEFAULT NULL,
  `date` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `action` text NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idUser` (`idUser`),
  KEY `idUser_2` (`idUser`),
  KEY `idProjet` (`idProjet`),
  KEY `idUserToContact` (`idUserToContact`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=102 ;

--
-- Contenu de la table `journal`
--

INSERT INTO `journal` (`id`, `idUser`, `idProjet`, `idUserToContact`, `date`, `action`) VALUES
(73, 1, 28, 2, '2014-07-15 22:09:00', 'rgabel a ajouté ray au projet :Juntos Test'),
(74, 2, 28, 1, '2014-07-15 22:11:41', 'ray a ajouté la tâche Exportation de la base de donnée'),
(75, 2, 28, 1, '2014-07-15 22:24:40', 'ray a ajouté le ticket ticket'),
(76, 2, 28, 2, '2014-07-15 22:25:36', 'ray a ajouté le ticket ERR 001'),
(77, 2, 28, 2, '2014-07-15 22:25:55', 'ray a supprmé le ticket 51'),
(78, 2, 28, 2, '2014-07-15 22:26:11', 'ray a mise à jour le ticket ERR 001'),
(79, 2, 28, 2, '2014-07-15 22:31:14', 'ray a ajouté le ticket ERR OO3'),
(80, 2, 28, 2, '2014-07-15 22:32:04', 'ray a ajouté le ticket ERR 004'),
(81, 2, 28, 2, '2014-07-15 22:34:25', 'ray a ajouté le ticket ERR 005'),
(82, 2, 28, 1, '2014-07-15 22:35:10', 'ray a ajouté le ticket ERR 004'),
(83, 2, 28, 1, '2014-07-15 22:35:29', 'ray a mise à jour le ticket ERR OO3'),
(84, 2, 28, 2, '2014-07-15 22:36:10', 'ray a supprmé le ticket 52'),
(85, 1, 28, 1, '2014-07-15 22:44:22', 'rgabel a supprimé un test du projet : '),
(86, 1, 28, 1, '2014-07-15 22:45:59', 'rgabel a ajouté un test : tt'),
(87, 1, 28, 1, '2014-07-15 22:47:55', 'rgabel a ajouté un test : test égalité'),
(88, 2, 28, 2, '2014-07-15 22:55:04', 'ray a ajouté un test : azeaezaaze'),
(89, 2, 28, 2, '2014-07-15 22:56:32', 'ray a ajouté un test : test'),
(90, 2, 28, 2, '2014-07-15 23:16:01', 'ray a ajouté un test : re'),
(91, 2, 28, 2, '2014-07-15 23:18:32', 'ray a ajouté un test : rgb'),
(92, 2, 28, 2, '2014-07-15 23:18:47', 'ray a ajouté un test : tes''t'),
(93, 2, 28, 2, '2014-07-15 23:21:11', 'ray a ajouté un test : l''égalité'),
(94, 2, 28, 2, '2014-07-15 23:24:01', 'ray a ajouté un test : test d''égalité'),
(95, 2, 28, 1, '2014-07-15 23:38:39', 'ray a ajouté le ticket ERR 006'),
(96, 2, 28, 2, '2014-07-15 23:39:41', 'ray a ajouté le ticket ERR 07'),
(97, 2, 28, 2, '2014-07-15 23:40:20', 'ray a ajouté le ticket ff''r'),
(98, 2, 28, 2, '2014-07-15 23:41:08', 'ray a supprmé le ticket 59'),
(99, 2, 28, 1, '2014-07-15 23:46:03', 'ray a mis à jour la tâche 25'),
(100, 2, 28, 2, '2014-07-15 23:55:02', 'ray a ajouté un test : nouveau t''estaze'),
(101, 2, 28, 2, '2014-07-15 23:55:21', 'ray a supprimé un test du projet : ');

-- --------------------------------------------------------

--
-- Structure de la table `log`
--

CREATE TABLE IF NOT EXISTS `log` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `login` varchar(50) CHARACTER SET utf8 NOT NULL DEFAULT '...',
  `title` varchar(255) CHARACTER SET utf8 NOT NULL,
  `message` text CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=22 ;

--
-- Contenu de la table `log`
--

INSERT INTO `log` (`id`, `login`, `title`, `message`) VALUES
(10, 'ray', 'user n''existe pas', 'user n''existe pas'),
(11, 'rgabel', 'Utilisateur', 'Vient de supprimer le test unitaire n° '),
(12, 'ray', 'Titre déjà présent', 'try to duplicate name values'),
(13, 'ray', 'user n''existe pas', 'user n''existe pas'),
(14, 'ray', 'user n''existe pas', 'user n''existe pas'),
(15, 'ray', 'user n''existe pas', 'user n''existe pas'),
(16, 'ray', 'user n''existe pas', 'user n''existe pas'),
(17, 'ray', 'Suppression impossible ', 'Vous êtes ni admin du projet, ni créateur de la tâche '),
(18, 'ray', 'Suppression impossible ', 'Vous êtes ni admin du projet, ni créateur de la tâche '),
(19, 'ray', 'Suppression impossible ', 'Vous êtes ni admin du projet, ni créateur de la tâche '),
(20, 'ray', 'Suppression impossible ', 'Vous êtes ni admin du projet, ni créateur de la tâche '),
(21, 'ray', 'Utilisateur', 'Vient de supprimer le test unitaire n° ');

-- --------------------------------------------------------

--
-- Structure de la table `message`
--

CREATE TABLE IF NOT EXISTS `message` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `senderId` int(10) unsigned DEFAULT NULL,
  `receiverId` int(10) unsigned DEFAULT NULL,
  `message` text,
  `projectID` int(10) unsigned DEFAULT NULL,
  `date` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `projectID` (`projectID`),
  KEY `receiverId` (`receiverId`),
  KEY `senderId` (`senderId`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=85 ;

--
-- Contenu de la table `message`
--

INSERT INTO `message` (`id`, `senderId`, `receiverId`, `message`, `projectID`, `date`) VALUES
(82, 2, 1, 'Envoie de message', 28, '2014-07-15 23:55:54'),
(83, 1, 2, 'c', 28, '2014-07-15 23:56:18'),
(84, 2, 1, 'c''est', 28, '2014-07-15 23:56:31');

-- --------------------------------------------------------

--
-- Structure de la table `project`
--

CREATE TABLE IF NOT EXISTS `project` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=31 ;

--
-- Contenu de la table `project`
--

INSERT INTO `project` (`id`, `name`, `description`) VALUES
(28, 'Juntos Test', 'Projet de test de notre projet Juntos');

-- --------------------------------------------------------

--
-- Structure de la table `sharefiles`
--

CREATE TABLE IF NOT EXISTS `sharefiles` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `projectId` int(11) DEFAULT NULL,
  `filename` text,
  `filecontent` longblob,
  `userId` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Contenu de la table `sharefiles`
--

INSERT INTO `sharefiles` (`id`, `projectId`, `filename`, `filecontent`, `userId`) VALUES
(3, 28, 'juntos_first.sql', 0x0a0a435245415445205441424c452060757365726020280a6069646020696e7420554e5349474e4544204e4f54204e554c4c204155544f5f494e4352454d454e542c0a606c6f67696e6020766172636861722832353529204e554c4c2c0a606d61696c6020766172636861722832353529204e554c4c2c0a606b6579706173736020766172636861722832353529204e554c4c2c0a5052494d415259204b45592028606964602c20606c6f67696e602c20606d61696c6029200a293b0a0a435245415445205441424c45206070726f6a6563746020280a6069646020696e7420554e5349474e4544204e4f54204e554c4c204155544f5f494e4352454d454e542c0a606e616d656020766172636861722832353529204e4f54204e554c4c2c0a606465736372697074696f6e6020766172636861722832353529204e554c4c2c0a6064617465426567696e60206461746574696d65204e554c4c2c0a6064617465456e6460206461746574696d65204e554c4c2c0a5052494d415259204b455920286069646029200a293b0a0a435245415445205441424c45206075736572496e50726f6a6563746020280a6069646020696e7420554e5349474e4544204e4f54204e554c4c204155544f5f494e4352454d454e542c0a606964557365726020696e7420554e5349474e4544204e554c4c2c0a60696450726f6a6563746020696e7420554e5349474e4544204e554c4c2c0a5052494d415259204b455920286069646029200a293b0a0a435245415445205441424c4520606d6573736167656020280a6069646020696e7420554e5349474e4544204e4f54204e554c4c204155544f5f494e4352454d454e542c0a6073656e64657249646020696e7420554e5349474e4544204e554c4c2c0a60726563656976657249646020696e7420554e5349474e4544204e554c4c2c0a606d657373616765602074657874204e554c4c2c0a6070726f6a65637449446020696e7420554e5349474e4544204e554c4c2c0a5052494d415259204b455920286069646029200a293b0a0a435245415445205441424c452060747970656020280a6069646020696e7420554e5349474e4544204e4f54204e554c4c204155544f5f494e4352454d454e542c0a606e6f6d6020766172636861722832353529204e554c4c2c0a5052494d415259204b455920286069646029200a293b0a0a435245415445205441424c4520607461736b6020280a6069646020696e7420554e5349474e4544204e4f54204e554c4c204155544f5f494e4352454d454e542c0a60696450726f6a6563746020696e7420554e5349474e4544204e554c4c2c0a606e616d656020766172636861722832353529204e4f54204e554c4c202c0a606465736372697074696f6e602074657874204e554c4c2c0a60646174654c6f6760206461746574696d65204e554c4c2c0a6064617465446f6e6560206461746574696d65204e554c4c2c0a606461746541737369676e546f60206461746574696d65204e554c4c2c0a6061737369676e546f557365726020696e74204e554c4c2c0a606964547970656020766172636861722832353529204e554c4c2c0a5052494d415259204b455920286069646029200a293b0a0a435245415445205441424c45206074657374556e6974616972656020280a6069646020696e7420554e5349474e4544204e4f54204e554c4c204155544f5f494e4352454d454e542c0a606e616d656020766172636861722832353529204e554c4c2c0a6070726f6a65637449646020696e7420554e5349474e4544204e4f54204e554c4c2c0a6064657363697074696f6e6020766172636861722832353529204e554c4c2c0a60706172616d496e6020766172636861722832353529204e554c4c2c0a60706172616d4f75746020766172636861722832353529204e554c4c2c0a5052494d415259204b455920286069646029200a293b0a0a0a414c544552205441424c45206075736572496e50726f6a656374602041444420434f4e53545241494e542060666b5f75736572496e50726f6a6563745f757365725f316020464f524549474e204b45592028606964557365726029205245464552454e43455320607573657260202860696460293b0a414c544552205441424c45206075736572496e50726f6a656374602041444420434f4e53545241494e542060666b5f75736572496e50726f6a6563745f70726f6a6563745f316020464f524549474e204b4559202860696450726f6a6563746029205245464552454e434553206070726f6a65637460202860696460293b0a414c544552205441424c4520607461736b602041444420434f4e53545241494e542060666b5f7461736b5f747970655f316020464f524549474e204b45592028606964547970656029205245464552454e43455320607479706560202860696460293b0a414c544552205441424c4520607461736b602041444420434f4e53545241494e542060666b5f7461736b5f70726f6a6563745f316020464f524549474e204b4559202860696450726f6a6563746029205245464552454e434553206070726f6a65637460202860696460293b0a414c544552205441424c4520606d657373616765602041444420434f4e53545241494e542060666b5f6d6573736167655f757365725f316020464f524549474e204b455920286073656e64657249646029205245464552454e43455320607573657260202860696460293b0a414c544552205441424c4520606d657373616765602041444420434f4e53545241494e542060666b5f6d6573736167655f757365725f326020464f524549474e204b4559202860726563656976657249646029205245464552454e43455320607573657260202860696460293b0a414c544552205441424c4520606d657373616765602041444420434f4e53545241494e542060666b5f6d6573736167655f70726f6a6563745f316020464f524549474e204b455920286070726f6a65637449446029205245464552454e434553206070726f6a65637460202860696460293b0a414c544552205441424c45206074657374556e697461697265602041444420434f4e53545241494e542060666b5f74657374556e6974616972655f70726f6a6563745f316020464f524549474e204b455920286070726f6a65637449646029205245464552454e434553206070726f6a65637460202860696460293b0a0a, 2);

-- --------------------------------------------------------

--
-- Structure de la table `task`
--

CREATE TABLE IF NOT EXISTS `task` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `idProject` int(10) unsigned DEFAULT NULL,
  `name` varchar(255) NOT NULL,
  `description` text,
  `createBy` int(10) unsigned NOT NULL,
  `dateLog` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `dateDone` datetime DEFAULT NULL,
  `dateAssignTo` datetime DEFAULT NULL,
  `assignToUser` int(10) unsigned DEFAULT NULL,
  `idType` int(10) unsigned DEFAULT '2',
  `Etat` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  KEY `idProject` (`idProject`),
  KEY `idType` (`idType`),
  KEY `Etat` (`Etat`),
  KEY `createBy` (`createBy`),
  KEY `assignToUser` (`assignToUser`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=60 ;

--
-- Contenu de la table `task`
--

INSERT INTO `task` (`id`, `idProject`, `name`, `description`, `createBy`, `dateLog`, `dateDone`, `dateAssignTo`, `assignToUser`, `idType`, `Etat`) VALUES
(53, 28, 'ERR OO3', 'test', 2, '2014-07-15 20:31:10', NULL, '2014-07-15 22:35:29', 1, 1, 4),
(54, 28, 'ERR 004', 'test', 2, '2014-07-15 20:31:59', NULL, NULL, NULL, 1, 2),
(55, 28, 'ERR 005', 'Bug interface', 2, '2014-07-15 20:34:23', '2014-07-15 22:34:23', '2014-07-15 22:34:23', 2, 1, 6),
(56, 28, 'ERR 004', 'ticket', 2, '2014-07-15 20:35:06', NULL, '2014-07-15 22:35:06', 1, 1, 1),
(57, 28, 'ERR 006', 'blah', 2, '2014-07-15 21:38:39', NULL, '2014-07-15 23:38:39', 1, 1, 4),
(58, 28, 'ERR 07', 'blad''hjh qdxs''rr', 2, '2014-07-15 21:39:41', NULL, '2014-07-15 23:39:55', NULL, 1, 1);

-- --------------------------------------------------------

--
-- Structure de la table `testunitaire`
--

CREATE TABLE IF NOT EXISTS `testunitaire` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `projectId` int(10) unsigned NOT NULL,
  `desciption` varchar(255) DEFAULT NULL,
  `paramIn` varchar(255) DEFAULT NULL,
  `paramOut` varchar(255) DEFAULT NULL,
  `resultat` tinyint(1) unsigned NOT NULL,
  `valideur` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`),
  KEY `projectId` (`projectId`),
  KEY `valideur` (`valideur`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=26 ;

--
-- Contenu de la table `testunitaire`
--

INSERT INTO `testunitaire` (`id`, `name`, `projectId`, `desciption`, `paramIn`, `paramOut`, `resultat`, `valideur`) VALUES
(24, 'test d''égalité', 28, 'test l''égalité des deux partie', 'int 2 , int 3', 'bool false', 0, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `todo`
--

CREATE TABLE IF NOT EXISTS `todo` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `titre` varchar(255) NOT NULL DEFAULT 'Titre du projet.',
  `description` text NOT NULL,
  `idProjet` int(10) unsigned NOT NULL,
  `idCreateur` int(10) unsigned NOT NULL,
  `idDeveloppeur` int(10) unsigned DEFAULT NULL,
  `dateCreation` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `dateModification` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `dateFinalisation` datetime DEFAULT NULL,
  `idAvancement` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `titre` (`titre`),
  KEY `idProjet` (`idProjet`,`idCreateur`,`idDeveloppeur`),
  KEY `idAvancement` (`idAvancement`),
  KEY `idCreateur` (`idCreateur`),
  KEY `idDeveloppeur` (`idDeveloppeur`),
  KEY `idCreateur_2` (`idCreateur`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=26 ;

--
-- Contenu de la table `todo`
--

INSERT INTO `todo` (`id`, `titre`, `description`, `idProjet`, `idCreateur`, `idDeveloppeur`, `dateCreation`, `dateModification`, `dateFinalisation`, `idAvancement`) VALUES
(23, 'Exportation de la base de donnée', 'Faire un export de la base pour la soutenance.', 28, 2, 1, '2014-07-15 22:11:41', '2014-07-15 22:11:41', '2014-07-15 22:00:00', 2),
(24, 'Création du document soutenance', 'Voir le document soutenance pour les détails.', 28, 2, NULL, '2014-07-15 22:13:23', '2014-07-15 22:13:23', '2014-07-15 22:00:00', 1);

-- --------------------------------------------------------

--
-- Structure de la table `type`
--

CREATE TABLE IF NOT EXISTS `type` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `nom` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Contenu de la table `type`
--

INSERT INTO `type` (`id`, `nom`) VALUES
(1, 'ticket'),
(2, 'task');

-- --------------------------------------------------------

--
-- Structure de la table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `login` varchar(255) NOT NULL DEFAULT '',
  `mail` varchar(255) NOT NULL DEFAULT '',
  `keypass` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`,`login`,`mail`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Contenu de la table `user`
--

INSERT INTO `user` (`id`, `login`, `mail`, `keypass`) VALUES
(1, 'rgabel', 'romain.gabel@gmail.com', 'test'),
(2, 'ray', 'ray@gmail.com', 'ray'),
(3, 'andy', 'andy@gmail.com', 'andy');

-- --------------------------------------------------------

--
-- Structure de la table `userinproject`
--

CREATE TABLE IF NOT EXISTS `userinproject` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `idUser` int(10) unsigned DEFAULT NULL,
  `idProject` int(10) unsigned DEFAULT NULL,
  `admin` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_userInProject_user_1` (`idUser`),
  KEY `fk_userInProject_project_1` (`idProject`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=58 ;

--
-- Contenu de la table `userinproject`
--

INSERT INTO `userinproject` (`id`, `idUser`, `idProject`, `admin`) VALUES
(54, 1, 28, 1),
(55, 2, 28, 0);

--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `journal`
--
ALTER TABLE `journal`
  ADD CONSTRAINT `journal_ibfk_2` FOREIGN KEY (`idProjet`) REFERENCES `project` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `journal_ibfk_3` FOREIGN KEY (`idUser`) REFERENCES `user` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `journal_ibfk_5` FOREIGN KEY (`idUserToContact`) REFERENCES `user` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `journal_ibfk_6` FOREIGN KEY (`idUserToContact`) REFERENCES `user` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `task`
--
ALTER TABLE `task`
  ADD CONSTRAINT `task_ibfk_1` FOREIGN KEY (`idProject`) REFERENCES `project` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `task_ibfk_2` FOREIGN KEY (`idType`) REFERENCES `type` (`id`) ON DELETE SET NULL ON UPDATE CASCADE,
  ADD CONSTRAINT `task_ibfk_3` FOREIGN KEY (`Etat`) REFERENCES `etat` (`id`),
  ADD CONSTRAINT `task_ibfk_4` FOREIGN KEY (`createBy`) REFERENCES `user` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `task_ibfk_5` FOREIGN KEY (`assignToUser`) REFERENCES `user` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `testunitaire`
--
ALTER TABLE `testunitaire`
  ADD CONSTRAINT `testunitaire_ibfk_2` FOREIGN KEY (`projectId`) REFERENCES `project` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `testunitaire_ibfk_1` FOREIGN KEY (`projectId`) REFERENCES `project` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `testunitaire_ibfk_3` FOREIGN KEY (`valideur`) REFERENCES `user` (`id`) ON DELETE SET NULL ON UPDATE CASCADE;

--
-- Contraintes pour la table `todo`
--
ALTER TABLE `todo`
  ADD CONSTRAINT `todo_ibfk_1` FOREIGN KEY (`idProjet`) REFERENCES `project` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `todo_ibfk_2` FOREIGN KEY (`idAvancement`) REFERENCES `avancementtodo` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `todo_ibfk_3` FOREIGN KEY (`idCreateur`) REFERENCES `user` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `todo_ibfk_4` FOREIGN KEY (`idDeveloppeur`) REFERENCES `user` (`id`) ON DELETE SET NULL ON UPDATE CASCADE;

--
-- Contraintes pour la table `userinproject`
--
ALTER TABLE `userinproject`
  ADD CONSTRAINT `fk_userInProject_project_1` FOREIGN KEY (`idProject`) REFERENCES `project` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_userInProject_user_1` FOREIGN KEY (`idUser`) REFERENCES `user` (`id`) ON DELETE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
