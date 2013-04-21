local file_dir = "scripts/looting_log.txt"
local file = assert(io.open(file_dir, "a"))
local loots = {}
for line in io.lines(file_dir) do
	local str = ""
	local sub_str = line:sub(30, string.len(line))
	for i=1, string.len(sub_str) do
		if (tonumber(sub_str:sub(i, i))) then
			str = str..sub_str:sub(i, i)
		end
	end
	table.insert(loots, {_line = line, _entry = str})
end
function registrate_on_loot(_, plr, pUnit, _, entry)
	if not (entry == 0) then
		local line = os.date("%x [%X]", os.time())..": "..plr:GetName().." has looted item "..entry.." from unit: "..pUnit:GetName()
		file:write(line.."\n")
		table.insert(loots, {_line = line, _entry = tostring(entry)})
	end
	file:flush()
end
RegisterServerHook(17, "registrate_on_loot")
function loot_on_check(_, player, msg)
	if (msg:find("#char loot") == 1) then
		local tbl = {}
		local plr = player:GetSelection()
		if not (plr) then return false; end
		local length = string.len(plr:GetName())
		for _, v in ipairs(loots) do
			if (v._line:sub(22, length+21) == plr:GetName()) then table.insert(tbl, v) end
		end
		local n_tbl = {}
		if (msg:find("#char loot ") == 1) then
			local entry = msg:gsub("#char loot ", "")
			for _, v in ipairs(tbl) do
				if (entry == v._entry) then table.insert(n_tbl, v) end
				if (#n_tbl == 20) then break; end
			end
			if not (#n_tbl > 0) then
				player:SendBroadcastMessage("No results found.")
				return false;
			end
		end
		local count = 0
		local tab = #n_tbl > 0 and n_tbl or tbl
		for _, v in ipairs(tab) do
			count = count + 1
			player:SendBroadcastMessage(v._line)
			if (count == 20) then
				player:SendBroadcastMessage("More than 20 results found, aborting.")
				return false;
			end
		end
		if (#tbl == 0) then
			player:SendBroadcastMessage("No results found.")
		end
		return false;
	end
end
RegisterServerHook(16, "loot_on_check")