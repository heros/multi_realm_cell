/*
 * Copyright (C) Likan Mod   (https://github.com/ChaosDevLikan/)
 * Copyright (C) Prydev      (http://sourceforge.net/projects/prydevserver) 
 * Copyright (C) TrinityCore (http://www.trinitycore.org)
 * Copyright (C) MaNGOS      (http://www.getmangos.com)
 * Copyright (C) ArkCORE     (http://www.arkania.net)
 * Copyright (C) SkyFireEMU  (http://www.projectskyfire.org)
 *
 * World of Warcraft
 * You can edit but you can not delete this copyright.
 * Genesis Emulator - Genesis Database 
 *
 *
 * By Likan Developer Core C++, SQL (FUN, WoTLK, Cata Realm) of Genesis Server
 */

#include "ScriptMgr.h"
#include "Player.h"

class AT_example_areatrigger : public AreaTriggerScript
{
    public:

        AT_example_areatrigger()
            : AreaTriggerScript("example_areatrigger")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
        {
            player->Kill(player);
            return true;
        }
};

class ItemUse_example_item : public ItemScript
{
    public:

        ItemUse_example_item()
            : ItemScript("example_item")
        {
        }

        bool OnUse(Player* /*player*/, Item* /*item*/, SpellCastTargets const& /*targets*/)
        {
            sScriptMgr->LoadDatabase();
            return true;
        }
};

class GOHello_example_go_teleporter : public GameObjectScript
{
    public:

        GOHello_example_go_teleporter()
            : GameObjectScript("example_go_teleporter")
        {
        }

        bool OnGossipHello(Player* player, GameObject* /*go*/)
        {
            player->TeleportTo(0, 1807.07f, 336.105f, 70.3975f, 0.0f);
            return false;
        }
};

void AddSC_example_misc()
{
    new AT_example_areatrigger();
    new ItemUse_example_item();
    new GOHello_example_go_teleporter();
}
