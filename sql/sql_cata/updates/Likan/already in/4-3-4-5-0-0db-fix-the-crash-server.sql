DELETE FROM `gameobject` WHERE `id`=2404120;
DELETE FROM `gameobject` WHERE `id`=3000005;
--Fix faction in stealth, which beat players
UPDATE `creature_template` SET `faction_A`='35' WHERE `entry`='55389';
UPDATE `creature_template` SET `faction_H`='35' WHERE `entry`='55389';
UPDATE `creature_template` SET `faction_A`='35' WHERE `entry`='55384';
UPDATE `creature_template` SET `faction_H`='35' WHERE `entry`='55384';
UPDATE `creature_template` SET `faction_A`='35' WHERE `entry`='55385';
UPDATE `creature_template` SET `faction_H`='35' WHERE `entry`='55385';
--loot 55559
UPDATE `creature_template` SET `lootid`='55559' WHERE `entry`=55559;
DELETE FROM `creature_loot_template` WHERE (`entry`=55559);
INSERT INTO `creature_loot_template` VALUES
(55559, 60485, 1, 1, 0, 2, 4),
(55559, 60486, 1, 1, 0, 2, 4);
--Can be beaten 54590
UPDATE `creature_template` SET `unit_flags`='32832' WHERE `entry`='54590';
--Loot 54590
UPDATE `creature_template` SET `lootid`='54590' WHERE `entry`=54590;
DELETE FROM `creature_loot_template` WHERE (`entry`=54590);
INSERT INTO `creature_loot_template` VALUES
(54590, 77957, 1, 1, 0, 1, 1),
(54590, 72853, 1, 1, 0, 1, 1),
(54590, 72851, 1, 1, 0, 1, 1),
(54590, 76150, 1, 1, 0, 1, 1),
(54590, 72850, 1, 1, 0, 1, 1);
UPDATE `creature_template` SET `unit_flags`='64' WHERE `entry`='40311';
UPDATE `creature_template` SET `unit_flags`='64' WHERE `entry`='40787';
--3098
UPDATE `creature_template` SET `npcflag`='0' WHERE `entry`='3098';
UPDATE `creature_template` SET `unit_flags`='64' WHERE `entry`='3098';
--quest 5441 (3)
UPDATE `creature_template` SET `npcflag`='0' WHERE `entry`='10556';
--quest 25167
UPDATE `creature_template` SET `InhabitType`='2' WHERE `entry`='39251';
--quest 24932
UPDATE `creature_template` SET `gossip_menu_id`='39270' WHERE `entry`='39270';
UPDATE `creature_template` SET `npcflag`='1' WHERE `entry`='39270';
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='39270';
insert into `gossip_menu` (`entry`, `text_id`) values('39270','0');
insert into `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) values('39270','0','0','Help','1','1','0','0','0','0',NULL);
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39270','0','0','1','62','0','100','0','39270','0','0','0','33','39270','0','0','0','0','0','7','0','0','0','0','0','0','0','Smart Script');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39270','0','1','2','61','0','100','0','0','0','0','0','46','20','0','0','0','0','0','0','0','0','0','0','0','0','0','Smart Script');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39270','0','2','0','61','0','100','0','0','0','0','0','23','1','0','0','0','0','0','1','0','0','0','0','0','0','0','Smart Script');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39270','0','3','0','60','1','100','0','1500','1500','500000','500000','44','2','0','0','0','0','0','1','0','0','0','0','0','0','0','Smart Script');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39270','0','4','0','60','1','100','0','3000','3000','500000','500000','37','0','0','0','0','0','0','1','0','0','0','0','0','0','0','Smart Script');
--quest 25188
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='3193';
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('3193','0','0','0','20','0','100','0','25193','0','0','0','33','39333','0','0','0','0','0','7','0','0','0','0','0','0','0','Smart Script');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='39324';
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39324','0','0','0','20','0','100','0','25195','0','0','0','33','39334','0','0','0','0','0','7','0','0','0','0','0','0','0','Smart Script');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='39326';
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39326','0','0','0','20','0','100','0','25190','0','0','0','33','39332','0','0','0','0','0','7','0','0','0','0','0','0','0','Smart Script');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='39325';
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39325','0','0','0','20','0','100','0','25189','0','0','0','33','39331','0','0','0','0','0','7','0','0','0','0','0','0','0','Smart Script');
--quest 25194
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='39337';
INSERT INTO `smart_scripts` VALUES (39337, 0, 0, 1, 4, 0, 100, 0, 0, 0, 0, 0, 33, 39336, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Smart Script");
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39337','0','1','2','61','0','100','0','0','0','0','0','46','120','0','0','0','0','0','0','0','0','0','0','0','0','0','Smart Script');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39337','0','2','0','61','0','100','0','0','0','0','0','23','1','0','0','0','0','0','1','0','0','0','0','0','0','0','Smart Script');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39337','0','3','0','60','1','100','0','1500','1500','500000','500000','44','2','0','0','0','0','0','1','0','0','0','0','0','0','0','Smart Script');
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('39337','0','4','0','60','1','100','0','3000','3000','500000','500000','37','0','0','0','0','0','0','1','0','0','0','0','0','0','0','Smart Script');
--correction
UPDATE `creature_template` SET `MovementType`='2' WHERE `entry`='39351';
UPDATE `quest_template` SET `flags`='8' WHERE `id`=25236;
UPDATE `creature_template` SET `exp`='0', `Health_mod`='2', `npcflag`='1', `unit_flags`='4', `faction_A`='7', `faction_H`='7' WHERE `entry`=39464;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=39464 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(39464, 0, 0, 0, 1, 0, 100, 0, 4000, 7000, 22000, 25000, 11, 73958, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cast Lightning Discharge"),
(39464, 0, 1, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 39464, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""),
(39464, 0, 2, 0, 64, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "");
-- Invisible Stlaker
UPDATE `creature_template` SET `faction_A`='35',`faction_H`='35' WHERE `entry`='54522';
UPDATE `creature_template` SET `faction_A`='35',`faction_H`='35' WHERE `entry`='54599';
 
--Anvil
UPDATE `gameobject_template` SET `data0`='1' WHERE `entry`='201415';
UPDATE `gameobject_template` SET `data0`='1' WHERE `entry`='201416';
