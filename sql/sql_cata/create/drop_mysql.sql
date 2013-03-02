REVOKE ALL PRIVILEGES ON * . * FROM 'LikanMod'@'localhost';

REVOKE ALL PRIVILEGES ON `world` . * FROM 'LikanMod'@'localhost';

REVOKE GRANT OPTION ON `world` . * FROM 'LikanMod'@'localhost';

REVOKE ALL PRIVILEGES ON `characters` . * FROM 'LikanMod'@'localhost';

REVOKE GRANT OPTION ON `characters` . * FROM 'LikanMod'@'localhost';

REVOKE ALL PRIVILEGES ON `auth` . * FROM 'LikanMod'@'localhost';

REVOKE GRANT OPTION ON `auth` . * FROM 'LikanMod'@'localhost';

DROP USER 'LikanMod'@'localhost';

DROP DATABASE IF EXISTS `world`;

DROP DATABASE IF EXISTS `characters`;

DROP DATABASE IF EXISTS `auth`;
