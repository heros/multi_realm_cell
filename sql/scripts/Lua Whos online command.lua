-- who is online command
-- By Grumbo/Blackwolf aka slp13at420
-- this lists all characters online except for the admin's characters
-- may be listing them by login time but not alphabetical nor team

function PlayersOnline(event, player, message, type, language)
if(message == ".who") then
local Playerctiw = GetPlayersInWorld()
local Pctiw = #Playerctiw
player:SendBroadcastMessage("[|cff00cc00players online|r]: "..Pctiw.."")
	for _,v in ipairs(GetPlayersInWorld()) do
		if(v and v:IsInWorld())and(v:GetGmRank()~='az')and(v:GetTeam()==0)then
			player:SendBroadcastMessage("[|cFF3399ff"..v:GetName().."|r]") -- ally
		elseif(v and v:IsInWorld())and(v:GetGmRank()~='az')and(v:GetTeam()==1)then
			player:SendBroadcastMessage("[|cFFff3300"..v:GetName().."|r]") -- horde

end
end
return false;
	else
end
end
RegisterServerHook(16, "PlayersOnline")