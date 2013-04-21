--Made by Laurea (the Insane)

local backupValues = false; --(Eluna only) Set to false if you don't want values to carry over an engine reload or server restart.
local instFunc, guidFunc, eluna = nil;

if (type(GetLuaEngine) ~= "function") then
	assert(false, "This script is intended for use with ArcEmu with ALE or TrinityCore with Eluna.");
elseif (GetLuaEngine() == "ALE") then
	instFunc = "GetInstanceID";
	guidFunc = "GetGUID";
	eluna = false;
elseif (GetLuaEngine():sub(1, 5) == "Eluna") then
	instFunc = "GetInstanceId";
	guidFunc = Unit.GetGUIDLow and "GetGUIDLow" or "GetGUID";
	eluna = true;
else
	assert(false, "This script requires either ALE (ArcEmu Lua Engine) or Eluna to function properly.\nALE comes with ArcEmu by default, and Eluna is a TrinityCore project.");
end

local DataValue = {
	_player = {},
	_creature = {},
	_gameobject = {},
	_guild = {},
	_group = {},
	_item = {},
	_map = {},
	_instance = {},
};

local PLAYER, UNIT, GOBJ, ITEM, GUILD, GROUP = nil;
if (eluna) then
	UNIT = Unit;
	GOBJ = GameObject;
	ITEM = Item;
	GUILD = Guild;
	GROUP = Group;
	
	assert(UNIT);
	assert(GOBJ);
	assert(ITEM);
	assert(GUILD);
	assert(GROUP);
else
	PLAYER = LCF.PlayerMethods;
	UNIT = LCF.CreatureMethods;
	GOBJ = LCF.GOMethods;
	
	assert(PLAYER);
	assert(UNIT);
	assert(GOBJ);
end

local function err(val, exp, func, arg, lvl)
	local tmp = {"Bad argument #", arg, " to ", func, " (", exp, " expected, got ", type(val), ")."};
	error(table.concat(tmp), lvl);
end
-----------------------------------------------------------------------------------------------------
local function Set(tbl, field, value, obj, extra)
	if (type(field) ~= "string" and type(field) ~= "number") then
		local pos = 1;
		local func = "SetValue";
		if (extra == 1) then
			pos = 2;
			func = "SetMapValue";
		elseif (extra == 2) then
			pos = 2;
			func = "SetInstanceValue";
		elseif (extra == 3) then
			func = "SetMemberValue";
		end
		err(field, "string or number", func, pos, eluna and 3 or 4);
		return nil;
	end
	if (tbl[obj] == nil) then
		tbl[obj] = {};
	end
	tbl[obj][field] = value;
	return 1;
end
--Set UNIT
function UNIT:SetValue(field, value)
	if (eluna and self:GetUnitType() == "Player") then
		return Set(DataValue._player, field, value, self[guidFunc](self));
	end
	return Set(DataValue._creature, field, value, self[guidFunc](self));
end
function UNIT:SetMapValue(field, value)
	return Set(DataValue._map, field, value, self:GetMapId(), 1);
end
function UNIT:SetInstanceValue(field, value)
	return Set(DataValue._instance, field, value, self[instFunc](self), 2);
end
--Set GOBJ
function GOBJ:SetValue(field, value)
	return Set(DataValue._gameobject, field, value, self[guidFunc](self));
end
function GOBJ:SetMapValue(field, value)
	return Set(DataValue._map, field, value, self:GetMapId(), 1);
end
function GOBJ:SetInstanceValue(field, value)
	return Set(DataValue._instance, field, value, self[instFunc](self), 2);
end
--Set Global
function SetMapValue(map, field, value)
	if (type(map) ~= "number") then err(map, "number", "SetMapValue", 1, 3); end
	return Set(DataValue._map, field, value, map, 1);
end
function SetInstanceValue(instance, field, value)
	if (type(instance) ~= "number") then err(instance, "number", "SetInstanceValue", 1, 3); end
	return Set(DataValue._instance, field, value, instance, 2);
end

if (eluna) then
	--Set ITEM
	function ITEM:SetValue(field, value)
		return Set(DataValue._item, field, value, self[guidFunc](self));
	end
	function ITEM:SetMapValue(field, value)
		return Set(DataValue._map, field, value, self:GetOwner():GetMapId(), 1);
	end
	function ITEM:SetInstanceValue(field, value)
		return Set(DataValue._instance, field, value, self:GetOwner()[instFunc](self:GetOwner()), 2);
	end
	--Set GUILD
	function GUILD:SetValue(field, value)
		return Set(DataValue._guild, field, value, self:GetId());
	end
	function GUILD:SetMemberValue(field, value)
		for _, player in pairs (self:GetMembers()) do
			Set(DataValue._player, field, value, player[guidFunc](player), 3);
		end
	end
	--Set GROUP
	function GROUP:SetValue(field, value)
		return Set(DataValue._group, field, value, self[guidFunc](self));
	end
	function GROUP:SetMemberValue(field, value)
		for _, player in pairs (self:GetMembers()) do
			Set(DataValue._player, field, value, player[guidFunc](player), 3);
		end
	end
else
	--Set PLAYER
	function PLAYER:SetValue(field, value)
		return Set(DataValue._player, field, value, self[guidFunc](self));
	end
	function PLAYER:SetMapValue(field, value)
		return Set(DataValue._map, field, value, self:GetMapId(), 1);
	end
	function PLAYER:SetInstanceValue(field, value)
		return Set(DataValue._instance, field, value, self[instFunc](self), 2);
	end
end
-----------------------------------------------------------------------------------------------------
local function Get(tbl, field, obj, extra)
	if (type(field) ~= "string" and type(field) ~= "number") then
		local pos = 1;
		local func = "GetValue";
		if (extra == 1) then
			pos = 2;
			func = "GetMapValue";
		elseif (extra == 2) then
			pos = 2;
			func = "GetInstanceValue";
		end
		err(field, "string or number", func, pos, eluna and 3 or 4);
		return nil;
	end
	if (tbl[obj] == nil) then
		return nil;
	end
	return tbl[obj][field];
end
--Get UNIT
function UNIT:GetValue(field)
	if (eluna and self:GetUnitType() == "Player") then
		return Get(DataValue._player, field, self[guidFunc](self));
	end
	return Get(DataValue._creature, field, self[guidFunc](self));
end
function UNIT:GetMapValue(field)
	return Get(DataValue._map, field, self:GetMapId(), 1);
end
function UNIT:GetInstanceValue(field)
	return Get(DataValue._instance, field, self[instFunc](self), 2);
end
--Get GOBJ
function GOBJ:GetValue(field)
	return Get(DataValue._gameobject, field, self[guidFunc](self));
end
function GOBJ:GetMapValue(field)
	return Get(DataValue._map, field, self:GetMapId(), 1);
end
function GOBJ:GetInstanceValue(field)
	return Get(DataValue._instance, field, self[instFunc](self), 2);
end
--Get Global
function GetMapValue(map, field)
	if (type(map) ~= "number") then err(map, "number", "GetMapValue", 1, 3); end
	return Get(DataValue._map, field, map, 1);
end
function GetInstanceValue(instance, field)
	if (type(instance) ~= "number") then err(instance, "number", "GetInstanceValue", 1, 3); end
	return Get(DataValue._instance, field, instance, 2);
end

if (eluna) then
	--Get ITEM
	function ITEM:GetValue(field)
		return Get(DataValue._item, field, self[guidFunc](self));
	end
	function ITEM:GetMapValue(field)
		return Get(DataValue._map, field, self:GetOwner():GetMapId(), 1);
	end
	function ITEM:GetInstanceValue(field)
		return Get(DataValue._instance, field, self:GetOwner()[instFunc](self:GetOwner()), 2);
	end
	--Get GUILD
	function GUILD:GetValue(field)
		return Get(DataValue._guild, field, self:GetId());
	end
	--Get GROUP
	function GROUP:GetValue(field, value)
		return Get(DataValue._group, field, self[guidFunc](self));
	end
else
	--Get PLAYER
	function PLAYER:GetValue(field)
		return Get(DataValue._player, field, self[guidFunc](self));
	end
	function PLAYER:GetMapValue(field)
		return Get(DataValue._map, field, self:GetMapId(), 1);
	end
	function PLAYER:GetInstanceValue(field)
		return Get(DataValue._instance, field, self[instFunc](self), 2);
	end
end
-----------------------------------------------------------------------------------------------------
local function Mod(tbl, field, value, obj, extra)
	if (value == nil) then return nil; end
	local t = type(value);
	if (type(field) ~= "string" and type(field) ~= "number") then
		local pos = 1;
		local func = "ModValue";
		if (extra == 1) then
			pos = 2;
			func = "ModMapValue";
		elseif (extra == 2) then
			pos = 2;
			func = "ModInstanceValue";
		elseif (extra == 3) then
			func = "ModMemberValue";
		end
		err(field, "string or number", func, pos, eluna and 3 or 4);
		return nil;
	elseif (t ~= "string" and t ~= "number" and t ~= "table") then
		local pos = 2;
		local func = "ModValue";
		if (extra == 1) then
			pos = 3;
			func = "ModMapValue";
		elseif (extra == 2) then
			pos = 3;
			func = "ModInstanceValue";
		elseif (extra == 3) then
			func = "ModMemberValue";
		end
		err(field, "string, number or table", func, pos, eluna and 3 or 4);
		return nil;
	end
	if (tbl[obj] == nil) then
		tbl[obj] = {};
	end
	if (t ~= type(tbl[obj][field])) then
		tbl[obj][field] = value;
	else
		local val = tbl[obj][field];
		if (t == "number") then
			tbl[obj][field] = val + value;
		elseif (t == "string") then
			tbl[obj][field] = val..value;
		elseif (t == "table") then
			for k, v in pairs (value) do
				tbl[obj][field][k] = v;
			end
		end
	end
	return tbl[obj][field];
end
--Mod UNIT
function UNIT:ModValue(field, value)
	if (eluna and self:GetUnitType() == "Player") then
		return Mod(DataValue._player, field, value, self[guidFunc](self));
	end
	return Mod(DataValue._creature, field, value, self[guidFunc](self));
end
function UNIT:ModMapValue(field, value)
	return Mod(DataValue._map, field, value, self:GetMapId(), 1);
end
function UNIT:ModInstanceValue(field, value)
	return Mod(DataValue._instance, field, value, self[instFunc](self), 2);
end
--Mod GOBJ
function GOBJ:ModValue(field, value)
	return Mod(DataValue._gameobject, field, value, self[guidFunc](self));
end
function GOBJ:ModMapValue(field, value)
	return Mod(DataValue._map, field, value, self:GetMapId(), 1);
end
function GOBJ:ModInstanceValue(field, value)
	return Mod(DataValue._instance, field, value, self[instFunc](self), 2);
end
--Mod Global
function ModMapValue(map, field, value)
	if (type(map) ~= "number") then err(map, "number", "ModMapValue", 1, 3); end
	return Mod(DataValue._map, field, value, map, 1);
end
function ModInstanceValue(instance, field, value)
	if (type(instance) ~= "number") then err(instance, "number", "ModInstanceValue", 1, 3); end
	return Mod(DataValue._instance, field, value, instance, 2);
end

if (eluna) then
	--Mod ITEM
	function ITEM:ModValue(field, value)
		return Mod(DataValue._item, field, value, self[guidFunc](self));
	end
	function ITEM:ModMapValue(field, value)
		return Mod(DataValue._map, field, value, self:GetOwner():GetMapId(), 1);
	end
	function ITEM:ModInstanceValue(field, value)
		return Mod(DataValue._instance, field, value, self:GetOwner()[instFunc](self:GetOwner()), 2);
	end
	--Mod GUILD
	function GUILD:ModValue(field, value)
		return Mod(DataValue._guild, field, value, self:GetId());
	end
	function GUILD:ModMemberValue(field, value)
		for _, player in pairs (self:GetMembers()) do
			Mod(DataValue._player, field, value, player[guidFunc](player), 3);
		end
	end
	--Mod GROUP
	function GROUP:ModValue(field, value)
		return Mod(DataValue._group, field, value, self[guidFunc](self));
	end
	function GROUP:ModMemberValue(field, value)
		for _, player in pairs (self:GetMembers()) do
			Mod(DataValue._player, field, value, player[guidFunc](player), 3);
		end
	end
else
	--Mod PLAYER
	function PLAYER:ModValue(field, value)
		return Mod(DataValue._player, field, value, self[guidFunc](self));
	end
	function PLAYER:ModMapValue(field, value)
		return Mod(DataValue._map, field, value, self:GetMapId(), 1);
	end
	function PLAYER:ModInstanceValue(field, value)
		return Mod(DataValue._instance, field, value, self[instFunc](self), 2);
	end
end
-----------------------------------------------------------------------------------------------------
if (eluna and backupValues) then
	function DataValue.Save(event)
		local f = io.open("scripts/Data Values.save", "w+");
		f:flush();
		f:close();
	end
	
	function DataValue.Load()
		local f = io.open("scripts/Data Values.save");
		if (f == nil) then
			return;
		end
		--local str = f:read("*a");
		f:close();
	end
	
	CreateLuaEvent(DataValue.Load, 100, 1);
	RegisterServerHook(54, DataValue.Save);
	RegisterServerHook(55, DataValue.Save);
end

function SetDataValue()
	error("SetDataValue has been removed.", eluna and 2 or 3);
end
function GetDataValue()
	error("GetDataValue has been removed.", eluna and 2 or 3);
end
function ModDataValue()
	error("ModDataValue has been removed.", eluna and 2 or 3);
end