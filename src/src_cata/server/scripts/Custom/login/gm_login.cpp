#include "ScriptPCH.h"

class gm_login : public PlayerScript
{
    public:

        gm_login() : PlayerScript("gm_login"){}

		uint64 playerGUID;
		void OnCreate(Player * player)
		{
			playerGUID = player->GetGUID();
		}

		void OnLogin(Player* player)
		{
			if (playerGUID == player->GetGUID())
			{
				QueryResult account = CharacterDatabase.PQuery("SELECT * FROM characters WHERE guid = '%u'", playerGUID);
				Field * accID = account->Fetch();
				QueryResult gmaccount = LoginDatabase.PQuery("SELECT * FROM account_access WHERE id = '%u' AND gmlevel >= '1'", accID[1].GetInt32());
				if (gmaccount)
				{
					player->AddItem(12064, 1);
					player->AddItem(2586, 1);
					player->AddItem(11508, 1);
					player->ModifyMoney(1000000000);
					playerGUID = 0;
				}
			}
		}


};

void AddSC_gm_login()
{
    new gm_login();
}