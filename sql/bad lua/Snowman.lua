function Happy_Snowman_Menu(pUnit, event, player)
pUnit:GossipCreateMenu(50, player, 0)
pUnit:GossipMenuAddItem(0, "I found you!", 1, 0)
pUnit:GossipMenuAddItem(0, "I want to keep you a secret!", 2, 0)
pUnit:GossipSendMenu(player)
end


function Happy_Snowman_Submenu(pUnit, event, player, id, intid, code)
if(intid == 1) then
player:GossipComplete()
player:AddItem(itemID, 1)
pUnit:Despawn(3, Spawntime) 
elseif(intid == 2) then
player:GossipComplete()
end
end


RegisterUnitGossipEvent(EntryID, 1, "Happy_Snowman_Menu")
RegisterUnitGossipEvent(EntryID, 2, "Happy_Snowman_Submenu")