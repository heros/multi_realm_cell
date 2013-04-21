--[[Description:
Each time a Game Master is logging it checks
if has less than gold "X" then add gold "Y".
]]--
--Configs:
local Enable = 1 -- If 1 set true, 0 = false
local goldNeeded = 100 -- If GM has less gold then this
local goldToGive = 5000 -- Amount of gold to add
local sendMSG = 1 -- Send message when receives gold (1 = yes, 0 = no) ?
local msgColor = "FF8000" -- Color for the message example: "FF0000" = red
--Configs.
function GM_CHECKIFHAS_GOLD_ON_EW(event, gm)
if(Enable == 1) then
	local c = "|cff"..msgColor..""
	local  gmCoins = gm:GetCoinage()
	local  gmGold = (math.ceil(gmCoins/10000))
	local  goldMerit = (math.ceil(goldToGive*10000))
	local  gmMSG = "GM: Looks like you need some cash. We give you "..goldToGive.."g, check your pocket."

	if (not gm:IsGm()) then
	else
	if (gmGold < tonumber(goldNeeded)) then
	 	gm:DealGoldMerit(goldMerit)
	if (sendMSG == 1) then
	 	gm:SendBroadcastMessage(c..""..gmMSG)
	end
	end 
	end
else
end
end
RegisterServerHook(4, GM_CHECKIFHAS_GOLD_ON_EW)
--[[Copyright (C) Anechitei Alexandru]]--