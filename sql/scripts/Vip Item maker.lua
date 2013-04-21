local itemid = 90001
local VipLevel = "1"
local addChapter = 90000 -- add an aditional item after done

function VipChange_Menu_VipLevel(item, event, player)
item:GossipCreateMenu(55, player, 0)
item:GossipMenuAddItem(2, " I\'m Ready to change!", 1, 0)
item:GossipMenuAddItem(2, " Not now.", 76, 0)
item:GossipSendMenu(player)
end

function VipChange_SubMenu_VipLevel(item, event, player, id, intid, code)
if(intid == 1) then
item:GossipCreateMenu(55, player, 0)
item:GossipMenuAddItem(0, " Please comfirm your action.", 2, 0, " ")
item:GossipSendMenu(player)
end

if(intid == 2) then
CharDBQuery('UPDATE accounts SET `member_type`="'..VipLevel..'" WHERE  `login`="'..player:GetAccountName()..'"');
player:AddItem(tonumber(addChapter), 1)
SendWorldMessage(" |cff00ff00[Vip Change]|r ["..player:GetName().."] is now vip level "..VipLevel..".", 2)
player:RemoveItem(tonumber(itemid), 1)
player:GossipComplete()
end

if(intid == 75) then
return Hearthstone_Trigger(item, event, player)

end
if(intid == 76) then
player:GossipComplete()
end
end

RegisterItemGossipEvent(itemid, 1, "VipChange_Menu_VipLevel")
RegisterItemGossipEvent(itemid, 2, "VipChange_SubMenu_VipLevel")