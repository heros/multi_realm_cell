Paladin = {}
local Tank = {}

DISPLAYS = {37813, 22251}

function TankBot_OnGossip(pUnit, event, player)
	pUnit:GossipCreateMenu(1, player, 0)
	pUnit:GossipMenuAddItem(0, "I need your help!", 1, 0)
	pUnit:GossipMenuAddItem(0, "Nevermind.", 2, 0)
	pUnit:GossipSendMenu(player)
end

function TankBot_OnGossipSel(pUnit, event, player, id, intid)
	if intid == 1 then
		local sUnit = tostring(player)
		if not Paladin[sUnit] then Paladin[sUnit] = {}
			Paladin[sUnit].used = {}
			Paladin[sUnit].used = false
			if Paladin[sUnit].used == true then
				player:SendBroadcastMessage("Can't get another tank.")
				player:GossipComplete()
			else
				Tank[sUnit] = player:CreateGuardian(36864, 6000000, 0, player:GetPlayerLevel())
				Tank[sUnit]:EquipWeapons(37401, 43085, 0)
				Tank[sUnit]:SetNPCFlags(4)
				Tank[sUnit]:CastSpellOnTarget(20217, player)
				Tank[sUnit]:CastSpell(20911)
				Tank[sUnit]:CastSpell(25780)
				Paladin[sUnit].used = true
				player:GossipComplete()
			end
		end
	end
	
	if intid == 2 then
		player:GossipComplete()
	end
end

RegisterUnitGossipEvent(36864, 1, "TankBot_OnGossip")
RegisterUnitGossipEvent(36864, 2, "TankBot_OnGossipSel")

CooldownTime = {}

function TankBot_OnCombat(pUnit, event, target)
	pUnit:CastSpell(27179)
	pUnit:CastSpellOnTarget(62124, target)
	pUnit:RegisterEvent("RighteousHammer", 6000, 0) 
	pUnit:RegisterEvent("CheckHp", 1000, 0)
	RegisterTimedEvent("Taunt", 3000, 0, pUnit, event)
end

function Taunt(pUnit, event)
	local enemies = pUnit:GetInRangeEnemies()
	for _,v in pairs(enemies) do
		if not v:GetSelection(pUnit) == true then
			if v:GetDistance(pUnit) <= 5 then
				v:SetTauntedBy(pUnit)
			end
		end
	end
end

function RighteousHammer(pUnit, event)
	pUnit:FullCastSpellOnTarget(53595, pUnit:GetSelection())
end

function CheckHp(pUnit, event)
	if pUnit:GetHealthPct() <= 50 then
		pUnit:FullCastSpell(52444)
	end
end

function TankBot_OnLeaveCombat(pUnit, event)
	pUnit:RemoveEvents()
	RemoveTimedEvents()
end

function TankBot_OnDead(pUnit, event)
	pUnit:Despawn(100, 0)
end

RegisterUnitEvent(36864, 4, "TankBot_OnDead")
RegisterUnitEvent(36864, 1, "TankBot_OnCombat")
RegisterUnitEvent(36864, 2, "TankBot_OnLeaveCombat")

function RemoveBot(event, player, message)
	if message == "#resetbot" then
		local sUnit = tostring(player)
		if not Paladin[sUnit] == false then
			Paladin[sUnit].used = true
			Tank[sUnit]:Despawn(100, 0)
		end
		return 0
	end
end

RegisterServerHook(16, "RemoveBot")