--[[
	Eluna Lua Anti Advertiser Script
	#Eluna Lua Engine
	#Credits: ak47sigh aka alexewarr
]]--

local banned_words = { -- begin of the list
	"http://"		, 
	"logon."		, 
	"www."			, 
	"web."			, 
	"wow."			, 
	".com"			, 
	".it"			, 
	".de"			, 
	".org"			, 
	".net"			, 
	".ru"			, 
	".ro"			,
	"rondor"		-- end of the list
}

function OnMessage(event, player, msg, Type, lang)
	for _,v in pairs(banned_words) do 
		if string.find(msg, v) then
			player:SendBroadcastMessage("You are not allowed to advertise:  "..msg.." ")
			-- ban it for doing that
			return false
		end
	end
end

local eventID = 18 -- { On Chat Usage }
RegisterServerHook(eventID, OnMessage)