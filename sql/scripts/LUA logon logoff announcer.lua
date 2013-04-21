-- Grumbo/Blackwolf logon script with help from foereaper ty.
-- this will announce that a player has logged on or off and keep admin stealthed 
-- from slp13@420 of ac-web 
function Player_Log(event, player)
local status = nil
	if event == 13 then
	status = "off"
	else
	status = "on"
 		if (player:GetGmRank()<'az') then -- keps admin steath
		 SendWorldMessage("|cff00cc00"..player:GetName().." has logged "..status..".|r", 2)
 		else
 	end
 end
 end
 RegisterServerHook(13, "Player_Log")
 RegisterServerHook(19, "Player_Log")