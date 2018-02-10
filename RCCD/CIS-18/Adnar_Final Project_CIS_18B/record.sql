DROP DATABASE IF EXISTS record;

CREATE DATABASE record;

USE record;

CREATE TABLE `user` (
  `user` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(10) NOT NULL,
  `password` varchar(10) NOT NULL,
  PRIMARY KEY (`user`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1;

INSERT INTO `user` (`user`, `name`, `password`) VALUES
(1, 'Adnar', 'test'),
(2, 'Ulices', 'test');
