#include "ScriptPCH.h"

class OnPlayerLogin : public PlayerScript
{
public:
OnPlayerLogin() : PlayerScript("OnPlayerLogin") {}

void OnLogin(Player * player)
{
char msg[500];
sprintf(msg, "%s Has Logged Into The Server!",player->GetName());
sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
}
}; 
void AddSC_OnPlayerLogin()
{
new OnPlayerLogin();
}
