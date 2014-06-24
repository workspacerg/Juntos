-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Mar 24 Juin 2014 à 23:24
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

DELIMITER ;

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
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Contenu de la table `log`
--

INSERT INTO `log` (`id`, `login`, `title`, `message`) VALUES
(9, 'rgabel', 'Le projet n''existe pas', 'Le projet n''existe pas');

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
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

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
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Contenu de la table `project`
--

INSERT INTO `project` (`id`, `name`, `description`) VALUES
(1, 'First', 'mon premier projet'),
(4, 'new', 'new'),
(8, 'ray_is_admin', 'rom is usual user');

-- --------------------------------------------------------

--
-- Structure de la table `task`
--

CREATE TABLE IF NOT EXISTS `task` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `idProject` int(10) unsigned DEFAULT NULL,
  `name` varchar(255) NOT NULL,
  `description` text,
  `dateLog` datetime DEFAULT NULL,
  `dateDone` datetime DEFAULT NULL,
  `dateAssignTo` datetime DEFAULT NULL,
  `assignToUser` int(11) DEFAULT NULL,
  `idType` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

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
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Structure de la table `type`
--

CREATE TABLE IF NOT EXISTS `type` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `nom` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

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
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=32 ;

--
-- Contenu de la table `userinproject`
--

INSERT INTO `userinproject` (`id`, `idUser`, `idProject`, `admin`) VALUES
(1, 1, 1, 1),
(4, 2, 4, 0),
(9, 2, 8, 1),
(25, 2, 1, 0),
(30, 1, 8, 0),
(31, 3, 1, 0);

--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `userinproject`
--
ALTER TABLE `userinproject`
  ADD CONSTRAINT `fk_userInProject_project_1` FOREIGN KEY (`idProject`) REFERENCES `project` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_userInProject_user_1` FOREIGN KEY (`idUser`) REFERENCES `user` (`id`) ON DELETE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
