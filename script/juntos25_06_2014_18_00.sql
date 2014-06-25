-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Mer 25 Juin 2014 à 17:47
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

DELIMITER ;

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
-- Structure de la table `log`
--

CREATE TABLE IF NOT EXISTS `log` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `login` varchar(50) CHARACTER SET utf8 NOT NULL DEFAULT '...',
  `title` varchar(255) CHARACTER SET utf8 NOT NULL,
  `message` text CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=35 ;

--
-- Contenu de la table `log`
--

INSERT INTO `log` (`id`, `login`, `title`, `message`) VALUES
(29, 'rgabel', 'Le projet n''existe pas', 'Le projet n''existe pas'),
(30, 'rgabel', 'Le projet n''existe pas', 'Le projet n''existe pas'),
(31, 'rgabel', 'Le projet n''existe pas', 'Le projet n''existe pas'),
(32, 'rgabel', 'Le projet n''existe pas', 'Le projet n''existe pas'),
(33, 'rgabel', 'Erreur connection', 'Tentative de connection avec un mauvais couple d''id'),
(34, 'rgabel', 'Erreur connection', 'Tentative de connection avec un mauvais couple d''id');

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
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=27 ;

--
-- Contenu de la table `project`
--

INSERT INTO `project` (`id`, `name`, `description`) VALUES
(1, 'First', 'mon premier projet'),
(26, 'Projet 2', 'Admin : rgabel \nAutre: andy');

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
  `assignToUser` int(10) unsigned NOT NULL,
  `idType` int(10) unsigned DEFAULT '2',
  `Etat` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  KEY `idProject` (`idProject`),
  KEY `idType` (`idType`),
  KEY `Etat` (`Etat`),
  KEY `createBy` (`createBy`),
  KEY `assignToUser` (`assignToUser`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Contenu de la table `task`
--

INSERT INTO `task` (`id`, `idProject`, `name`, `description`, `createBy`, `dateLog`, `dateDone`, `dateAssignTo`, `assignToUser`, `idType`, `Etat`) VALUES
(1, 1, 'Mon premier ticket', 'Ticket de test pour le projet 1', 1, '2014-06-25 08:09:41', '2014-06-25 17:10:00', '2014-06-25 16:20:00', 3, 1, 1),
(2, 1, 'Bug ticket', 'Crash lors du chargement des tickets', 1, '2014-06-25 15:10:53', NULL, '2014-06-25 17:15:37', 2, 1, 3),
(4, 26, 'Ya pas ray', 'pas de ray sur le projet', 3, '2014-06-25 15:17:29', NULL, '2014-06-25 17:00:00', 1, 1, 6);

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
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=49 ;

--
-- Contenu de la table `userinproject`
--

INSERT INTO `userinproject` (`id`, `idUser`, `idProject`, `admin`) VALUES
(1, 1, 1, 1),
(43, 2, 1, 0),
(47, 1, 26, 1),
(48, 3, 26, 0);

--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `task`
--
ALTER TABLE `task`
  ADD CONSTRAINT `task_ibfk_5` FOREIGN KEY (`assignToUser`) REFERENCES `user` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `task_ibfk_1` FOREIGN KEY (`idProject`) REFERENCES `project` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `task_ibfk_2` FOREIGN KEY (`idType`) REFERENCES `type` (`id`) ON DELETE SET NULL ON UPDATE CASCADE,
  ADD CONSTRAINT `task_ibfk_3` FOREIGN KEY (`Etat`) REFERENCES `etat` (`id`),
  ADD CONSTRAINT `task_ibfk_4` FOREIGN KEY (`createBy`) REFERENCES `user` (`id`) ON UPDATE CASCADE;

--
-- Contraintes pour la table `userinproject`
--
ALTER TABLE `userinproject`
  ADD CONSTRAINT `fk_userInProject_project_1` FOREIGN KEY (`idProject`) REFERENCES `project` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_userInProject_user_1` FOREIGN KEY (`idUser`) REFERENCES `user` (`id`) ON DELETE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
