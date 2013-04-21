--[[
	Created by IOwnAPC. For Eluna Lua Engine.
]]--

function Revive(event, plr)
	if (plr:IsDead() == true) and plr:HasItem(199999) then
		plr:RemoveItem(199999, 1)
		plr:FullCastSpell(26638)
		plr:ResurrectPlayer()
		plr:SendBroadcastMessage("|cffFF0000[SYSTEM] |cff00ff00"..plr:GetName().."|r, one |cff571B7e[SERVER NAME HERE Resurrection item]|r has been consumed. Successful revive.")
	else
		plr:SendBroadcastMessage("|cffFF0000[SYSTEM] |cff00ff00"..plr:GetName().."|r, you cannot be auto-revived, you need one |cff571B7e[SERVER NAME HERE Resurrection item]|r. Fail to Revive.")
		plr:SendAreaTriggerMessage("|cffFF0000[SYSTEM] |cff00ff00"..plr:GetName().."|r, |cff43BFC7you don't have the |cff571B7e[SERVER NAME HERE Resurrection item]")
	end
end

RegisterServerHook(6, "Revive")