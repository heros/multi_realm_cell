--[[
	World Chat v3
	Scripted by DevilCrocker =
]]--

local T = {
	{"z", "|cff0033FFKosmian-WoW Team |cffC41F3B[Ownner]"},
	{"a", "|cff0033FFKosmian-WoW Team |cffFF7d0A[Administrator]"},
	{"c", "|cff0033FFKosmian-WoW Team |cffE700B1[GameMaster]"},
        {"e", "|cff0033FFKosmian-WoW Team |cffDA70D6[V.I.P]"}
	{0, "|cffF3F781World Chat |cffFF0000<Horde> |cffC79C6E"},
	{1, "|cffF3F781World Chat |cff69CCF0<Alliance> |cff69CCF0"}
};

function OnChat_Message(event, pPlayer, message)
	if(message.find(message, "#w") == 1) then
		local nmessage = message:gsub("#w", "");
		for k, v in pairs(T) do
			if (pPlayer:IsGm() and pPlayer:CanUseCommand(T[k][1])) then
				SendWorldMessage(T[k][2]..pPlayer:GetName()..":|cffBCF5A9"..nmessage, 2);
			else
				if(pPlayer:GetTeam() == T[k][1]) then
					SendWorldMessage(T[k][2]..pPlayer:GetName()..":|cffBCF5A9"..nmessage, 2);
				end
			end
		end
		return false;
	end
	return true;
end

RegisterServerHook(16, OnChat_Message);