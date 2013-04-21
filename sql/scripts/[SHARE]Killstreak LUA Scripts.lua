KILL = {}
 
KILL.TokenId = TOKENIDHERE
 
KILL.Count = 3
                                               
 
KILL.TokenOne = 1
KILL.TokenTwo = 5
KILL.TokenThree = 5
KILL.TokenFour = 10
KILL.TokenFive = 5
KILL.TokenSix = 15
KILL.TokenSeven = 10
KILL.TokenEight = 20
KILL.TokenNine = 10
KILL.TokenTen = 25
KILL.TokenEleven = 15  
 
function KILL.OnKillPlayer(event, player, victim)
        if (KILL[player:GetName()] == nil) then
                KILL[player:GetName()] = {}
                KILL[player:GetName()].killstreak = 1
                KILL[victim:GetName()] = {}
                KILL[victim:GetName()].killstreak = 0
                player:SendBroadcastMessage("You owned: |cFF90EE90"..victim:GetName().."")
                player:SendBroadcastMessage("Killstreak: |cFF90EE90"..KILL[player:GetName()].killstreak.."")
                victim:SendBroadcastMessage("You got owned by: |cFF90EE90"..player:GetName().."")
                player:AddItem(KILL.TokenId, KILL.TokenOne)
        elseif (KILL[player:GetName()].killstreak == nil) then
                KILL[player:GetName()].killstreak = 1
                KILL[victim:GetName()] = {}
                KILL[victim:GetName()].killstreak = 0
                player:SendBroadcastMessage("You owned: |cFF90EE90"..victim:GetName().."")
                player:SendBroadcastMessage("Killstreak: |cFF90EE90"..KILL[player:GetName()].killstreak.."")
                victim:SendBroadcastMessage("You got owned by: |cFF90EE90"..player:GetName().."")
                player:AddItem(KILL.TokenId, KILL.TokenOne)
        else
                if (KILL.PlayerCheck(player, victim) == true) then
                        KILL[player:GetName()].killstreak = KILL[player:GetName()].killstreak + 1
                        KILL[victim:GetName()] = {}
                        KILL[victim:GetName()].killstreak = 0
                        player:SendBroadcastMessage("You owned: |cFF90EE90"..victim:GetName().."")
                        player:SendBroadcastMessage("Killstreak: |cFF90EE90"..KILL[player:GetName()].killstreak.."")
                        victim:SendBroadcastMessage("You got owned by: |cFF90EE90"..player:GetName().."")
                        if (KILL[player:GetName()].killstreak > 0) then
                                if (KILL[player:GetName()].killstreak < 10) then
                                        player:AddItem(KILL.TokenId, KILL.TokenOne)
                                end
                        end    
                        if (KILL[player:GetName()].killstreak == 10) then
                                local plrs = GetPlayersInWorld()
                                for k, v in pairs(plrs) do
                                        v:SendBroadcastMessage("|cFFADD8E6[PvP System]: |cFFFFFF00"..player:GetName().." is on a "..KILL[player:GetName()].killstreak.." kill streak.")
                                        player:AddItem(KILL.TokenId, KILL.TokenTwo)
                                end    
                        end    
                        if (KILL[player:GetName()].killstreak > 10) then
                                if (KILL[player:GetName()].killstreak < 20) then
                                        player:AddItem(KILL.TokenId, KILL.TokenThree)
                                end    
                        end            
                        if (KILL[player:GetName()].killstreak == 20) then
                                local plrs = GetPlayersInWorld()
                                for k, v in pairs(plrs) do
                                        v:SendBroadcastMessage("|cFFADD8E6[PvP System]: |cFFFFFF00"..player:GetName().." is on a "..KILL[player:GetName()].killstreak.." kill streak.")
                                        player:AddItem(KILL.TokenId, KILL.TokenFour)
                                end
                        end    
                        if (KILL[player:GetName()].killstreak > 20) then
                                if (KILL[player:GetName()].killstreak < 30) then
                                        player:AddItem(KILL.TokenId, KILL.TokenFive)
                                end
                        end            
                        if (KILL[player:GetName()].killstreak == 30) then
                                local plrs = GetPlayersInWorld()
                                for k, v in pairs(plrs) do
                                        v:SendBroadcastMessage("|cFFADD8E6[PvP System]: |cFFFFFF00"..player:GetName().." is on a "..KILL[player:GetName()].killstreak.." kill streak.")
                                        player:AddItem(KILL.TokenId, KILL.TokenSix)
                                end
                        end    
                        if (KILL[player:GetName()].killstreak > 30) then
                                if (KILL[player:GetName()].killstreak < 40) then
                                        player:AddItem(KILL.TokenId, KILL.TokenSeven)
                                end    
                        end            
                        if (KILL[player:GetName()].killstreak == 40) then
                                local plrs = GetPlayersInWorld()
                                for k, v in pairs(plrs) do
                                        v:SendBroadcastMessage("|cFFADD8E6[PvP System]: |cFFFFFF00"..player:GetName().." is on a "..KILL[player:GetName()].killstreak.." kill streak.")
                                        player:AddItem(KILL.TokenId, KILL.TokenEight)
                                end
                        end    
                        if (KILL[player:GetName()].killstreak > 40) then
                                if (KILL[player:GetName()].killstreak < 50) then
                                        player:AddItem(KILL.TokenId, KILL.TokenNine)
                                end
                        end            
                        if (KILL[player:GetName()].killstreak == 50) then
                                local plrs = GetPlayersInWorld()
                                for k, v in pairs(plrs) do
                                        v:SendBroadcastMessage("|cFFADD8E6[PvP System]: |cFFFFFF00"..player:GetName().." is on a "..KILL[player:GetName()].killstreak.." kill streak.")
                                        player:AddItem(KILL.TokenId, KILL.TokenTen)
                                end
                        end    
                        if (KILL[player:GetName()].killstreak > 50) then
                                player:AddItem(KILL.TokenId, KILL.TokenEleven)         
                        end
                else
                        player:SendBroadcastMessage("You have to kill another player first in order to get more PvP tokens.")
                        victim:SendBroadcastMessage("You got owned by: |cFF90EE90"..player:GetName().."")
                end
        end
end    
 
function KILL.PlayerCheck(player, victim)
        if (KILL[player:GetName()].target == victim:GetName()) then
                KILL[player:GetName()].killcount = KILL[player:GetName()].killcount + 1
                if (KILL[player:GetName()].killcount >= KILL.Count) then
                        return false
                else
                        return true
                end    
        else
                KILL[player:GetName()].target = victim:GetName()
                KILL[player:GetName()].killcount = 1
                return true
        end
end    
 
RegisterServerHook(2,"KILL.OnKillPlayer")