--[[
        PVP System for Mall
        Scripted by DevilCrocker
]]--
 
local npcid = 34101 -- Die ID des NPCs
local typ = 2           -- 0 = Kill, 1 = PvPFlagg ausmachen, 2 = kick
local bannsys = true -- Bannsystem aktivieren(true) oder deaktivieren(false)
local maxwarning = 3 -- Wenn Bannsystem aktiviert, sind das die maximalen Warnungen, die der Spieler bis zum 100%igen Bann bekommt.
local banntime = 30 -- Wielange der Spieler gebannt wird, in Minuten angeben!
local bann_text = "Du wurdest gebannt." -- Text, der erscheint, sobald der Spieler gebannt wird.
local sorry_text = "Es tut uns leid dass sich dieser Spieler nicht an die Regeln halten konnte." -- Text, den der attackierte Spieler bekommt.
 
 
function anti_pvp(unt, _)
        unt:RegisterEvent("lfpvp", 3000, 0)
end
 
local plr1_tab = {}
local plr2_tab = {}
 
function Anti_PvP_System_Gossip(unt, _, plr)
        unt:GossipCreateMenu(1, plr, 0)
        if(plr:IsGm())then
        unt:GossipMenuAddItem(3, "[Admin]: Spieler Warnungen", 1, 1)
        end
        unt:GossipMenuAddItem(3, "Meine Warnungen", 2, 0)
        unt:GossipMenuAddItem(7, "[Beenden]", 3, 0)
        unt:GossipSendMenu(plr)
end
 
function Anti_PvP_System_Select(unt, _, plr, _, id, code)
        if(id==1)then
        if(CharDBQuery("SELECT name FROM characters WHERE name='"..code.."';")~=nil) then
        if(CharDBQuery("SELECT player FROM pvp_banned_player WHERE player='"..code.."';")~=nil) then
        local warnings = CharDBQuery("SELECT warnings from pvp_banned_player where player='"..code.."';")
        plr:SendBroadcastMessage("|CFFFF0000[Anti-PvP]: |R|CFFFFFFFFDieser Spieler hat "..warnings:GetColumn(0):GetString().."/"..maxwarning.." Warnung(en).|R")
        else
        plr:SendBroadcastMessage("|CFFFF0000[Anti-PvP]: |R|CFFFFFFFFDieser Spieler besitzt noch keine Verwarnungen.|R")
        end
        else
        plr:SendBroadcastMessage("|CFFFF0000[Anti-PvP]: |R|CFFFFFFFFDieser Spieler existiert nicht.|R")
        end
        plr:GossipComplete()
        end
        if(id==2)then
        if(CharDBQuery("SELECT player FROM pvp_banned_player WHERE player='"..plr:GetName().."';")~=nil) then
        local warnings = CharDBQuery("SELECT warnings from pvp_banned_player where player='"..plr:GetName().."';")
        plr:SendBroadcastMessage("|CFFFF0000[Anti-PvP]: |R|CFFFFFFFFDu hast "..warnings:GetColumn(0):GetString().."/"..maxwarning.." Warnung(en).|R")
        else
        plr:SendBroadcastMessage("|CFFFF0000[Anti-PvP]: |R|CFFFFFFFF Du besitzt noch keinen Eintrag.Weiter so ;)|R")
        end
        plr:GossipComplete()
        end
        if(id==3)then
        plr:GossipComplete()
        end
end
 
RegisterUnitGossipEvent(npcid, 1, "Anti_PvP_System_Gossip")
RegisterUnitGossipEvent(npcid, 2, "Anti_PvP_System_Select")
 
function gtwarnings(name)
        if(plr2_tab[tostring(v)]~=true)then
                return 0;
        else
                return plr1_tab[tostring(v)].warnings;
        end
end
 
function lfpvp(unt, _)
local plr = unt:GetInRangePlayers()
        for k, v in pairs(plr) do
                if(v:IsPlayerAttacking(true))and(v:GetDistance(unt)<=1400)then
                        if(plr1_tab[tostring(v)]==nil)and(plr2_tab[tostring(v)]~=true)then
                                plr1_tab[tostring(v)] = {}
                                plr1_tab[tostring(v)].warnings = 0
                                plr2_tab[tostring(v)] = true
                        end
                        if(plr1_tab[tostring(v)].attcheck~=true)and(plr1_tab[tostring(v)].banned~=true)then
                                plr1_tab[tostring(v)].attcheck = true
                                RegisterTimedEvent("attcheck_nil",3000,1,v)
                                punishment(v, v:GetSelection(), unt)
                        end
           end
        end
end
 
RegisterUnitEvent(34101, 18, "anti_pvp")
 
function attcheck_nil(v)
        plr1_tab[tostring(v)].attcheck = false
end
 
function punishment(plr1, plr2, unt)
if(CharDBQuery("SELECT player FROM pvp_banned_player WHERE player='"..plr1:GetName().."';")==nil) then
        CharDBQuery("INSERT INTO `pvp_banned_player` VALUES('', '"..plr1:GetName().."', '0', '', '', '');")
        end
        local warning = CharDBQuery("SELECT warnings FROM pvp_banned_player WHERE player='"..plr1:GetName().."';")
        plr1_tab[tostring(plr1)].warnings = warning:GetColumn(0):GetString()+1
        CharDBQuery("UPDATE `pvp_banned_player` SET `warnings` = '"..plr1_tab[tostring(plr1)].warnings.."' WHERE player = '"..plr1:GetName().."';")
        SendWorldMessage("|CFFFF0000[Anti-PvP]: |R|CFFFFFFFF"..plr1:GetName().." hat seine "..plr1_tab[tostring(plr1)].warnings..". Warnung erhalten, bei "..maxwarning.." Warnungen wird er f\195\188r "..banntime.." Minuten gebannt!|R", 2)
        if(typ==0)and(maxwarning>plr1_tab[tostring(plr1)].warnings)then
                unt:Kill(plr1)
        elseif(typ==1)then
                plr1:RemovePvPFlag()
                plr2:RemovePvPFlag()
                plr1:SetNextTarget(unt)
                plr2:SetNextTarget(unt)
        elseif(typ==2)and(maxwarning>plr1_tab[tostring(plr1)].warnings)then
                plr1:KickPlayer(1000)
        end
        if(bannsys == true)then
                if(maxwarning<=plr1_tab[tostring(plr1)].warnings)then
                        local name = plr1:GetName()
                        plr1_tab[tostring(plr1)].banned = true
                        SendWorldMessage("|CFFFF0000[Anti-PvP]: |R|CFFFFFFFF"..plr1:GetName().." wurde wegen merfachen verbotenen PVP`s fόr "..banntime.." Minuten gebannt|R", 2)
                        plr2:SendBroadcastMessage("|CFFFF0000[Anti-PvP]: |R|CFFFFFFFF"..sorry_text.."|R")
                        RegisterTimedEvent("bann_player",4000,1,name)
                end
        end
end
 
 
 
function bann_player(name)
        local plr = GetPlayer(name)
        plr:SoftDisconnect()
        plr1_tab[tostring(plr)] = nil
        plr2_tab[tostring(plr)] = nil
        CharDBQuery("UPDATE pvp_banned_player SET `warnings` = '0' WHERE player = '"..name.."';")
        local t = os.date("*t")
        local ti = t.hour*3600+t.min*60+t.sec
        local bt = ti+banntime*60
        local date = t.day..";"..t.month..";"..t.year
        CharDBQuery("UPDATE `pvp_banned_player` SET `time_start` = '"..ti.."', time_end = '"..bt.."', date = '"..date.."' WHERE player = '"..name.."';")
        CharDBQuery("UPDATE `characters` SET `online` = '0' WHERE name = '"..name.."';")
        CharDBQuery("UPDATE `characters` SET `banned` = '1' WHERE name = '"..name.."';")
        RegisterTimedEvent("player_bann_remove",banntime*60*1000,1,name)
end
 
 
function player_bann_remove(name)
        CharDBQuery("UPDATE pvp_banned_player SET `time_start` = '0', time_end = '0', date = '0' WHERE player = '"..name.."';")
        CharDBQuery("UPDATE characters SET banned=0 WHERE name = '"..name.."';")
end
 
 
function bannsystem_serverrestart()
        if(bannsys==true)then
                local column = CharDBQuery("SELECT MAX(id) FROM pvp_banned_player;"):GetColumn(0):GetFloat()
                        for x=1,column,1 do
                                        if(CharDBQuery("SELECT id FROM pvp_banned_player WHERE id='"..x.."';")~=nil)then
                                                local pl_name = CharDBQuery("SELECT player FROM pvp_banned_player WHERE id='"..x.."';"):GetColumn(0):GetString()
                                                local pl_bend = CharDBQuery("SELECT time_end FROM pvp_banned_player WHERE id='"..x.."';"):GetColumn(0):GetFloat()
                                                local pl_date = CharDBQuery("SELECT date FROM pvp_banned_player WHERE id='"..x.."';"):GetColumn(0):GetString() 
                                                local t = os.date("*t")        
                                                local os_date = t.day..";"..t.month..";"..t.year
                                                if(pl_name~=nil)then
                                                        if(pl_date==os_date)and(t.hour*3600+t.min*60+t.sec<pl_bend)then
                                                                local ti = (pl_bend-(t.hour*3600+t.min*60+t.sec))*1000
                                                                RegisterTimedEvent("player_bann_remove",ti,1,pl_name)
                                                        else
                                                                player_bann_remove(pl_name)
                                                        end
                                                end
                                        end
                                end
        end
end
bannsystem_serverrestart()
print("Anti-PvP erfolgreich geladen!")