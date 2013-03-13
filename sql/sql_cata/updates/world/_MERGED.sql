-- -------------------------------------------------------- 
-- ####### 2013_02_14_00_world_version.sql 
-- -------------------------------------------------------- 
UPDATE `version` SET `db_version`='TDB 335.51', `cache_id`=51 LIMIT 1;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_15_00_world_waypoint_data.sql 
-- -------------------------------------------------------- 
SET @NPC_DRAKE  := 29709;

DELETE FROM `waypoint_data` WHERE `id`=@NPC_DRAKE;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@NPC_DRAKE,1,7294.96,-2418.733,823.869,0,0,0,0,100,0),
(@NPC_DRAKE,2,7315.984,-2331.46,826.3972,0,0,0,0,100,0),
(@NPC_DRAKE,3,7271.826,-2271.479,833.5917,0,0,0,0,100,0),
(@NPC_DRAKE,4,7186.253,-2218.475,847.5632,0,0,0,0,100,0),
(@NPC_DRAKE,5,7113.195,-2164.288,850.2301,0,0,0,0,100,0),
(@NPC_DRAKE,6,7078.018,-2063.106,854.7581,0,0,0,0,100,0),
(@NPC_DRAKE,7,7073.221,-1983.382,861.9246,0,0,0,0,100,0),
(@NPC_DRAKE,8,7061.455,-1885.899,865.119,0,0,0,0,100,0),
(@NPC_DRAKE,9,7033.32,-1826.775,876.2578,0,0,0,0,100,0),
(@NPC_DRAKE,10,6999.902,-1784.012,897.4521,0,0,0,0,100,0),
(@NPC_DRAKE,11,6954.913,-1747.043,897.4521,0,0,0,0,100,0),
(@NPC_DRAKE,12,6933.856,-1720.698,882.2022,0,0,0,0,100,0),
(@NPC_DRAKE,13,6932.729,-1687.306,866.1189,0,0,0,0,100,0),
(@NPC_DRAKE,14,6952.458,-1663.802,849.8133,0,0,0,0,100,0),
(@NPC_DRAKE,15,7002.819,-1651.681,831.397,0,0,0,0,100,0),
(@NPC_DRAKE,16,7026.531,-1649.239,828.8406,0,0,0,0,100,0);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_16_00_world_creature_template.sql 
-- -------------------------------------------------------- 
UPDATE `creature_template` SET `Armor_mod`=0 WHERE `entry`=29747;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_16_01_world_spell_target_position.sql 
-- -------------------------------------------------------- 
DELETE FROM `spell_target_position` WHERE `id` IN (64014,64024,64025,64028,64029,64030,64031,64032,65042);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(64014, 603, -705.9705, -92.55729, 430.8192, 0),
(64024, 603, 2086.224, -24.05382, 422.2889, 0),
(64025, 603, 2518.131, 2569.342, 412.6822, 0),
(64028, 603, 553.243, -12.30903, 410.5428, 0),
(64029, 603, 1859.563, -24.83773, 449.1945, 6.230825),
(64030, 603, 1497.989, -24.16162, 421.6254, 0.03490658),
(64031, 603, 926.2917, -11.44444, 418.9779, 0.01745329),
(64032, 603, 131.1389, -35.36806, 410.187, 0),
(65042, 603, 1855.073, -11.48785, 334.559, 5.532694);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_16_02_world_creature_text.sql 
-- -------------------------------------------------------- 
-- Lurgglbr
DELETE FROM `creature_text` WHERE `entry`=25208;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(25208,0,0, 'You can''t hold me against my will! You''ve all been brainwashed!', 12,0,100,0,0,0, 'Lurgglbr'),
(25208,1,0, 'Together we will fight our way out of here. Are you ready?', 12,0,100,0,0,0, 'Lurgglbr'),
(25208,2,0, 'This is far enough. I can make it on my own from here.', 12,0,100,0,0,0, 'Lurgglbr'),
(25208,3,0, 'Thank you for rescuing me, $r. Please tell the king that I am back.', 12,0,100,0,0,0, 'Lurgglbr');

 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_16_03_world_sai.sql 
-- -------------------------------------------------------- 
-- quest fix cuergo's gold (q2882)
SET @ENTRY :=7898;
UPDATE `creature_template` SET `AIName`= 'SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND`entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND`entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Trigger - on respawn - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,300000,300000,11,11463,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn pirate1'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,300000,300000,11,11463,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn pirate2'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,300000,300000,11,11485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn buccaneer1'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,300000,300000,11,11485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn buccaneer2'),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,300000,300000,11,11487,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn swashbuckler'),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - despawn trigger');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_16_04_world_creature_loot_template.sql 
-- -------------------------------------------------------- 
-- Remove Zulian Mudskunk from Zulian Crocolisk's loot template
DELETE FROM `creature_loot_template` WHERE `entry`=15043 and `item`=19975;
-- Add Vicious Oil (Item) into loot template of Vicious Oil (NPC)
DELETE FROM `creature_loot_template` WHERE `entry`=30325 and `item`=42640;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) values
(30325,42640,-100,1,0,1,1);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_16_05_world_quest_template.sql 
-- -------------------------------------------------------- 
-- Previous quest should be The Defense of Warsong Hold not To Conquest Hold, But Be Careful!
UPDATE `quest_template` SET `PrevQuestId`=11596 WHERE  `Id`=12486;
-- Change grouping so Alliance and Horde quests are no longer in 1 group
UPDATE `quest_template` SET `ExclusiveGroup`=-12222 WHERE  `Id` IN(12222,12223);
-- Hellscreams Champion requires some conditions to start the quest
UPDATE `quest_template` SET `ExclusiveGroup`=0,`NextQuestId`=0 WHERE  `Id` IN(11652,11705,11722);
UPDATE `quest_template` SET `NextQuestId`=11709 WHERE `Id`=11705;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry`=11916;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(20,0,11916,0,0,8,0,11652,0,0,0,0, '', 'Player must have completed The Plains of Nasam before been able to accept Hellscream''s Champion'),
(19,0,11916,0,0,8,0,11652,0,0,0,0, '', 'Player must have completed The Plains of Nasam before been able to accept Hellscream''s Champion'),
(20,0,11916,0,0,8,0,11705,0,0,0,0, '', 'Player must have completed The Foolish Endeavors before been able to accept Hellscream''s Champion'),
(19,0,11916,0,0,8,0,11705,0,0,0,0, '', 'Player must have completed The Foolish Endeavors before been able to accept Hellscream''s Champion'),
(20,0,11916,0,0,8,0,11722,0,0,0,0, '', 'Player must have completed The Trophies of Gammoth before been able to accept Hellscream''s Champion'),
(19,0,11916,0,0,8,0,11722,0,0,0,0, '', 'Player must have completed The Trophies of Gammoth before been able to accept Hellscream''s Champion');
-- Fix SAI issue for Hugh Glass (wrong npcflag was set)
UPDATE `smart_scripts` SET `action_param1`=643 WHERE  `entryorguid`=2648400 AND `source_type`=9 AND `id`=6;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_17_00_world_spell_script_names.sql 
-- -------------------------------------------------------- 
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_frost_breath';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_item_unsated_craving';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(69649,'spell_sindragosa_frost_breath'),
(71056,'spell_sindragosa_frost_breath'),
(71057,'spell_sindragosa_frost_breath'),
(71058,'spell_sindragosa_frost_breath'),
(73061,'spell_sindragosa_frost_breath'),
(73062,'spell_sindragosa_frost_breath'),
(73063,'spell_sindragosa_frost_breath'),
(73064,'spell_sindragosa_frost_breath'),
(71168,'spell_item_unsated_craving');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=71952;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_18_00_world_misc_equip.sql 
-- -------------------------------------------------------- 
-- creature_template.equipment_id deleted
-- creature_equip_template.entry == creature_template.entry
-- id field added to creature_equip_template -> PK(entry, id)
-- id field in creature_equip_template starts at 1
-- creature.equipment_id references id of creature_equip_template
-- creature.equipment_id = 0 means no equipment at all (default 1)
-- creature.equipment_id = -1 means pick a random equipment from creature_equip_template

-- Diff_entries should use the same template of the normal entry
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `name` LIKE '%(1)' OR `name` LIKE '%(2)' OR `name` LIKE '%(3)' OR `name` LIKE '%(4)';

-- Delete unused templates
DROP TABLE IF EXISTS `temp_c_e`;
CREATE TABLE IF NOT EXISTS `temp_c_e` (`entry` mediumint(8));
ALTER TABLE `temp_c_e` ADD INDEX `ind` (`entry`);
INSERT INTO `temp_c_e` SELECT `equipment_id` FROM `creature_template` WHERE `equipment_id` != 0 UNION
                       SELECT `equipment_id` FROM `creature` WHERE `equipment_id` != 0 UNION
                       SELECT `equipment_id` FROM `game_event_model_equip` WHERE `equipment_id` != 0;
DELETE FROM `creature_equip_template` WHERE `entry` NOT IN (SELECT `entry` FROM `temp_c_e`);
DROP TABLE `temp_c_e`;

-- Create temporary table to hold the values of creature_equip_template with converted entry
DROP TABLE IF EXISTS `creature_equip_template2`;
CREATE TABLE IF NOT EXISTS `creature_equip_template2` (
  `entry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `id` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `itemEntry1` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `itemEntry2` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `itemEntry3` mediumint(8) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`, `id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `creature_equip_template2` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`)
    SELECT `creature_template`.`entry`, 1, `itemEntry1`, `itemEntry2`, `itemEntry3`
    FROM `creature_template`
    JOIN `creature_equip_template` ON `creature_equip_template`.`entry` = `equipment_id`
    WHERE `equipment_id` != 0;

INSERT IGNORE INTO `creature_equip_template2` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`)
    SELECT `id`, 2, `itemEntry1`, `itemEntry2`, `itemEntry3`
    FROM `creature`
    JOIN `creature_equip_template` ON `creature_equip_template`.`entry` = `equipment_id`
    WHERE `equipment_id` != 0;

DROP TABLE `creature_equip_template`;
RENAME TABLE `creature_equip_template2` TO `creature_equip_template`;

UPDATE `creature` SET `equipment_id` = 2 WHERE `equipment_id` != 0;
UPDATE `creature` SET `equipment_id` = 1 WHERE `equipment_id` = 0;

-- From game_event_model_equip
UPDATE `creature` SET `equipment_id` = 1 WHERE `guid` IN (12088, 12093, 12095, 79670, 79675, 79676, 79690, 79792, 79807, 79814);
UPDATE `game_event_model_equip` SET `equipment_id` = 2 WHERE `guid` IN (12088, 12093, 12095, 79670, 79675, 79676, 79690, 79792, 79807, 79814);
DELETE FROM `creature_equip_template` WHERE `entry` IN (1976, 23585, 424) AND `id`=2;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(1976, 2, 2715, 143, 0),
(23585, 2, 2715, 143, 0),
(424, 2, 2715, 143, 0);

-- ALTER TABLE `creature_equip_template` CHANGE `entry` `entry` mediumint(8) unsigned NOT NULL;
-- ALTER TABLE `creature_equip_template` ADD `id` tinyint(3) unsigned NOT NULL DEFAULT '1' AFTER `entry`;
-- ALTER TABLE `creature_equip_template` DROP INDEX `PRIMARY`, ADD PRIMARY KEY (`entry`, `id`);
ALTER TABLE `creature_template` DROP `equipment_id`;
ALTER TABLE `creature` CHANGE `equipment_id` `equipment_id` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `game_event_model_equip` CHANGE `equipment_id` `equipment_id` tinyint(3) unsigned NOT NULL DEFAULT '1';

-- Conversion from SAI
UPDATE `smart_scripts` SET `action_param1` = 1 WHERE `entryorguid` = 2523901 AND `source_type` = 9 AND `id` = 3;
UPDATE `smart_scripts` SET `action_param1` = 0 WHERE `entryorguid` = 2523900 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_param1` = 2 WHERE `entryorguid` = 32720   AND `source_type` = 0 AND `id` = 0;
DELETE FROM `creature_equip_template` WHERE `entry` = 25239 AND `id`=1;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES 
(25239, 1, 6829, 0, 0);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_18_01_world_trinity_string.sql 
-- -------------------------------------------------------- 
DELETE FROM `trinity_string` WHERE `entry` = 5036;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES 
(5036, 'EquipmentId: %u (Original: %u).');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_18_02_world_misc.sql 
-- -------------------------------------------------------- 
-- Creature Gossip_menu_option Update from sniff
UPDATE `gossip_menu_option` SET `menu_id`=9528 WHERE `menu_id`=21250;
UPDATE `gossip_menu_option` SET `action_menu_id`=9527 WHERE `action_menu_id`=50423;
UPDATE `gossip_menu_option` SET `action_menu_id`=9521 WHERE `action_menu_id`=50424;
UPDATE `gossip_menu_option` SET `action_menu_id`=9526 WHERE `action_menu_id`=50425;
UPDATE `gossip_menu_option` SET `action_menu_id`=9525 WHERE `action_menu_id`=50426;
UPDATE `gossip_menu_option` SET `action_menu_id`=9681 WHERE `menu_id`=9680;
UPDATE `gossip_menu_option` SET `action_menu_id`=9696 WHERE `menu_id`=9695;
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9302,9303,9304,9305,9422,9461,9462,9474,9501,9532,9536,9568,9586,9594,9595,9610,9611,9612,9653,9696) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9302,0,0, 'Worry no more, taunka. The Horde will save and protect you and your people, but first you must swear allegiance to the Warchief by taking the blood oath of the Horde.',1,1,9305,0,0,0, ''),
(9303,0,0, 'For the Horde!\r\n\r\nArm yourself from the crates that surround us and report to Agmar''s Hammer, east of here. Your first trial as a member of the Horde is to survive the journey.\r\n\r\nLok''tar ogar!',1,1,0,0,0,0, ''),
(9304,0,0, 'Then repeat after me: "Lok''tar ogar! Victory or death - it is these words that bind me to the Horde. For they are the most sacred and fundamental of truths to any warrior of the Horde.\r\n\r\nI give my flesh and blood freely to the Warchief. I am the instrument of my Warchief''s desire. I am a weapon of my Warchief''s command.\r\n\r\nFrom this moment until the end of days I live and die - For the Horde!"',1,1,9303,0,0,0, ''),
(9305,0,0, 'Yes, taunka. Retribution is a given right of all members of the Horde.',1,1,9304,0,0,0, ''),
(9422,0,0, 'I seem to have misplaced your Shredder Control Device... might you have another?',1,1,0,0,0,0, ''),
(9461,0,0, 'Greetings High Chief. Would you do me the honor of accepting my invitation to join the Horde as an official member and leader of the Taunka?',1,1,9462,0,0,0, ''),
(9462,0,0, 'It is you who honor me, High Chief. Please read from this scroll. It is the oath of allegiance.',1,1,0,0,0,0, ''),
(9474,0,1, 'Let me browse your goods.',3,128,0,0,0,0, ''),
(9501,0,0, 'Agent Skully, I need you to use the banshee''s magic mirror on me again!',1,1,9538,0,0,0, ''),
(9532,0,0, 'Your eminence, may I have a word in private?',1,1,9536,0,0,0, ''),
(9536,0,0, 'I am ready, your grace. <kiss the ring>',1,1,9535,0,0,0, ''),
(9568,0,0, 'We need to get into the fight. Are you ready?',1,1,9569,0,0,0, ''),
(9586,0,0, 'Why have I been sent back to this particular place and time?',1,1,9594,0,0,0, ''),
(9594,0,0, 'What was this decision?',1,1,9595,0,0,0, ''),
(9595,0,0, 'So how does the Infinite Dragonflight plan to interfere?',1,1,9596,0,0,0, ''),
(9610,0,0, 'What do you think they''re up to?',1,1,9611,0,0,0, ''),
(9611,0,0, 'You want me to do what?',1,1,9612,0,0,0, ''),
(9612,0,0, 'Very well, Chromie.',1,1,9613,0,0,0, ''),
(9653,0,0, 'Yes, my Prince. We are ready.',1,1,0,0,0,0, ''),
(9696,0,0, 'For Lordaeron!',1,1,0,0,0,0, '');

UPDATE `gossip_menu` SET `entry`=9350 WHERE `entry`=21238;
UPDATE `gossip_menu` SET `entry`=9136 WHERE `entry`=21243;
UPDATE `gossip_menu` SET `entry`=9151 WHERE `entry`=21244;
UPDATE `gossip_menu` SET `entry`=9474 WHERE `entry`=21245;
UPDATE `gossip_menu` SET `entry`=9528 WHERE `entry`=21250;
UPDATE `gossip_menu` SET `entry`=9527 WHERE `entry`=50423;
UPDATE `gossip_menu` SET `entry`=9521 WHERE `entry`=50424;
UPDATE `gossip_menu` SET `entry`=9526 WHERE `entry`=50425;
UPDATE `gossip_menu` SET `entry`=9525 WHERE `entry`=50426;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9302 AND `text_id`=12611;
DELETE FROM `gossip_menu` WHERE `entry`=9303 AND `text_id`=12620;
DELETE FROM `gossip_menu` WHERE `entry`=9304 AND `text_id`=12619;
DELETE FROM `gossip_menu` WHERE `entry`=9305 AND `text_id`=12618;
DELETE FROM `gossip_menu` WHERE `entry`=9461 AND `text_id`=12721;
DELETE FROM `gossip_menu` WHERE `entry`=9462 AND `text_id`=12722;
DELETE FROM `gossip_menu` WHERE `entry`=9532 AND `text_id`=12846;
DELETE FROM `gossip_menu` WHERE `entry`=9535 AND `text_id`=12849;
DELETE FROM `gossip_menu` WHERE `entry`=9536 AND `text_id`=12848;
DELETE FROM `gossip_menu` WHERE `entry`=9538 AND `text_id`=12851;
DELETE FROM `gossip_menu` WHERE `entry`=9568 AND `text_id`=12899;
DELETE FROM `gossip_menu` WHERE `entry`=9569 AND `text_id`=12900;
DELETE FROM `gossip_menu` WHERE `entry`=9586 AND `text_id`=13471;
DELETE FROM `gossip_menu` WHERE `entry`=9653 AND `text_id`=13076;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9302,12611),
(9303,12620),
(9304,12619),
(9305,12618),
(9461,12721),
(9462,12722),
(9532,12846),
(9535,12849),
(9536,12848),
(9538,12851),
(9568,12899),
(9569,12900),
(9586,13471),
(9653,13076);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9136 WHERE `entry`=25197; -- King Mrgl-Mrgl <D.E.H.T.A.>
UPDATE `creature_template` SET `gossip_menu_id`=9151 WHERE `entry`=25326; -- Overlord Bor'gorok
UPDATE `creature_template` SET `gossip_menu_id`=9474 WHERE `entry`=25736; -- Supply Master Taz'ishi <Poison & Reagents>
UPDATE `creature_template` SET `gossip_menu_id`=9302, `npcflag`=`npcflag`|1, `AIName`='SmartAI' WHERE `entry`=26179; -- Taunka''le Refugee
UPDATE `creature_template` SET `gossip_menu_id`=9302, `npcflag`=`npcflag`|1, `AIName`='SmartAI' WHERE `entry`=26184; -- Taunka''le Refugee
UPDATE `creature_template` SET `gossip_menu_id`=9350 WHERE `entry`=26538; -- Nargo Screwbore <Durotar Zeppelin Master>
UPDATE `creature_template` SET `gossip_menu_id`=9461 WHERE `entry`=26810; -- Roanauk Icemist
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=27056; -- Sentinel Sweetspring <Stable Master>
UPDATE `creature_template` SET `gossip_menu_id`=9532 WHERE `entry`=27245; -- High Abbot Landgren
UPDATE `creature_template` SET `gossip_menu_id`=9528 WHERE `entry`=27425; -- Darrok
UPDATE `creature_template` SET `gossip_menu_id`=9610 WHERE `entry`=27915; -- Chromie
UPDATE `creature_template` SET `gossip_menu_id`=9656 WHERE `entry`=28126; -- Don Carlos

DELETE FROM `creature_text` WHERE `entry` IN (26179,26184);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26179,0,0,'Victory or death! For the Horde!',14,1,100,15,0,0,'Taunka''le Refugee'),
(26184,0,0,'Victory or death! For the Horde!',14,1,100,15,0,0,'Taunka''le Refugee');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9568 AND `SourceEntry`=12899;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9586 AND `SourceEntry`=13471;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9302 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9422 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9461 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9501 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9568 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9586 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9568,12899,0,0,9,0,12372,0,0,0,0,'','Wyrmrest Defender - Show different gossip if player has taken quest Defending Wyrmrest Temple'),
(14,9586,13471,0,0,2,0,37888,1,0,0,0,'','Chromie - Show different gossip if player has item Arcane Disruptor'),
(15,9302,0,0,0,9,0,11983,0,0,0,0,'','Taunka''le Refugee - Show gossip option only if player has taken quest Blood Oath of the Horde'),
(15,9422,0,0,0,9,0,12050,0,0,0,0,'','Xink - Show gossip option only if player has taken quest Lumber Hack'),
(15,9422,0,0,0,2,0,36734,1,0,1,0,'','Xink - Show gossip option only if player has no item Xink''s Shredder Control Device'),
(15,9422,0,0,1,9,0,12052,0,0,0,0,'','Xink - Show gossip option only if player has taken quest Harp on This!'),
(15,9422,0,0,1,2,0,36734,1,0,1,0,'','Xink - Show gossip option only if player has no item Xink''s Shredder Control Device'),
(15,9461,0,0,0,9,0,12140,0,0,0,0,'','Roanauk Icemist - Show gossip option only if player has taken quest All Hail Roanauk!'),
(15,9501,0,0,0,9,0,12274,0,0,0,0,'','Agent Skully - Show gossip option only if player has taken quest A Fall From Grace'),
(15,9501,0,0,0,1,0,48761,0,0,1,0,'','Agent Skully - Show gossip option only if player has no aura Scarlet Raven Priest Image'),
(15,9501,0,0,0,1,0,48763,0,0,1,0,'','Agent Skully - Show gossip option only if player has no aura Scarlet Raven Priest Image'),
(15,9568,0,0,0,9,0,12372,0,0,0,0,'','Wyrmrest Defender - Show gossip option only if player has taken quest Defending Wyrmrest Temple'),
(15,9586,0,0,0,2,0,37888,1,0,1,0,'','Chromie - Show gossip option only if player has no item Arcane Disruptor');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (26660,27350);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26179,26184,26660,27350) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26179*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26179,0,0,1,62,0,100,0,9303,0,0,0,11,47029,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Spellcast Taunka Sworn In'),
(26179,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Close gossip'),
(26179,0,2,3,61,0,100,0,0,0,0,0,33,26179,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Quest credit'),
(26179,0,3,4,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Remove npcflag gossip'),
(26179,0,4,5,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188252,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26179,0,5,6,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188253,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26179,0,6,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188254,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26179,0,7,0,34,0,100,0,0,1,0,0,80,26179*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On movement inform - Run script'),
(26179,0,8,9,34,0,100,0,0,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On movement inform - Despawn'),
(26179,0,9,0,61,0,100,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Add npcflag gossip'),
(26184,0,0,1,62,0,100,0,9303,0,0,0,11,47029,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Spellcast Taunka Sworn In'),
(26184,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Close gossip'),
(26184,0,2,3,61,0,100,0,0,0,0,0,33,26179,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Quest credit'),
(26184,0,3,4,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Remove npcflag gossip'),
(26184,0,4,5,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188252,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26184,0,5,6,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188253,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26184,0,6,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188254,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26184,0,7,0,34,0,100,0,0,1,0,0,80,26179*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On movement inform - Run script'),
(26184,0,8,9,34,0,100,0,0,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On movement inform - Despawn'),
(26184,0,9,0,61,0,100,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Add npcflag gossip'),
(26660,0,0,1,62,0,100,0,9422,0,0,0,11,52872,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Xink - On gossip option select - Spellcast Forceitem Xink''s Shredder'),
(26660,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Xink - On gossip option select - Close gossip'),
(27350,0,0,0,62,0,100,0,9501,0,0,0,11,48762,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Agent Skully - On gossip option select - Spellcast A Fall from Grace: Scarlet Raven Priest Image - Master'),

(26179*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,20,188252,20,0,0,0,0,0, 'Taunka''le Refugee script - Turn to Recovered Horde Armaments'),
(26179*100,9,1,0,0,0,100,0,1100,1100,0,0,5,381,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Play emote'),
(26179*100,9,2,0,0,0,100,0,2500,2500,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Cancel emote'),
(26179*100,9,3,0,0,0,100,0,0,0,0,0,11,47024,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Spellcast Taunka Transform'),
(26179*100,9,4,0,0,0,100,0,2200,2200,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Say line'),
(26179*100,9,5,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Set run'),
(26179*100,9,6,0,0,0,100,0,4700,4700,0,0,69,2,0,0,0,0,0,8,0,0,0,3680.874,2875.829,91.52616,0, 'Taunka''le Refugee script - Move to position');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_18_03_world_spell_area.sql 
-- -------------------------------------------------------- 
DELETE FROM `spell_area` WHERE `spell`=68132 AND `area`=4741;
INSERT INTO `spell_area` (`spell`, `area`, `autocast`) VALUES
(68132, 4741, 1);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_19_00_world_creature_template.sql 
-- -------------------------------------------------------- 
-- Issue 8590: Damage Boss ICC
-- Lord Marrowgar
UPDATE `creature_template` SET `dmg_multiplier`=55 WHERE `entry`=36612;
UPDATE `creature_template` SET `dmg_multiplier`=85 WHERE `entry`=37957;
UPDATE `creature_template` SET `dmg_multiplier`=75 WHERE `entry`=37958;
UPDATE `creature_template` SET `dmg_multiplier`=110 WHERE `entry`=37959;
-- Lady Deathwhisper
UPDATE `creature_template` SET `dmg_multiplier`=70 WHERE `entry`=36855;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=38106;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38296;
UPDATE `creature_template` SET `dmg_multiplier`=140 WHERE `entry`=38297;
-- Deathbringer Saurfang
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=37813;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38402;
UPDATE `creature_template` SET `dmg_multiplier`=85 WHERE `entry`=38582;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38583;
-- Festergut
UPDATE `creature_template` SET `dmg_multiplier`=75 WHERE `entry`=36626;
UPDATE `creature_template` SET `dmg_multiplier`=115 WHERE `entry`=37504;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=37505;
UPDATE `creature_template` SET `dmg_multiplier`=150 WHERE `entry`=37506;
-- Rotface
UPDATE `creature_template` SET `dmg_multiplier`=70 WHERE `entry`=36627;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=38390;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38549;
UPDATE `creature_template` SET `dmg_multiplier`=140 WHERE `entry`=38550;
-- Professor Putricide
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=36678;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38431;
UPDATE `creature_template` SET `dmg_multiplier`=80 WHERE `entry`=38585;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38586;
-- Blood Prince Council except Keleseth who is a caster
UPDATE `creature_template` SET `dmg_multiplier`=65 WHERE `entry` IN (37970,37973);
UPDATE `creature_template` SET `dmg_multiplier`=95 WHERE `entry` IN (38401,38400);
UPDATE `creature_template` SET `dmg_multiplier`=85 WHERE `entry` IN (38784,38771);
UPDATE `creature_template` SET `dmg_multiplier`=130 WHERE `entry` IN (38785,38772);
-- Blood Queen Lana'thel
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=37955;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38434;
UPDATE `creature_template` SET `dmg_multiplier`=80 WHERE `entry`=38435;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38436;
-- Sindragosa (and damage for Sindragosa 10 who hits only 1)
UPDATE `creature_template` SET `dmg_multiplier`=60, mindmg=509, maxdmg=683, attackpower=805 WHERE `entry`=36853;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38265;
UPDATE `creature_template` SET `dmg_multiplier`=80 WHERE `entry`=38266;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38267;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_19_01_world_creature_template.sql 
-- -------------------------------------------------------- 
-- Flags 128+2: creature is trigger-NPC (invisible to players only) + creature does not aggro (ignore faction/reputation hostility)
UPDATE `creature_template` SET `flags_extra` = (`flags_extra`|2|128) WHERE `entry` IN (32195,32196,32197,32199);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_19_02_world_conditions.sql 
-- -------------------------------------------------------- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=12944 AND `SourceEntry` IN (20761,17051,17022,17018,17023,19444);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=12944 AND `SourceEntry` IN (19219,17017,17025,19330,19448,17059,17060,17049,19206);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=12944 AND `SourceEntry` IN (19220,19332,19333,19331,19449,19209,19208,19207,17053,17052);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=12944 AND `SourceEntry` IN (19211,19210,19212,20040);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
-- Conditon rep Friendly
(23,12944,20761,0,0,5,0,59,16,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,17051,0,0,5,0,59,16,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,17022,0,0,5,0,59,16,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,17018,0,0,5,0,59,16,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,17023,0,0,5,0,59,16,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,19444,0,0,5,0,59,16,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
-- Conditon rep Honored
(23,12944,19219,0,0,5,0,59,32,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17017,0,0,5,0,59,32,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17025,0,0,5,0,59,32,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,19330,0,0,5,0,59,32,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,19448,0,0,5,0,59,32,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17059,0,0,5,0,59,32,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17060,0,0,5,0,59,32,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17049,0,0,5,0,59,32,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,19206,0,0,5,0,59,32,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
-- Conditon rep Revered
(23,12944,19220,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19332,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19333,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19331,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19449,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19209,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19208,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19207,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,17053,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,17052,0,0,5,0,59,64,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
-- Conditon rep Exalted 
(23,12944,19211,0,0,5,0,59,128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Exalted with Thorium Brotherhood'),
(23,12944,19210,0,0,5,0,59,128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Exalted with Thorium Brotherhood'),
(23,12944,19212,0,0,5,0,59,128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Exalted with Thorium Brotherhood'),
(23,12944,20040,0,0,5,0,59,128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Exalted with Thorium Brotherhood');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_19_03_world_sai.sql 
-- -------------------------------------------------------- 
-- Fix quest: Gather the Orbs http://www.wowhead.com/quest=10859
-- ID indexes
-- Almost all is based on Untaught script, just corrected some stuff with sniff
SET @OrbCollectingTotem := 22333;
SET @LightOrb           := 20635;
SET @Script :=   @LightOrb * 100;
SET @BanishedState :=      32566;
SET @ArcaneExplosion :=    35426; -- such spells need delay to execute properly, that is why I made actionlist
-- Update templates
UPDATE `creature_template` SET `unit_flags`=unit_flags|0x02000000 WHERE `entry`=@LightOrb; -- sniff
-- Add SAI support for Light Orbs and Totem
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@LightOrb;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@LightOrb,@OrbCollectingTotem);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@LightOrb,@OrbCollectingTotem) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Script AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OrbCollectingTotem,0,0,1,54,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@LightOrb,20,0,0,0,0,0, 'Orb collecting totem - On spawned - Set Data 0 1'),
(@OrbCollectingTotem,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Orb collecting totem - Linked with previous event - Store invoker'),
(@OrbCollectingTotem,0,2,0,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@LightOrb,20,0,0,0,0,0, 'Orb collecting totem - Linked with previous event - Send stored target list 1'),
(@LightOrb,0,0,0,25,0,100,1,0,0,0,0,11,@BanishedState,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spawn/reset - Cast Purple Banish State'),
(@LightOrb,0,1,0,38,0,100,0,0,1,30000,30000,69,1,0,0,0,0,0,19,@OrbCollectingTotem,20,0,0,0,0,0, 'Light Orb - On Data Set 0 1 - Move to totem'),
(@LightOrb,0,2,3,34,0,100,1,8,1,0,0,11,@ArcaneExplosion,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - On point 1 reached - Cast arcane explosion'),
(@LightOrb,0,3,4,61,0,100,0,0,0,0,0,33,21929,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Light Orb - Linkedw with previous event - Call kill credit'),
(@LightOrb,0,4,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Linkedw with previous event - Start action list to display arcase explosion'),
(@Script,9,0,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Action 0 - Set unseen'),
(@Script,9,1,0,0,0,100,0,0,0,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Action 1 - Despawn in 100 ms');
-- Remove deprecated required spell cast that was blocking the credit, on top of that it had some nosense spell that has nothing to do with quest?!
UPDATE `quest_template` SET `requiredspellcast1`=0 WHERE `id`=10859;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_19_04_world_misc_equip.sql 
-- -------------------------------------------------------- 
ALTER TABLE `creature` CHANGE `equipment_id` `equipment_id` tinyint(3) signed NOT NULL DEFAULT '0';
ALTER TABLE `creature_equip_template` CHANGE `id` `id` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `game_event_model_equip` CHANGE `equipment_id` `equipment_id` tinyint(3) unsigned NOT NULL DEFAULT '0';

UPDATE `creature` SET `equipment_id`=0 WHERE `id` NOT IN (SELECT `entry` FROM `creature_equip_template`);

-- content
DELETE FROM `creature_equip_template` WHERE `entry` IN (25317, 2110, 26797, 25239) AND `id`=1;
DELETE FROM `creature_equip_template` WHERE `entry` IN (32720) AND `id`=2;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(25317, 1, 2178, 143, 0),
(2110, 1, 24324, 24324, 24319),
(26797, 1, 19970, 0, 0),
(25239, 1, 6829, 0, 0),
(32720, 2, 31308, 0, 0);

UPDATE `creature` SET `equipment_id`=0 WHERE `guid` IN (200908,200918,200968,200971,200980,200998,201004,201035,201050,201052,201068,201094,201103,201112,201113,201135,201149,201150,201192,201203,201206,201363,201438,201449,201486,201685,201710,201722,201740,201752,201756,201773,201782,201788,201814,201864,201908,201916,202023,202043,202146,202164,39317,39318,39319,39320,39321,39322,39323,39324,39325,39326,39327,39328,39329,39330,39331,39332,39333,40170,40171,40227,40563,40564,41319,41322,41323,41324,41325,41326,41327,41328,41669,41726,42616,42641,42668,42669,42680,42686,44193,44194,46975,47413,47414,47415,47416,47417,47418,47419,47420,47421,47422,47423,47424,47425,47426,47427,47428,47429,47430,47431,47445,47632,48383,49987,51458,51751,51982,51983,52926,52927,52928,52929,53166,53651,53844,53845,53846,53847,53848,53849,53850,53851,53951,57315,68749,68750,68751,68752,68753,76521,79676,79725,79758,79759,79760,79761,79762,79763,79764,117784,117785,117788,117789,117790,117796,117797,117798,117799,117800,117801,117802,112352,112353,112354,112355,112356,112357,112358,112359,112360,112361,112362,112363,112364,112365,112366,112367,112368,112371,112372);

-- 25317
UPDATE `creature` SET `equipment_id`=1 WHERE `guid` IN (117794);

-- 2110
UPDATE `creature` SET `equipment_id`=1 WHERE `guid` IN (102345,102347,102348,125999,126000,126001,126002,126003,126004,126005,126006,126007,126008,126009,126010,126011,126012,126013,126014,126015,126016,126095,126096,126097,126098,126099,126100,126101,126724,126725,126726,126727,126729,126730,126731,127489,127490,127491,127492,131859,131860,131861,131862,131863,13354,13355,13356,13357,16230,16231,16232,16233,16234,16235,16236,18316,18392,28779,28781,28782,31778,31779,31965,31973,32010,32011,4212,4214,4215,4227,42676,42683,42708,42714,42726,4274,42793,4286,4310,4313,4352,4358,4408,45397,45398,45399,45403,46795,46796,46799,46810,46860,46861,47175,47182,47184,47980,47981,47988,48220,48263,48265,48909,4939,5031,5191,52670,53043,53116,53119,53181,6007,6049,6050,6051,6056,6057,6058,6076,86393,86394,87158,87161,87163,87164,87165,87168,87225,87234,87236,87252);

-- 26797
UPDATE `creature` SET `equipment_id`=1 WHERE `guid` IN (112351, 112369, 112370);

UPDATE `smart_scripts` SET `action_param1` = 1 WHERE `entryorguid` = 2523900 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_param1` = 0 WHERE `entryorguid` = 2523901 AND `source_type` = 9 AND `id` = 3;
UPDATE `smart_scripts` SET `action_param1` = 2 WHERE `entryorguid` = 32720   AND `source_type` = 0 AND `id` = 0;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_23_00_world_gameobject.sql 
-- -------------------------------------------------------- 
DELETE FROM `gameobject` WHERE `guid`=61090;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_23_01_world_areatrigger_teleport.sql 
-- -------------------------------------------------------- 
DELETE FROM `areatrigger_teleport` WHERE `id`=5148;
INSERT INTO `areatrigger_teleport` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `name`) VALUES
(5148, 1, -8756.6, -4457.02, -200.481, 1.39626, 'CoT Stratholme - Exit Target');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_24_00_world_creature_summon_groups.sql 
-- -------------------------------------------------------- 
DROP TABLE IF EXISTS `creature_summon_groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_summon_groups` (
  `summonerId` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `summonerType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `groupId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `entry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `position_x` float NOT NULL DEFAULT '0',
  `position_y` float NOT NULL DEFAULT '0',
  `position_z` float NOT NULL DEFAULT '0',
  `orientation` float NOT NULL DEFAULT '0',
  `summonType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `summonTime` int(10) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_24_01_world_areatrigger_scripts.sql 
-- -------------------------------------------------------- 
DELETE FROM `areatrigger_scripts` WHERE `entry`=5173;
INSERT INTO `areatrigger_scripts`(`entry`,`ScriptName`) VALUE
(5173,'at_frostgrips_hollow');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_24_02_world_smart_scripts.sql 
-- -------------------------------------------------------- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=29861 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`event_type`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(29861,0,54,80,2986100,2,1,'Stormforged Eradictor - Just summoned - Call timed actionlist 2986100');

DELETE FROM `smart_scripts` WHERE `entryorguid`=2986100 AND `source_type`=9;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`target_type`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUE
(2986100,9,0,10000,10000,12,29729,4,10000,8,6972.13,14.24,805.79,3.349,'Stormforged Eradictor - Timed actionlist - Summon Frostborn Axemaster');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_24_03_world_waypoint_data.sql 
-- -------------------------------------------------------- 
DELETE FROM `waypoint_data` WHERE `id`=2986200;
INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(2986200,0,6963.95,45.65,818.71),
(2986200,1,6965.09,39.67,820.15),
(2986200,2,6963.56,21.14,805.79);

DELETE FROM `waypoint_data` WHERE `id`=2986100;
INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(2986100,0,6983.18,7.150,806.33),
(2986100,1,6975.37,16.73,804.98),
(2986100,2,6967.15,13.27,806.56);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_24_04_world_creature_template.sql 
-- -------------------------------------------------------- 
UPDATE `creature_template` SET `faction_A`=1954,`faction_H`=1954,`AIName`='SmartAI' WHERE `entry`=29861;
UPDATE `creature_template` SET `faction_A`=1954,`faction_H`=1954 WHERE `entry`=29862;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_24_05_world_command.sql 
-- -------------------------------------------------------- 
DELETE FROM `command` WHERE `name` = 'reload creature_summon_groups';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('reload creature_summon_groups',3,'Syntax: .reload creature_summon_groups
Reload creature_summon_groups table.');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_25_00_world_smart_scripts.sql 
-- -------------------------------------------------------- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=29861 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(29861,0,0,54,0,0,0,0,80,2986100,2,1,'Stormforged Eradictor - Just summoned - Call timed actionlist 2986100'),
(29861,0,1,0,3000,7000,14000,18000,11,56352,0,2,'Stormforged Eradictor - Cast Storm Punch'),
(29861,0,2,0,9000,12000,13000,18000,11,15588,0,0,'Stormforged Eradictor - Cast Thunderclap');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_25_01_world_creature_ai_scripts.sql 
-- -------------------------------------------------------- 
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=29861;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_25_02_world_areatrigger_teleport.sql 
-- -------------------------------------------------------- 
UPDATE `areatrigger_teleport` SET `target_position_x`=728.055,`target_position_y`= 1329.03,`target_position_z`=275,`target_orientation`=5.51524 WHERE `id`=5290; -- The Eye of Eternity (entrance)
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_27_00_world_command.sql 
-- -------------------------------------------------------- 
DELETE FROM `command` WHERE `name` = 'reload rbac';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('reload rbac',3,'Syntax: .reload rbac\nReload rbac system.');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_27_00_world_creature_summon_groups_434.sql 
-- -------------------------------------------------------- 
DELETE FROM `creature_summon_groups` WHERE `summonerId`=52151 AND `groupId`=0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(52151, 0, 0, 52156, -12330.3, -1878.41, 127.32, 3.89208, 8, 0),
(52151, 0, 0, 52156, -12351.94, -1861.51,  127.4807, 4.677482, 8, 0),
(52151, 0, 0, 52156, -12326.71, -1904.328, 127.4111, 2.75762, 8, 0),
(52151, 0, 0, 52156, -12347.41, -1917.535, 127.3196, 1.553343, 8, 0),
(52151, 0, 0, 52156, -12378.57, -1861.222, 127.5416, 5.340707, 8, 0),
(52151, 0, 0, 52156, -12397.79, -1887.731, 127.5453, 0.03490658, 8, 0),
(52151, 0, 0, 52156, -12372.36, -1918.844, 127.343,  1.151917, 8, 0),
(52151, 0, 0, 52156, -12391.23, -1905.273, 127.3196, 0.6108652, 8, 0);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_28_00_world_eye_of_eternity.sql 
-- -------------------------------------------------------- 
-- Add spell script names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (56046,56047,61693,61694,57459,56438,61210,56397,58842,59084,59099,56070,56072,60936,60939,61028,61023);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(56046, 'spell_malygos_portal_beam'),
(56047, 'spell_malygos_random_portal'),
(61693, 'spell_malygos_arcane_storm'), -- Phase I /10/
(61694, 'spell_malygos_arcane_storm'), -- Phase I /25/
(57459, 'spell_malygos_arcane_storm'), -- Phase III
(56438, 'spell_arcane_overload'),
(61210, 'spell_nexus_lord_align_disk_aggro'),
(56397, 'spell_scion_of_eternity_arcane_barrage'),
(58842, 'spell_malygos_destroy_platform_channel'),
(59084, 'spell_alexstrasza_bunny_destroy_platform_boom_visual'),
(59099, 'spell_alexstrasza_bunny_destroy_platform_event'),
(56070, 'spell_wyrmrest_skytalon_summon_red_dragon_buddy'),
(56072, 'spell_wyrmrest_skytalon_ride_red_dragon_buddy_trigger'),
(60936, 'spell_malygos_surge_of_power_25'),
(60939, 'spell_malygos_surge_of_power_warning_selector_25'),
(61028, 'spell_alexstrasza_gift_beam'),
(61023, 'spell_alexstrasza_gift_beam_visual');

-- Add spell difficulties
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (61693,56272,57058);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`) VALUES
(61693,61693,61694,0,0), -- Arcane Storm - Phase I
(56272,56272,60072,0,0), -- Arcane Breath
(57058,57058,60073,0,0); -- Arcane Shock (Nexus Lord)

-- Insert missing creature template addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (28859,30234,30248,32295,30592,31748,31749);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28859,0,0,0x1000000|0x2000000,0x1,0, ''), -- Malygos
(30234,0,0,0x1000000|0x2000000,0x1,0, '43775'), -- Hover Disk (Nexus Lord), add aura "Flight"
(30248,0,0,0x1000000|0x2000000,0x1,0, '43775'), -- Hover Disk (Scion of Eternity), add aura "Flight"
(31748,0,0,0x1000000|0x2000000,0x1,0, '43775'), -- Hover Disk Difficulty (Nexus Lord), add aura "Flight"
(31749,0,0,0x1000000|0x2000000,0x1,0, '43775'), -- Hover Disk Difficulty (Scion of Eternity), add aura "Flight"
(32295,0,0,0x1000000|0x2000000,0x1,0, ''), -- Alexstrasza
(30592,0,0,0x1000000|0x2000000,0x1,0, '57428'); -- Static Field bunny

-- Add, restructure and update missing texts and sounds
DELETE FROM `creature_text` WHERE `entry` IN (28859,32295);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28859,0,0, 'Lesser beings, intruding here! A shame that your excess courage does not compensate for your stupidity!',14,0,100,0,10000,14512,'Malygos - Intro'),
(28859,0,1, 'None but the blue dragonflight are welcome here. Perhaps this is the work of Alexstrasza? Well, then, she has sent you to your deaths!',14,0,100,0,11000,14513,'Malygos - Intro'),
(28859,0,2, 'What could you hope to accomplish? To storm brazenly into my domain... to employ magic... against ME?',14,0,100,0,13000,14514,'Malygos - Intro'),
(28859,0,3, 'I am without limits here. The rules of your cherished reality do not apply. In this realm, I am in control!',14,0,100,0,10000,14515,'Malygos - Intro'),
(28859,0,4, 'I give you one chance. Pledge fealty to me, and perhaps I will not slaughter you for your insolence.',14,0,100,0,7000,14516,'Malygos - Intro'),
(28859,1,0, 'My patience has reached its limit, I will be rid of you!',14,0,100,0,4000,14517,'Malygos - Start phase 1'),
(28859,2,0, 'You will not succeed while I draw breath!',14,0,100,0,3000,14518,'Malygos - Begin to cast Deep Breath'),
(28859,3,0, 'Your stupidity has finally caught up to you!',14,0,100,0,3250,14519,'Malygos - Killed Player (Phase 1)'),
(28859,3,1, 'More artifacts to confiscate...',14,0,100,0,2800,14520,'Malygos - Killed Player (Phase 1)'),
(28859,3,2, 'How very naive.',14,0,100,0,4800,14521,'Malygos - Killed Player (Phase 1)'),
(28859,4,0, 'I had hoped to end your lives quickly, but you have proven more... resilient than I anticipated. Nonetheless, your efforts are in vain. It is you reckless, careless mortals who are to blame for this war. I do what I must, and if it means your extinction.... then SO BE IT!!',14,0,100,0,22900,14522,'Malygos - End Phase One'),
(28859,5,0, 'Few have experienced the pain I will now inflict upon you!',14,0,100,0,5500,14523,'Malygos - Start phase 2'), -- Unused by Blizzard for some reason
(28859,6,0, 'I will teach you IGNORANT children just how little you know of magic...',14,0,100,0,7000,14524,'Malygos - Anti-Magic Shell'),
(28859,7,0, 'Watch helplessly as your hopes are swept away...',14,0,100,0,4000,14525,'Malygos - Magic Blast'),
(28859,8,0, 'Your energy will be put to good use!',14,0,100,0,2000,14526,'Malygos - Killed Player (Phase 2)'),
(28859,8,1, 'I am the spell-weaver! My power is infinite!',14,0,100,0,5200,14527,'Malygos - Killed Player (Phase 2)'),
(28859,8,2, 'Your spirit will linger here forever!',14,0,100,0,3800,14528,'Malygos - Killed Player (Phase 2)'),
(28859,9,0, 'ENOUGH! If you intend to reclaim Azeroth''s magic, then you shall have it...',14,0,100,0,7000,14529,'Malygos - End Phase 2'),
(28859,10,0, 'Now your benefactors make their appearance... But they are too late. The powers contained here are sufficient to destroy the world ten times over! What do you think they will do to you?',14,0,100,0,13000,14530,'Intro Phase 3'),
(28859,11,0, 'SUBMIT!',14,0,100,0,1000,14531,'Malygos - Start phase 3'), -- Unused by Blizzard for some reason
(28859,12,0, 'Malygos takes a deep breath.',41,0,100,0,10000,0,'Malygos - Surge of Power warning (Phase 2)'),
(28859,13,0, 'The powers at work here exceed anything you could possibly imagine!',14,0,100,0,5000,14532,'Malygos - Surge of Power'),
(28859,14,0, 'I AM UNSTOPPABLE!',14,0,100,0,2000,14533,'Malygos - Buffed by a spark'),
(28859,15,0, 'Alexstrasza! Another of your brood falls!',14,0,100,0,3600,14534,'Malygos - Killed Player (Phase 3)'),
(28859,15,1, 'Little more then gnats!',14,0,100,0,2650,14535,'Malygos - Killed Player (Phase 3)'),
(28859,15,2, 'Your red allies will share your fate...',14,0,100,0,3000,14536,'Malygos - Killed Player (Phase 3)'),
(28859,16,0, 'Still standing? Not for long...',14,0,100,0,3600,14537,'Malygos - Spell Casting 1(Phase 3)'),
(28859,16,1, 'Your cause is lost!',14,0,100,0,2000,14538,'Malygos - Spell Casting 2 (Phase 3)'),
(28859,16,2, 'Your fragile mind will be shattered!',14,0,100,0,4000,14539,'Malygos - Spell Casting 3 (Phase 3)'),
(28859,17,0, 'Unthinkable! The mortals will destroy... everything! My sister, what have you...',14,0,100,0,8500,14540,'Malygos - Death'),
(28859,18,0, '%s fixes his eyes on you!',42,0,100,0,3000,0,'Malygos - Surge of Power warning (Phase 3)'),
(28859,19,0, '%s goes into a berserker rage!',41,0,100,0,10000,0,'Malygos - Hit berserk timer (Any phase)'),
(32295,0,0, 'I did what I had to, brother. You gave me no alternative.',14,0,100,0,4000,14406,'Alexstrasza - Yell text 1'),
(32295,1,0, 'And so ends the Nexus War.',14,0,100,0,4000,14407,'Alexstrasza - Yell text 2'),
(32295,2,0, 'This resolution pains me deeply, but the destruction, the monumental loss of life had to end. Regardless of Malygos''s recent transgressions, I will mourn his loss. He was once a guardian, a protector. This day, one of the world''s mightiest has fallen.',14,0,100,0,24000,14408,'Alexstrasza - Yell text 3'),
(32295,3,0, 'The red dragonflight will take on the burden of mending the devastation wrought on Azeroth. Return home to your people and rest. Tomorrow will bring you new challenges, and you must be ready to face them. Life... goes on.',14,0,100,0,22000,14409,'Alexstrasza - Yell text 4');
-- Update wrong sound and add duration for Power Sparks warning
UPDATE `creature_text` SET `duration`=10000,`sound`=0 WHERE `entry`=30084 AND `groupid`=0 AND`id`=0;

-- Add conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (56047,58846,61028,56429,56505,59099,61714,61715,57432,57429,61210,56548,56431,56438);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,56047,0,0,31,0,3,30118,0,0,0,0,'', 'Random Portal can implicitly hit only Portal (Malygos)'),
(13,1,56047,0,0,29,0,28859,30,0,1,0,0,'', 'Random Portal can implicitly hit only target that is not in 30 yards near Malygos'),
(13,1,58846,0,0,32,0,0x0010,0,0,0,0,0,'', 'Summon Red Dragon Buddy force cast can implicitly hit only players'),
(13,1,61028,0,0,31,0,3,32448,0,0,0,0,'', 'Alexstrasza''s Gift Beam can hit only Alexstrasza''s Gift'),
(13,1,56429,0,0,31,0,3,31253,0,0,0,0,'', 'Summon Arcane Bomb can hit only Alexstrasza the Life-Binder (bunny)'),
(13,1,56505,0,0,31,0,3,30334,0,0,0,0,'', 'Surge of Power (phase II) can hit only Surge of Power'),
(13,1,56548,0,0,31,0,3,30234,0,1,0,0,'', 'Surge of Power triggered damage spell (phase II) can''t hit melee Hover Disk'),
(13,3,56431,0,0,31,0,3,30234,0,1,0,0,'', 'Arcane Overload damage and knockback spell can''t hit melee Hover Disk'),
(13,1,56438,0,0,1,0,1,56438,0,1,0,0,'', 'Arcane Overload damage reduce aura can''t apply to target that already is affected by such'),
(13,6,59099,0,0,32,0,0x0010,0,0,0,0,0,'', 'Destroy Platform Event effect 1 and 2 can hit only players'),
(13,7,61714,0,0,31,0,3,30245,0,0,0,0,'', 'Berserk (spell 2) can hit Nexus Lord'),
(13,7,61714,0,1,31,0,3,30249,0,0,0,0,'', 'Berserk (spell 2) can hit Scion of Eternity'),
(13,7,61715,0,0,31,0,3,30592,0,0,0,0,'', 'Berserk (spell 3) can hit Static Field bunny'),
(13,1,57432,0,0,31,0,3,30161,0,0,0,0,'', 'Arcane Pulse can hit only drakes'),
(13,3,57429,0,0,31,0,3,30161,0,0,0,0,'', 'Static Field can hit only drakes'),
(13,1,61210,0,0,33,1,0,4,0,0,0,0,'', 'Align Disk Aggro can only hit the vehicle of the passenger caster');

-- Add missing equipment
DELETE FROM `creature_equip_template` WHERE `entry` IN (30245,31750,30249,31751);
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(30245,1,30714,0,0), -- Nexus Lord
(31750,1,30714,0,0), -- Nexus Lord (Difficulty)
(30249,1,29107,0,0), -- Scion of Eternity
(31751,1,29107,0,0); -- Scion of Eternity (Difficulty)

-- Update accessories of hover disks to die with the vehicle and have lower despawn time. They should fall from hover disks,
-- and despawn after 5 sec, but for some reason they keep staying standing while dead. This needs to be fixed coreside.
UPDATE `vehicle_template_accessory` SET `minion`=1,`summontype`=6,`summontimer`=1000 WHERE `entry`=30234 AND `seat_id`=0;
UPDATE `vehicle_template_accessory` SET `minion`=1,`summontype`=6,`summontimer`=1000 WHERE `entry`=30248 AND `seat_id`=0;

-- Add flag GO not selectable for both and extra condition for Heart of Magic
UPDATE `gameobject_template` SET `flags`=16 WHERE `entry`=193967; -- Alexstrasza Gift
UPDATE `gameobject_template` SET `flags`=20 WHERE `entry`=194159; -- Heart of Magic

-- Add some gameobject data update
UPDATE `gameobject` SET `animprogress`=255,`spawntimesecs`=300 WHERE `guid` IN (151791,193960); -- that spawn time has no influence, but having different values doesn't look correct

-- Delete static GO spawns of Alexstrasza's Gift Boxes, they are dynamic (10/25)
DELETE FROM `gameobject` WHERE `guid` IN (151792,151793);

-- Add map difficulty checks for achievement "Denyin the Scion"
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7573,7574) AND `type`=12;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`) VALUES
(7573,12,0), -- 10 mode
(7574,12,1); -- 25 mode

-- Delete Nexus Lords SAI script, because of incapacity to handle the combat spell mechanic of Arcane Shock correctly
-- Delete Scions of Eternity SAI script, because of incapacity to handle non reactive AI when being attacked in a way it won't bug other encounter mechanics.
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30245,30249) AND `source_type`=0;

-- Add SAI support for Alexstrasza since is only short timed event after boss mechanic ends
SET @NPC_ALEXSTRASZA  := 32295;
SET @ACTIONLIST       := @NPC_ALEXSTRASZA * 100;
SET @SPELL_GIFT_BEAM  := 61028;

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@NPC_ALEXSTRASZA;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_ALEXSTRASZA AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ACTIONLIST AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_ALEXSTRASZA,0,0,0,54,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,788.07,1276.09,246.9,0,'Alexstrasza - On just summoned - Move to pos'),
(@NPC_ALEXSTRASZA,0,1,0,34,0,100,0,8,1,0,0,80,@ACTIONLIST,2,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza - On point 1 reached - Start actionlist'),
(@ACTIONLIST,9,0,0,0,0,100,0,0,0,0,0,11,@SPELL_GIFT_BEAM,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza - Action 0 - Cast Gift Beam'),
(@ACTIONLIST,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza - Action 1 - Yell 0'),
(@ACTIONLIST,9,2,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza - Action 2 - Yell 1'),
(@ACTIONLIST,9,3,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza - Action 3 - Yell 2'),
(@ACTIONLIST,9,4,0,0,0,100,0,24000,24000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza - Action 4 - Yell 3');

-- Add areatrigger script for the improvised platform that is killing/rooting falling players
DELETE FROM `areatrigger_scripts` WHERE `entry`=5342;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5342, 'at_eye_of_eternity_improvised_floor');

-- /////////////// Various misc in creature, creature template and creature addon ///////////////
-- Update some guids spawn positions
UPDATE `creature` SET `position_x`=754.362,`position_y`=1301.61,`position_z`=266.171,`orientation`=4.24115 WHERE `guid`=132302; -- Alexstrasza the Life-Binder (Bunny)
UPDATE `creature` SET `position_x`=747.61,`position_y`=1393.43,`position_z`=295.9722,`orientation`=3.03832 WHERE `guid`=132313; -- Malygos

-- Update some creature guids to be have static MovementType and spawn dist to 0 accordingly
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN
(132313, -- Malygos
132314, -- Alexstrasza''s Gift Bunny
132302); -- Alexstrasza the Life-Binder (Bunny)

-- Update template to InhabitType "Air" for various creatures
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (28859,31734,30245,31750,30249,31751,32295,32448);

-- Clear scripts names for Alexstrasza the Life-Binder (Bunny)
UPDATE `creature_template` SET `AIName`='',`ScriptName`='' WHERE `entry`=31253;

--  Update Portal (Malygos) initial flags before the encounter starts
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|0x00000100|0x02000000,`flags_extra`=128 WHERE `entry`=30118; -- Immunity to Players + Not selectable

-- Update flags extra to trigger & civilian for Static Field and add script name
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_static_field',`flags_extra`=130 WHERE `entry`=30592;

-- Update flags extra to extra trigger & extra civilian for Alexstrasza Bunny
UPDATE `creature_template` SET `flags_extra`=130, `ScriptName`='' WHERE `entry`=31253;

-- Remove uneeded creature_addon data
DELETE FROM `creature_addon` WHERE `guid` IN
(30592, -- The spawn for Static Field is dynamique, so not fixed guid.
132313); -- Malygos is boss so is unique and needs only the template addon.

-- Update templates for both types of hover disks
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`VehicleId`=223,`InhabitType`=4 WHERE `entry` IN (30248,31749); -- Hover disk for Scions
UPDATE `creature_template` SET `ScriptName`='npc_caster_hover_disk' WHERE `entry`=30248;
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`InhabitType`=4 WHERE `entry` IN (30234,31748); -- Hover disk for Nexus Lords
UPDATE `creature_template` SET `ScriptName`='npc_melee_hover_disk' WHERE `entry`=30234;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_nexus_lord' WHERE `entry`=30245; -- Nexus Lord
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_scion_of_eternity' WHERE `entry`=30249; -- Scion of Eternity

-- Fix model display for Vortex Triggers (in creature handling).
-- Remove extra trigger flag because for some reason it was bugging model displaying as always visible,
-- since it has the invisible one for triggers first and other as second, this is the only nonhacky way (don't try to change it unless core side != c++ hack in instance script)
UPDATE `creature_template` SET `flags_extra`=flags_extra &~ 0x00000080 WHERE `entry`=30090;
UPDATE `creature` SET `modelid`=11686 WHERE `guid` BETWEEN 132304 AND 132308;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_02_28_00_world_playercreateinfo_spell.sql 
-- -------------------------------------------------------- 
-- Add missing generic spell for opening chests for most of Blood Elf's classes
-- (was preventing them to loot Eye of Eternity Alexstrasza's Gift Box, Heart of Magic and maybe more.)
DELETE FROM `playercreateinfo_spell` WHERE `race`=10 AND `Spell`=61437;
INSERT INTO `playercreateinfo_spell` (`race`,`class`,`Spell`,`Note`) VALUES
(10,2,61437, 'Opening'),
(10,3,61437, 'Opening'),
(10,4,61437, 'Opening'),
(10,5,61437, 'Opening'),
(10,6,61437, 'Opening'),
(10,8,61437, 'Opening'),
(10,9,61437, 'Opening');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_01_00_world_misc.sql 
-- -------------------------------------------------------- 
SET @ELM_BUNNY        :=23837;
SET @SHADOW_CULTIST   :=30835;
SET @VARDMADRA        :=30836;
SET @LK_EYE           :=192861;
SET @CREDIT           :=57884;
SET @SUMMON_CULTIST   :=57885;
SET @GOSSIP_CAST      :=57888;
SET @LK_EYE_CAST      :=57889;
SET @SUMMON_VARDMADRA :=57891;

DELETE FROM `creature_text` WHERE `entry` IN (@ELM_BUNNY,@VARDMADRA,@SHADOW_CULTIST);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ELM_BUNNY, 0, 0, 'Scrying upon many insignificant situations within Icecrown, you stumble upon something interesting...', 42, 0, 100, 0, 0, 0, 'Eye of Lich King Ambient'),
(@SHADOW_CULTIST, 0, 0, 'My lady.', 12, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 1, 0, 'There is word from Jotunheim. The sleep-watchers there believe that they have found someone of significance.', 12, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 2, 0, 'The cultist practically sputters.', 16, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 3, 0, 'Look like, my lady? A vrykul, I suppose. They did not actually show him to me. Ever since The Shadow Vault....', 12, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 4, 0, 'A name? Oh, yes, the name! I believe it was Iskalder.', 12, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 5, 0, 'Right away, my lady.', 12, 0, 100, 2, 0, 0, 'Shadow Cultist'),
(@VARDMADRA, 0, 0, 'Report.', 12, 0, 100, 1, 0, 0, 'Vardmadra'),
(@VARDMADRA, 1, 0, 'Describe this vrykul. What does he look like?', 12, 0, 100, 1, 0, 0, 'Vardmadra'),
(@VARDMADRA, 2, 0, 'I am not interested in excuses. Perhaps they gave you a name?', 12, 0, 100, 1, 0, 0, 'Vardmadra'),
(@VARDMADRA, 3, 0, 'Iskalder?! You fool! Have you no idea who that is? He''s only the greatest vrykul warrior who ever lived!', 12, 0, 100, 1, 0, 0, 'Vardmadra'),
(@VARDMADRA, 4, 0, 'Return to Jotunheim and tell them to keep him asleep until I arrive. I will judge this vrykul with my own eyes.', 12, 0, 100, 1, 0, 0, 'Vardmadra');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=57889;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(57889,57891,0,'On spellcast Using the Eye of the Lich King cast Through the Eye: Summon Image of Vardmadra'),
(57889,57885,0,'On spellcast Using the Eye of the Lich King cast Through the Eye: Summon Image of a Shadow Cultist');

DELETE FROM `spell_scripts` WHERE `id`=57884;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(57884,1,0,14,57889,0,0,0,0,0,0);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@LK_EYE;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@LK_EYE;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@LK_EYE, 1, 0, 1, 62, 0, 100, 0, 10005, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of the Lich King - On gossip select - Close gossip'),
(@LK_EYE, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, @GOSSIP_CAST, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of the Lich King - On gossip select - Invoker Spellcast Through the Eye: Eye of the Lich King Gossip Force Cast'),
(@LK_EYE, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, @ELM_BUNNY, 10, 0, 0, 0, 0, 0, 'Eye of the Lich King - On gossip select - Set data 0 1 Elm General Purpose Bunny');

UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=80,`maxlevel`=80,`exp`=2,`faction_A`=1610,`faction_H`=1610,`unit_flags`=33544, `HoverHeight`=6 WHERE `entry`=@VARDMADRA;
UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=80,`maxlevel`=80,`exp`=2,`faction_A`=1610,`faction_H`=1610,`unit_flags`=33544 WHERE `entry`=@SHADOW_CULTIST;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-121192,@VARDMADRA,@SHADOW_CULTIST);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@SHADOW_CULTIST*100;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121192, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Elm General Purpose Bunny - On data set 0 1 - Say line'),
(@SHADOW_CULTIST, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6828.99, 3814.678, 621.0696, 0, 'Shadow Cultist - Just summoned - Move to position'),
(@SHADOW_CULTIST, 0, 1, 2, 34, 0, 100, 0, 0, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist - On movement inform - Turn to Image of Vardmadra'),
(@SHADOW_CULTIST, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @SHADOW_CULTIST*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist - On movement inform - Run script'),
(@VARDMADRA, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, @SHADOW_CULTIST, 30, 0, 0, 0, 0, 0, 'Image of Vardmadra - Just summoned - Turn to Shadow Cultist'),
(@VARDMADRA, 0, 1, 0, 38, 0, 100, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 1 - Say line'),
(@VARDMADRA, 0, 2, 0, 38, 0, 100, 0, 0, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 2 - Say line'),
(@VARDMADRA, 0, 3, 0, 38, 0, 100, 0, 0, 3, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 3 - Say line'),
(@VARDMADRA, 0, 4, 0, 38, 0, 100, 0, 0, 4, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 4 - Say line'),
(@VARDMADRA, 0, 5, 0, 38, 0, 100, 0, 0, 5, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 5 - Say line'),
(@VARDMADRA, 0, 6, 7, 38, 0, 100, 0, 0, 6, 0, 0, 11, 57884, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 6 - Spellcast Through the Eye: Kill Credit to Master'),
(@VARDMADRA, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 6 - Despawn after 1 second'),

(@SHADOW_CULTIST*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set unit_field_bytes1 (kneel)'),
(@SHADOW_CULTIST*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 2, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 1 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9, 3, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 4, 0, 0, 0, 100, 0, 6500, 6500, 0, 0, 45, 0, 2, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 2 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9, 5, 0, 0, 0, 100, 0, 500, 500, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 6, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 45, 0, 3, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 3 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9, 8, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 0, 4, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 4 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9,10, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 45, 0, 5, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 5 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9,11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Remove unit_field_bytes1 (kneel)'),
(@SHADOW_CULTIST*100, 9,12, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9,13, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6816.328, 3801.11, 621.153, 0, 'Shadow Cultist script - Move to position'),
(@SHADOW_CULTIST*100, 9,14, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 0, 6, 0, 0, 0, 0, 19, @VARDMADRA, 30, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 6 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9,15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@SUMMON_VARDMADRA,@SUMMON_CULTIST);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10005;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SUMMON_VARDMADRA,0,0,30,0,@LK_EYE,10,0,1,0,0,'','Spell Through the Eye: Summon Image of Vardmadra will be casted only if target is not within 10y of Eye of the Lichking'),
(13,1,@SUMMON_VARDMADRA,0,0,31,0,3,@ELM_BUNNY,0,0,0,0,'','Spell Through the Eye: Summon Image of Vardmadra targets Elm General Purpose Bunny'),
(13,1,@SUMMON_CULTIST,0,0,31,0,3,@ELM_BUNNY,0,0,0,0,'','Spell Through the Eye: Summon Image of a Shadow Cultist targets Elm General Purpose Bunny'),
(15,10005,0,0,0,9,0,13121,0,0,0,0,0,'','Show gossip option only if player has taken quest Through the Eye'),
(15,10005,0,0,0,1,0,@LK_EYE_CAST,0,0,1,0,0,'','Hide gossip option when aura Using the Eye of the Lich King is present');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_01_02_world_misc.sql 
-- -------------------------------------------------------- 
SET @RAZUUN            := 21502; -- Image of Warbringer Razuun
SET @JOVAAN            := 21633; -- Deathbringer Jovaan
SET @TRIGGER           := 4548;  -- Smart Trigger
SET @DEVICE            := 184833;-- Legion Communication Device
SET @GO_INFERNAL       := 184834;-- Gobject that needs to be despawned during the script
SET @GO_INFERNAL2      := 184835;-- Gobject that needs to be despawned during the script

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@RAZUUN,@JOVAAN);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@JOVAAN,@RAZUUN) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@JOVAAN*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@RAZUUN,0,0,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On data 0 1 set - Say line'),
(@RAZUUN,0,1,0,38,0,100,0,0,2,0,0,1,1,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On data 0 2 set - Say line'),
(@RAZUUN,0,2,0,52,0,100,0,1,@RAZUUN,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On text over - Play emote'),
(@RAZUUN,0,3,0,38,0,100,0,0,3,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On data 0 3 set - Say line'),
(@RAZUUN,0,4,0,38,0,100,0,0,4,0,0,1,3,1500,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On data 0 4 set - Say line'),
(@RAZUUN,0,5,0,52,0,100,0,3,@RAZUUN,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On text over - Play emote'),
(@JOVAAN,0,0,1,11,0,100,0,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - Just summoned - Spellcast Etheral Teleport'),
(@JOVAAN,0,1,0,61,0,100,0,0,0,0,0,53,0,@JOVAAN,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - Just summoned - Start WP movement'),
(@JOVAAN,0,2,3,40,0,100,0,4,@JOVAAN,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - On WP 4 reached - Pause 45 seconds'),
(@JOVAAN,0,3,0,61,0,100,0,0,0,0,0,80,@JOVAAN*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - On WP 4 reached - Run Script'),

(@JOVAAN*100,9,0,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,14,25736,@DEVICE,0,0,0,0,0,'Deathbringer Jovaan script - Turn to Legion Communication Device'),
(@JOVAAN*100,9,1,0,0,0,100,0,2500,2500,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Play emote'),
(@JOVAAN*100,9,2,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Say line'),
(@JOVAAN*100,9,3,0,0,0,100,0,100,100,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Set unit_field_bytes1 (kneel)'),
(@JOVAAN*100,9,4,0,0,0,100,0,100,100,0,0,12,@RAZUUN,1,37500,0,0,0,8,0,0,0,-3300.087,2927.053,173.3354,2.199115,'Deathbringer Jovaan script - Summon Image of Warbringer Razuun'),
(@JOVAAN*100,9,5,0,0,0,100,0,800,800,0,0,45,0,1,0,0,0,0,19,@RAZUUN,10,0,0,0,0,0,'Deathbringer Jovaan script - Set data 0 1 Image of Warbringer Razuun'),
(@JOVAAN*100,9,6,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Say line'),
(@JOVAAN*100,9,7,0,0,0,100,0,5000,5000,0,0,45,0,2,0,0,0,0,19,@RAZUUN,10,0,0,0,0,0,'Deathbringer Jovaan script - Set data 0 2 Image of Warbringer Razuun'),
(@JOVAAN*100,9,8,0,0,0,100,0,7000,7000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Remove unit_field_bytes1 (kneel)'),
(@JOVAAN*100,9,9,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Say line'),
(@JOVAAN*100,9,10,0,0,0,100,0,6000,6000,0,0,45,0,3,0,0,0,0,19,@RAZUUN,10,0,0,0,0,0,'Deathbringer Jovaan script - Set data 0 3 Image of Warbringer Razuun'),
(@JOVAAN*100,9,11,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Say line'),
(@JOVAAN*100,9,12,0,0,0,100,0,4000,4000,0,0,45,0,4,0,0,0,0,19,@RAZUUN,10,0,0,0,0,0,'Deathbringer Jovaan script - Set data 0 4 Image of Warbringer Razuun'),
(@JOVAAN*100,9,13,0,0,0,100,0,3500,3500,0,0,33,@RAZUUN,0,0,0,0,0,21,20,0,0,0,0,0,0,'Deathbringer Jovaan script - Give Quest Credit'),
(@JOVAAN*100,9,14,0,0,0,100,0,0,0,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Play emote');

DELETE FROM `creature_text` WHERE `entry` IN (@RAZUUN,@JOVAAN);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@RAZUUN,0,0,'Doom Lord Kazzak will be pleased. You are to increase the pace of your attacks. Destroy the orcish and dwarven strongholds with all haste.',12,0,100,1,0,0,'Razuun'),
(@RAZUUN,1,0,'Don''t worry about that. I''ve increased production at the Deathforge. You''ll have all the infernals you need to carry out your orders. Don''t fail, Jovaan.',12,0,100,1,0,0,'Razuun'),
(@RAZUUN,2,0,'Yes?',12,0,100,6,0,0,'Razuun'),
(@RAZUUN,3,0,'Crate? I didn''t send you a crate, Jovaan. Don''t you have more important things to worry about? Go see to them!',12,0,100,274,0,0,'Razuun'),
(@JOVAAN,0,0,'Everything is in readiness, warbringer.',12,0,100,0,0,0,'Jovaan'),
(@JOVAAN,1,0,'Warbringer, that will require the use of all the hold''s infernals. It may leave us vulnerable to a counterattack.',12,0,100,0,0,0,'Jovaan'),
(@JOVAAN,2,0,'It shall be as you say, warbringer. One last question, if I may...',12,0,100,6,0,0,'Jovaan'),
(@JOVAAN,3,0,'What''s in the crate?',12,0,100,6,0,0,'Jovaan');

DELETE FROM `waypoints` WHERE `entry`=@JOVAAN;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@JOVAAN, 1, -3310.995, 2951.892, 171.2171, 'Deathbrinder Jovaan'),
(@JOVAAN, 2, -3307.998, 2942.022, 171.1127, 'Deathbrinder Jovaan'),
(@JOVAAN, 3, -3306.255, 2935.729, 171.0294, 'Deathbrinder Jovaan'),
(@JOVAAN, 4, -3304.257, 2930.78, 170.9866, 'Deathbrinder Jovaan'),
(@JOVAAN, 5, -3307.609, 2936.385, 170.9919, 'Deathbrinder Jovaan'),
(@JOVAAN, 6, -3309.415, 2942.621, 171.119, 'Deathbrinder Jovaan');

DELETE FROM `areatrigger_scripts` WHERE `entry`=@TRIGGER;
INSERT INTO `areatrigger_scripts` VALUES (@TRIGGER,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRIGGER AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@TRIGGER,2,0,1,46,0,100,0,@TRIGGER,0,0,0,45,0,0,0,0,0,0,14,25736,@DEVICE,0,0,0,0,0,'Smart Trigger - On Trigger - Set Data to GO'),
(@TRIGGER,2,1,2,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,14,25737,@GO_INFERNAL,0,0,0,0,0,'Smart Trigger - On Link - Set Data GO'),
(@TRIGGER,2,2,0,61,0,100,0,0,0,0,0,45,0,2,0,0,0,0,14,25738,@GO_INFERNAL2,0,0,0,0,0,'Smart Trigger - On Link - Set Data GO');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@DEVICE,@GO_INFERNAL,@GO_INFERNAL2);
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid` IN (@DEVICE,@GO_INFERNAL,@GO_INFERNAL2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@DEVICE,1,0,0,38,0,100,0,0,0,0,0,12,@JOVAAN,1,57000,0,0,0,8,0,0,0,-3310.995, 2951.892, 171.2171, 5.5355,'Legion Communicator - On Data Set - Summon Jovaan'),
(@GO_INFERNAL,1,0,0,38,0,100,0,0,1,0,0,99,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infernal  - On Data Set- Change State'),
(@GO_INFERNAL,1,1,0,70,0,100,0,2,0,0,0,70,50,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infernal - On Data Set- Despawn GO'),
(@GO_INFERNAL2,1,0,0,38,0,100,0,0,2,0,0,99,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infernal 2 - On Data Set- Change State'),
(@GO_INFERNAL2,1,1,0,70,0,100,0,2,0,0,0,70,50,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infernal 2 - On Data Set - Despawn GO');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (@TRIGGER,@DEVICE);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@TRIGGER,2,0,1,0,37097,0,0,0,0,'','SAI areatrigger 4548 triggers only if player has aura Crate Disguise'),
(22,1,@TRIGGER,2,0,29,0,@JOVAAN,50,0,1,0,'','SAI areatrigger 4548 triggers only if there is no Deathbringer Jovaan present'),
(22,1,@DEVICE,2,0,1,0,37097,0,0,0,0,'','SAI Legion Communication Device triggers only if player has aura Crate Disguise');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_02_00_world_conditions.sql 
-- -------------------------------------------------------- 
-- Add conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56438;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,56438,0,0,1,0,56438,0,0,1,0,0,'', 'Arcane Overload damage reduce aura can''t apply to target that already is affected by such');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_03_00_world_eye_of_eternity.sql 
-- -------------------------------------------------------- 
-- Delete wrongly inserted spell linked spell of Scion of Eternity - "Arcane Barrage".
-- It should be handled in the original caster spell with spellscript effect.
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=56397 AND `spell_effect`=63934 AND`type`=1;

-- Update flags in creature for Malygos since differ from these in creature_template
UPDATE `creature` SET `unit_flags`=320,`dynamicflags`=8 WHERE `id`=28859;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_03_01_world_misc.sql 
-- -------------------------------------------------------- 
-- Issue 9311
-- Add Missing Sunreaver Guardian Mage inside Sunreaver Tavern (Thx Aokromes) 
SET @CGUID := 40267; -- Set by TDB Team
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@CGUID,29255,571,1,1,5900.299,505.75,641.6531,4.171337,120,0,0);

-- Issue 9322: 
-- fix SAI to make the quest Mission: The Abyssal Shelf (10162) Horde completable (thx Kirkhammett) 
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=19273;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19273;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19273,0,0,0,19, 0,100,0,10162,0,0,0,15,10162,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Commander To''arch - On Quest Accept - Call Areaexplored');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_03_02_world_sai.sql 
-- -------------------------------------------------------- 
-- Issue 9250
-- A Worthy Weapon (thx Durotar)
UPDATE `creature_template` SET `InhabitType`=4, `hoverheight`=1065353216, `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=33273;
-- Set visual effect: sitting
DELETE FROM `creature_template_addon` WHERE `entry`=33273;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`) VALUES (33273,1,1,0);
-- Winter Hyacinth (item 45000) Send Script Event (20990) by right-click
DELETE FROM `event_scripts` WHERE `id`=20990;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `x`, `y`, `z`, `o`) VALUES
(20990, 0, 10, 33273, 42000, 4602.977, -1600.141, 156.7834, 0.7504916);
-- TEMP Drak'Mar Offering Ring
SET @ObjectGuid := 6068; -- set by TDB staff
DELETE FROM `gameobject` WHERE `id`=300009;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@ObjectGuid+0,300009,571,1,1, 4606.72, -1606.91, 156.659, 1.62734,0.0,0.0, 0.726811, 0.686837,300,0,1),
(@ObjectGuid+1,300009,571,1,1, 4596.78, -1606.69, 156.659, 1.5488,0.0,0.0, 0.699286, 0.714842,300,0,1),
(@ObjectGuid+2,300009,571,1,1, 4597.1, -1594.08, 156.658, 1.53702,0.0,0.0, 0.695063, 0.718949,300,0,1),
(@ObjectGuid+3,300009,571,1,1, 4608.33, -1592.98, 156.658, 0.162569,0.0,0.0, 0.0811951, 0.996698,300,0,1),
(@ObjectGuid+4,300009,571,1,1, 4602.78, -1600.05, 156.658, 4.08564,0.0,0.0, 0.890651, -0.454688,300,0,1);
-- creature_text
DELETE FROM `creature_text` WHERE `entry`=33273 AND `groupid` BETWEEN 0 AND 3;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(33273,0,0, 'Are those winter hyacinths? For me?',12,0,100,6,0,0, 'Maiden of Drak''Mar'),
(33273,1,0, 'It''s been so long since a traveler has come here bearing flowers.',12,0,100,1,0,0, 'Maiden of Drak''Mar'),
(33273,2,0, 'The lake has been too lonely these past years. The travelers stopped coming and evil came to these waters.',12,0,100,1,0,0, 'Maiden of Drak''Mar'),
(33273,3,0, 'Your gift is a rare kindness, traveler. Please take this blade with my gratitude. Long ago, another traveler left it here, but I have little use for it.',12,0,100,1,0,0, 'Maiden of Drak''Mar');
-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=33273 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=33273*100 AND `source_type`=9 AND `id` BETWEEN 0 AND 6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33273,0,0,0,54,0,100,0,0,0,0,0,80,33273*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On spawn - Run script'),
(33273*100,9,0,0,0,0,100,0,0,0,0,0,50,194239,42000,0,0,0,0,8,0,0,0,4602.977,-1600.141,156.7834,0, 'Maiden of DrakMar - On script - Summon GO DrakMar Lily Pad'),
(33273*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On script - Say 0'),
(33273*100,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On script - Say 1'),
(33273*100,9,3,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On script - Say 2'),
(33273*100,9,4,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On script - Say 3'),
(33273*100,9,5,0,0,0,100,0,0,0,0,0,50,194238,20000,0,0,0,0,8,0,0,0,4603.351,-1599.288,156.8822,2.234018, 'Maiden of DrakMar - On script - Summon GO Blade of DrakMar');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_04_01_world_waypoint_data.sql 
-- -------------------------------------------------------- 
SET @GUID := 40470;
SET @PATH := @GUID*10;
DELETE FROM `creature` where `id`=18686;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES 
(@GUID,18686,530,1,1,0,0,-2847.327,3195.10722,7.4167,.0910940,300,0,0,9144,13525,2,0,0,0);
-- Pathing Data
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`) VALUES 
(@PATH,1,-2843.86,3205.97,5.45323,0,0,0,0,100),
(@PATH,2,-2829.24,3218.81,9.59048,0,0,0,0,100),
(@PATH,3,-2814.12,3235.72,10.1736,0,0,0,0,100),
(@PATH,4,-2792.54,3259.91,5.91885,0,0,0,0,100),
(@PATH,5,-2774.46,3280.17,2.8828,0,0,0,0,100),
(@PATH,6,-2751.21,3306.24,0.199384,0,0,0,0,100),
(@PATH,7,-2728.55,3318.21,-0.833018,0,0,0,0,100),
(@PATH,8,-2719.59,3331.35,-1.04936,0,0,0,0,100),
(@PATH,9,-2708.94,3349.74,-0.819842,0,0,0,0,100),
(@PATH,10,-2694.72,3374.29,-0.156626,0,0,0,0,100),
(@PATH,11,-2685.08,3390.93,0.328583,0,0,0,0,100),
(@PATH,12,-2675.69,3407.16,0.474826,0,0,0,0,100),
(@PATH,13,-2669.68,3416.29,0.743526,0,0,0,0,100),
(@PATH,14,-2660.96,3425.20,0.805554,0,0,0,0,100),
(@PATH,15,-2654.25,3430.82,0.77502,0,0,0,0,100),
(@PATH,16,-2645.46,3437.83,1.28666,0,0,0,0,100),
(@PATH,17,-2639.59,3442.50,3.25542,0,0,0,0,100),
(@PATH,18,-2630.71,3449.41,1.86245,0,0,0,0,100),
(@PATH,19,-2621.54,3456.21,0.653284,0,0,0,0,100),
(@PATH,20,-2617.41,3460.51,0.593326,0,0,0,0,100),
(@PATH,21,-2611.50,3471.52,0.520041,0,0,0,0,100),
(@PATH,22,-2610.04,3475.69,0.53993,0,0,0,0,100),
(@PATH,23,-2606.90,3480.85,0.492544,0,0,0,0,100),
(@PATH,24,-2590.41,3502.84,0.225892,0,0,0,0,100),
(@PATH,25,-2582.03,3512.00,0.101641,0,0,0,0,100),
(@PATH,26,-2566.36,3522.06,0.189451,0,0,0,0,100),
(@PATH,27,-2534.38,3523.07,1.3404,0,0,0,0,100),
(@PATH,28,-2523.33,3527.83,1.66667,0,0,0,0,100),
(@PATH,29,-2516.31,3533.95,1.65006,0,0,0,0,100),
(@PATH,30,-2507.47,3544.67,1.56155,0,0,0,0,100),
(@PATH,31,-2491.83,3549.68,1.43199,0,0,0,0,100),
(@PATH,32,-2471.56,3551.98,1.23732,0,0,0,0,100),
(@PATH,33,-2463.14,3555.66,1.03546,0,0,0,0,100),
(@PATH,34,-2456.30,3555.25,0.942503,0,0,0,0,100),
(@PATH,35,-2452.53,3537.02,0.402467,0,0,0,0,100),
(@PATH,36,-2446.32,3528.59,-0.236494,0,0,0,0,100),
(@PATH,37,-2462.93,3549.41,1.08819,0,0,0,0,100),
(@PATH,38,-2460.92,3557.50,1.00403,0,0,0,0,100),
(@PATH,39,-2425.49,3596.20,0.274173,0,0,0,0,100),
(@PATH,40,-2405.20,3613.88,0.217946,0,0,0,0,100),
(@PATH,41,-2391.31,3632.83,0.792431,0,0,0,0,100),
(@PATH,42,-2383.97,3658.54,0.99065,0,0,0,0,100),
(@PATH,43,-2351.54,3700.72,0.420721,0,0,0,0,100),
(@PATH,44,-2314.59,3729.83,0.0297019,0,0,0,0,100),
(@PATH,45,-2296.57,3749.89,0.363868,0,0,0,0,100),
(@PATH,46,-2285.44,3767.70,0.291327,0,0,0,0,100),
(@PATH,47,-2279.30,3787.95,0.314858,0,0,0,0,100),
(@PATH,48,-2276.30,3799.32,0.521091,0,0,0,0,100),
(@PATH,49,-2254.61,3831.13,2.70024,0,0,0,0,100),
(@PATH,50,-2251.75,3848.92,5.15061,0,0,0,0,100),
(@PATH,51,-2249.52,3869.55,2.39354,0,0,0,0,100),
(@PATH,52,-2244.66,3893.46,1.58335,0,0,0,0,100),
(@PATH,53,-2239.88,3904.19,1.10899,0,0,0,0,100),
(@PATH,54,-2224.28,3927.45,0.706091,0,0,0,0,100),
(@PATH,55,-2187.45,3958.22,0.921813,0,0,0,0,100),
(@PATH,56,-2175.09,3978.98,0.929392,0,0,0,0,100),
(@PATH,57,-2171.14,4011.04,0.450247,0,0,0,0,100),
(@PATH,58,-2175.93,4027.88,0.519539,0,0,0,0,100),
(@PATH,59,-2187.96,4064.43,1.42810,0,0,0,0,100),
(@PATH,60,-2166.44,4102.49,4.27243,0,0,0,0,100), -- Had guid as action_id
(@PATH,61,-1700.15,3993.57,55.6859,0,0,0,0,100),
(@PATH,62,-1710.59,4034.97,60.6101,0,0,0,0,100),
(@PATH,63,-1719.95,4059.83,62.7452,0,0,0,0,100),
(@PATH,64,-1718.67,4104.32,64.3796,0,0,0,0,100),
(@PATH,65,-1743.77,4151.60,62.3929,0,0,0,0,100),
(@PATH,66,-1754.61,4173.29,58.3691,0,0,0,0,100),
(@PATH,67,-1788.41,4206.51,44.1839,0,0,0,0,100),
(@PATH,68,-1818.93,4214.12,33.1137,0,0,0,0,100),
(@PATH,69,-1841.51,4228.10,22.0741,0,0,0,0,100),
(@PATH,70,-1871.54,4263.50,8.22153,0,0,0,0,100),
(@PATH,71,-1891.00,4295.91,3.23019,0,0,0,0,100),
(@PATH,72,-1911.96,4351.49,1.66825,0,0,0,0,100),
(@PATH,73,-1910.12,4389.42,1.77078,0,0,0,0,100),
(@PATH,74,-1907.67,4417.31,2.99456,0,0,0,0,100),
(@PATH,75,-1917.63,4452.07,6.27493,0,0,0,0,100),
(@PATH,76,-1929.40,4473.47,8.90937,0,0,0,0,100),
(@PATH,77,-1942.74,4489.67,11.1029,0,0,0,0,100),
(@PATH,78,-1958.47,4508.45,12.7432,0,0,0,0,100),
(@PATH,79,-1975.36,4519.94,13.1616,0,0,0,0,100),
(@PATH,80,-1982.19,4524.49,13.0993,0,0,0,0,100),
(@PATH,81,-1983.38,4507.03,12.7591,0,0,0,0,100),
(@PATH,82,-1984.02,4496.55,11.9535,0,0,0,0,100),
(@PATH,83,-1984.87,4482.57,11.1499,0,0,0,0,100),
(@PATH,84,-1978.92,4509.87,12.6695,0,0,0,0,100),
(@PATH,85,-1978.12,4527.35,13.36,0,0,0,0,100),
(@PATH,86,-1967.33,4546.79,12.8741,0,0,0,0,100),
(@PATH,87,-1953.04,4566.47,10.1123,0,0,0,0,100),
(@PATH,88,-1946.50,4582.91,7.44598,0,0,0,0,100),
(@PATH,89,-1948.30,4599.58,4.61956,0,0,0,0,100),
(@PATH,90,-1955.08,4637.48,-0.0588505,0,0,0,0,100),
(@PATH,91,-1943.63,4685.04,-2.18987,0,0,0,0,100),
(@PATH,92,-1941.99,4705.25,-2.67768,0,0,0,0,100),
(@PATH,93,-1945.22,4727.47,-3.22917,0,0,0,0,100),
(@PATH,94,-1951.89,4748.79,-2.9388,0,0,0,0,100),
(@PATH,95,-1957.77,4773.70,-1.42409,0,0,0,0,100),
(@PATH,96,-1957.36,4798.11,-0.0807409,0,0,0,0,100),
(@PATH,97,-1944.66,4829.17,0.67,0,0,0,0,100),
(@PATH,98,-1929.68,4851.09,1.64973,0,0,0,0,100),
(@PATH,99,-1918.23,4883.89,2.11937,0,0,0,0,100),
(@PATH,100,-1901.18,4906.49,-1.12705,0,0,0,0,100),
(@PATH,101,-1881.87,4926.69,-9.60835,0,0,0,0,100),
(@PATH,102,-1870.05,4946.21,-17.0149,0,0,0,0,100),
(@PATH,103,-1866.49,4960.25,-20.2899,0,0,0,0,100),
(@PATH,104,-1860.94,5033.3,-26.0991,0,0,0,0,100),
(@PATH,105,-1869.80,4962.46,-20.3781,0,0,0,0,100),
(@PATH,106,-1884.86,4924.67,-8.30171,0,0,0,0,100),
(@PATH,107,-1904.83,4905.16,-0.202733,0,0,0,0,100),
(@PATH,108,-1922.67,4912.5,6.06643,0,0,0,0,100),
(@PATH,109,-1937.46,4934.99,14.8054,0,0,0,0,100),
(@PATH,110,-1953.22,4961.69,24.7149,0,0,0,0,100),
(@PATH,111,-1958.07,4992.99,30.1767,0,0,0,0,100),
(@PATH,112,-1958.74,5013.42,32.4293,0,0,0,0,100),
(@PATH,113,-1947.03,5042.52,25.2899,0,0,0,0,100),
(@PATH,114,-1942.58,5058.03,19.5292,0,0,0,0,100),
(@PATH,115,-1963.32,5083.08,11.1075,0,0,0,0,100),
(@PATH,116,-1984.50,5100.08,7.82778,0,0,0,0,100),
(@PATH,117,-2004.59,5114.07,8.26657,0,0,0,0,100),
(@PATH,118,-2029.48,5123.26,8.48839,0,0,0,0,100),
(@PATH,119,-2055.94,5125.38,7.48301,0,0,0,0,100),
(@PATH,120,-2089.33,5115.44,3.14184,0,0,0,0,100),
(@PATH,121,-2112.53,5107.32,-2.40737,0,0,0,0,100),
(@PATH,122,-2137.40,5108.51,-11.5709,0,0,0,0,100),
(@PATH,123,-2155.69,5115.97,-18.1534,0,0,0,0,100),
(@PATH,124,-2170.60,5125.13,-21.2824,0,0,0,0,100),
(@PATH,125,-2182.81,5131.87,-21.667,0,0,0,0,100),
(@PATH,126,-2198.88,5138.77,-21.2323,0,0,0,0,100),
(@PATH,127,-2219.62,5144.57,-19.6848,0,0,0,0,100),
(@PATH,128,-2238.57,5146.29,-17.4706,0,0,0,0,100),
(@PATH,129,-2266.45,5144.26,-13.0598,0,0,0,0,100),
(@PATH,130,-2290.86,5142.23,-9.17377,0,0,0,0,100),
(@PATH,131,-2308.35,5142.09,-7.11532,0,0,0,0,100),
(@PATH,132,-2333.72,5149.44,-5.0165,0,0,0,0,100),
(@PATH,133,-2365.45,5157.88,-2.8501,0,0,0,0,100),
(@PATH,134,-2390.26,5158.22,-1.19618,0,0,0,0,100),
(@PATH,135,-2417.84,5153.35,0.775549,0,0,0,0,100),
(@PATH,136,-2442.28,5142.04,3.53141,0,0,0,0,100),
(@PATH,137,-2469.81,5120.56,6.76948,0,0,0,0,100),
(@PATH,138,-2498.06,5115.06,7.87731,0,0,0,0,100),
(@PATH,139,-2532.85,5118.89,7.54034,0,0,0,0,100),
(@PATH,140,-2555.60,5120.59,7.69492,0,0,0,0,100), -- GUID+1 as action_id
(@PATH,141,-2843.86,3205.97,5.45323,0,0,0,0,100);
-- Assign Path
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES 
(@GUID,@PATH);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_04_02_world_quest_template.sql 
-- -------------------------------------------------------- 
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `Id`=8345;
UPDATE `quest_template` SET `NextQuestId`=0 WHERE `Id`=8330;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_04_03_world_sai.sql 
-- -------------------------------------------------------- 
-- The Admiral Revealed (12852) - http://www.wowhead.com/quest=12852
-- http://www.youtube.com/watch?v=I9doc1BVmA8
SET @WHIRLWIND       := 49807; -- Admiral's Whirlwind, AoE, used in phase 1
SET @STRIKE          := 57846; -- Admiral's Heroic Strike, cast on tank, used in phase 1
SET @CLEAVE          := 15284; -- Admiral's Cleave, cast in cone, used in phase 1
SET @TOUCH           := 60501; -- Selfcast on Mal'Ganis, heals him, used in phase 2
SET @SLEEP           := 53045; -- Mal'Ganis Sleep,Cast on random group member, used in phase 2
SET @BLAST           := 60500; -- Mal'Ganis Mind Blast, Cast on random group member, used in phase 2
SET @CARRION         := 60502; -- Mal'Ganis Carrion Swarm, Cast in cone, used in phase 2
SET @SHIELD          := 50161; -- Cast when Admiral on 50 %
SET @ITEMSPELL       := 31699; -- Spell to disable shield
SET @ADMIRAL         := 29621; -- Grand Admiral Westwind
SET @MALGANIS        := 29620; -- Dreadlord Mal'Ganis
SET @PORTAL          := 27731; -- Portal visual
SET @LEGION_TELEPORT := 35502; -- Mal'Ganis Legion Portal visual
SET @CREDIT_BUNNY    := 29627; -- Cute little flaming bunny
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@CREDIT_BUNNY);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CREDIT_BUNNY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`, `target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CREDIT_BUNNY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 75, @PORTAL, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Credit Bunny - Just Summoned - Cast Portal');
-- SAI for Grand Admiral Westwind
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@ADMIRAL,@MALGANIS,@ADMIRAL*100);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (@ADMIRAL,@ADMIRAL*100) AND `source_type` IN (0,9);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MALGANIS AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`, `target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ADMIRAL, 0, 0, 1, 4, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On aggro - Set invicibility at 1 HP'),
(@ADMIRAL, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Say line 0'),
(@ADMIRAL, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Set phase 1'),
(@ADMIRAL, 0, 3, 4, 2, 0, 100, 1, 0, 50, 0, 0, 11, @SHIELD, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - At 50% HP - Cast Protection Sphere'),
(@ADMIRAL, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - Link - Say line 1'),
(@ADMIRAL, 0, 5, 6, 8, 0, 100, 0, @ITEMSPELL, 0, 0, 0, 28, @SHIELD, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On spell hit - Remove aura'),
(@ADMIRAL, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - Link - Say line 2'),
(@ADMIRAL, 0, 7, 8, 2, 0, 100, 1, 0, 30, 0, 0, 3, @MALGANIS, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - At 30% HP - Morph to Dreadlord Mal''Ganis'),
(@ADMIRAL, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Set phase 2'),
(@ADMIRAL, 0, 9,10, 61, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - Link - Say line 3'),
(@ADMIRAL, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'Grand Admiral Westwind - Link - Sheath'),
(@ADMIRAL, 0, 11, 0, 2, 0, 100, 1, 0, 15, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - At 15% HP - Say line 4'),
(@ADMIRAL, 0, 12, 0, 1, 0, 100, 0, 0, 0, 0, 0, 3, @ADMIRAL, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On evade - Restore model'),
(@ADMIRAL, 0, 13, 14, 2, 0, 100, 1, 1, 1, 0, 0, 18, 33554434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On 1 hp - Set unit_flags'),
(@ADMIRAL, 0, 14, 15, 61, 0, 100, 1, 0, 0, 0, 0, 12, @CREDIT_BUNNY, 1, 19000, 0, 0, 0, 8, 0, 0, 0, 7494.893066, 4871.533203, -12.655286, 1.376, 'Grand Admiral Westwind - On Link - Summon Npc'),
(@ADMIRAL, 0, 15, 16, 61, 0, 100, 1, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Stop Combat/Attack Attack State'),
(@ADMIRAL, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @ADMIRAL*100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Start timed script'),
(@ADMIRAL*100, 9, 0, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On script - Set phase 3'),
(@ADMIRAL*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 7494.788, 4872.567, -12.72154, 0, 'Grand Admiral Westwind - On Script - Move to Pos'),
(@ADMIRAL*100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Script - Say line 6'),
(@ADMIRAL*100, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, @LEGION_TELEPORT, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Script - Cast spell on self'),
(@ADMIRAL*100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 33, @CREDIT_BUNNY, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Script - Give quest credit'),
(@ADMIRAL*100, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 41, 3500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Script - Despawn'),
(@ADMIRAL, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 33554434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Respawn - Unset unit_flags'),
(@ADMIRAL, 0, 18, 0, 0, 1, 100, 0, 15000, 16000, 16000, 16000, 11, @WHIRLWIND, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 1 - Cast Whirlwind'),
(@ADMIRAL, 0, 19, 0, 0, 1, 100, 0, 6000, 7000, 6000, 7000, 11, @STRIKE, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 1 - Cast Heroic Strike'),
(@ADMIRAL, 0, 20, 0, 0, 2, 100, 0, 15000, 16000, 15000, 16000, 11, @SLEEP, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 2 - Cast Sleep'),
(@ADMIRAL, 0, 21, 0, 0, 2, 100, 0, 6000, 7000, 6000, 7000, 11, @TOUCH, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 2- Cast Vampiric Touch'),
(@ADMIRAL, 0, 22, 0, 0, 1, 100, 0, 13000, 13500, 13000, 13500, 11, @CLEAVE, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 1 - Cast Cleave'),
(@ADMIRAL, 0, 23, 0, 0, 2, 100, 0, 8000, 9000, 8000, 9000, 11, @CARRION, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 2 - Cast Carrion Swarm'),
(@ADMIRAL, 0, 24, 0, 0, 2, 100, 0, 18000, 19000, 18000, 19000, 11, @BLAST, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 2 - Cast Mind Blast'),
(@ADMIRAL, 0, 25, 0, 25, 0, 100, 0, 0, 0, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Reset - Allow Attack State');
/*
Sound ID's
14429 Final speech - When he uses portal
14428 2% HP - When he becomes immune
14427 15 % - When he rages
14426 30% HP - When he morphs
14207 Sphere removed - When Item spell is used on him
14205 Sphere cast - When he casts sphere on self
14201 Beginning of combat - When he aggros
*/
-- Sniffed text with sounds
DELETE FROM `creature_text` WHERE `entry` IN (@ADMIRAL,@MALGANIS);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ADMIRAL,0,0, 'How did you find me? Did Landgren tell?',12,0,100,0,0,14201, 'Grand Admiral Westwind'),
(@ADMIRAL,1,0, 'You thought I would just let you kill me?',12,0,100,0,0,14205, 'Grand Admiral Westwind'),
(@ADMIRAL,2,0, 'WHAT?! No matter. Even without my sphere, I will crush you! Behold my true identity and despair!',14,0,100,0,0,14207, 'Grand Admiral Westwind'),
(@ADMIRAL,3,0, 'Gah! I spent too much time in that weak little shell.',14,0,100,0,0,14426, 'Grand Admiral Westwind'),
(@ADMIRAL,4,0, 'Kirel narak! I am Mal''Ganis. I AM ETERNAL!',14,0,100,0,0,14427, 'Grand Admiral Westwind'),
(@ADMIRAL,5,0, 'ENOUGH! I waste my time here. I must gather my strength on the homeworld.',14,0,100,0,0,14428, 'Grand Admiral Westwind'),
(@ADMIRAL,6,0, 'You''ll never defeat the Lich King without my forces. I''ll have my revenge... on him AND you!',14,0,100,0,0,14429, 'Grand Admiral Westwind');
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_04_04_world_player_factionchange_quests.sql 
-- -------------------------------------------------------- 
-- ----------------------------
-- Table structure for `player_factionchange_quests`
-- ----------------------------
DROP TABLE IF EXISTS `player_factionchange_quests`;
CREATE TABLE `player_factionchange_quests` (
  `alliance_id` int(10) unsigned NOT NULL,
  `horde_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`alliance_id`,`horde_id`),
  UNIQUE INDEX `alliance_uniq` (`alliance_id`),
  UNIQUE INDEX `horde_uniq` (`horde_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_04_05_world_player_factionchange_quests.sql 
-- -------------------------------------------------------- 
DELETE FROM `player_factionchange_quests` WHERE `alliance_id` IN (9524, 8114, 7168, 7169, 7170, 7171, 7172, 8115, 8311, 8960, 8860, 8997, 9520, 9522, 9587, 9869, 9933, 9938, 9940, 9982, 9994, 9996, 10005, 10014, 10033, 10035, 10038, 10040, 10042, 10048, 10051, 10053, 10054, 10055, 10056, 10057, 10076, 10078, 10080, 10083, 10084, 10115, 10116, 10140, 10141, 10122, 10142, 10126, 10145, 10128, 10146, 10130, 10131, 10147, 10148, 10137, 10138, 10139, 10163, 10394, 10397, 10395, 10443, 10444, 10476, 10562, 10563, 10564, 10572, 10582, 10583, 10585, 10586, 10589, 10606, 10612, 10621, 10626, 10662, 10680, 10744, 10772, 10773, 10754, 10762, 10763, 10764, 10759, 10774, 10766, 10775, 10776, 10863, 10869, 10962, 11002, 11117, 11122, 11123, 11150, 11185, 11242, 11302, 11346, 11348, 11349, 11355, 11358, 11359, 11321, 11131, 12135, 11400, 11486, 11502, 11657, 11713, 11704, 11731, 11882, 11921, 11924, 11986, 11993, 12022, 12105, 12129, 12130, 12131, 12133, 12138, 12142, 12143, 12146, 12153, 12161, 12183, 12184, 12185, 12219, 12220, 12222, 12223, 12246, 12247, 12249, 12248, 12250, 12255, 12278, 12464, 12323, 12416, 12417, 12418, 12460, 12479, 12491, 12854, 12858, 12860, 12862, 12870, 12872, 12885, 13186, 13222, 13188, 13226, 13395, 13387, 13388, 13389, 13390, 13391, 13392, 13284, 13393, 13394, 13332, 13334, 13309, 13337, 13338, 13339, 13335, 13336, 13341, 13396, 13397, 13398, 13399, 13400, 13401, 13402, 13403, 13380, 13381, 13382, 13383, 13408, 13410, 13415, 13418, 13480, 13484, 13633, 13625, 13671, 13672, 13679, 13686, 13828, 13835, 13837, 14022, 14023, 14024, 14028, 14030, 14033, 14035, 14048, 14051, 14053, 14054, 14055, 14096, 14111, 20438, 20439, 24498, 24499, 24500, 24510, 24535, 24656, 24657, 24683, 24710, 24711, 24655, 24804, 24848, 25055, 25180, 25253, 25282, 25290, 25414);
INSERT INTO `player_factionchange_quests` (`alliance_id`, `horde_id`) VALUES
(9524, 9525),
(8114, 8121),
(7168, 7163),
(7169, 7164),
(7170, 7165),
(7171, 7166),
(7172, 7167),
(8115, 8122),
(8311, 8312),
(8960, 9032),
(8860, 8861),
(8997, 8998),
(9520, 9535),
(9522, 9536),
(9587, 9588),
(9869, 9870),
(9933, 9934),
(9938, 9937),
(9940, 9939),
(9982, 9983),
(9994, 9995),
(9996, 9997),
(10005, 10006),
(10014, 10015),
(10033, 10034),
(10035, 10036),
(10038, 10039),
(10040, 10041),
(10042, 10043),
(10048, 10049),
(10051, 10052),
(10053, 10059),
(10054, 10060),
(10055, 10086),
(10056, 10158),
(10057, 10062),
(10076, 10074),
(10078, 10087),
(10080, 10089),
(10083, 10090),
(10084, 10092),
(10115, 10118),
(10116, 10117),
(10140, 10120),
(10141, 10121),
(10122, 10150),
(10142, 10123),
(10126, 10151),
(10145, 10127),
(10128, 10153),
(10146, 10129),
(10130, 10152),
(10131, 10154),
(10147, 10133),
(10148, 10135),
(10137, 10155),
(10138, 10156),
(10139, 10157),
(10163, 10162),
(10394, 10390),
(10397, 10392),
(10395, 10393),
(10443, 10442),
(10444, 10448),
(10476, 10479),
(10562, 10595),
(10563, 10596),
(10564, 10598),
(10572, 10597),
(10582, 10600),
(10583, 10601),
(10585, 10602),
(10586, 10603),
(10589, 10604),
(10606, 10611),
(10612, 10613),
(10621, 10623),
(10626, 10627),
(10662, 10663),
(10680, 10681),
(10744, 10745),
(10772, 10750),
(10773, 10751),
(10754, 10755),
(10762, 10756),
(10763, 10757),
(10764, 10758),
(10759, 10761),
(10774, 10765),
(10766, 10767),
(10775, 10768),
(10776, 10769),
(10863, 10862),
(10869, 10868),
(10962, 10963),
(11002, 11003),
(11117, 11431),
(11122, 11412),
(11123, 11124),
(11150, 11205),
(11185, 11186),
(11242, 11403),
(11302, 11312),
(11346, 11350),
(11348, 11352),
(11349, 11351),
(11355, 11365),
(11358, 11366),
(11359, 11367),
(11321, 11413),
(11131, 11219),
(12135, 12139),
(11400, 11419),
(11486, 11487),
(11502, 11503),
(11657, 11923),
(11713, 11684),
(11704, 11702),
(11731, 11922),
(11882, 11915),
(11921, 11926),
(11924, 11925),
(11986, 12026),
(11993, 12058),
(12022, 12191),
(12105, 12423),
(12129, 12165),
(12130, 12196),
(12131, 12197),
(12133, 12155),
(12138, 12198),
(12142, 12144),
(12143, 12145),
(12146, 12147),
(12153, 12199),
(12161, 12425),
(12183, 12201),
(12184, 12202),
(12185, 12203),
(12219, 12207),
(12220, 12213),
(12222, 12256),
(12223, 12257),
(12246, 12229),
(12247, 12231),
(12249, 12236),
(12248, 12241),
(12250, 12242),
(12255, 12259),
(12278, 12306),
(12464, 12285),
(12323, 12324),
(12416, 12448),
(12417, 12449),
(12418, 12450),
(12460, 12461),
(12479, 12480),
(12491, 12492),
(12854, 12895),
(12858, 12926),
(12860, 12927),
(12862, 13060),
(12870, 12882),
(12872, 12928),
(12885, 12929),
(13186, 13185),
(13222, 13223),
(13188, 13189),
(13226, 13227),
(13395, 13236),
(13387, 13259),
(13388, 13262),
(13389, 13263),
(13390, 13271),
(13391, 13275),
(13392, 13282),
(13284, 13301),
(13393, 13304),
(13394, 13305),
(13332, 13306),
(13334, 13307),
(13309, 13310),
(13337, 13312),
(13338, 13316),
(13339, 13328),
(13335, 13329),
(13336, 13330),
(13341, 13340),
(13396, 13348),
(13397, 13349),
(13398, 13359),
(13399, 13360),
(13400, 13361),
(13401, 13362),
(13402, 13363),
(13403, 13364),
(13380, 13373),
(13381, 13374),
(13382, 13376),
(13383, 13379),
(13408, 13409),
(13410, 13411),
(13415, 13416),
(13418, 13419),
(13480, 13479),
(13484, 13483),
(13633, 13634),
(13625, 13677),
(13671, 13676),
(13672, 13678),
(13679, 13680),
(13686, 13687),
(13828, 13829),
(13835, 13838),
(13837, 13839),
(14022, 14036),
(14023, 14037),
(14024, 14040),
(14028, 14041),
(14030, 14044),
(14033, 14043),
(14035, 14047),
(14048, 14061),
(14051, 14062),
(14053, 14059),
(14054, 14060),
(14055, 14058),
(14096, 14142),
(14111, 14100),
(20438, 24556),
(20439, 24451),
(24498, 24507),
(24499, 24511),
(24500, 24802),
(24510, 24506),
(24535, 24563),
(24656, 24541),
(24657, 24576),
(24683, 24682),
(24710, 24712),
(24711, 24713),
(24655, 24536),
(24804, 24805),
(24848, 24850),
(25055, 25092),
(25180, 25181),
(25253, 25228),
(25282, 25254),
(25290, 25288),
(25414, 25293);
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_06_00_world_conditions.sql 
-- -------------------------------------------------------- 
-- Delete condition that can cause some damage reduction "spikes" leading to leaking damage,
-- or in simple language some delay can cause not applying.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56438;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_07_00_world_conditions.sql 
-- -------------------------------------------------------- 
-- Delete condition that is already covered by spell attribute
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=58846;
 
 
-- -------------------------------------------------------- 
-- ####### 2013_03_07_01_world_misc.sql 
-- -------------------------------------------------------- 
SET @CGUID := 86429;
SET @OGUID := 24440;

UPDATE `gameobject` SET `spawntimesecs`=120, `animprogress`=255 WHERE `id`=188464;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+21;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+00, 188464, 571, 1, 1, 4781.308, -4865.809, 26.53011, 0.8377575, 0, 0, 0.4067364, 0.9135455, 120, 255, 1),
(@OGUID+01, 188464, 571, 1, 1, 4753.355, -4830.314, 26.04058, 5.532695, 0, 0, -0.3665009, 0.9304177, 120, 255, 1),
(@OGUID+02, 188464, 571, 1, 1, 4758.613, -4824.151, 25.96103, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1),
(@OGUID+03, 188464, 571, 1, 1, 4764.173, -4818.161, 25.88273, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1),
(@OGUID+04, 188464, 571, 1, 1, 4785.614, -4793.256, 26.12138, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1),
(@OGUID+05, 188464, 571, 1, 1, 4848.127, -4827.709, 25.96146, 2.408554, 0, 0, 0.9335804, 0.358368, 120, 255, 1),
(@OGUID+06, 188464, 571, 1, 1, 4790.917, -4787.033, 26.19655, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1),
(@OGUID+07, 188464, 571, 1, 1, 4796.205, -4780.994, 26.19833, 5.567601, 0, 0, -0.3502073, 0.9366722, 120, 255, 1),
(@OGUID+08, 188464, 571, 1, 1, 4829.167, -4799.646, 25.96292, 3.961899, 0, 0, -0.9170599, 0.3987495, 120, 255, 1),
(@OGUID+09, 188464, 571, 1, 1, 4775.307, -4860.43, 26.52502, 0.8377575, 0, 0,  0.4067364, 0.9135455, 120, 255, 1),
(@OGUID+10, 188499, 571, 1, 1, 4783.06, -4870.042, 26.63436, 5.567601, 0, 0, -0.3502073, 0.9366722, 300, 255, 1),
(@OGUID+11, 188499, 571, 1, 1, 4776.997, -4864.7, 26.76528, 5.67232, 0, 0, -0.3007059, 0.9537169, 300, 255, 1),
(@OGUID+12, 188499, 571, 1, 1, 4804.492, -4880.459, 25.95016, 0.9250238, 0, 0, 0.4461975, 0.8949345, 300, 255, 1),
(@OGUID+13, 188499, 571, 1, 1, 4754.443, -4825.909, 26.1786, 4.01426, 0, 0, -0.9063072, 0.4226195, 300, 255, 1),
(@OGUID+14, 188499, 571, 1, 1, 4797.431, -4776.76, 26.2836, 3.979355, 0, 0, -0.9135447, 0.4067384, 300, 255, 1),
(@OGUID+15, 188499, 571, 1, 1, 4792.048, -4782.723, 26.41635, 4.049168, 0, 0, -0.8987932, 0.4383728, 300, 255, 1),
(@OGUID+16, 188499, 571, 1, 1, 4806.47, -4775.945, 26.30708, 2.373644, 0, 0,  0.9271832, 0.3746083, 300, 255, 1),
(@OGUID+17, 188499, 571, 1, 1, 4809.335, -4874.765, 26.06562, 0.8377575, 0, 0, 0.4067364, 0.9135455, 300, 255, 1),
(@OGUID+18, 188499, 571, 1, 1, 4819.935, -4862.525, 26.05573, 0.8203033, 0, 0,  0.3987484, 0.9170604, 300, 255, 1),
(@OGUID+19, 188499, 571, 1, 1, 4786.889, -4788.973, 26.3336, 4.049168, 0, 0, -0.8987932, 0.4383728, 300, 255, 1),
(@OGUID+20, 188499, 571, 1, 1, 4852.343, -4826.055, 26.06636, 0.8552105, 0, 0, 0.4146929, 0.9099615, 300, 255, 1),
(@OGUID+21, 188499, 571, 1, 1, 4845.617, -4811.589, 26.17898, 2.391098, 0, 0, 0.9304171, 0.3665025, 300, 255, 1);

DELETE FROM `creature` WHERE `id` IN (26811,26812);
DELETE FROM `creature` WHERE `guid` IN (113208,113209);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+00, 26811, 571, 1, 1, 4733.245, -4857.637, 26.4931, 2.617994, 300, 5, 1),
(@CGUID+01, 26812, 571, 1, 1, 4796.549, -4846.317, 25.50747, 4.249843, 300, 5, 1),
(@CGUID+02, 26811, 571, 1, 1, 4766.232, -4820.333, 25.69218, 2.329675, 300, 5, 1),
(@CGUID+03, 26811, 571, 1, 1, 4823.353, -4839.751, 25.7641, 1.145746, 300, 5, 1),
(@CGUID+04, 26812, 571, 1, 1, 4797.967, -4783.413, 25.99624, 4.269053, 300, 5, 1),
(@CGUID+05, 26812, 571, 1, 1, 4759.746, -4835.385, 25.90628, 3.535823, 300, 5, 1),
(@CGUID+06, 26812, 571, 1, 1, 4782.295, -4858.29, 26.10907, 4.433136, 300, 5, 1),
(@CGUID+07, 26811, 571, 1, 1, 4795.084, -4869.773, 25.85341, 3.63068, 300, 5, 1),
(@CGUID+08, 26812, 571, 1, 1, 4758.876, -4857.517, 25.89942, 3.830702, 300, 5, 1),
(@CGUID+09, 26811, 571, 1, 1, 4809.717, -4858.999, 25.77467, 4.760717, 300, 5, 1),
(@CGUID+10, 26811, 571, 1, 1, 4801.294, -4802.357, 25.66738, 5.655887, 300, 5, 1),
(@CGUID+11, 26812, 571, 1, 1, 4831.968, -4810.053, 25.6752, 4.12599, 300, 5, 1),
(@CGUID+12, 26811, 571, 1, 1, 4845.415, -4821.253, 25.65237, 4.234284, 300, 5, 1),
(@CGUID+13, 26806, 571, 1, 1, 4668.349, -4849.098, 35.56351, 3.106686, 300, 0, 0),
(@CGUID+14, 26806, 571, 1, 1, 4669.264, -4869.123, 35.5635, 3.263766, 300, 0, 0);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (26591,26811,26812);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=188464;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26591,26811,26812) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=188464 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26812*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26591,0,0,0,38,0,100,0,0,1,0,0,11,47798,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Pacer Bunny - Drak Theron Exterior - On data set 0 1 - Spellcast Summon Mummy Remnants'),
(26811,0,0,1,8,0,100,0,47778,0,0,0,11,47795,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Spellcast Cold Cleanse'),
(26811,0,1,2,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Set event phase 1'),
(26811,0,2,3,61,0,100,0,0,0,0,0,18,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Set unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE'),
(26811,0,3,4,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Set run'),
(26811,0,4,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Stop combat movement'),
(26811,0,5,6,23,1,100,1,47795,0,0,0,69,1,0,0,0,0,0,20,188464,40,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellfade Cold Cleanse - Move to position Ancient Troll Mummy'),
(26811,0,6,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellfade Cold Cleanse - Say line'),
(26811,0,7,0,34,0,100,0,0,1,0,0,80,26812*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On movement inform - Run script'),
(26811,0,8,0,11,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spawn - Remove unit_field_bytes1 (sleep)'),
(26812,0,0,1,8,0,100,0,47778,0,0,0,11,47795,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Spellcast Cold Cleanse'),
(26812,0,1,2,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Set event phase 1'),
(26812,0,2,3,61,0,100,0,0,0,0,0,18,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Set unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE'),
(26812,0,3,4,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Set run'),
(26812,0,4,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Stop combat movement'),
(26812,0,5,6,23,1,100,1,47795,0,0,0,69,1,0,0,0,0,0,20,188464,40,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellfade Cold Cleanse - Move to position Ancient Troll Mummy'),
(26812,0,6,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellfade Cold Cleanse - Say line'),
(26812,0,7,0,34,0,100,0,0,1,0,0,80,26812*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On movement inform - Run script'),
(26812,0,8,0,11,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spawn - Remove unit_field_bytes1 (sleep)'),

(188464,1,0,0,38,0,100,0,0,1,0,0,99,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Troll Mummy - On data set 0 1 - Change state (deactivated)'),
(188464,1,1,0,70,0,100,0,2,0,0,0,70,120,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Troll Mummy - On state changed - Despawn'),

(26812*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,26591,5,0,0,0,0,0, 'Ancient Drakkari script - Turn to Pacer Bunny - Drak Theron Exterior'),
(26812*100,9,1,0,0,0,100,0,50,50,0,0,90,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari script - Set unit_field_bytes1 (sleep)'),
(26812*100,9,2,0,0,0,100,0,2000,2000,0,0,19,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari script - Remove unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE'),
(26812*100,9,3,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,26591,5,0,0,0,0,0, 'Ancient Drakkari script - Set data 0 1 Pacer Bunny - Drak Theron Exterior'),
(26812*100,9,4,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,20,188464,5,0,0,0,0,0, 'Ancient Drakkari script - Set data 0 1 Ancient Troll Mummy'),
(26812*100,9,5,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari script - Despawn');

DELETE FROM `creature_text` WHERE `entry` IN (26811,26812);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26811,0,0,'I could sleep forever, mon....',12,0,100,0,0,0,'Ancient Drakkari Warmonger'),
(26811,0,1,'Finally, I can be restin''...',12,0,100,0,0,0,'Ancient Drakkari Warmonger'),
(26811,0,2,'Free at last, mon.',12,0,100,0,0,0,'Ancient Drakkari Warmonger'),
(26811,0,3,'Where''s mah mummy?',12,0,100,0,0,0,'Ancient Drakkari Warmonger'),
(26812,0,0,'I could sleep forever, mon....',12,0,100,0,0,0,'Ancient Drakkari Soothsayer'),
(26812,0,1,'Finally, I can be restin''...',12,0,100,0,0,0,'Ancient Drakkari Soothsayer'),
(26812,0,2,'Free at last, mon.',12,0,100,0,0,0,'Ancient Drakkari Soothsayer'),
(26812,0,3,'Where''s mah mummy?',12,0,100,0,0,0,'Ancient Drakkari Soothsayer');
 
 
-- -------------------------------------------------------- 
-- ####### _MERGED.sql 
-- -------------------------------------------------------- 
 
 
