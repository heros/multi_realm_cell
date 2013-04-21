-- Made by Ghostcrawler 336
-- Made for ac-web.org

function Buffcommand(event, pPlayer, message, type, language)
	if(message == ".buff") then
	pPlayer:AddAura(48162, 3000000)
	pPlayer:AddAura(48074, 3000000)
	pPlayer:AddAura(48170, 3000000)
	pPlayer:AddAura(43223, 3000000)
	pPlayer:AddAura(36880, 3000000)
	pPlayer:AddAura(467, 3000000)
	pPlayer:AddAura(48469, 3000000)
	pPlayer:PlayerSendChatMessage(1, 0, "You've been buffed!") 
	return false
	end
end
RegisterServerHook(16, "Buffcommand")