--[[
  _____                        ____               
 |  ___| __ ___ _______ _ __  / ___|___  _ __ ___ 
 | |_ | '__/ _ \_  / _ \ '_ \| |   / _ \| '__/ _ \
 |  _|| | | (_) / /  __/ | | | |__| (_) | | |  __/
 |_|  |_|  \___/___\___|_| |_|\____\___/|_|  \___|
	 Lightning speed and strength
		 conjured directly from the depths of logic!   
			Infusion-WoW 2013 (C)
<--------------------------------------------------------------------------->
 - Developer(s): Psykko
 - Complete: 100%
 - ScriptName: 'Cooldown Reset'
 - Comment: N/A
<--------------------------------------------------------------------------->
]]

function Spieler_OnDuelFinish(event, pWinner, pLoser)
pWinner:ClearAllCooldowns()
pLoser:ClearAllCooldowns()
end

RegisterServerHook(30, "Spieler_OnDuelFinish")