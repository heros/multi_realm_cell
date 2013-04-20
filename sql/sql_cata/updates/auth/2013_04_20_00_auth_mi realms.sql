/*Table structure for table `realmlist` */

DROP TABLE IF EXISTS `realmlist`;

CREATE TABLE `realmlist` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL DEFAULT '',
  `address` varchar(255) NOT NULL DEFAULT '127.0.0.1',
  `localAddress` varchar(255) NOT NULL DEFAULT '127.0.0.1',
  `localSubnetMask` varchar(255) NOT NULL DEFAULT '255.255.255.0',
  `port` smallint(5) unsigned NOT NULL DEFAULT '8085',
  `icon` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `flag` tinyint(3) unsigned NOT NULL DEFAULT '2',
  `timezone` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `allowedSecurityLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `population` float unsigned NOT NULL DEFAULT '0',
  `gamebuild` int(10) unsigned NOT NULL DEFAULT '15595',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8 COMMENT='Realm System';

/*Data for the table `realmlist` */

insert  into `realmlist`(`id`,`name`,`address`,`localAddress`,`localSubnetMask`,`port`,`icon`,`flag`,`timezone`,`allowedSecurityLevel`,`population`,`gamebuild`) values (1,'Genesis_434','127.0.0.1','127.0.0.1','255.255.255.0',8085,1,0,8,0,0,15595),(2,'Genesis_504','127.0.0.1','127.0.0.1','255.255.255.0',8086,2,0,8,0,0,16016),(3,'Genesis_505b','127.0.0.1','127.0.0.1','255.255.255.0',8087,2,0,8,0,0,16035),(4,'Genesis_505','127.0.0.1','127.0.0.1','255.255.255.0',8088,2,0,8,0,0,16048),(5,'Genesis_510','127.0.0.1','127.0.0.1','255.255.255.0',8089,2,0,8,0,0,16309),(6,'Genesis_510a','127.0.0.1','127.0.0.1','255.255.255.0',8090,2,0,8,0,0,16357),(7,'Genesis_520','127.0.0.1','127.0.0.1','255.255.255.0',8091,2,0,8,0,0,16733),(8,'Genesis_520_test_a','127.0.0.1','127.0.0.1','255.255.255.0',8092,2,0,8,0,0,16769),(9,'Genesis_520_test_b','127.0.0.1','127.0.0.1','255.255.255.0',8093,2,0,8,0,0,16826),(10,'Genesis_520_test_c','127.0.0.1','127.0.0.1','255.255.255.0',8094,2,0,8,0,0,19080),(11,'Genesis_test_cata_old','127.0.0.1','127.0.0.1','255.255.255.0',8095,2,0,8,0,0,13623),(12,'Genesis_test_wotlk_old','127.0.0.1','127.0.0.1','255.255.255.0',8096,2,0,8,0,0,12340);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
