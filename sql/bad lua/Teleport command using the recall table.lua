---------------------------
local rank = "0" -- Eg. "a" or "az" -> "0" = all ranks.
---------------------------
local cost = 0 -- Item id -> 0 = no cost.
local amount = 1
---------------------------
local forbidden_zones = {
	"GM1",
	"GM2",
	"GMIsland"
}
---------------------------
------ End of config ------
---------------------------
local function isForbidden(area)
	for _, v in pairs(forbidden_zones) do
		if (v:lower() == area:lower()) then return true; end
	end
	return false;
end		
local zones = {}
local function loadCoords()
	local query = WorldDBQuery("SELECT * from `recall`;")
	repeat
		local tbl = {name = query:GetColumn(1):GetString():lower(), coords = {}}
		for i=2, 5 do
			table.insert(tbl.coords, query:GetColumn(i):GetString())
		end
		table.insert(zones, tbl)
	until query:NextRow() == false
end
loadCoords()
local function getCoords(area)
	local str = area:lower()
	while (str:find("%s")) do
		str = str:gsub(str:sub(str:find("%s")), "")
	end
	for _, v in pairs(zones) do
		if (v.name == str) then return v.name, v.coords; end
	end
	local zone, coords
	for i=4, 20 do
		for _, v in pairs(zones) do
			if (str:sub(1, i) == v.name:sub(1, i)) then zone = v.name; coords = v.coords end
		end
	end
	return zone, coords;
end
RegisterServerHook(16, function (_, plr, msg)
	if (msg:sub(1, cmd:len()+1) == cmd.." ") then
		local area = msg:sub(cmd:len()+2, msg:len())
		if (area) then
			if (plr:IsInCombat()) then
				plr:SendAreaTriggerMessage"You are in combat or pvp flagged."
				return false;
			elseif (area:len() < 4) then
				plr:SendAreaTriggerMessage"Area name to short, needs at least 4 characters."
				return false;
			end
			local name, coords = getCoords(area)
			if (rank and rank ~= "0" and not plr:CanUseCommand(rank)) then
				plr:SendAreaTriggerMessage"You don't have the required rank."
			elseif (cost and cost ~= 0 and plr:GetItemCount(cost) < amount) then
				plr:SendAreaTriggerMessage"You don't have the required item(s)."
			elseif (name and isForbidden(name)) then
				plr:SendAreaTriggerMessage"You can't teleport to that area."
			elseif not (coords) then
				plr:SendAreaTriggerMessage"Area not found."
			elseif (coords) then
				if not (item == 0) then
					plr:RemoveItem(cost, amount)
				end
				for _, v in pairs(coords) do v = tonumber(v) end
				plr:Teleport(unpack(coords))
			end
		elseif not (area) then
			plr:SendAreaTriggerMessage"No area entered."
		end
		return false;
	end
end)