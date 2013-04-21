--[[
	GUNSHIP PVP BATTLE
	
		-	Description:
			
			When the battle starts you have to get a rocket pack
			from the goblin on your ship. You have to use the 
			rocket pack to get to the other ship. On that ship is a 
			flag of your enemy, you have to take that flag to your 
			commander. Once there you can choose to enable your guns,
			or disable the enemy guns. The goal of the battle is to
			destroy the enemy ship. Guns are activated only for a 
			limited time and when disabled also for a limited time.
			So choose wisely.
	
		-	This battle has/is:
			
			o	Worldstates
			o	Vehicles
			o	Queue system
			o	PvP messages
			o	Rocket pack
			o	Flag system
			o	Phased
					
]]--

--[[**********************************************************************

	CONFIG:
	
		P_COUNT:
		    P_COUNT defines the amount of players required to start
		    a battle. Standart: 5.
			
		SHIP_HP:
		    SHIP_HP defines the amount of health a ship has. When its
		    health reaches 0 the battle ends. Standart: 300000
			
		GUN_ENABLE_TIME:
		    GUN_ENABLE_TIME defines the amount of seconds a gun is
		    activated. Standart: 15
			
		GUN_DISABLE_TIME:
		    GUN_DISABLE_TIME defines the amount of seconds a gun is
		    disabled. Standart: 15	
			
		FLAG_RESPAWN_TIME:
		    FLAG_RESPAWN_TIME defines the amount of seconds it takes
		    to respawn the flag after it is captured. Standart: 15
		
		RECRUITMENT_ALLIANCE_STATEMENT:
		    RECRUITMENT_ALLIANCE_STATEMENT defines the message the
		    recruitment npc will say after someone joins.
			
		RECRUITMENT_HORDE_STATEMENT:
		    RECRUITMENT_HORDE_STATEMENT defines the message the
		    recruitment npc will say after someone joins.
			
		REWARD_ID
		    REWARD_ID defines the item that will be given upon a
		    victory. WARNING if you don't want any items to be given
		    then set this variable to false.
			
		REWARD_AMOUNT
		    REWARD_AMOUNT defines the amount of the item that will
		    be given upon a victory. WARNING if you don't want any 
		    items to be given then set this variable to false.

]]--**********************************************************************
local P_COUNT                           = 1 	-- How many people each team.

local SHIP_HP                           = 300000

local GUN_ENABLE_TIME                   = 15
local GUN_DISABLE_TIME                  = 15

local FLAG_RESPAWN_TIME					= 15

local RECRUITMENT_ALLIANCE_STATEMENT    = "We need more alliance for the battle to start."
local RECRUITMENT_HORDE_STATEMENT       = "We need more horde for the battle to start."

local REWARD_ID                         = false
local REWARD_AMOUNT                     = false
--************************************************************************** 
--                                                                         *
--             IT IS NOT RECOMMENED TO EDIT BELOW THIS LINE UNLESS         *
--             YOU KNOW WHAT YOU'RE DOING.                                 *
--                                                                         *
--**************************************************************************

-- Table declaration. 
local phase                             = {}
local q_plr                             = {}
local b_tbl                             = {}

-- Unit field flags.
local OBJECT_END                        = 0x0006
local UNIT_FIELD_FLAGS                  = OBJECT_END + 0x0034
local UNIT_FLAG_NOT_ATTACKABLE          = 0x00000002

-- Flag status
local FLAG_STATUS_SPAWNED               = 1
local FLAG_STATUS_NOT_SPAWNED           = 2
local FLAG_STATUS_PICKED                = 3

-- Unit/Game object entry id's
local GUN_ID                            = 36838
local ALLIANCE_COMMANDER                = 38607
local HORDE_COMMANDER                   = 25749
local EVENT_STARTER                     = 4251 -- A shitty goblin with rockets.
local A_FLAG                            = 179785
local H_FLAG                            = 179786
local A_SHIP                            = 195121
local H_SHIP                            = 195276
local ROCKET                            = 37184

-- Aura's
local A_FLAG_AURA                       = 23335	
local H_FLAG_AURA                       = 23333		
local FREEZE_AURA                       = 62766	

-- Unit/Game object coordinates.
local FLAG_COORDS_ALLIANCE              = {6211, -4630, 928.5, 0}
local FLAG_COORDS_HORDE                 = {6315, -4722, 940.5, 0}
local COMMANDER_COORDS_ALLIANCE         = {6315, -4630, 930.3, 3.1}
local COMMANDER_COORDS_HORDE            = {6322, -4722, 922.1, 3.16}
local ALLIANCE_CANNON_ONE               = {6270, -4652, 926.8, 4.66}
local ALLIANCE_CANNON_TWO               = {6248, -4652, 926.8, 4.68}
local HORDE_CANNON_ONE                  = {6288, -4695, 927.5, 1.62}
local HORDE_CANNON_TWO                  = {6268, -4694, 926.2, 1.61}
local ALLIANCE_SHIP_COORDS              = {6274, -4630, 905, 0}
local HORDE_SHIP_COORDS                 = {6274, -4722, 892, 0}
local ROCKET_PACK_ALLIANCE              = {6257, -4630.1, 925.8, 3.14}
local ROCKET_PACK_HORDE                 = {6287, -4711, 926.7, 3.07}

-- Player pawn points.
local PLR_SPAWN_POINT_A                 = {1, 6250, -4630, 925.8, 4.72}
local PLR_SPAWN_POINT_H                 = {1, 6276, -4723, 926.3, 1.64}

-- Npc flags
local NPC_NIL_FLAGS                     = 0
local NPC_GOSSIP_FLAGS                  = 1
local NPC_VEHICLE_FLAGS                 = 16777216

-- Spawn functions.
function SpawnGO(unit, id, tbl, f)
	local x, y, z, o = unpack(tbl)
	return unit:SpawnGameObject(id, x, y, z, o, 0, 100, f);
end
function SpawnNPC(unit, id, tbl, fac, f)
	local x, y, z, o = unpack(tbl)
	return unit:SpawnCreature(id, x, y, z, o, fac, 0, _, _, _, f);
end	

function SendPvPMessage(obj, msg)
	local unit
	if (obj:IsCreature()) then
		unit = obj
	elseif not (obj:IsCreature()) then	
		unit = b_tbl[phase.get(obj)].commander["a"]
	end	
	unit:SendChatMessage(42, 0, msg)
end	

--[[

	Gunship Queue

]]--

function queue_player(plr)
	for _, v in pairs(q_plr) do
		if (tostring(v) == tostring(plr)) then return; end
	end
	table.insert(q_plr, plr)
end	

function unqueue_player(plr)
	for k, v in pairs(q_plr) do
		if (tostring(v) == tostring(plr)) then q_plr[k] = nil; end
	end
end	

function queue_get_faction_count(faction, bool)
	local tbl = {}
	if (faction == "alliance") then
		for _, v in pairs(q_plr) do
			if (v:GetTeam() == 0) then table.insert(tbl, v) end
		end
		if (bool) then return tbl; end
		return #tbl;
	elseif (faction == "horde") then
		for _, v in pairs(q_plr) do
			if (v:GetTeam() == 1) then table.insert(tbl, v) end
		end
		if (bool) then return tbl; end
		return #tbl;
	end
	return #q_tbl;
end	

function is_in_queue(plr)
	for _, v in pairs(q_plr) do
		if (tostring(v) == tostring(plr)) then return true; end
	end
	return false;
end

function queue_debug()
	if not (q_tbl) then return; end
	for k, v in pairs(q_tbl) do
		if not (v:IsInWorld()) then q_tbl[k] = nil; end
	end
end

function is_queue_ready(pUnit)
	queue_debug() -- To be sure we don't get offline players.
	if (queue_get_faction_count("alliance") >= P_COUNT) then
		if (queue_get_faction_count("horde") >= P_COUNT) then
			local a_players = queue_get_faction_count("alliance", true)
			local h_players = queue_get_faction_count("horde", true)
			start_battle(a_players, h_players)
		elseif not (queue_get_faction_count("horde") >= P_COUNT) then
			pUnit:SendChatMessage(12, 0, RECRUITMENT_HORDE_STATEMENT)
		end
	elseif not (queue_get_faction_count("alliance") >= P_COUNT) then
		pUnit:SendChatMessage(12, 0, RECRUITMENT_ALLIANCE_STATEMENT)
		if not (queue_get_faction_count("horde") >= P_COUNT) then
			pUnit:SendChatMessage(12, 0, RECRUITMENT_HORDE_STATEMENT)
		end
	end
end	

function remove_queue_players(a, h)
	for k, v in pairs(a) do
		for key, val in pairs(q_plr) do
			if (tostring(v) == tostring(val)) then
				q_plr[key] = nil; break;
			end
		end
	end	
	for k, v in pairs(h) do
		for key, val in pairs(q_plr) do
			if (tostring(v) == tostring(val)) then
				q_plr[key] = nil; break;
			end
		end
	end	
end	

RegisterTimedEvent("queue_debug", 5000, 0)

--[[

	Gunship gossip

]]--

function event_starter(pUnit, event, plr, _, intid)	
	if (event == 1) then
		pUnit:GossipCreateMenu(3000, plr, 0)
		if not (is_in_queue(plr)) then
			pUnit:GossipMenuAddItem(3, "I'm ready to fight.", 1, 0)
		elseif (is_in_queue(plr)) then
			pUnit:GossipMenuAddItem(3, "On second thought, I'm not ready yet.", 2, 0)
		end	
		pUnit:GossipMenuAddItem(3, "Nevermind.", 3, 0)
		pUnit:GossipSendMenu(plr)
	elseif (event == 2) then
		if (intid == 1) then
			queue_player(plr)
			is_queue_ready(pUnit)
		elseif (intid == 2) then
			unqueue_player(plr)
		elseif (intid == 3) then
			plr:GossipComplete()
		end	
		plr:GossipComplete()
	end
end	

RegisterUnitGossipEvent(EVENT_STARTER, 1, "event_starter")
RegisterUnitGossipEvent(EVENT_STARTER, 2, "event_starter")

--[[

	Preparing/starting battle.

]]--

function start_battle(a2, h2)
	local f = get_available_phase(b_tbl)
	b_tbl[f] = {
		-- players
		alliance 	= a2,
		horde 		= h2,
		
		-- flag
		flag 		= {a,h},
		flag_holder	= {a,h},
		flag_status	= {a,h},
		flag_coords	= {a={x,y,z,o},h={x,y,z,o}},
		
		-- ship
		ships 		= {a,h},
		ship_hp		= {a,h},
		
		-- npc's
		commander	= {a,h},
		rocket 		= {a,h},
		rock_coords	= {a={x,y,z,o},h={x,y,z,o}},
		c_coords 	= {a={x,y,z,o},h={x,y,z,o}},
		gun        	= {a={},h={}},
		gun_coords	= {a={[1]={x,y,z,o},[2]={x,y,z,o}},h={[1]={x,y,z,o},[2]={x,y,z,o}}},
	};
	
	-- Spawning the ships.
	local p = reverse_phase(f)
	b_tbl[f].ships["a"] = SpawnGO(a2[1], A_SHIP, ALLIANCE_SHIP_COORDS, p)
	b_tbl[f].ships["h"] = SpawnGO(a2[1], H_SHIP, HORDE_SHIP_COORDS, p)
	
	-- Preparing battle.
	for _, v in pairs(a2) do
		v:Teleport(unpack(PLR_SPAWN_POINT_A)) -- still need coords
		phase.set(v, f)
	end
	for _, v in pairs(h2) do
		v:Teleport(unpack(PLR_SPAWN_POINT_H)) -- still need coords
		phase.set(v, f)
	end

	-- Defining coords.
	b_tbl[f].flag_coords["a"] 	= FLAG_COORDS_ALLIANCE
	b_tbl[f].flag_coords["h"] 	= FLAG_COORDS_HORDE
	b_tbl[f].c_coords["a"] 		= COMMANDER_COORDS_ALLIANCE
	b_tbl[f].c_coords["h"] 		= COMMANDER_COORDS_HORDE
	b_tbl[f].gun_coords["a"][1]	= ALLIANCE_CANNON_ONE
	b_tbl[f].gun_coords["a"][2]	= ALLIANCE_CANNON_TWO
	b_tbl[f].gun_coords["h"][1]	= HORDE_CANNON_ONE
	b_tbl[f].gun_coords["h"][2]	= HORDE_CANNON_TWO
	b_tbl[f].rock_coords["a"]	= ROCKET_PACK_ALLIANCE
	b_tbl[f].rock_coords["h"]	= ROCKET_PACK_HORDE
	
	-- Spawning the commanders.
	b_tbl[f].commander["a"] = SpawnNPC(a2[1], ALLIANCE_COMMANDER, b_tbl[f].c_coords["a"], 35, p)
	b_tbl[f].commander["h"] = SpawnNPC(a2[1], HORDE_COMMANDER, b_tbl[f].c_coords["h"], 35, p)
	
	-- Removing players from queue
	remove_queue_players(a2, h2)
end	

function b_tbl_debug()
	if not (b_tbl) then return; end
	for f, v in pairs(b_tbl) do
		for k, val in pairs(v.alliance) do
			if not (GetPlayer(val:GetName())) then
				b_tbl[f].alliance[k] = nil;
				if (#b_tbl[f].alliance == 0) then
					stop_battle(f, "horde")
				end	
			end
		end
		for k, val in pairs(v.horde) do
			if not (GetPlayer(val:GetName())) then
				b_tbl[f].horde[k] = nil;
				if (#b_tbl[f].horde == 0) then
					stop_battle(f, "alliance")
				end	
			end
		end
	end
end

function falling_check()
	if not (b_tbl) then return; end
	for _, v in pairs(return_bg_plrs()) do
		if (v:GetZ() < 900) then
			if (v:GetTeam() == 0) then
				v:Teleport(unpack(PLR_SPAWN_POINT_A))
			elseif (v:GetTeam() == 1) then
				v:Teleport(unpack(PLR_SPAWN_POINT_H))
			end	
			send_current_packet(v)
		end
	end
end	

RegisterTimedEvent("falling_check", 1000, 0)
RegisterTimedEvent("b_tbl_debug", 1000, 0)

--[[

	On battle end.

]]--

function stop_battle(phase, preset_winner)
	local tbl = b_tbl[phase]

	-- Broadcasting winner.
	local winner
	if (preset_winner) then
		winner = preset_winner;
	elseif not (preset_winner) then	
		winner = tbl.ship_hp["a"] <= 0 and "horde" or "alliance";
	end	
	SendPvPMessage(tbl.commander["a"], "the "..winner.." have won this battle.")

	-- Removing events.
	tbl.commander["h"]:RemoveEvents()
	--remove_packet(tbl)

	-- Deleting npc's / game objects
	for i=1, 2 do
		tbl.gun["a"][i]:EjectAllVehiclePassengers()
		tbl.gun["h"][i]:EjectAllVehiclePassengers()
		tbl.gun["a"][i]:Despawn(0, 0)
		tbl.gun["h"][i]:Despawn(0, 0)
	end	
	tbl.commander["a"]:Despawn(0, 0)
	tbl.commander["h"]:Despawn(0, 0)
	tbl.ships["a"]:Despawn(0, 0)
	tbl.ships["h"]:Despawn(0, 0)
	tbl.flag["a"]:Despawn(0, 0)
	tbl.flag["h"]:Despawn(0, 0)
	tbl.rocket["a"]:Despawn(0, 0)
	tbl.rocket["h"]:Despawn(0, 0)

	-- Creating a copy of the players.
	local w_tbl = {w={}, l={}}
	for _, v in pairs(tbl[winner]) do
		table.insert(w_tbl["w"], v)
	end
	for _, v in pairs(tbl[winner=="alliance" and "horde" or "alliance"]) do
		table.insert(w_tbl["l"], v)
	end	
	end_battle(w_tbl)
	
	-- Cleaning table.
	for k, v in pairs(tbl) do
		tbl[k] = {};
	end
	tbl = nil;
end

function end_battle(tbl)
	if (REWARD_ID) then
		for _, v in pairs(tbl["w"]) do
			v:AddItem(REWARD_ID, REWARD_AMOUNT)
		end
	end
	for _, v in pairs(tbl["w"]) do
		v:RemoveItem(49278)
		v:PhaseSet(1)
		v:Teleport(0, -13244.3, 198.506, 31)
	end	
	for _, v in pairs(tbl["l"]) do
		v:RemoveItem(49278)
		v:PhaseSet(1)
		v:Teleport(0, -13244.3, 198.506, 31)
	end	
end
	
--[[

	Commanders

]]--

function commander_on_gossip(pUnit, event, plr, _, intid)
	local f = plr:GetTeam() == 0 and "a" or "h"
	local aura = f == "h" and A_FLAG_AURA or H_FLAG_AURA
	if not (plr:HasAura(aura)) then return; end
	if (pUnit:GetEntry() == HORDE_COMMANDER and f == "a") then return; end
	if (pUnit:GetEntry() == ALLIANCE_COMMANDER and f == "h") then return; end
	pUnit:GossipCreateMenu(3000, plr, 0)
	if (event == 1) then
		pUnit:GossipMenuAddItem(3, "I want to enable my guns.", 1, 0)
		pUnit:GossipMenuAddItem(3, "I want to disable the enemy guns.", 2, 0)
		pUnit:GossipSendMenu(plr)
	elseif (event == 2) then
		if (intid == 1) then
			enable_guns(pUnit, f, plr)
		elseif (intid == 2) then
			freeze_guns(pUnit, f == "h" and "a" or "h")
		end
		remove_flag(plr)
		plr:GossipComplete()	
	end
end	

function commander_on_load(pUnit)
	-- Important settings.
	pUnit:SetFaction(35)
	pUnit:SetNPCFlags(1)
	
	-- Spawning needed npc's.
	local f	        = pUnit:GetPhase()
	local tbl       = b_tbl[phase.get(pUnit)]
	tbl.flag["a"] 	= SpawnGO(pUnit, A_FLAG, tbl.flag_coords["a"], f)
	tbl.flag["h"] 	= SpawnGO(pUnit, H_FLAG, tbl.flag_coords["h"], f)
	tbl.gun["a"][1]	= SpawnNPC(pUnit, GUN_ID, tbl.gun_coords["a"][1], 1, f)
	tbl.gun["a"][2]	= SpawnNPC(pUnit, GUN_ID, tbl.gun_coords["a"][2], 1, f)
	tbl.gun["h"][1]	= SpawnNPC(pUnit, GUN_ID, tbl.gun_coords["h"][1], 2, f)
	tbl.gun["h"][2]	= SpawnNPC(pUnit, GUN_ID, tbl.gun_coords["h"][2], 2, f)
	tbl.rocket["a"] = SpawnNPC(pUnit, ROCKET, tbl.rock_coords["a"], 35, f)
	tbl.rocket["h"] = SpawnNPC(pUnit, ROCKET, tbl.rock_coords["h"], 35, f)
	
	-- Last variables that need to be assigned.
	tbl.flag_status["a"] 	= FLAG_STATUS_SPAWNED
	tbl.flag_status["h"]	= FLAG_STATUS_SPAWNED
	tbl.ship_hp["a"]        = SHIP_HP
	tbl.ship_hp["h"]        = SHIP_HP
	
	-- Events that need to be registered.
	pUnit:RegisterEvent("flag_handler", 1000, 0)
	pUnit:RegisterEvent("deal_ship_damage", 1000, 0)
	
	-- Sending the worldstate.
	create_packet(pUnit)
end	

function commander_on_load_flags(pUnit)
	pUnit:SetFaction(35)
	pUnit:SetNPCFlags(1)
end

RegisterUnitEvent(HORDE_COMMANDER, 18, "commander_on_load")
RegisterUnitEvent(ALLIANCE_COMMANDER, 18, "commander_on_load_flags")

RegisterUnitGossipEvent(ALLIANCE_COMMANDER, 1, "commander_on_gossip")
RegisterUnitGossipEvent(ALLIANCE_COMMANDER, 2, "commander_on_gossip")
RegisterUnitGossipEvent(HORDE_COMMANDER, 1, "commander_on_gossip")
RegisterUnitGossipEvent(HORDE_COMMANDER, 2, "commander_on_gossip")
	
--[[

	Guns

]]--

function gun_ai(pUnit)
	pUnit:Root()
	pUnit:SetNPCFlags(1)
	pUnit:SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE)
	pUnit:CastSpell(1908)	
end	

RegisterUnitEvent(GUN_ID, 18, "gun_ai")
	
function enable_guns(pUnit, f, plr)
	local tbl = b_tbl[phase.get(pUnit)]
	if (tbl.gun[f][1]:HasAura(FREEZE_AURA)) then
		return plr:SendBroadcastMessage("You can't enable your guns when they are frozen.");
	end	
	tbl.gun[f][1]:SetNPCFlags(NPC_VEHICLE_FLAGS)
	tbl.gun[f][2]:SetNPCFlags(NPC_VEHICLE_FLAGS)
	if (f == "a") then
		SendPvPMessage(pUnit, "The alliance guns have been enabled.")
	elseif (f == "h") then
		SendPvPMessage(pUnit, "The horde guns have been enabled.")
	end
	RegisterTimedEvent("disable_guns", GUN_ENABLE_TIME*1000, 1, pUnit, f)
end

function disable_guns(pUnit, f)
	local tbl = b_tbl[phase.get(pUnit)]
	tbl.gun[f][1]:SetNPCFlags(1)
	tbl.gun[f][2]:SetNPCFlags(1)
	tbl.gun[f][1]:EjectAllVehiclePassengers()
	tbl.gun[f][2]:EjectAllVehiclePassengers()
	if (f == "a") then
		SendPvPMessage(pUnit, "The alliance guns have been disabled.")
	elseif (f == "h") then
		SendPvPMessage(pUnit, "The horde guns have been disabled.")
	end
end

function freeze_guns(pUnit, f)
	local tbl = b_tbl[phase.get(pUnit)]
	for i=1,2 do
		tbl.gun[f][i]:SetNPCFlags(1)
		tbl.gun[f][i]:EjectAllVehiclePassengers()
		tbl.gun[f][i]:CastSpell(FREEZE_AURA)
	end	
	if (f == "a") then
		SendPvPMessage(pUnit, "The alliance guns have been frozen.")
	elseif (f == "h") then
		SendPvPMessage(pUnit, "The horde guns have been frozen.")
	end
	RegisterTimedEvent("unfreeze_guns", GUN_DISABLE_TIME*1000, 1, pUnit, f)
end

function unfreeze_guns(pUnit, f)
	local tbl = b_tbl[phase.get(pUnit)]
	tbl.gun[f][1]:RemoveAura(FREEZE_AURA)
	tbl.gun[f][2]:RemoveAura(FREEZE_AURA)
	if (f == "a") then
		SendPvPMessage(pUnit, "The alliance guns are ready to be activated again.")
	elseif (f == "h") then
		SendPvPMessage(pUnit, "The horde guns are ready to be activated again.")
	end
end
	
function deal_ship_damage(pUnit)
	local tbl = b_tbl[phase.get(pUnit)]
	for i=1, 2 do
		local j = i == 1 and "alliance" or "horde";
		for _, v in pairs(tbl[j]) do
			local f = j == "alliance" and "a" or "h"
			if (v:IsOnVehicle()) then
				tbl.ship_hp[f == "a"and"h"or"a"] = tbl.ship_hp[f=="a"and"h"or"a"]-1500
				send_packet(pUnit, SHIP_HP-tbl.ship_hp["a"], SHIP_HP-tbl.ship_hp["h"])
			end	
		end
	end
end

-- Temporary cannon fix
function cannon_cooldown(spell_effect, spell)
	local caster = spell:GetCaster()
	local power = caster:GetPower(3)
	if (power == 100) then
		caster:CastSpell(69487) -- Overheat.
	elseif not (power == 100) then	
		caster:SetPower(power-1, caster:GetPowerType(3))
	end
end	

RegisterDummySpell(69471, "cannon_cooldown")

function incinerating_blast(spell_effect, spell)
	local caster = spell:GetCaster()
	local power = caster:GetPower(3)
	caster:SetPower(100, caster:GetPowerType(3))
end	

RegisterDummySpell(70175, "incinerating_blast")

function overheat_cooldown(spell_effect, spell)
	local caster = spell:GetCaster()
	local power = caster:GetPower(3)
	caster:SetPower(power-10, caster:GetPowerType(3))
end	

RegisterDummySpell(69488, "overheat_cooldown")

--[[

	Flag handlers

]]--

function flag_handler(pUnit)
	-- Some needed vars
	local p = pUnit:GetPhase()
	local tbl = b_tbl[phase.get(pUnit)]
	
	-- To prevent the function from crashing the server.
	
	for i=1, 2 do
		local j = i == 1 and "a" or "h";
		if (tbl.flag_holder[j]) then
			if not (tbl.flag_holder[j]:IsInWorld()) then
				tbl.flag_holder[j] = nil;
				tbl.flag_status[j] = FLAG_STATUS_NOT_SPAWNED
			end	
		end
	end	
	
	-- Flag status handler.
	for f, flag_status in pairs(tbl.flag_status) do
		if (flag_status == FLAG_STATUS_NOT_SPAWNED) then
			local FLAG = f == "h" and H_FLAG or A_FLAG
			local fac = f == "h" and "horde" or "alliance"
			tbl.flag[f] = SpawnGO(pUnit, FLAG, tbl.flag_coords[f], p)
			tbl.flag_status[f] = FLAG_STATUS_SPAWNED
			SendPvPMessage(pUnit, "A new "..fac.." flag has been spawned.")
		elseif (flag_status == FLAG_STATUS_PICKED) then
			local fac = f == "h" and "a" or "h"
			local f_h = tbl.flag_holder[fac]
			local f_h_aura = f == "h" and H_FLAG_AURA or A_FLAG_AURA
			if (f_h) then
				if not (f_h:GetZoneId() == 618) then
					f_h:RemoveAura(A_FLAG_AURA); f_h:RemoveAura(H_FLAG_AURA);
					tbl.flag_status[f] = FLAG_STATUS_NOT_SPAWNED
					tbl.f_h[fac] = nil; break;
				elseif (f_h:IsDead()) then
					local x, y, z, o = f_h:GetLocation()
					local FLAG = f == "h" and H_FLAG or A_FLAG
					tbl.flag[f] = pUnit:SpawnGameObject(FLAG, x, y, z, o, 0, 100, p)
					tbl.flag_status[f] = FLAG_STATUS_SPAWNED
					SendPvPMessage(pUnit, f_h:GetName().." has dropped the flag.")
					tbl.flag_holder[fac] = nil; break;
				elseif not (f_h:HasAura(f_h_aura)) then
					local x, y, z, o = f_h:GetLocation()
					local FLAG = f == "h" and H_FLAG or A_FLAG
					tbl.flag[f] = pUnit:SpawnGameObject(FLAG, x, y, z, o, 0, 100, p)
					tbl.flag_status[f] = FLAG_STATUS_SPAWNED
					SendPvPMessage(pUnit, f_h:GetName().." has dropped the flag.")
					tbl.flag_holder[fac] = nil; break;
				end
			end
		end
	end	
end
	
function flag_on_pickup(gObject, _, plr)
	local f = plr:GetTeam() == 0 and "h" or "a" -- Faction of flag.
	if (f == "h" and tonumber(gObject:GetEntry()) == A_FLAG) then return; end
	if (f == "a" and tonumber(gObject:GetEntry()) == H_FLAG) then return; end
	local tbl = b_tbl[phase.get(plr)]
	if (f == "a") then
		plr:CastSpell(A_FLAG_AURA)
	elseif (f == "h") then
		plr:CastSpell(H_FLAG_AURA)
	end	
	tbl.flag_holder[plr:GetTeam() == 0 and "a" or "h"] = plr
	tbl.flag_status[f] = FLAG_STATUS_PICKED
	tbl.flag[f]:Despawn(0, 0)
	SendPvPMessage(plr, plr:GetName().." has picked up the flag.")	
end	

function remove_flag(plr)
	local tbl = b_tbl[phase.get(plr)]
	tbl.flag_holder[plr:GetTeam() == 0 and "a" or "h"] = nil;
	plr:RemoveAura(A_FLAG_AURA); plr:RemoveAura(H_FLAG_AURA);
	RegisterTimedEvent("respawn_flag", FLAG_RESPAWN_TIME*1000, 1, plr)
end

function respawn_flag(plr)
	local tbl = b_tbl[phase.get(plr)]
	tbl.flag_status[plr:GetTeam() == 0 and "h" or "a"] = FLAG_STATUS_NOT_SPAWNED
end
	
RegisterGameObjectEvent(A_FLAG, 4, "flag_on_pickup")
RegisterGameObjectEvent(H_FLAG, 4, "flag_on_pickup")

--[[

	Phase system
	
]]--

function phase.set(obj, phase, save)
	if not (type(obj) == "userdata") then 
		return error("Userdata expected, got "..type(obj), 2);
	end
	if (phase == 1) then  return obj:PhaseSet(1, save or nil); end
	obj:PhaseSet(2^(phase+1), save or nil)
end

function phase.get(obj)
	if not (type(obj) == "userdata") then 
		return error("Userdata expected, got "..type(obj), 2);
	end
	local phase = obj:GetPhase()
	if (phase == 1) then return 1; end
	return count_phase(phase);
end	

function count_phase(phase)
	local phase_num = 8
	local phase_count = 2
	while (phase ~= phase_num) do
		phase_num = phase_num*2
		phase_count = phase_count + 1
	end
	return phase_count;
end

function reverse_phase(phase)
	return 2^(phase+1);
end	

function get_available_phase(tbl)
	for i, v in ipairs(tbl) do
		return i+1;
	end
	return 2;
end	

--[[

	Rocket pack work around.

]]--
local c_tbl = {}

function rocket_on_gossip(pUnit, event, plr, _, intid)
	if (event == 1) then
		pUnit:GossipCreateMenu(3000, plr, 0)
		pUnit:GossipMenuAddItem(3, "Give me a rocket pack.", 1, 0)
		pUnit:GossipMenuAddItem(3, "Nevermind.", 2, 0)
		pUnit:GossipSendMenu(plr)
	elseif (event == 2) then
		if (intid == 1) then
			if (plr:HasItem(49278)) then
				pUnit:SendChatMessage(12, 0, "You already have my rocket pack!")
			elseif not (plr:HasItem(49278)) then
				plr:AddItem(49278, 1)
			end	
		elseif (intid == 2) then
			plr:GossipComplete()
		end
		plr:GossipComplete()
	end
end

function rocket_on_load(pUnit)
	pUnit:SetFaction(35)
	pUnit:SetNPCFlags(1)
end

function on_use_rocket_pack(_, _, plr)
	if not (c_tbl[tostring(plr)]) then
		c_tbl[tostring(plr)] = os.time();
	elseif (c_tbl[tostring(plr)]) then
		if (os.time() < c_tbl[tostring(plr)]) then
			return plr:SendAreaTriggerMessage("|cffff0000You can't use this yet.");
		end	
	end
	c_tbl[tostring(plr)] = os.time()+10
	RegisterTimedEvent("blink", 100, 10, plr)	
end	

function rocket_pack()
	if not (b_tbl) then return; end
	for _, v in pairs(b_tbl) do
		for i=1,2 do
			local j = i == 1 and "alliance" or "horde";
			for _, val in pairs(v[j]) do
				if not(val:IsInWorld()) then break; end
				local item = val:GetEquippedItemBySlot(3)
				if not (item) or not (item:GetEntryId() == 49278) then
					if (val:HasAura(69188)) then -- Jetpack
						val:CastSpell(73077) -- Jetpack removal spell.
					end	
				elseif (item:GetEntryId() == 49278) and not (val:HasAura(69188)) then
					val:CastSpell(69188)
				end
			end	
		end
	end
end	

function blink(plr)
	plr:CastSpell(1953)
end	

RegisterTimedEvent("rocket_pack", 1000, 0)

RegisterUnitEvent(ROCKET, 18, "rocket_on_load")				

RegisterUnitGossipEvent(ROCKET, 1, "rocket_on_gossip")
RegisterUnitGossipEvent(ROCKET, 2, "rocket_on_gossip")

RegisterItemGossipEvent(49278, 1, "on_use_rocket_pack")

--[[

	world states

]]--

--[[
	
	Alliance:
	
	Map: 1
	Zone: 1377
	AN: 0
	states: 2313/2317
	
	Horde:
	
	Map: 1
	Zone: 1377
	AN: 0
	states: 2314/2317
	
]]--	

function create_packet(pUnit)
	local packet = {}
	-- General packet.
	packet[1] = LuaPacket:CreatePacket(706, 18)
	packet[1]:WriteULong(1) 
	packet[1]:WriteULong(1377)
	packet[1]:WriteULong(0) 
	packet[1]:WriteUShort(1)
	packet[1]:WriteULong(0) 
	packet[1]:WriteULong(0)
	-- Update packet.
	packet[2] = LuaPacket:CreatePacket(707,8) 
	packet[2]:WriteULong(2317)
	packet[2]:WriteULong(SHIP_HP)
	-- Send packet.
	local tbl = b_tbl[phase.get(pUnit)]
	for _, v in pairs(tbl.alliance) do
		for i=1, 2 do
			v:SendPacketToPlayer(packet[i])
		end
	end
	for _, v in pairs(tbl.horde) do
		for i=1, 2 do
			v:SendPacketToPlayer(packet[i])
		end
	end
	send_packet(pUnit, 0, 0)
end	

function send_current_packet(plr)
	packet = LuaPacket:CreatePacket(706, 18)
	packet:WriteULong(1) 
	packet:WriteULong(1377)
	packet:WriteULong(0) 
	packet:WriteUShort(1)
	packet:WriteULong(0) 
	packet:WriteULong(0)
	plr:SendPacketToPlayer(packet)
end
	
function update_packet(state, value)
	local packet = LuaPacket:CreatePacket(707, 8)
	packet:WriteULong(state)
	packet:WriteULong(value)
	return packet;
end 

function send_packet(unit, a_score, h_score)
	if (a_score) >= SHIP_HP then return stop_battle(phase.get(unit)); end
	if (h_score) >= SHIP_HP then return stop_battle(phase.get(unit)); end
	local tbl = b_tbl[phase.get(unit)]
	for _, v in pairs(tbl.alliance) do
		if (a_score) then
			v:SendPacketToPlayer(update_packet(2313, a_score))
		end	
		if (h_score) then	
			v:SendPacketToPlayer(update_packet(2314, h_score))
		end	
	end
	for _, v in pairs(tbl.horde) do
		if (a_score) then
			v:SendPacketToPlayer(update_packet(2313, a_score))
		end	
		if (h_score) then	
			v:SendPacketToPlayer(update_packet(2314, h_score))
		end	
	end
end	

function remove_packet(tbl)
	local p = LuaPacket:CreatePacket(706, 8)
	p:WriteULong(0)
	p:WriteULong(0)
	for _, v in pairs(tbl.alliance) do 
		v:SendPacketToPlayer()
	end	
	for _, v in pairs(tbl.horde) do 
		v:SendPacketToPlayer()
	end		
end	

--[[

	Resurrect System

]]--

function on_resurrect(event, plr)
	if (plr:GetZoneId() == 618) and not (plr:GetPhase() == 1) then
		if (event == 6) then -- On death
			plr:SendBroadcastMessage("You will be resurrected in 10 seconds.")
			RegisterTimedEvent("resurrect", 10000, 1, plr)
		elseif (event == 7) then -- On repop could be 32 aswell.
			plr:SendBroadcastMessage("You will be resurrected soon!")
			return 0;
		end
	end
end

function resurrect(plr)
	if not (plr) then return; end
	if (plr:GetTeam() == 0) then
		plr:Teleport(unpack(PLR_SPAWN_POINT_A))
	elseif (plr:GetTeam() == 1) then
		plr:Teleport(unpack(PLR_SPAWN_POINT_H))
	end	
	if not (plr:IsDead()) then return; end
	plr:ResurrectPlayer()
end	

RegisterServerHook(6, "on_resurrect")
RegisterServerHook(7, "on_resurrect")

--[[

	Check for leavers logging in.

]]--

function return_bg_plrs()
	if not (b_tbl) then return; end
	local tbl = {}
	for _, v in pairs(b_tbl) do
		for k, val in pairs(v.alliance) do
			table.insert(tbl, val)
		end
		for k, val in pairs(v.horde) do
			table.insert(tbl, val)
		end
	end
	return tbl;
end

function on_enter_bg(_, plr)
	if (plr:GetZoneId() == 618) and not (plr:GetPhase() == 1) then
		local bool = false;
		for _, v in pairs(return_bg_plrs()) do
			if (tostring(plr) == tostring(v)) then bool = true; end
		end
		if not (bool) then
			plr:RemoveAura(A_FLAG_AURA); plr:RemoveAura(H_FLAG_AURA); 
			plr:PhaseSet(1)
			RegisterTimedEvent("port_leaver", 1000, 1, plr)
		end
	end	
end	

function port_leaver(plr) -- To prevent a crash.
	plr:Teleport(0, -13244.3, 198.506, 31)
end	
	
RegisterServerHook(4, "on_enter_bg")