DROP TABLE IF EXISTS `chat_inc`;
CREATE TABLE `chat_inc` (
  `id`  int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) CHARACTER SET utf8,
  `text` varchar(254) CHARACTER SET utf8,
  `timer`  int(10) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Web Chat';

DROP TABLE IF EXISTS `chat_out`;
CREATE TABLE `chat_out` (
  `id`  int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) CHARACTER SET utf8,
  `text` varchar(254) CHARACTER SET utf8,
  `timer`  int(10) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Web Chat';
