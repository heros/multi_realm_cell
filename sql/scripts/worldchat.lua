local COMMAND_MESSAGE = ".world"
local COLOR_RANK = "|cff00ff00"
local COLOR_PLRNAME = "|cffff6060"
local COLOR_TEXT = "|cffffffff"



local function WorldChat(_, plr, msg)
	for x=1,string.len(COMMAND_MESSAGE),1 do
			if(string.sub(COMMAND_MESSAGE,x,x)==".")then if(string.sub(COMMAND_MESSAGE,x,x)~=string.sub(msg,x,x))then return; end end
			if(x>1)then
				local cmd = string.sub(COMMAND_MESSAGE,1,x)
				local s,e = string.find(msg, cmd)
				if(s==1)and(e==x)then
					if(string.lower(msg):find(cmd.." "))then
							local text = msg:gsub(cmd.." ", "")
							WorldDBQuery("INSERT INTO chat_out (name,text,timer) VALUES('"..plr:GetName().."','"..text.."', '0');")
							SendWorldMessage("|cff00ccff[Worldchat]|R |cffff6060["..plr:GetName().."]|R |cffffffffwrote: "..text.."|R",2)
							return false;
					end	
				end
			end
		end
end
RegisterServerHook(16, WorldChat)

function WorldChat_Check()
	local query = LSA.sqltoluatable("chat_inc", "world", {"id","name","text","timer"},false)
	for k,v in pairs(query)do
		SendWorldMessage("|cff00ccff[Worldchat]|R |cffff6060["..v[2].."]|R |cffffffffwrote: "..v[3].."|R",2)
	end
	WorldDBQuery("DELETE FROM chat_inc;")
end

RegisterTimedEvent("WorldChat_Check", 3000, 0)