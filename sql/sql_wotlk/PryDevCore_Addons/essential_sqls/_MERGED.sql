-- -------------------------------------------------------- 
-- ####### rev155_World_Naygaths_ItemRequester.sql 
-- -------------------------------------------------------- 
REPLACE INTO `creature_template` (`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,`faction_A`,`faction_H`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`mindmg`,`maxdmg`,`dmgschool`,`attackpower`,`dmg_multiplier`,`baseattacktime`,`rangeattacktime`,`unit_class`,`unit_flags`,`dynamicflags`,`family`,`trainer_type`,`trainer_spell`,`trainer_class`,`trainer_race`,`minrangedmg`,`maxrangedmg`,`rangedattackpower`,`type`,`type_flags`,`lootid`,`pickpocketloot`,`skinloot`,`resistance1`,`resistance2`,`resistance3`,`resistance4`,`resistance5`,`resistance6`,`spell1`,`spell2`,`spell3`,`spell4`,`spell5`,`spell6`,`spell7`,`spell8`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`InhabitType`,`Health_mod`,`Mana_mod`,`Armor_mod`,`RacialLeader`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`movementId`,`RegenHealth`,`equipment_id`,`mechanic_immune_mask`,`flags_extra`,`ScriptName`,`WDBVerified`) VALUES
(99004,0,0,0,0,0,18,0,18,0,'Naygath\'s Item Requester','Request Items',NULL,0,59,61,0,35,35,1,1.45,1.14,1,0,655,663,0,158,1,1500,1900,1,0,0,0,0,0,0,0,0,0,100,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',1,3,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,'ItemRequester',1);
 
 
-- -------------------------------------------------------- 
-- ####### rev155_World_Pryds_BufferNpc.sql 
-- -------------------------------------------------------- 
-- Pryds Guild NPC Buffer

REPLACE INTO `creature_template` (entry,difficulty_entry_1,difficulty_entry_2,difficulty_entry_3,KillCredit1,KillCredit2,modelid1,modelid2,modelid3,modelid4,name,subname,IconName,gossip_menu_id,minlevel,maxlevel,exp,faction_A,faction_H,npcflag,speed_walk,speed_run,scale,rank,mindmg,maxdmg,dmgschool,attackpower,dmg_multiplier,baseattacktime,rangeattacktime,unit_class,unit_flags,dynamicflags,family,trainer_type,trainer_spell,trainer_class,trainer_race,minrangedmg,maxrangedmg,rangedattackpower,type,type_flags,lootid,pickpocketloot,skinloot,resistance1,resistance2,resistance3,resistance4,resistance5,resistance6,spell1,spell2,spell3,spell4,spell5,spell6,spell7,spell8,PetSpellDataId,VehicleId,mingold,maxgold,AIName,MovementType,InhabitType,Health_mod,Mana_mod,Armor_mod,RacialLeader,questItem1,questItem2,questItem3,questItem4,questItem5,questItem6,movementId,RegenHealth,equipment_id,mechanic_immune_mask,flags_extra,ScriptName,WDBVerified)
VALUES (99002,0,0,0,0,0,18,0,18,0,'Pryds Buffer','Guild Buffer','',0,59,61,0,35,35,1,1.48,1.14286,1,0,655,663,0,158,1,1500,1900,1,0,0,0,0,0,0,0,0,0,100,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',1,3,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,'pryds_buffer',0); 
 
-- -------------------------------------------------------- 
-- ####### rev155_World_Pryds_TeleNpc.sql 
-- -------------------------------------------------------- 
-- Pryds Custom TeleNPC

DROP TABLE IF EXISTS `custom_npc_tele_category`;
CREATE TABLE `custom_npc_tele_category` (
  `id` int(6) unsigned NOT NULL default '0',
  `name` varchar(255) NOT NULL default '',
  `flag` tinyint(3) unsigned NOT NULL default '0',
  `data0` bigint(20) unsigned NOT NULL default '0',
  `data1` int(6) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `custom_npc_tele_destination`;
CREATE TABLE `custom_npc_tele_destination` (
  `id` int(6) unsigned NOT NULL auto_increment,
  `name` char(100) NOT NULL default '',
  `pos_X` float NOT NULL default '0',
  `pos_Y` float NOT NULL default '0',
  `pos_Z` float NOT NULL default '0',
  `map` smallint(5) unsigned NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `level` tinyint(3) unsigned NOT NULL default '0',
  `cost` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `custom_npc_tele_association`;
CREATE TABLE `custom_npc_tele_association` (
  `cat_id` int(6) unsigned NOT NULL default '0',
  `dest_id` int(6) unsigned NOT NULL default '0',
  PRIMARY KEY  (`cat_id`, `dest_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

TRUNCATE `custom_npc_tele_category`;
INSERT INTO `custom_npc_tele_category`
   (`id`, `name`, `flag`, `data0`, `data1`)
VALUES
   (1, 'Cities', 0, 1, 0),
   (2, 'Cities', 0, 2, 0),
   (3, 'Battlegrounds', 0, 1, 0),
   (4, 'Battlegrounds', 0, 2, 0),
   (5, 'Arenas', 0, 0, 0),
   (6, '[Instances Lvl 1-60]', 0, 0, 0),
   (7, '[Instances Lvl 60+]', 5, 60, 0),
   (8, '[Instances Lvl 70+]', 5, 70, 0),
   (9, 'Destinations MJ', 3, 0, 0);

TRUNCATE `custom_npc_tele_destination`;
INSERT INTO `custom_npc_tele_destination`
   (`id`, `name`, `pos_X`, `pos_Y`, `pos_Z`, `map`, `orientation`, `level`, `cost`)
VALUES
   (1, 'Alterac Valley', 883.187, -489.375, 96.7618, 30, 3.06932, 0, 0),
   (2, 'Alterac Valley', -818.155, -623.043, 54.0884, 30, 2.1, 0, 0),
   (3, 'Arathi Basin', 686.053, 683.165, -12.9149, 529, 0.18, 0, 0),
   (4, 'Arathi Basin', 1308.68, 1306.03, -9.0107, 529, 3.91285, 0, 0),
   (5, 'Black Temple', -3610.72, 324.988, 37.4, 530, 3.28298, 0, 0),
   (6, 'Blackfathom Deeps', 4254.58, 664.74, -29.04, 1, 1.97, 0, 0),
   (7, 'Blackrock Depths', -7301.03, -913.19, 165.37, 0, 0.08, 0, 0),
   (8, 'Blackrock Spire', -7535.43, -1212.04, 285.45, 0, 5.29, 0, 0),
   (9, 'Blackwing Lair', -7665.55, -1102.49, 400.679, 469, 0, 0, 0),
   (10, 'Caverns of Time', -8173.66, -4746.36, 33.8423, 1, 4.93989, 0, 0),
   (11, 'Circle of Blood', 2839.44, 5930.17, 11.1002, 530, 3.16284, 0, 0),
   (12, 'Coilfang Reservoir', 517.288, 6976.28, 32.0072, 530, 0, 0, 0),
   (13, 'Darnassus', 9947.52, 2482.73, 1316.21, 1, 0, 0, 0),
   (14, 'Dire Maul', -3982.47, 1127.79, 161.02, 1, 0.05, 0, 0),
   (15, 'Exodar', -4073.03, -12020.4, -1.47, 530, 0, 0, 0),
   (16, 'Eye of the Storm', 2487.72, 1609.12, 1224.64, 566, 3.35671, 0, 0),
   (17, 'Eye of the Storm', 1843.73, 1529.77, 1224.43, 566, 0.297579, 0, 0),
   (18, 'Goldshire', -9464, 62, 56, 0, 0, 0, 0),
   (19, 'Gruul\'s Lair', 3539.01, 5082.36, 1.69107, 530, 0, 0, 0),
   (20, 'Gurubashi', -13261.3, 168.294, 35.0792, 0, 1.00688, 0, 0),
   (21, 'Hellfire Citadel', -305.816, 3056.4, -2.47318, 530, 2.01, 0, 0),
   (22, 'Ironforge', -4924.07, -951.95, 501.55, 0, 5.4, 0, 0),
   (23, 'Isle Of Quel\'Danas', 12947.4, -6893.31, 5.68398, 530, 3.09154, 0, 0),
   (24, 'Karazhan', -11118.8, -2010.84, 47.0807, 0, 0, 0, 0),
   (25, 'Maraudon', -1433.33, 2955.34, 96.21, 1, 4.82, 0, 0),
   (26, 'Molten Core', 1121.45, -454.317, -101.33, 230, 3.5, 0, 0),
   (27, 'Naxxramas', 3125.18, -3748.02, 136.049, 0, 0, 0, 0),
   (28, 'Onyxia\'s Lair', -4707.44, -3726.82, 54.6723, 1, 3.8, 0, 0),
   (29, 'Orgrimmar', 1552.5, -4420.66, 8.94802, 1, 0, 0, 0),
   (30, 'Razor Hill', 315.721, -4743.4, 10.4867, 1, 0, 0, 0),
   (31, 'Razorfen Downs', -4645.08, -2470.85, 85.53, 1, 4.39, 0, 0),
   (32, 'Razorfen Kraul', -4484.04, -1739.4, 86.47, 1, 1.23, 0, 0),
   (33, 'Ring of Trials', -1999.94, 6581.71, 11.32, 530, 2.3, 0, 0),
   (34, 'Ruins of Ahn\'Qiraj', -8409.03, 1498.83, 27.3615, 1, 2.49757, 0, 0),
   (35, 'Scholomance', 1219.01, -2604.66, 85.61, 0, 0.5, 0, 0),
   (36, 'Shadowfang Keep', -254.47, 1524.68, 76.89, 0, 1.56, 0, 0),
   (37, 'Shattrath City', -1850.21, 5435.82, -10.9614, 530, 3.40391, 0, 0),
   (38, 'Silvermoon', 9338.74, -7277.27, 13.7895, 530, 0, 0, 0),
   (39, 'Stormwind', -8960.14, 516.266, 96.3568, 0, 0, 0, 0),
   (40, 'Stratholme', 3263.54, -3379.46, 143.59, 0, 0, 0, 0),
   (41, 'Tempest Keep', 3089.58, 1399.05, 187.653, 530, 4.79407, 0, 0),
   (42, 'Temple of Ahn\'Qiraj', -8245.84, 1983.74, 129.072, 1, 0.936195, 0, 0),
   (43, 'The Deadmines', -11212, 1658.58, 25.67, 0, 1.45, 0, 0),
   (44, 'The Maul', -3761.49, 1133.43, 132.083, 1, 4.57259, 0, 0),
   (45, 'The Scarlet Monastery', 2843.89, -693.74, 139.32, 0, 5.11, 0, 0),
   (46, 'The Sunken Temple', -10346.9, -3851.9, -43.41, 0, 6.09, 0, 0),
   (47, 'The Wailing Caverns', -722.53, -2226.3, 16.94, 1, 2.71, 0, 0),
   (48, 'Thunder Bluff', -1290, 147.034, 129.682, 1, 4.919, 0, 0),
   (49, 'Uldaman', -6119.7, -2957.3, 204.11, 0, 0.03, 0, 0),
   (50, 'Undercity', 1819.71, 238.79, 60.5321, 0, 0, 0, 0),
   (51, 'Warsong Gulch', 930.851, 1431.57, 345.537, 489, 0.015704, 0, 0),
   (52, 'Warsong Gulch', 1525.95, 1481.66, 352.001, 489, 3.20756, 0, 0),
   (53, 'Zul\'Aman', 6846.95, -7954.5, 170.028, 530, 4.61501, 0, 0),
   (54, 'Zul\'Farrak', -6839.39, -2911.03, 8.87, 1, 0.41, 0, 0),
   (55, 'Zul\'Gurub', -11916.7, -1212.82, 92.2868, 0, 4.6095, 0, 0),
   (56, 'Ile des MJ', 16254, 16276.9, 14.5082, 1, 1.70269, 0, 0);

TRUNCATE `custom_npc_tele_association`;
INSERT INTO `custom_npc_tele_association`
  (`cat_id`, `dest_id`)
VALUES
  (1, 13), (1, 15), (1, 18), (1, 22), (1, 23), (1, 37), (1, 39), (2, 23), (2, 29), (2, 30), (2, 37), (2, 38), (2, 48), (2, 50), (3, 1), (3, 4), (3, 16), (3, 52), (4, 2), (4, 3), (4, 17), (4, 51), (5, 11), (5, 20), (5, 33), (5, 44), (6, 6), (6, 7), (6, 8), (6, 14), (6, 25), (6, 31), (6, 32), (6, 35), (6, 36), (6, 40), (6, 43), (6, 45), (6, 46), (6, 47), (6, 49), (6, 54), (7, 9), (7, 26), (7, 27), (7, 28), (7, 34), (7, 42), (7, 55), (8, 5), (8, 10), (8, 12), (8, 19), (8, 21), (8, 24), (8, 41), (8, 53), (9, 56);

-- `npc_text`
REPLACE INTO `npc_text` (`ID`, `text0_0`) VALUES
   (100000, 'Choose your Category.'),
   (100001, 'Choose your Destination.');

-- `creature_template`
INSERT INTO `creature_template` VALUES (99001, 0, 0, 0, 0, 0, 18, 0, 18, 0, 'Pryds TeleNPC', '', 'Teleport Master', 0, 59, 61, 0, 35, 35, 1, 1.48, 1.14286, 1, 0, 509, 683, 0, 158, 1, 1500, 1900, 1, 0, 0, 0, 0, 0, 0, 0, 371, 535, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_teleport', 0); 
 
-- -------------------------------------------------------- 
-- ####### rev155_World_SPGMs_AllInOne.sql 
-- -------------------------------------------------------- 
-- Pryds ALL In ONE

REPLACE INTO `creature_template` (entry,difficulty_entry_1,difficulty_entry_2,difficulty_entry_3,KillCredit1,KillCredit2,modelid1,modelid2,modelid3,modelid4,name,subname,IconName,gossip_menu_id,minlevel,maxlevel,exp,faction_A,faction_H,npcflag,speed_walk,speed_run,scale,rank,mindmg,maxdmg,dmgschool,attackpower,dmg_multiplier,baseattacktime,rangeattacktime,unit_class,unit_flags,dynamicflags,family,trainer_type,trainer_spell,trainer_class,trainer_race,minrangedmg,maxrangedmg,rangedattackpower,type,type_flags,lootid,pickpocketloot,skinloot,resistance1,resistance2,resistance3,resistance4,resistance5,resistance6,spell1,spell2,spell3,spell4,spell5,spell6,spell7,spell8,PetSpellDataId,VehicleId,mingold,maxgold,AIName,MovementType,InhabitType,Health_mod,Mana_mod,Armor_mod,RacialLeader,questItem1,questItem2,questItem3,questItem4,questItem5,questItem6,movementId,RegenHealth,equipment_id,mechanic_immune_mask,flags_extra,ScriptName,WDBVerified)
VALUES (99003,0,0,0,0,0,18,0,18,0,'Pryds All In One NPC','AIO Master','',0,59,61,0,35,35,1,1.48,1.14286,1,0,655,663,0,158,1,1500,1900,1,0,0,0,0,0,0,0,0,0,100,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',1,3,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,'pryds_allinone',0);

UPDATE `creature_template` SET `name`='Zentrin',`subname`='Buff SkillUp Trainer Morph',`IconName`='',`AIName`='',`ScriptName`='pryds_allinone' WHERE `entry`=111000;

UPDATE `creature_template` SET `name`='Zentrin',`subname`='Buff SkillUp Trainer Morph',`IconName`='',`AIName`='',`ScriptName`='pryds_allinone' WHERE `entry`=909056; 
 
-- -------------------------------------------------------- 
-- ####### rev156_World_BeastMaster.sql 
-- -------------------------------------------------------- 
REPLACE INTO `creature_template` (`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,`faction_A`,`faction_H`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`mindmg`,`maxdmg`,`dmgschool`,`attackpower`,`dmg_multiplier`,`baseattacktime`,`rangeattacktime`,`unit_class`,`unit_flags`,`dynamicflags`,`family`,`trainer_type`,`trainer_spell`,`trainer_class`,`trainer_race`,`minrangedmg`,`maxrangedmg`,`rangedattackpower`,`type`,`type_flags`,`lootid`,`pickpocketloot`,`skinloot`,`resistance1`,`resistance2`,`resistance3`,`resistance4`,`resistance5`,`resistance6`,`spell1`,`spell2`,`spell3`,`spell4`,`spell5`,`spell6`,`spell7`,`spell8`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`InhabitType`,`Health_mod`,`Mana_mod`,`Armor_mod`,`RacialLeader`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`movementId`,`RegenHealth`,`equipment_id`,`mechanic_immune_mask`,`flags_extra`,`ScriptName`,`WDBVerified`) VALUES
(99005,0,0,0,0,0,18,0,18,0,'Pryds\'s Beastmaster','Hunter Pet Master',NULL,0,59,61,0,35,35,1,1.45,1.14,1,0,655,663,0,158,1,1500,1900,1,0,0,0,0,0,0,0,0,0,100,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',1,3,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,'Npc_Beastmaster',1);
 
 
-- -------------------------------------------------------- 
-- ####### rev161_World_Ulduar_Raid.sql 
-- -------------------------------------------------------- 

update `creature_template` SET `scriptname` = 'mob_black_hole' WHERE `entry`=32953;
update `creature_template` SET `scriptname` = 'mob_living_constellation' WHERE `entry`=33052;
update `creature_template` SET `scriptname` = 'mob_algalon_stalker_asteroid_target' WHERE `entry`=33104;
update `creature_template` SET `scriptname` = 'mob_algalon_stalker_asteroid_target' WHERE `entry`=33105;

update `creature_template` SET `scriptname` = 'npc_brann_ulduar' WHERE `entry`=33579;
update `creature_template` SET `scriptname` = 'boss_freya' WHERE `entry`=32906;
update `creature_template` SET `scriptname` = 'boss_elder_brightleaf' WHERE `entry`=32915;
update `creature_template` SET `scriptname` = 'creature_unstable_sun_beam' WHERE `entry`=33050;
update `creature_template` SET `scriptname` = 'creature_sun_beam' WHERE `entry`=33170;
update `creature_template` SET `scriptname` = 'boss_elder_ironbranch' WHERE `entry`=32913;
update `creature_template` SET `scriptname` = 'creature_iron_roots' WHERE `entry`=33168;
update `creature_template` SET `scriptname` = 'boss_elder_stonebark' WHERE `entry`=32914;
update `creature_template` SET `scriptname` = 'creature_eonars_gift' WHERE `entry`=33228;
update `creature_template` SET `scriptname` = 'creature_nature_bomb' WHERE `entry`=34129;
update `creature_template` SET `scriptname` = 'creature_detonating_lasher' WHERE `entry`=32918;
update `creature_template` SET `scriptname` = 'creature_ancient_conservator' WHERE `entry`=33203;
update `creature_template` SET `scriptname` = 'creature_healthy_spore' WHERE `entry`=33215;
update `creature_template` SET `scriptname` = 'creature_storm_lasher' WHERE `entry`=32919;
update `creature_template` SET `scriptname` = 'creature_snaplasher' WHERE `entry`=32916;
update `creature_template` SET `scriptname` = 'creature_ancient_water_spirit' WHERE `entry`=33202;
update `creature_template` SET `scriptname` = 'mob_freya_trash' WHERE `entry`=33406;
update `creature_template` SET `scriptname` = 'mob_saronite_vapors' WHERE `entry`=33488;
update `creature_template` SET `scriptname` = 'mob_saronite_animus' WHERE `entry`=33524;

update `creature_template` SET `scriptname` = 'npc_hodir_shaman' WHERE `entry`=32900;
update `creature_template` SET `scriptname` = 'npc_hodir_shaman' WHERE `entry`=32950;
update `creature_template` SET `scriptname` = 'npc_hodir_shaman' WHERE `entry`=33328;
update `creature_template` SET `scriptname` = 'npc_hodir_shaman' WHERE `entry`=33332;

update `creature_template` SET `scriptname` = 'npc_hodir_druid' WHERE `entry`=32901;
update `creature_template` SET `scriptname` = 'npc_hodir_druid' WHERE `entry`=32941;
update `creature_template` SET `scriptname` = 'npc_hodir_druid' WHERE `entry`=33325;
update `creature_template` SET `scriptname` = 'npc_hodir_druid' WHERE `entry`=33333;

update `creature_template` SET `scriptname` = 'npc_hodir_mage' WHERE `entry`=32893;
update `creature_template` SET `scriptname` = 'npc_hodir_mage' WHERE `entry`=32946;
update `creature_template` SET `scriptname` = 'npc_hodir_mage' WHERE `entry`=33327;
update `creature_template` SET `scriptname` = 'npc_hodir_mage' WHERE `entry`=33331;

update `creature_template` SET `scriptname` = 'npc_hodir_priest' WHERE `entry`=32897;
update `creature_template` SET `scriptname` = 'npc_hodir_priest' WHERE `entry`=32948;
update `creature_template` SET `scriptname` = 'npc_hodir_priest' WHERE `entry`=33326;
update `creature_template` SET `scriptname` = 'npc_hodir_priest' WHERE `entry`=33330;

update `creature_template` SET `scriptname` = 'boss_hodir' WHERE `entry`=32845;
update `creature_template` SET `scriptname` = 'mob_icicle' WHERE `entry`=33169;
update `creature_template` SET `scriptname` = 'mob_icicle_snowdrift' WHERE `entry`=33173;
update `creature_template` SET `scriptname` = 'toasty_fire' WHERE `entry`=33342;
update `creature_template` SET `scriptname` = 'mob_flash_freeze' WHERE `entry`=32938;
update `creature_template` SET `scriptname` = 'mob_snowpacked_icicle' WHERE `entry`=33174;

update `creature_template` SET `scriptname` = 'boss_left_arm' WHERE `entry`=32933;
update `creature_template` SET `scriptname` = 'boss_right_arm' WHERE `entry`=32934;
update `creature_template` SET `scriptname` = 'mob_ulduar_rubble' WHERE `entry`=33768;
update `creature_template` SET `scriptname` = 'npc_focused_eye_right' WHERE `entry`=33802;
update `creature_template` SET `scriptname` = 'npc_focused_eye_left' WHERE `entry`=33632;
update `creature_template` SET `scriptname` = 'boss_mimiron' WHERE `entry`=33350;
update `creature_template` SET `scriptname` = 'boss_leviathan_mk' WHERE `entry`=33432;
update `creature_template` SET `scriptname` = 'boss_leviathan_mk' WHERE `entry`=34071;
update `creature_template` SET `scriptname` = 'boss_leviathan_mk_turret' WHERE `entry`=34071;
update `creature_template` SET `scriptname` = 'mob_proximity_mine' WHERE `entry`=34362;
update `creature_template` SET `scriptname` = 'boss_vx_001' WHERE `entry`=33651;
update `creature_template` SET `scriptname` = 'rocket_strike' WHERE `entry`=34047;
update `creature_template` SET `scriptname` = 'boss_aerial_unit' WHERE `entry`=33670;
update `creature_template` SET `scriptname` = 'magnetic_core' WHERE `entry`=34068;
update `creature_template` SET `scriptname` = 'mob_boom_bot' WHERE `entry`=33836;
update `creature_template` SET `scriptname` = 'mob_junk_bot' WHERE `entry`=33855;
update `creature_template` SET `scriptname` = 'mob_assault_bot' WHERE `entry`=34057;
update `creature_template` SET `scriptname` = 'mob_emergency_bot' WHERE `entry`=34147;

update `gameobject_template` SET `scriptname` = 'not_push_button' WHERE `entry`=194739;
update `gameobject_template` SET `scriptname` = 'go_celestial_planetarium_access' WHERE `entry`=194628;


update `creature_template` SET `scriptname` = 'mob_mimiron_flame' WHERE `entry`=34121;
update `creature_template` SET `scriptname` = 'mob_mimiron_flame' WHERE `entry`=34363;
update `creature_template` SET `scriptname` = 'mob_mimiron_flame_spread' WHERE `entry`=34121;
update `creature_template` SET `scriptname` = 'mob_frost_bomb' WHERE `entry`=34149;

update `gameobject_template` SET `scriptname` = 'go_razorscale_harpoon' WHERE `entry`=194519;
update `gameobject_template` SET `scriptname` = 'go_razorscale_harpoon' WHERE `entry`=194541;
update `gameobject_template` SET `scriptname` = 'go_razorscale_harpoon' WHERE `entry`=194542;
update `gameobject_template` SET `scriptname` = 'go_razorscale_harpoon' WHERE `entry`=194543;

update `creature_template` SET `scriptname` = 'boss_thorim' WHERE `entry`=32865;

update `creature_template` SET `scriptname` = 'mob_pre_phase' WHERE `entry`=32882;
update `creature_template` SET `scriptname` = 'mob_pre_phase' WHERE `entry`=32885;
update `creature_template` SET `scriptname` = 'mob_pre_phase' WHERE `entry`=32908;
update `creature_template` SET `scriptname` = 'mob_pre_phase' WHERE `entry`=33110;

update `creature_template` SET `scriptname` = 'mob_arena_phase' WHERE `entry`=32874;
update `creature_template` SET `scriptname` = 'mob_arena_phase' WHERE `entry`=32875;
update `creature_template` SET `scriptname` = 'mob_arena_phase' WHERE `entry`=32876;
update `creature_template` SET `scriptname` = 'mob_arena_phase' WHERE `entry`=32877;
update `creature_template` SET `scriptname` = 'mob_arena_phase' WHERE `entry`=32878;
update `creature_template` SET `scriptname` = 'mob_arena_phase' WHERE `entry`=32904;

update `creature_template` SET `scriptname` = 'mob_runic_colossus' WHERE `entry`=32872;
update `creature_template` SET `scriptname` = 'mob_rune_giant' WHERE `entry`=32873;
update `creature_template` SET `scriptname` = 'npc_sif' WHERE `entry`=33196;

update `creature_template` SET `scriptname` = 'npc_thorim_lightning_orb' WHERE `entry`=33138;


--update `creature_template` SET `scriptname` = 'at_thorim_phase_trigger' WHERE `entry`=;
UPDATE `creature_template` SET `flags_extra` = 2, `ScriptName` = 'at_thorim_phase_trigger' WHERE `entry` = 32892;

update `creature_template` SET `scriptname` = 'boss_sara' WHERE `entry`=33134;
update `creature_template` SET `scriptname` = 'boss_yoggsaron' WHERE `entry`=33288;
update `creature_template` SET `scriptname` = 'boss_brain_yoggsaron' WHERE `entry`=33890;

update `creature_template` SET `scriptname` = 'npc_ominous_cloud' WHERE `entry`=32406;
update `creature_template` SET `scriptname` = 'npc_ominous_cloud' WHERE `entry`=33292;


update `creature_template` SET `scriptname` = 'npc_guardian_yoggsaron' WHERE `entry`=33136;
update `creature_template` SET `scriptname` = 'npc_death_orb' WHERE `entry`=33882;
update `creature_template` SET `scriptname` = 'npc_laughing_skull' WHERE `entry`=33990;

update `creature_template` SET `scriptname` = 'npc_illusion' WHERE `entry`=33433;
update `creature_template` SET `scriptname` = 'npc_illusion' WHERE `entry`=33567;
update `creature_template` SET `scriptname` = 'npc_illusion' WHERE `entry`=33716;
update `creature_template` SET `scriptname` = 'npc_illusion' WHERE `entry`=33717;
update `creature_template` SET `scriptname` = 'npc_illusion' WHERE `entry`=33719;
update `creature_template` SET `scriptname` = 'npc_illusion' WHERE `entry`=33720;

update `creature_template` SET `scriptname` = 'npc_descend_into_madness' WHERE `entry`=34122;
update `creature_template` SET `scriptname` = 'npc_descend_into_madness' WHERE `entry`=34123;

update `creature_template` SET `scriptname` = 'npc_passive_illusions' WHERE `entry`=33436;
update `creature_template` SET `scriptname` = 'npc_passive_illusions' WHERE `entry`=33437;
update `creature_template` SET `scriptname` = 'npc_passive_illusions' WHERE `entry`=33441;
update `creature_template` SET `scriptname` = 'npc_passive_illusions' WHERE `entry`=33442;
update `creature_template` SET `scriptname` = 'npc_passive_illusions' WHERE `entry`=33495;
update `creature_template` SET `scriptname` = 'npc_passive_illusions' WHERE `entry`=33523;
update `creature_template` SET `scriptname` = 'npc_passive_illusions' WHERE `entry`=33535;
update `creature_template` SET `scriptname` = 'npc_passive_illusions' WHERE `entry`=33536;


update `creature_template` SET `scriptname` = 'npc_constrictor_tentacle' WHERE `entry`=33983;
update `creature_template` SET `scriptname` = 'npc_crusher_tentacle' WHERE `entry`=33966;
update `creature_template` SET `scriptname` = 'npc_corruptor_tentacle' WHERE `entry`=33985;
update `creature_template` SET `scriptname` = 'npc_immortal_guardian' WHERE `entry`=33988;

update `creature_template` SET `scriptname` = 'npc_keeper_image' WHERE `entry`=33213;
update `creature_template` SET `scriptname` = 'npc_keeper_image' WHERE `entry`=33241;
update `creature_template` SET `scriptname` = 'npc_keeper_image' WHERE `entry`=33242;
update `creature_template` SET `scriptname` = 'npc_keeper_image' WHERE `entry`=33244;

update `creature_template` SET `scriptname` = 'npc_ys_freya' WHERE `entry`=33410;
update `creature_template` SET `scriptname` = 'npc_ys_thorim' WHERE `entry`=33413;
update `creature_template` SET `scriptname` = 'npc_ys_mimiron' WHERE `entry`=33412;
update `creature_template` SET `scriptname` = 'npc_ys_hodir' WHERE `entry`=33411;
update `creature_template` SET `scriptname` = 'npc_sanity_well' WHERE `entry`=33991;

insert ignore into `spell_script_names` VALUES (63050, 'spell_yoggsaron_sanity');
insert ignore into `spell_script_names` VALUES (61969, 'spell_block_of_ice');
insert ignore into `spell_script_names` VALUES (61990, 'spell_block_of_ice');


update `creature_template` SET `scriptname` = 'npc_razorscale_harpoon' WHERE `entry`=33233;

update `creature_template` SET `scriptname` = 'npc_descend_into_madness' WHERE `entry`=34122;
update `creature_template` SET `scriptname` = 'npc_descend_into_madness' WHERE `entry`=34123; 
 
-- -------------------------------------------------------- 
-- ####### rev169_World_Dalaran_Sewers.sql 
-- -------------------------------------------------------- 
UPDATE `gameobject_template` SET `flags` = '36' WHERE `gameobject_template`.`entry` =192642 LIMIT 1 ;
UPDATE `gameobject_template` SET `flags` = '36' WHERE `gameobject_template`.`entry` =192643 LIMIT 1 ;
UPDATE `battleground_template` SET `MinPlayersPerTeam` = '0', `MaxPlayersPerTeam` = '2' WHERE `battleground_template`.`id` =10 LIMIT 1 ;
DELETE FROM `disables` WHERE `entry` = 10 ; 
 
-- -------------------------------------------------------- 
-- ####### rev173_World_Ruby_Sanctum.sql 
-- -------------------------------------------------------- 
REPLACE INTO script_texts (`entry`, `content_default`, `npc_entry`, `content_loc3`, `sound`, `type`, `language`) VALUES
('-1752008', 'Help! I am trapped within this tree! I require aid!', '0', '', '17490', '1', '0'),
('-1752009', 'Thank you! I could not have held out for much longer.... A terrible thing has happened here.', '0', '', '17491', '1', '0'),
('-1752010', 'We believed the Sanctum was well-fortified, but we were not prepared for the nature of this assault.', '0', '', '17492', '0', '0'),
('-1752011', 'The Black dragonkin materialized from thin air, and set upon us before we could react.', '0', '', '17493', '0', '0'),
('-1752012', 'We did not stand a chance. As my brethren perished around me, I managed to retreat here and bar the entrance.', '0', '', '17494', '0', '0'),
('-1752013', 'They slaughtered us with cold efficiency, but the true focus of their interest seemed to be the eggs kept here in the Sanctum.', '0', '', '17495', '0', '0'),
('-1752014', 'The commander of the forces on the ground here is a cruel brute named Zarithrian, but I fear there are greater powers at work.', '0', '', '17496', '0', '0'),
('-1752015', 'In their initial assault, I caught a glimpse of their true leader, a fearsome full-grown twilight dragon.', '0', '', '17497', '0', '0'),
('-1752016', 'I know not the extent of their plans, heroes, but I know this: They cannot be allowed to succeed!', '0', '', '17498', '0', '0'),
( -1752001, 'Ah, the entertainment has arrived.', 0, '', 17520, 1, 0),
( -1752002, 'Baltharus leaves no survivors!', 0, '', 17521, 1, 0),
( -1752003, 'This world has enough heroes.', 0, '', 17522, 1, 0),
( -1752004, 'I..Didn''t saw...that coming...', 0, '', 17523, 1, 0),
( -1752005, 'Twice the pain and half the fun.', 0, '', 17524, 1, 0),
( -1752006, 'Your power wanes, ancient one.... Soon you will join your friends.', 0, '', 17525, 1, 0),
( -1752017, 'Alexstrasza has chosen capable allies... A pity that I must END YOU!', 0, '', 17512, 1, 0),
( -1752018, 'You thought you stood a chance?', 0, '', 17513, 1, 0),
( -1752019, 'It\'s for the best.', 0, '', 17514, 1, 0),
( -1752020, 'HALION! I...', 0, '', 17515, 1, 0),
( -1752021, 'Turn them to ashes, minions!', 0, '', 17516, 1, 0),
( -1752022, 'You will sssuffer for this intrusion!', 0, '', 17528, 1, 0),
( -1752023, 'As it should be...', 0, '', 17529, 1, 0),
( -1752024, 'Halion will be pleased', 0, '', 17530, 1, 0),
( -1752025, 'Hhrr...Grr..', 0, '', 17531, 1, 0),
( -1752026, 'Burn in the master\'s flame!', 0, '', 17532, 1, 0),
(-1752027, 'Insects! You\'re too late. The Ruby Sanctum is lost.',NULL,NULL,17499,0,0),
(-1752028, 'Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!',NULL,NULL,17500,0,0),
(-1752029, 'Another hero falls.',NULL,NULL,17501,0,0),
(-1752030, 'Hahahahaha.',NULL,NULL,17502,0,0),
(-1752031, 'Relish this victory, mortals, for it will be your last! This world will burn with the master\'s return!',NULL,NULL,17503,0,0),
(-1752032, 'Not good enough.',NULL,NULL,17504,0,0),
(-1752033, 'The heavens burn!',NULL,NULL,17505,0,0),
(-1752034, 'Beware the shadow!',NULL,NULL,17506,0,0),
(-1752035, 'You will find only suffering within the realm of twilight! Enter if you dare!',NULL,NULL,17507,0,0),
(-1752036, 'I am the light and the darkness! Cower, mortals, before the herald of Deathwing!',NULL,NULL,17508,0,0);

UPDATE `instance_template` SET `script`='instance_ruby_sanctum' WHERE (`map`='724');
UPDATE `creature_template` SET `ScriptName` = 'boss_baltharus' WHERE `entry` = '39751';
UPDATE `creature_template` SET `ScriptName` = 'boss_baltharus_summon' WHERE `entry` = '39899';
UPDATE `creature_template` SET `ScriptName` = 'npc_xerestrasza' WHERE `entry` = '40429';
UPDATE `creature_template` SET `ScriptName` = 'boss_zarithrian' WHERE `entry` = '39746';
UPDATE `creature_template` SET `ScriptName` = 'boss_ragefire' WHERE `entry` = '39747';
UPDATE `creature_template` SET `ScriptName` = 'boss_halion' WHERE `entry`= '39863';
UPDATE `creature_template` SET `ScriptName` = 'boss_twilight_halion' WHERE `entry` = '40142';
UPDATE `creature_template` SET `ScriptName` = 'npc_onyx_flamecaller' WHERE `entry` = '39814';
UPDATE `creature_template` SET `ScriptName` = 'npc_meteor_strike', `flags_extra`='128' WHERE `entry` = '40041';
UPDATE `creature_template` SET `ScriptName` = 'npc_meteor_flame', `flags_extra`='128' WHERE `entry` = '40042';
UPDATE `creature_template` SET `ScriptName` = 'npc_spell_meteor_strike', `flags_extra`=128 WHERE `entry` = '40029';
UPDATE `creature_template` SET `name`='summon halion', `ScriptName` = 'npc_summon_halion', `flags_extra`=128 WHERE `entry` = '40044';

REPLACE `spell_script_names` SET `ScriptName` = 'spell_halion_portal', `spell_id`=74812;

UPDATE `gameobject_template` SET `data10`=74807 WHERE `entry`=202794;
UPDATE `gameobject_template` SET `data10`=74812 WHERE `entry`=202796;

DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='-74562') AND (`spell_effect`='74610');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='-74792') AND (`spell_effect`='74800');
INSERT INTO spell_linked_spell VALUES (-74562, 74610, 0, 'Fiery Combustion removed -> Combustion');
INSERT INTO spell_linked_spell VALUES (-74792, 74800, 0, 'Soul Consumption removed -> Consumption');

DELETE FROM creature WHERE `id`=39863 and `map`=724;
INSERT INTO creature VALUES (null,39863,724,15,1,0,0,3144.93,527.233,72.8887,0.110395,300,0,0,11156000,0,0,0,0,0,0);

-- ----------------------------------
-- --Ruby Sanctum Loots by Naygath--
-- ----------------------------------


-- SAVIANA RAGEFIRE
UPDATE `creature_template` SET `lootid`='39747' WHERE `entry` IN (39747);
-- Frozen Leather Helmet
REPLACE INTO `creature_loot_template` VALUES (39747, 33434, 83.3, 1, 0, 1, 5);
-- Necropolis Legplates
REPLACE INTO `creature_loot_template` VALUES (39747, 36400, 100, 1, 0, 1, 1);


-- CHARSCALE ASSAULTER
UPDATE `creature_template` SET `lootid`='40419' WHERE `entry` IN (40419);
-- Thick Fur Clothing Scraps
REPLACE INTO `creature_loot_template` VALUES (40419, 43852, 11.1, 1, 0, 1, 1);
-- Frostweave Cloth
REPLACE INTO `creature_loot_template` VALUES (40419, 33470, 22.2, 1, 0, 1, 1);
-- Salted Venison
REPLACE INTO `creature_loot_template` VALUES (40419, 33454, 22.2, 1, 0, 1, 1);
-- Cracked Iron Staff
REPLACE INTO `creature_loot_template` VALUES (40419, 33424, 11.1, 1, 0, 1, 1);
-- Spiderlord Chestpiece
REPLACE INTO `creature_loot_template` VALUES (40419, 36277, 11.1, 1, 0, 1, 1);


-- CHARSCALE INVOKER
UPDATE `creature_template` SET `lootid`='40417' WHERE `entry` IN (40417);
-- Borean Leather
REPLACE INTO `creature_loot_template` VALUES (40417, 33568, 15.8, 1, 0, 1, 1);
-- Thick Fur Clothing Scraps
REPLACE INTO `creature_loot_template` VALUES (40417, 43852, 15.8, 1, 0, 1, 1);
-- Frostweave Cloth
REPLACE INTO `creature_loot_template` VALUES (40417, 33470, 10.5, 1, 0, 1, 1);
-- Frigid Mail Shoulderpads 
REPLACE INTO `creature_loot_template` VALUES (40417, 33403, 5.3, 1, 0, 1, 1);
-- Frost-Worn Plate Gloves 
REPLACE INTO `creature_loot_template` VALUES (40417, 33416, 5.3, 1, 0, 1, 1);
-- Frost-Worn Plate Helmet 
REPLACE INTO `creature_loot_template` VALUES (40417, 33435, 5.3, 1, 0, 1, 1);
-- Vizier Sash 
REPLACE INTO `creature_loot_template` VALUES (40417, 36051, 5.3, 1, 0, 1, 1);
-- Coldwraith Robe 
REPLACE INTO `creature_loot_template` VALUES (40417, 36061, 5.3, 1, 0, 1, 1);
-- Icy Dragonscale 
REPLACE INTO `creature_loot_template` VALUES (40417, 38557, 5.3, 1, 0, 1, 1);



-- CHARSCALE ELITE
UPDATE `creature_template` SET `lootid`='40421' WHERE `entry` IN (40421);
-- Borean Leather
REPLACE INTO `creature_loot_template` VALUES (40421, 33568, 42.9, 1, 0, 1, 1);
-- Frostweave Cloth
REPLACE INTO `creature_loot_template` VALUES (40421, 33470, 14.3, 1, 0, 1, 1);
-- Vizier Slippers
REPLACE INTO `creature_loot_template` VALUES (40421, 36052, 14.3, 1, 0, 1, 1);
-- Recipe: Bad Clams
REPLACE INTO `creature_loot_template` VALUES (40421, 43509, 100, 1, 0, 1, 1);


-- CHARSCALE COMMANDER
UPDATE `creature_template` SET `lootid`='40423' WHERE `entry` IN (40423);
-- Frozen Bracers
REPLACE INTO `creature_loot_template` VALUES (40423, 33382, 50, 1, 0, 1, 1);
-- Frostweave Cloth
REPLACE INTO `creature_loot_template` VALUES (40423, 33470, 100, 1, 0, 1, 1);

-- BALTHARUS THE WARBORN 
UPDATE `creature_template` SET `lootid`='39751' WHERE `entry` IN (39751);
-- Frigid Mail Boots
REPLACE INTO `creature_loot_template` VALUES (39751, 33399, 50, 1, 0, 1, 1);




 
 
-- -------------------------------------------------------- 
-- ####### rev174_Character_AhBot.sql 
-- -------------------------------------------------------- 
/*Table structure for table `auctionhousebot` */

DROP TABLE IF EXISTS `auctionhousebot`;

CREATE TABLE `auctionhousebot` (
  `auctionhouse` int(11) NOT NULL default '0' COMMENT 'mapID of the auctionhouse.',
  `name` char(25) default NULL COMMENT 'Text name of the auctionhouse.',
  `minitems` int(11) default '0' COMMENT 'This is the minimum number of items you want to keep in the auction house. a 0 here will make it the same as the maximum.',
  `maxitems` int(11) default '0' COMMENT 'This is the number of items you want to keep in the auction house.',
  `percentgreytradegoods` int(11) default '0' COMMENT 'Sets the percentage of the Grey Trade Goods auction items',
  `percentwhitetradegoods` int(11) default '27' COMMENT 'Sets the percentage of the White Trade Goods auction items',
  `percentgreentradegoods` int(11) default '12' COMMENT 'Sets the percentage of the Green Trade Goods auction items',
  `percentbluetradegoods` int(11) default '10' COMMENT 'Sets the percentage of the Blue Trade Goods auction items',
  `percentpurpletradegoods` int(11) default '1' COMMENT 'Sets the percentage of the Purple Trade Goods auction items',
  `percentorangetradegoods` int(11) default '0' COMMENT 'Sets the percentage of the Orange Trade Goods auction items',
  `percentyellowtradegoods` int(11) default '0' COMMENT 'Sets the percentage of the Yellow Trade Goods auction items',
  `percentgreyitems` int(11) default '0' COMMENT 'Sets the percentage of the non trade Grey auction items',
  `percentwhiteitems` int(11) default '10' COMMENT 'Sets the percentage of the non trade White auction items',
  `percentgreenitems` int(11) default '30' COMMENT 'Sets the percentage of the non trade Green auction items',
  `percentblueitems` int(11) default '8' COMMENT 'Sets the percentage of the non trade Blue auction items',
  `percentpurpleitems` int(11) default '2' COMMENT 'Sets the percentage of the non trade Purple auction items',
  `percentorangeitems` int(11) default '0' COMMENT 'Sets the percentage of the non trade Orange auction items',
  `percentyellowitems` int(11) default '0' COMMENT 'Sets the percentage of the non trade Yellow auction items',
  `minpricegrey` int(11) default '100' COMMENT 'Minimum price of Grey items (percentage).',
  `maxpricegrey` int(11) default '150' COMMENT 'Maximum price of Grey items (percentage).',
  `minpricewhite` int(11) default '150' COMMENT 'Minimum price of White items (percentage).',
  `maxpricewhite` int(11) default '250' COMMENT 'Maximum price of White items (percentage).',
  `minpricegreen` int(11) default '800' COMMENT 'Minimum price of Green items (percentage).',
  `maxpricegreen` int(11) default '1400' COMMENT 'Maximum price of Green items (percentage).',
  `minpriceblue` int(11) default '1250' COMMENT 'Minimum price of Blue items (percentage).',
  `maxpriceblue` int(11) default '1750' COMMENT 'Maximum price of Blue items (percentage).',
  `minpricepurple` int(11) default '2250' COMMENT 'Minimum price of Purple items (percentage).',
  `maxpricepurple` int(11) default '4550' COMMENT 'Maximum price of Purple items (percentage).',
  `minpriceorange` int(11) default '3250' COMMENT 'Minimum price of Orange items (percentage).',
  `maxpriceorange` int(11) default '5550' COMMENT 'Maximum price of Orange items (percentage).',
  `minpriceyellow` int(11) default '5250' COMMENT 'Minimum price of Yellow items (percentage).',
  `maxpriceyellow` int(11) default '6550' COMMENT 'Maximum price of Yellow items (percentage).',
  `minbidpricegrey` int(11) default '70' COMMENT 'Starting bid price of Grey items as a percentage of the randomly chosen buyout price. Default: 70',
  `maxbidpricegrey` int(11) default '100' COMMENT 'Starting bid price of Grey items as a percentage of the randomly chosen buyout price. Default: 100',
  `minbidpricewhite` int(11) default '70' COMMENT 'Starting bid price of White items as a percentage of the randomly chosen buyout price. Default: 70',
  `maxbidpricewhite` int(11) default '100' COMMENT 'Starting bid price of White items as a percentage of the randomly chosen buyout price. Default: 100',
  `minbidpricegreen` int(11) default '80' COMMENT 'Starting bid price of Green items as a percentage of the randomly chosen buyout price. Default: 80',
  `maxbidpricegreen` int(11) default '100' COMMENT 'Starting bid price of Green items as a percentage of the randomly chosen buyout price. Default: 100',
  `minbidpriceblue` int(11) default '75' COMMENT 'Starting bid price of Blue items as a percentage of the randomly chosen buyout price. Default: 75',
  `maxbidpriceblue` int(11) default '100' COMMENT 'Starting bid price of Blue items as a percentage of the randomly chosen buyout price. Default: 100',
  `minbidpricepurple` int(11) default '80' COMMENT 'Starting bid price of Purple items as a percentage of the randomly chosen buyout price. Default: 80',
  `maxbidpricepurple` int(11) default '100' COMMENT 'Starting bid price of Purple items as a percentage of the randomly chosen buyout price. Default: 100',
  `minbidpriceorange` int(11) default '80' COMMENT 'Starting bid price of Orange items as a percentage of the randomly chosen buyout price. Default: 80',
  `maxbidpriceorange` int(11) default '100' COMMENT 'Starting bid price of Orange items as a percentage of the randomly chosen buyout price. Default: 100',
  `minbidpriceyellow` int(11) default '80' COMMENT 'Starting bid price of Yellow items as a percentage of the randomly chosen buyout price. Default: 80',
  `maxbidpriceyellow` int(11) default '100' COMMENT 'Starting bid price of Yellow items as a percentage of the randomly chosen buyout price. Default: 100',
  `maxstackgrey` int(11) default '0' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `maxstackwhite` int(11) default '0' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `maxstackgreen` int(11) default '0' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `maxstackblue` int(11) default '0' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `maxstackpurple` int(11) default '0' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `maxstackorange` int(11) default '0' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `maxstackyellow` int(11) default '0' COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.',
  `buyerpricegrey` int(11) default '1' COMMENT 'Multiplier to vendorprice when buying grey items from auctionhouse',
  `buyerpricewhite` int(11) default '3' COMMENT 'Multiplier to vendorprice when buying white items from auctionhouse',
  `buyerpricegreen` int(11) default '5' COMMENT 'Multiplier to vendorprice when buying green items from auctionhouse',
  `buyerpriceblue` int(11) default '12' COMMENT 'Multiplier to vendorprice when buying blue items from auctionhouse',
  `buyerpricepurple` int(11) default '15' COMMENT 'Multiplier to vendorprice when buying purple items from auctionhouse',
  `buyerpriceorange` int(11) default '20' COMMENT 'Multiplier to vendorprice when buying orange items from auctionhouse',
  `buyerpriceyellow` int(11) default '22' COMMENT 'Multiplier to vendorprice when buying yellow items from auctionhouse',
  `buyerbiddinginterval` int(11) default '1' COMMENT 'Interval how frequently AHB bids on each AH. Time in minutes',
  `buyerbidsperinterval` int(11) default '1' COMMENT 'number of bids to put in per bidding interval',
  PRIMARY KEY  (`auctionhouse`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `auctionhousebot` */

INSERT IGNORE INTO `auctionhousebot` (`auctionhouse`, `name`, `minitems`, `maxitems`, `mintime`, `maxtime`, `percentgreytradegoods`, `percentwhitetradegoods`, `percentgreentradegoods`, `percentbluetradegoods`, `percentpurpletradegoods`, `percentorangetradegoods`, `percentyellowtradegoods`, `percentgreyitems`, `percentwhiteitems`, `percentgreenitems`, `percentblueitems`, `percentpurpleitems`, `percentorangeitems`, `percentyellowitems`, `minpricegrey`, `maxpricegrey`, `minpricewhite`, `maxpricewhite`, `minpricegreen`, `maxpricegreen`, `minpriceblue`, `maxpriceblue`, `minpricepurple`, `maxpricepurple`, `minpriceorange`, `maxpriceorange`, `minpriceyellow`, `maxpriceyellow`, `minbidpricegrey`, `maxbidpricegrey`, `minbidpricewhite`, `maxbidpricewhite`, `minbidpricegreen`, `maxbidpricegreen`, `minbidpriceblue`, `maxbidpriceblue`, `minbidpricepurple`, `maxbidpricepurple`, `minbidpriceorange`, `maxbidpriceorange`, `minbidpriceyellow`, `maxbidpriceyellow`, `maxstackgrey`, `maxstackwhite`, `maxstackgreen`, `maxstackblue`, `maxstackpurple`, `maxstackorange`, `maxstackyellow`, `buyerpricegrey`, `buyerpricewhite`, `buyerpricegreen`, `buyerpriceblue`, `buyerpricepurple`, `buyerpriceorange`, `buyerpriceyellow`, `buyerbiddinginterval`, `buyerbidsperinterval`) VALUES
	(2,'Alliance',100,15000,8,24,0,27,12,10,1,0,0,0,10,30,8,2,0,0,100,150,150,250,800,1400,1250,1750,2250,4550,3250,5550,5250,6550,70,100,70,100,80,100,75,100,80,100,80,100,80,100,0,0,3,2,1,1,1,1,1,5,12,15,20,22,1,1),
	(6,'Horde',100,15000,8,24,0,27,12,10,1,0,0,0,10,30,8,2,0,0,100,150,150,250,800,1400,1250,1750,2250,4550,3250,5550,5250,6550,70,100,70,100,80,100,75,100,80,100,80,100,80,100,0,0,3,2,1,1,1,1,1,5,12,15,20,22,1,1),
	(7,'Neutral',100,5000,8,24,0,27,12,10,1,0,0,0,10,30,8,2,0,0,100,150,150,250,800,1400,1250,1750,2250,4550,3250,5550,5250,6550,70,100,70,100,80,100,75,100,80,100,80,100,80,100,0,0,3,2,1,1,1,1,1,5,12,15,20,22,1,1);


 
 
-- -------------------------------------------------------- 
-- ####### rev180_World_Isle_of_Conquest.sql 
-- -------------------------------------------------------- 
UPDATE gameobject_template SET size=2.151325 WHERE entry=195451;
UPDATE gameobject_template SET size=2.151325 WHERE entry=195452;
UPDATE gameobject_template SET size=3.163336 WHERE entry=195223;
UPDATE creature_template SET speed_run=1.142857 WHERE entry=36154;
UPDATE creature_template SET speed_run=1.142857 WHERE entry=36169;

-- Canon of the Alliance gunboat
UPDATE `creature_template` SET `spell1`=69495,`VehicleId`='452' WHERE `entry` =34929;

-- Canon of the Horde gunboat 
UPDATE `creature_template` SET `spell1`=68825,`VehicleId`='453' WHERE `entry` =34935;

-- the cannon of the keep
UPDATE `creature_template` SET `VehicleId`=160,`spell1`=67452,`spell2`='68169' WHERE `entry` =34944;

-- Catapult
UPDATE `creature_template` SET `VehicleId`=438,`spell1`=66218,`spell2`=66296 WHERE `entry`=34793;

-- Wrecker
UPDATE `creature_template` SET `VehicleId`='509',`spell1`='67442',`spell2`='68068' WHERE `entry` =34775;

-- Siege engine
UPDATE `creature_template` SET `VehicleId`=447,`spell1`=67816,`spell2`=69502 WHERE `entry`=34776;

-- Siege engine
UPDATE `creature_template` SET `VehicleId`=436,`spell1`=67816,`spell2`=69502 WHERE `entry`=35069;

-- Launcher sword
UPDATE `creature_template` SET `VehicleId`=447,`spell1`=68827,`spell2`=69515 WHERE `entry`=34802;

-- Launcher sword
UPDATE `creature_template` SET `VehicleId`=447,`spell1`=68827,`spell2`=69515 WHERE `entry`=35273;

-- Flame Turret
UPDATE `creature_template` SET `spell1`='68832' WHERE `entry` =34778;

-- Flame Turret
UPDATE `creature_template` SET `spell1`='68832' WHERE `entry` =36356;

-- Turret head
UPDATE `creature_template` SET `spell1`=67462,`spell2`=69505 WHERE `entry`=34777;

-- Turret head
UPDATE `creature_template` SET `spell1`=67462,`spell2`=69505 WHERE `entry`=36355;

-- Catapult speed
UPDATE creature_template SET `speed_run`=2.428571,`speed_walk`=2.8 WHERE `entry`=34793;

-- Overlord Agmar &   script
UPDATE creature_template SET `ScriptName`='boss_isle_of_conquest' WHERE `entry` IN (34924,34922);

DELETE FROM `trinity_string` WHERE entry BETWEEN 12011 AND 12039;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(12039, 'the alliance keep', '', '', '', '', '', '', '', ''),
(12038, 'the Horde keep', '', '', '', '', '', '', '', ''),
(12037, 'The Alliance took the Horde keep!', '', '', '', '', '', '', '', ''),
(12036, 'The Horde took the Alliance keep!', '', '', '', '', '', '', '', ''),
(12035, '%s the keep!', '', '', '', '', '', '', '', ''),
(12034, '%s attacked the Horde keep!', '', '', '', '', '', '', '', ''),
(12033, '%s attacked the Alliance keep!', '', '', '', '', '', '', '', ''),
(12032, 'The west gate of the Horde keep is destroyed!', '', '', '', '', '', '', '', ''),
(12031, 'The east gate of the Horde keep was destroyed!', '', '', '', '', '', '', '', ''),
(12030, 'The south gate of the Horde keep was destroyed!', '', '', '', '', '', '', '', ''),
(12029, 'The west gate of the Alliance keep is destroyed!', '', '', '', '', '', '', '', ''),
(12028, 'The east gate of the Alliance keep is destroyed!', '', '', '', '', '', '', '', ''),
(12027, 'The north gate of the Alliance keep is destroyed!', '', '', '', '', '', '', '', ''),
(12026, 'The battle will begin in 15 seconds!', '', '', '', '', '', '', '', ''),
(12025, '$n has assaulted the %s', '', '', '', '', '', '', '', ''),
(12024, '$n has defended the %s', '', '', '', '', '', '', '', ''),
(12023, '$n claims the %s! If left unchallenged, the %s will control it in 1 minute!', '', '', '', '', '', '', '', ''),
(12022, 'Alliance', '', '', '', '', '', '', '', ''),
(12021, 'Horde', '', '', '', '', '', '', '', ''),
(12020, 'The %s has taken the %s', '', '', '', '', '', '', '', ''),
(12019, 'Workshop', '', '', '', '', '', '', '', ''),
(12018, 'Docks', '', '', '', '', '', '', '', ''),
(12017, 'Refinery', '', '', '', '', '', '', '', ''),
(12016, 'Quarry', '', '', '', '', '', '', '', ''),
(12015, 'Hangar', '', '', '', '', '', '', '', ''),
(12014, 'The battle has begun!', '', '', '', '', '', '', '', ''),
(12013, 'The battle will begin in 30 seconds!', '', '', '', '', '', '', '', ''),
(12012, 'The battle will begin in one minute!', '', '', '', '', '', '', '', ''),
(12011, 'The battle will begin in two minutes!', '', '', '', '', '', '', '', '');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (66548, 66549, 66550);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(66548, 66550, 0, 'Isle of Conquest (OUT>IN)'),
(66549, 66550, 0, 'Isle of Conquest (IN>OUT)'),
(66550, -66549, 2, 'Isle of Conquest Teleport (OUT>IN) Debuff limit'),
(66550, -66548, 2, 'Isle of Conquest Teleport (IN>OUT) Debuff limit');

DELETE FROM `creature` WHERE `id` = 23472 AND `map` = 628;
DELETE FROM `creature` WHERE `id` = 22515 AND `map` = 628;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
(250194, 23472, 628, 3, 1, 0, 0, 1139.92, -780.212, 48.6757, 3.16908, 300, 0, 0, 4120, 0, 0, 0),
(250214, 22515, 628, 3, 1, 0, 0, 323.214, -884.536, 48.9155, 1.59435, 300, 0, 0, 4120, 0, 0, 0),
(250212, 22515, 628, 3, 1, 0, 0, 325.953, -782.401, 48.9163, 4.65741, 300, 0, 0, 4120, 0, 0, 0),
(250210, 22515, 628, 3, 1, 0, 0, 393.258, -858.941, 48.9161, 3.22484, 300, 0, 0, 4120, 0, 0, 0),
(250208, 22515, 628, 3, 1, 0, 0, 1233.08, -840.021, 48.9176, 1.51268, 300, 0, 0, 4120, 0, 0, 0),
(250206, 22515, 628, 3, 1, 0, 0, 1162.9, -746.146, 48.6285, 6.1536, 300, 0, 0, 4120, 0, 0, 0),
(250203, 22515, 628, 3, 1, 0, 0, 1235.15, -689.807, 49.1079, 1.52132, 300, 0, 0, 4120, 0, 0, 0),
(250198, 23472, 628, 3, 1, 0, 0, 1235.61, -863.124, 48.9713, 4.7171, 300, 0, 0, 4120, 0, 0, 0),
(250196, 23472, 628, 3, 1, 0, 0, 1236.6, -663.616, 47.8887, 3.00572, 300, 0, 0, 4120, 0, 0, 0),
(250182, 23472, 628, 3, 1, 0, 0, 324.262, -745.282, 49.4923, 1.55901, 300, 0, 0, 4120, 0, 0, 0),
(250180, 23472, 628, 3, 1, 0, 0, 311.937, -918.894, 48.6856, 4.76736, 300, 0, 0, 4120, 0, 0, 0),
(250186, 23472, 628, 3, 1, 0, 0, 430.61, -857.491, 48.198, 0.074609, 300, 0, 0, 4120, 0, 0, 0);


REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66630, 'spell_gen_gunship_portal'),
(66637, 'spell_gen_gunship_portal'),
(66656, 'spell_gen_parachute_ic');

DELETE FROM `achievement_criteria_data` WHERE criteria_id IN (12062,12063,12064,12065);
INSERT INTO `achievement_criteria_data` (criteria_id,type,ScriptName) VALUES
(12062,11,'achievement_bg_control_all_nodes'),
(12063,11,'achievement_bg_control_all_nodes'),
(12064,11,'achievement_bg_control_all_nodes'),
(12065,11,'achievement_bg_control_all_nodes');

-- Achievement Four Car Garage
UPDATE `creature_template` SET `ScriptName`='npc_four_car_garage' WHERE `entry` IN (34802,34793,34775,35069,34776);
-- Achievement Glaive Grave
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=12183;
INSERT INTO `achievement_criteria_data` (criteria_id,type,ScriptName) VALUES (12183,11,'achievement_bg_ic_glaive_grave');

-- Achievement Mowed Down
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=12068;
INSERT INTO `achievement_criteria_data` (criteria_id,type,ScriptName) VALUES (12068,11,'achievement_bg_ic_mowed_down');

-- Achievement Resource Glut
DELETE FROM `achievement_criteria_data` WHERE criteria_id IN (12060,12061);
INSERT INTO `achievement_criteria_data` (criteria_id,type,ScriptName) VALUES
(12060,11,'achievement_bg_ic_resource_glut'),
(12061,11,'achievement_bg_ic_resource_glut'); 
 
-- -------------------------------------------------------- 
-- ####### rev186_World_ToC_ToCr.sql 
-- -------------------------------------------------------- 
REPLACE INTO `script_texts` VALUES ('0','-1600205','Welcome champions, you have heard the call of the Argent Crusade, and you have boldly answered. It is here, in the Crusader\'s Coliseum, that you will face your greatest challenges. Those of you, who survive the rigors of the coliseum will join the Argent Crusade on it\'s march to Icecrown Citadel.','','','','','','','','','16036','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600206','Hailing from the deepest, darkest carverns of the storm peaks, Gormok the Implailer! Battle on, heros!','','','','','','','','','16038','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600207','','','','','','','','','','16037','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600208','','','','','','','','','','16026','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600209','Steel yourselves, heroes, for the twin terrors Acidmaw and Dreadscale. Enter the arena!','','','','','','','','','16039','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600210','The air freezes with the introduction of our next combatant, Icehowl! Kill or be killed, champions!','','','','','','','','','16040','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600211','Grand Warlock Wilfred Fizzlebang will summon forth your next challenge. Stand by for his entry!','','','','','','','','','16043','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600212','Thank you, Highlord! Now challengers, I will begin the ritual of summoning! When I am done, a fearsome Doomguard will appear!','','','','','','','','','16268','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600213','Prepare for oblivion!','','','','','','','','','16269','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600214','Ah ha! Behold the absolute power of Wilfred Fizzlebang, master summoner! You are bound to ME, demon!','','','','','','','','','16270','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600215','Trifling gnome, your arrogance will be your undoing!','','','','','','','','','16143','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600216','But I\'m in charge her-','','','','','','','','','16271','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600217','Quickly, heroes! Destroy the demon lord before it can open a portal to its twisted demonic realm!','','','','','','','','','16044','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600218','You face Jaraxxus, eredar lord of the Burning Legion!','','','','','','','','','16144','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600219','FLESH FROM BONE!','','','','','','','','','16149','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600220','Come forth, sister! Your master calls!','','','','','','','','','16150','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600221','INFERNO!','','','','','','','','','16151','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600222','Insignificant gnat!','','','','','','','','','16145','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600223','Banished to the Nether!','','','','','','','','','16146','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600224','Another will take my place. Your world is doomed.','','','','','','','','','16147','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600229','The next battle will be against the Argent Crusade\'s most powerful knights! Only by defeating them will you be deemed worthy...','','','','','','','','','0','1','0','0','');
-- 1600229 - 1600233 Todo Texte
REPLACE INTO `script_texts` VALUES ('0','-1600234','The next battle will be against the Argent Crusade\'s most powerful knights! Only by defeating them will you be deemed worthy...','','','','','','','','','16047','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600235','Our honor has been besmirched! They make wild claims and false accusations against us. I demand justice! Allow my champions to fight in place of your knights, Tirion. We challenge the Horde!','','','','','','','','','16066','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600236','Very well, I will allow it. Fight with honor!','','','','','','','','','16048','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600237','Fight for the glory of the Alliance, heroes! Honor your king and your people!','','','','','','','','','16065','1','0','0','');
-- 1600238 Horde Spawn
REPLACE INTO `script_texts` VALUES ('0','-1600239','Only by working together will you overcome the final challenge. From the depths of Icecrown come to of the Scourge\'s most powerful lieutenants: fearsome val\'kyr, winged harbingers of the Lich King!','','','','','','','','','0','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600240','A mighty blow has been dealt to the Lich King! You have proven yourselves able bodied champions of the Argent Crusade. Together we will strike at Icecrown Citadel and destroy what remains of the Scourge! There is no challenge that we cannot face united!','','','','','','','','','16051','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600241','You will have your challenge, Fordring.','','','','','','','','','16321','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600242','Arthas! You are hopelessly outnumbered! Lay down Frostmourne and I will grant you a just death.','','','','','','','','','16052','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600243','The Nerubians built an empire beneath the frozen wastes of Northrend. An empire that you so foolishly built your structures upon. MY EMPIRE.','','','','','','','','','16322','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600244','The souls of your fallen champions will be mine, Fordring.','','','','','','','','','16323','1','0','0','');
-- 1600245 Anubarak Intro
REPLACE INTO `script_texts` VALUES ('0','-1600246','The loss of Wilfred Fizzlebang, while unfortunate, should be a lesson to those that dare dabble in dark magic. Alas, you are victorious and must now face the next challenge. ','','','','','','','','','16045','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600247','Treacherous Alliance dogs! You summon a demon lord against warriors of the Horde!? Your deaths will be swift! ','','','','','','','','','16021','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600248','The Alliance doesn\'t need the help of a demon lord to deal with Horde filth. Come, pig! ','','','','','','','','','16064','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600249','Everyone, calm down! Compose yourselves! There is no conspiracy at play here. The warlock acted on his own volition - outside of influences from the Alliance. The tournament must go on! ','','','','','','','','','16046','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600250','A shallow and tragic victory. We are weaker as a whole from the losses suffered today. Who but the Lich King could benefit from such foolishness? Great warriors have lost their lives. And for what? The true threat looms ahead - the Lich King awaits us all in death.','','','','','','','','','0','1','0','0','');
-- -1600251 Northrend Beast Wipe
REPLACE INTO `script_texts` VALUES ('0','-1600252','In the name of our dark master. For the Lich King. You. Will. Die.','','','','','','','','','16272','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600253','CHAOS!','','','','','','','','','16274','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600254','The Scourge cannot be stopped...','','','','','','','','','16275','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600255','UNWORTHY!','','','','','','','','','16276','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600256','You have been measured, and found wanting!','','','','','','','','','16277','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600257','Let the dark consume you!','','','','','','','','','16278','1','0','0','');
REPLACE INTO `script_texts` VALUES ('0','-1600258','Let the light consume you!','','','','','','','','','16279','1','0','0','');


-- missing scripts
UPDATE `creature_template` SET `ScriptName`='npc_tcrus_announcer' WHERE (`entry`='34816');
UPDATE `creature_template` SET `ScriptName`='npc_tcrus_tirion' WHERE (`entry`='34996');
UPDATE `creature_template` SET `ScriptName`='npc_tcrus_fizzlebang' WHERE (`entry`='35458');
UPDATE `creature_template` SET `ScriptName`='npc_Garrosh' WHERE (`entry`='34995');
UPDATE `creature_template` SET `ScriptName`='npc_KingVyrn' WHERE (`entry`='34990');
UPDATE `creature_template` SET `ScriptName`='npc_tcrus_tirion' WHERE (`entry`='34996');
UPDATE `creature_template` SET `ScriptName`='npc_LichKing' WHERE (`entry`='35877');

-- Faction Champions Horde
UPDATE `creature_template` SET `ScriptName`='boss_gorgrim_shadowcleave' WHERE (`entry`='34458');
UPDATE `creature_template` SET `ScriptName`='boss_birana_stormhoof' WHERE (`entry`='34451');
UPDATE `creature_template` SET `ScriptName`='boss_erin_misthoof' WHERE (`entry`='34459');
UPDATE `creature_template` SET `ScriptName`='boss_rujkah' WHERE (`entry`='34448');
UPDATE `creature_template` SET `ScriptName`='boss_ginselle_blightslinger' WHERE (`entry`='34449');
UPDATE `creature_template` SET `ScriptName`='boss_liandra_suncaller' WHERE (`entry`='34445');
UPDATE `creature_template` SET `ScriptName`='boss_malithas_brightblader' WHERE (`entry`='34456');
UPDATE `creature_template` SET `ScriptName`='boss_caiphus_the_stern' WHERE (`entry`='34447');
UPDATE `creature_template` SET `ScriptName`='boss_vivienne_blackwhisper' WHERE (`entry`='34441');
UPDATE `creature_template` SET `ScriptName`='boss_mazdinah' WHERE (`entry`='34454');
UPDATE `creature_template` SET `ScriptName`='boss_broln_stouthorn' WHERE (`entry`='34455');
UPDATE `creature_template` SET `ScriptName`='boss_thrakgar' WHERE (`entry`='34444');
UPDATE `creature_template` SET `ScriptName`='boss_harkzog' WHERE (`entry`='34450');
UPDATE `creature_template` SET `ScriptName`='boss_narrhok_steelbreaker' WHERE (`entry`='34453');


-- Faction Champions Allianz
UPDATE `creature_template` SET `ScriptName`='boss_tyrius_duskblade' WHERE (`entry`='34461');
UPDATE `creature_template` SET `ScriptName`='boss_kavina_grovesong' WHERE (`entry`='34460');
UPDATE `creature_template` SET `ScriptName`='boss_melador_valestrider' WHERE (`entry`='34469');
UPDATE `creature_template` SET `ScriptName`='boss_alyssia_moonstalker' WHERE (`entry`='34467');
UPDATE `creature_template` SET `ScriptName`='boss_noozle_whizzlestick' WHERE (`entry`='34468');
UPDATE `creature_template` SET `ScriptName`='boss_velanaa' WHERE (`entry`='34465');
UPDATE `creature_template` SET `ScriptName`='boss_baelnor_lightbearer' WHERE (`entry`='34471');
UPDATE `creature_template` SET `ScriptName`='boss_anthar_forgemender' WHERE (`entry`='34466');
UPDATE `creature_template` SET `ScriptName`='boss_brienna_nightfell' WHERE (`entry`='34473');
UPDATE `creature_template` SET `ScriptName`='boss_irieth_shadowstepe' WHERE (`entry`='34472');
UPDATE `creature_template` SET `ScriptName`='boss_shaabad' WHERE (`entry`='34463');
UPDATE `creature_template` SET `ScriptName`='boss_saamul' WHERE (`entry`='34470');
UPDATE `creature_template` SET `ScriptName`='boss_serissa_grimdabbler' WHERE (`entry`='34474');
UPDATE `creature_template` SET `ScriptName`='boss_shocuul' WHERE (`entry`='34475');

UPDATE `instance_template` SET `script`='instance_trial_of_the_crussader' WHERE (`map`='649');

-- Spell DBC
REPLACE INTO `spelldifficulty_dbc` VALUES ('6000', '66331', '67478', '67477', '67479'); -- Gormok Impale
REPLACE INTO `spelldifficulty_dbc` VALUES ('6001', '66330', '67647', '67648', '67649'); -- Gormok Staggering Stomp
REPLACE INTO `spelldifficulty_dbc` VALUES ('6002', '66689', '67650', '67651', '67652'); -- Icehowl Artic Breath
REPLACE INTO `spelldifficulty_dbc` VALUES ('6003', '66683', '67660', '67660', '67662'); -- Icehowl Massic Crash
REPLACE INTO `spelldifficulty_dbc` VALUES ('6004', '67345', '67663', '67663', '67665'); -- Icehowl Whirl
REPLACE INTO `spelldifficulty_dbc` VALUES ('6005', '66770', '67655', '67654', '67656'); -- Icehowl Ferocious Butt
REPLACE INTO `spelldifficulty_dbc` VALUES ('6006', '66879', '67624', '67625', '67626'); -- Dreadscale Burning Bite
REPLACE INTO `spelldifficulty_dbc` VALUES ('6007', '66820', '67636', '67635', '67637'); -- Dreadscale Molten Spew
REPLACE INTO `spelldifficulty_dbc` VALUES ('6020', '66237', '67049', '67050', '67051'); -- Jaraxxus Incinerate Flesh
REPLACE INTO `spelldifficulty_dbc` VALUES ('6021', '66528', '67029', '67030', '67031'); -- Jaraxxus Fel Lighting
REPLACE INTO `spelldifficulty_dbc` VALUES ('6022', '68124', '68126', '68127', '68128'); -- Jaraxxus Legion Flame
REPLACE INTO `spelldifficulty_dbc` VALUES ('6023', '66532', '66963', '66964', '66965'); -- Jaraxxus Fel Fireball
REPLACE INTO `spelldifficulty_dbc` VALUES ('6024', '66258', '66258', '67903', '67903'); -- Jaraxxus Summon Volcan
REPLACE INTO `spelldifficulty_dbc` VALUES ('6025', '67103', '67103', '67104', '67105'); -- Portal Summon Guardian

UPDATE `creature_template` SET `ScriptName`='Boss_Jaraxxus' WHERE (`entry`='34780');
UPDATE `creature_template` SET `ScriptName`='Mob_Vulcan' WHERE `entry`=34813;
UPDATE `creature_template` SET `ScriptName`='Mob_FireTrigger' WHERE `entry`=34784;
UPDATE `creature_template` SET `ScriptName`='Mob_Netherportal' WHERE `entry`=34825;
UPDATE `creature_template` SET `scale`='2' WHERE `entry`=34825;
UPDATE `creature_template` SET `ScriptName`='Mob_MistressOfPain' WHERE `entry`=34826;
REPLACE INTO `creature_template` (`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,`faction_A`,`faction_H`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`mindmg`,`maxdmg`,`dmgschool`,`attackpower`,`dmg_multiplier`,`baseattacktime`,`rangeattacktime`,`unit_class`,`unit_flags`,`dynamicflags`,`family`,`trainer_type`,`trainer_spell`,`trainer_class`,`trainer_race`,`minrangedmg`,`maxrangedmg`,`rangedattackpower`,`type`,`type_flags`,`lootid`,`pickpocketloot`,`skinloot`,`resistance1`,`resistance2`,`resistance3`,`resistance4`,`resistance5`,`resistance6`,`spell1`,`spell2`,`spell3`,`spell4`,`spell5`,`spell6`,`spell7`,`spell8`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`InhabitType`,`Health_mod`,`Mana_mod`,`Armor_mod`,`RacialLeader`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`movementId`,`RegenHealth`,`equipment_id`,`mechanic_immune_mask`,`flags_extra`,`ScriptName`,`WDBVerified`) VALUES (41000,0,0,0,0,0,169,11686,169,0,'Wilfred Portal Trigger',NULL,NULL,0,1,1,0,0,0,0,1,1.14286,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',0,3,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,'',1);
UPDATE `creature_template` SET `name`='Wilfred Portal Trigger',`faction_A`=14,`faction_H`=14,`rank`=2,`baseattacktime`=2000,`rangeattacktime`=2000,`unit_class`=1,`minrangedmg`=1,`maxrangedmg`=2,`type`=10,`AIName`='',`Health_mod`=0.0238095,`ScriptName`='2' WHERE `entry`=41000;


-- Gormok
UPDATE `creature_template` SET `ScriptName`='boss_gormok_impaler' WHERE (`entry`='34796');
UPDATE `creature_template` SET `scale`='1.5', `faction_A`='16', `faction_H`='16', `ScriptName`='mob_firebomb_trigger' WHERE (`entry`='34854');

-- Acidmaw & Dreadscale
UPDATE `creature_template` SET `ScriptName`='boss_acidmaw' WHERE (`entry`='35144');
UPDATE `creature_template` SET `ScriptName`='boss_dreadscale' WHERE (`entry`='34799');

-- IceHowl
UPDATE `creature_template` SET `ScriptName`='boss_icehowl' WHERE (`entry`='34797');

UPDATE `creature_template` SET `ScriptName`='boss_fjola' WHERE (`entry`='34497');
UPDATE `creature_template` SET `ScriptName`='boss_eydis' WHERE (`entry`='34496');

UPDATE `creature_template` SET `ScriptName`='mob_power_of_twin' WHERE (`entry`='34630');
UPDATE `creature_template` SET `ScriptName`='mob_power_of_twin' WHERE (`entry`='34628');

UPDATE `creature_template` SET `ScriptName`='mob_essence_of_twin' WHERE (`entry`='34630');
UPDATE `creature_template` SET `ScriptName`='mob_essence_of_twin' WHERE (`entry`='34628');

UPDATE `creature_template` SET `ScriptName`='Boss_Raid_Anubarak' WHERE (`entry`='34564');
UPDATE `creature_template` SET `ScriptName`='Mob_NerubianTrigger' WHERE (`entry`='34862');

UPDATE `creature_template` SET `AIName`='', `ScriptName`='boss_eydis' WHERE `entry`=34496;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='boss_fjola' WHERE `entry`=34497;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_valkyr_orb' WHERE `entry` IN (34628, 34630);
UPDATE `creature_template` SET unit_flags= 33554434, faction_A =14, faction_H=14 WHERE `entry` IN (34628, 34630);


REPLACE INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES (34567,65684,0,0,0,1,0,0,0);
REPLACE INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES (34568,65686,0,0,0,1,0,0,0);

REPLACE INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES (65876,34496,1,'null 2');
REPLACE INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES (65875,34497,1,'nul');




-- Health
UPDATE `creature_template` SET `Health_mod`='73.7' WHERE `entry`=12000; -- Classe 2
UPDATE `creature_template` SET `Health_mod`='73.7' WHERE `entry`=12001; -- Classe 2
UPDATE `creature_template` SET `Health_mod`='73.7' WHERE `entry`=12002; -- Classe 2
UPDATE `creature_template` SET `Health_mod`='58.5' WHERE `entry`=12003; -- Classe 1
UPDATE `creature_template` SET `Health_mod`='58.5' WHERE `entry`=12004; -- Classe 1
UPDATE `creature_template` SET `Health_mod`='73.7' WHERE `entry`=12005; -- Classe 2
UPDATE `creature_template` SET `Health_mod`='73.7' WHERE `entry`=12006; -- Classe 2
UPDATE `creature_template` SET `Health_mod`='58.5' WHERE `entry`=12007; -- Classe 1
UPDATE `creature_template` SET `Health_mod`='58.5' WHERE `entry`=12008; -- Classe 1
UPDATE `creature_template` SET `Health_mod`='58.5' WHERE `entry`=12009; -- Classe 1
UPDATE `creature_template` SET `Health_mod`='20.5' WHERE `entry`=12010;
UPDATE `creature_template` SET `Health_mod`='76.5' WHERE `entry`=12011;


-- Riesen Ghoul


-- Black Knight
REPLACE INTO `script_texts` VALUES ('0', '-1600254', 'This farce ends here!', null, null, '', null, null, null, null, null, '16259', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600255', 'My rotting flesh was just getting in the way!', null, null, '', null, null, null, null, null, '16262', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600256', 'I have no need for bones to best you!', null, null, '', null, null, null, null, null, '16263', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600257', 'A waste of flesh.', null, null, '', null, null, null, null, null, '16260', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600258', 'Pathetic.', null, null, '', null, null, null, null, null, '16261', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600259', 'No! I must not fail... again...', null, null, '', null, null, null, null, null, '16264', '1', '0', '0', '');

-- Paladin
REPLACE INTO `script_texts` VALUES ('0', '-1600260', 'Are you up to the challenge? I will not hold back.', null, null, '', null, null, null, null, null, '16134', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600261', 'Prepare yourselves!', null, null, '', null, null, null, null, null, '16135', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600262', 'Hammer of the Righteous!', null, null, '', null, null, null, null, null, '16136', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600263', 'You... You need more practice.', null, null, '', null, null, null, null, null, '16137', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600264', 'Neigh! Neigh! And I say yet again NEIGH! Not good enough!', null, null, '', null, null, null, null, null, '16138', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600265', 'I yield! I submit. Excellent work. May I run away now?', null, null, '', null, null, null, null, null, '16139', '1', '0', '0', '');

-- Beschwörerin
REPLACE INTO `script_texts` VALUES ('0', '-1600266', 'Thank you, good herald. Your words are too kind.', null, null, '', null, null, null, null, null, '16245', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600267', 'May the Light give me strength to provide a worthy challenge.', null, null, '', null, null, null, null, null, '16246', '0', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600268', 'Well then, let us begin.', null, null, '', null, null, null, null, null, '16247', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600269', 'Take this time to consider your past deeds.', null, null, '', null, null, null, null, null, '16248', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600270', 'Take your rest.', null, null, '', null, null, null, null, null, '16250', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600271', 'Be at ease.', null, null, '', null, null, null, null, null, '16251', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600272', 'Even the darkest memory fades when confronted.', null, null, '', null, null, null, null, null, '16249', '1', '0', '0', '');
REPLACE INTO `script_texts` VALUES ('0', '-1600273', 'Excellent work!', null, null, '', null, null, null, null, null, '16251', '1', '0', '0', '');


DELETE FROM `vehicle_accessory` WHERE `entry` in (35491,33299,33418,33409,33300,33408,33301,33414,33297,33416,33298);
INSERT INTO `vehicle_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`) VALUES
(35491,35451,0,0, 'Black Knight'),
(33299,35323,0,0, 'Darkspear Raptor'),
(33418,35326,0,0, 'Silvermoon Hawkstrider'),
(33409,35314,0,0, 'Orgrimmar Wolf'),
(33300,35325,0,0, 'Thunder Bluff Kodo'),
(33408,35329,0,0, 'Ironforge Ram'),
(33301,35331,0,0, 'Gnomeregan Mechanostrider'),
(33414,35327,0,0, 'Forsaken Warhorse'),
(33297,35328,0,0, 'Stormwind Steed'),
(33416,35330,0,0, 'Exodar Elekk'),
(33298,35332,0,0, 'Darnassian Nightsaber');

UPDATE `creature_template_addon` SET `mount` = 0 WHERE `entry` in (35323,35326,35314,35325,35329,35331,35327,35328,35330,35332);

UPDATE `creature_template` SET `minlevel` = 80,`maxlevel` = 80 WHERE `entry` in (33298,33416,33297,33301,33408,35640,33299,33300,35634,33418,35638,33409,33414,33299,35635,35641);
UPDATE `creature_template` SET `faction_A` = 14,`faction_H` = 14 WHERE `entry` in (33298,33416,33297,33301,33408,35545,33299,35564,35590,35119,34928,35309,35305,33414,35307,35325,33300,35327,35326,33418,35638,35314,33409,33299,35635,35640,35641,35634,35633,35636,35768,35637,34658);
UPDATE `creature_template` SET `Health_mod` = 10,`mindmg` = 20000,`maxdmg` = 30000 WHERE `entry` in (33298,33416,33297,33301,33408,33409,33418,33300,33414,33299,33298,33416,33297,33301,33408,35640,35638,35634,35635,35641,35633,35636,35768,35637,34658);
UPDATE `creature_template` SET `speed_run` = 2,`Health_mod` = 40,`mindmg` = 10000,`maxdmg` = 20000,`spell1` =68505,`spell2` =62575,`spell3` =68282,`spell4` =66482 WHERE `entry` in (35644,36558);
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `id` in (35644,36558);
# ScriptName
UPDATE `creature_template` SET `ScriptName`='generic_vehicleAI_toc5' WHERE `entry`=33299;
# VehicleId
UPDATE `creature_template` SET `VehicleId`=486 WHERE `entry` in (33299,35491);
# faction for Vehicle
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`unit_flags`=33554432  WHERE `entry` in (35314,35326,35327,35325,35323,35331,35330,35329,35328,35332,35491);
# Texts
DELETE FROM `script_texts` WHERE `entry` <= -1999926 and `entry` >= -1999956;
REPLACE INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(0,-1999926, 'Coming out of the gate Grand Champions other faction.',16036,1,0,1, 'SAY_START' ),
(0,-1999927, 'Good work! You can get your award from Crusader\'s Coliseum chest!.  ' ,16038,1,0,1, 'Win' ),
(0,-1999928, 'You spoiled my grand entrance. Rat.' ,16256,1,0,5, 'SAY_AGGRO' ),
(0,-1999929, 'Did you honestly think an agent if the Kich King would be bested on the field of your pathetic little tournament?' ,16257,1,0,5, 'SAY_AGGRO_1' ),
(0,-1999930, 'I have come to finish my task ' ,16258,1,0,5, 'SAY_AGGRO_2' ),
(0,-1999931, 'This farce ends here!' ,16259,1,0,5, 'SAY_AGGRO_3' ),
(0,-1999932, '[Zombie]Brains.... .... ....' ,0,1,0,5, 'SAY_SLAY' ),
(0,-1999933, 'My roting flash was just getting in the way!' ,16262,1,0,5, 'SAY_DEATH_1' ),
(0,-1999934, 'I have no need for bones to best you!' ,16263,1,0,5, 'SAY_DEATH_2' ),
(0,-1999935, 'No! I must not fail...again...' ,16264,1,0,5, 'SAY_DEATH_3' ),
(0,-1999936, 'What\'s that. up near the rafters ?' ,0,1,0,5, 'detected' ),
(0,-1999937, 'Please change your weapon! Next battle will be start now!' ,0,3,0,5, 'nx' ),
(0,-1999939, 'Excellent work!' ,0,1,0,1, 'work' ),
(0,-1999940, 'Coming out of the gate Crusader\'s Coliseum Champion.' ,0,0,0,1, 'SAY_START3' ),
(0,-1999941, 'Excellent work!' ,16139,1,0,0, 'win' ),
(0,-1999942, 'The Sunreavers are proud to present their representatives in this trial by combat.' ,16036,0,0,1, 'an1' ),
(0,-1999943, 'Welcome, champions. Today, before the eyes of your leeders and peers, you will prove youselves worthy combatants.',0,0,0,1, 'an2' ),
(0,-1999944, 'Fight well, Horde! Lok\'tar Ogar!' ,16022,1,0,5, 'Thrall' ),
(0,-1999945, 'Finally, a fight worth watching.' ,16229,1,0,5, 'Garrosh' ),
(0,-1999946, 'I did not come here to watch animals tear at each other senselessly, Tirion' ,16101,1,0,5, 'King' ),
(0,-1999947, 'You will first be facing three of the Grand Champions of the Tournament! These fierce contenders have beaten out all others to reach the pinnacle of skill in the joust.' ,16129,1,0,5, 'Hightlord' ),
(0,-1999948, 'Will tought! You next challenge comes from the Crusade\'s own ranks. You will be tested against their consederable prowess.',16037,1,0,5,'Hightlord2' ),
(0,-1999949, 'You may begin!',0,0,0,5, 'text' ),
(0,-1999950, 'Well, then. Let us begin.',0,1,0,5, 'pal agro' ),
(0,-1999951, 'Take this time to consider your past deeds.' ,16248,1,0,5, 'palsum' ),
(0,-1999952, 'What is the meaning of this?' ,0,1,0,5, 'dk_hightlord' ),
(0,-1999953, 'No...I\'m still too young' ,0,1,0,5, 'die' ),
(0,-1999954, 'Excellent work!' ,16252,1,0,0, 'win' ),
(0,-1999955, 'Excellent work!' ,16252,1,0,0, 'win' ),
(0,-1999956, 'Excellent work!' ,16252,1,0,0, 'win' );


REPLACE INTO `script_texts` (npc_entry,entry,content_default,content_loc1,content_loc2,content_loc3,content_loc4,content_loc5,content_loc6,content_loc7,content_loc8,sound,type,language,emote,comment) VALUES
(0,-1999956,'Excellent work!','','','','','','','','',16252,1,0,0,'win'),
(0,-1999955,'Excellent work!','','','','','','','','',16252,1,0,0,'win'),
(0,-1999954,'Excellent work!','','','','','','','','',16252,1,0,0,'win'),
(0,-1999953,'No...Im still too young','','','','','','','','',0,1,0,5,'die'),
(0,-1999952,'What is the meaning of this?','','','','','','','','',0,1,0,5,'dk_hightlord'),
(0,-1999951,'Take this time to consider your past deeds.','','','','','','','','',16248,1,0,5,'palsum'),
(0,-1999950,'Well, then. Let us begin.','','','','','','','','',0,1,0,5,'pal agro'),
(0,-1999949,'You may begin!','','','','','','','','',0,0,0,5,'text'),
(0,-1999948,'Will tought! You next challenge comes from the Crusades own ranks. You will be tested against their consederable prowess.','','','','','','','','',16037,1,0,5,'Hightlord2'),
(0,-1999947,'You will first be facing three of the Grand Champions of the Tournament! These fierce contenders have beaten out all others to reach the pinnacle of skill in the joust.','','','','','','','','',16129,1,0,5,'Hightlord'),
(0,-1999946,'I did not come here to watch animals tear at each other senselessly, Tirion','','','','','','','','',16101,1,0,5,'King'),
(0,-1999945,'Finally, a fight worth watching.','','','','','','','','',16229,1,0,5,'Garrosh'),
(0,-1999944,'Fight well, Horde! Lok\'tar Ogar!','','','','','','','','',16022,1,0,5,'Thrall'),
(0,-1999943,'Welcome, champions. Today, before the eyes of your leeders and peers, you will prove youselves worthy combatants.','','','','','','','','',0,0,0,1,'an2'),
(0,-1999942,'The Sunreavers are proud to present their representatives in this trial by combat.','','','','','','','','',16036,0,0,1,'an1'),
(0,-1999941,'Excellent work!','','','','','','','','',16139,1,0,0,'win'),
(0,-1999940,'Coming out of the gate Crusader\'s Coliseum Champion.','','','','','','','','',0,0,0,1,'SAY_START3'),
(0,-1999939,'Excellent work!','','','','','','','','',0,1,0,1,'work'),
(0,-1999937,'Please change your weapon! Next battle will be start now!','','','','','','','','',0,3,0,5,'nx'),
(0,-1999936,'Whats that. up near the rafters ?','','','','','','','','',0,1,0,5,'detected'),
(0,-1999935,'No! I must not fail...again...','','','','','','','','',16264,1,0,5,'SAY_DEATH_3'),
(0,-1999934,'I have no need for bones to best you!','','','','','','','','',16263,1,0,5,'SAY_DEATH_2'),
(0,-1999933,'My rotting flash was just getting in the way!','','','','','','','','',16262,1,0,5,'SAY_DEATH_1'),
(0,-1999932,'[Zombie]Brains.... .... ....','','','','','','','','',0,1,0,5,'SAY_SLAY'),
(0,-1999931,'This farce ends here!','','','','','','','','',16259,1,0,5,'SAY_AGGRO_3'),
(0,-1999930,'I have come to finish my task ','','','','','','','','',16258,1,0,5,'SAY_AGGRO_2'),
(0,-1999929,'Did you honestly think an agent if the Kich King would be bested on the field of your pathetic little tournament?','','','','','','','','',16257,1,0,5,'SAY_AGGRO_1'),
(0,-1999928,'You spoiled my grand entrance. Rat.','','','','','','','','',16256,1,0,5,'SAY_AGGRO'),
(0,-1999927,'Good work! You can get your award from Crusaders Coliseum chest!.  ','','','','','','','','',16038,1,0,1,'Win'),
(0,-1999926,'Coming out of the gate Grand Champions other faction.','','','','','','','','',16036,1,0,1,'SAY_START');

 
 
-- -------------------------------------------------------- 
-- ####### rev189_World_Spell_Linked_Spell.sql 
-- -------------------------------------------------------- 
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=58875 AND `spell_effect`=58876;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(58875,58876,1, 'Spirit Walk'); 
 
-- -------------------------------------------------------- 
-- ####### rev190_World_Spell_Target_Position.sql 
-- -------------------------------------------------------- 
DELETE FROM `spell_target_position` WHERE `id` = 49305;
INSERT INTO `spell_target_position` VALUES
(49305, 578, 983.108, 1054.513, 359.967, 3.354); 
 
-- -------------------------------------------------------- 
-- ####### _MERGED.sql 
-- -------------------------------------------------------- 
 
 
