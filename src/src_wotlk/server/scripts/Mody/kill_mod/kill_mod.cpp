/* inklude */
  #include "ScriptPCH.h"
/* define */
/* class */

  class kill_mod : public PlayerScript
{
	public:
	kill_mod() : PlayerScript("kill_mod") {}
/* funkce */
////////////////////////////hrači vs hrači//////////////////////////////////
/* mod 1 */ // pvp ali - horde
/*
  void OnPVPKill(Player * killer, Player * killed)
    {
    uint32 killerlvl = killer->getLevel();
    uint32 killedlvl = killed->getLevel();
    int32 diff = killerlvl-killedlvl;
    uint32 XPLow = (killedlvl*5+45)*(1+0.05*diff);
    uint32 XPHigh = (killedlvl*5+45)*(1+0.05*diff);
    uint32 minusgold = killer->GetMoney()-(diff*10000);
    uint32 plusgold = killer->GetMoney()+(diff*10000);
    uint32 killergold = killer->GetMoney();
    uint32 killedgold = killed->GetMoney();
	uint32 plusgold2= killedgold+killergold;
/*
   if (killerlvl < killedlvl +1)
   killer->GiveXP(XPHigh , killed);

   else 
   if (diff > 10)

    if(killerlvl < killedlvl -1)
    { 
    killer->GiveXP(XPLow , killed);
    }

    if (killerlvl < killedlvl +2)
    {
    killer->SetMoney(plusgold2);
	killer->GiveXP(XPHigh , killed);
    //killed->SetMoney(minusgold);  // !!! bug otoči menu
    }

    if (killerlvl < killedlvl -1)
    {
    killer->SetMoney(minusgold);
    killed->SetMoney(plusgold);
    }
    }
*/
/*
   //start
   if (killerlvl < killedlvl +1)
   killer->GiveXP(XPHigh , killed);
   killer->SetMoney(plusgold);
   else
   if (diff > 10)
   if (killergold > minusgold)
   {
   killer->SetMoney(minusgold);
   }
   else 
   if(0  < diff && diff <10) 
   killer->GiveXP(XPLow , killed);
   //konec

   //start
   if (killerlvl < killedlvl +2)
   killer->GiveXP(XPHigh , killed);
   killer->SetMoney(plusgold2);
   else
   if (diff > 10)
   if (killergold > minusgold)
   {
   killer->SetMoney(minusgold);
   }
   else 
   if(0  < diff && diff <10) 
   killer->GiveXP(XPLow , killed);
   //konec

   //start
   if(killerlvl < killedlvl -1)
   { 
   killer->GiveXP(XPLow , killed);
   killer->SetMoney(minusgold);
   }
   else 
   if(0  < diff && diff <10) 
   killer->GiveXP(XPLow , killed);
   //konec
    }
    }



/* mod 2 */  
// zabytie aly - aly kill, horde - horde kill
/*  void OnPvPKill(Player *pKiller, Player *pVictim)
    {
    int reward = 100; 
    {
    if(pKiller->GetTeam() != pVictim->GetTeam()) 
    {
    int honor = pKiller->GetHonorPoints();
    pKiller->ModifyHonorPoints(honor + reward);
   }
   }
   }
*/
/* mod 3 */
// pvp duely
/* void OnDuelEnd(Player *winner, Player *looser, DuelCompleteType type)
    {
    uint32 winnerlvl = winner->getLevel();
    uint32 looserlvl = looser->getLevel();
    int32 diff = winnerlvl-looserlvl;
    uint32 XPLow = (looserlvl*5+45)*(1+0.05*diff);
    uint32 XPHigh = (looserlvl*5+45)*(1+0.05*diff);
    uint32 minusgold = winner->GetMoney()-(diff*10000);
    uint32 plusgold = looser->GetMoney()+(diff*10000);
    uint32 winnergold = winner->GetMoney();
    uint32 loosergold = looser->GetMoney();

    winner->RemoveArenaSpellCooldowns();
    looser->RemoveArenaSpellCooldowns();
    winner->SetHealth(winner->GetMaxHealth());
    winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
    looser->SetHealth(looser->GetMaxHealth());
    looser->SetPower(POWER_MANA, looser->GetMaxPower(POWER_MANA));

    if (winnerlvl < looserlvl +1)
    {
    winner->GiveXP(XPHigh , looser);
    } 
    if(winnerlvl < looserlvl -1)
    { 
    winner->GiveXP(XPLow , looser);
    }
    if (winnerlvl < looserlvl +1)
    {
    winner->SetMoney(plusgold);
    looser->SetMoney(minusgold);
    }
    if (winnerlvl < looserlvl -1)
    {
    winner->SetMoney(minusgold);
    looser->SetMoney(plusgold);
    }
    }
   }
*/
/* funkce */
////////////////////////////hrači vs moby//////////////////////////////////
/* mod 4 */
/*
  void OnCreatureKill(Player* killer, Creature* killed)
    {
    uint32 killerlvl = killer->getLevel();
    uint32 killedlvl = killed->getLevel();
    int32 diff = killerlvl-killedlvl;
    uint32 XPLow = (killedlvl*5+45)*(1+0.05*diff);
    uint32 XPHigh = (killedlvl*5+45)*(1+0.05*diff);

    if (killerlvl < killedlvl +1)
    {
    killer->GiveXP(XPHigh , killed);
    }

    if(killerlvl < killedlvl -1)
    { 
    killer->GiveXP(XPLow , killed);
    }

    killer->ModifyMoney(+11111);
	}
*/
/* mod 5 */
/*
void OnPlayerKilledByCreature(Creature* killer, Player* killed)
    {
    killed->ModifyMoney(-11111);
    }
*/
/* funkce */
//////////////////////////// kilstraik kecani //////////////////////////////////
/* mod 6 *//*
/*
void OnLogin(Player * player)
{
char msg[500];
sprintf(msg, "%s Has Logged Into The Server!",player->GetName());
sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
*/

};

void AddSC_kill_mod()
{
	new kill_mod();
}

