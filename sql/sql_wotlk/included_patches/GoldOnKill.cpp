
#include "ScriptPCH.h"

class GoldOnKill : public PlayerScript
{
	public:
	GoldOnKill() : PlayerScript("GoldOnKill") {}
//1
  //void OnPVPKill(Player * killer, Player * killed)
    //{
    //killer->SetMoney(killer->GetMoney() + 20000);
    //sWorld->SendWorldText(LANG_SYSTEMMESSAGE, Win!!!);
    //killed->SetMoney(killed->GetMoney() - 10000);
    //} 

//2

};

void AddSC_GoldOnKill()
{
	new GoldOnKill();
}
