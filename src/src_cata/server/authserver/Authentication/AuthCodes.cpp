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

#include "AuthCodes.h"
#include <cstddef>

namespace AuthHelper
{
    static RealmBuildInfo const PostBcAcceptedClientBuilds[] =
    {
        {16650, 5, 2, 0, ' '},
        {16309, 5, 1, 0, ' '},
        {16048, 5, 0, 5, ' '},
        {16016, 5, 0, 4, ' '},
        {15595, 4, 3, 4, ' '},
        {15254, 4, 3, 3, ' '},
		{15211, 4, 3, 2, ' '},
        {15005, 4, 3, 0, ' '},
        {14545, 4, 2, 2, ' '},
        {14480, 4, 2, 0, ' '},
        {13914, 4, 1, 0, ' '},
        {13623, 4, 0, 6, 'a'},
        {13596, 4, 0, 6, ' '},
        {12340, 3, 3, 5, 'a'},
        {13329, 4, 0, 3, ' '},
        {12340, 3, 3, 5, 'a'},
        {11723, 3, 3, 3, 'a'},
        {11403, 3, 3, 2, ' '},
        {11159, 3, 3, 0, 'a'},
        {10958, 3, 3, 0, ' '},
        {10505, 3, 2, 2, 'a'},
        {9947,  3, 1, 3, ' '},
        {8606,  2, 4, 3, ' '},
        {0,     0, 0, 0, ' '}                                   // terminator
    };

    static RealmBuildInfo const PreBcAcceptedClientBuilds[] =
    {
        {6005,  1, 12, 2, ' '},
        {5875,  1, 12, 1, ' '},
        {0,     0, 0, 0, ' '}                                   // terminator
    };

    bool IsPreBCAcceptedClientBuild(int build)
    {
        for (int i = 0; PreBcAcceptedClientBuilds[i].Build; ++i)
            if (PreBcAcceptedClientBuilds[i].Build == build)
                return true;

        return false;
    }

    bool IsPostBCAcceptedClientBuild(int build)
    {
        for (int i = 0; PostBcAcceptedClientBuilds[i].Build; ++i)
            if (PostBcAcceptedClientBuilds[i].Build == build)
                return true;

        return false;
    }

    bool IsAcceptedClientBuild(int build)
    {
        return (IsPostBCAcceptedClientBuild(build) || IsPreBCAcceptedClientBuild(build));
    }

    RealmBuildInfo const* GetBuildInfo(int build)
    {
        for (int i = 0; PostBcAcceptedClientBuilds[i].Build; ++i)
            if (PostBcAcceptedClientBuilds[i].Build == build)
                return &PostBcAcceptedClientBuilds[i];

        for (int i = 0; PreBcAcceptedClientBuilds[i].Build; ++i)
            if (PreBcAcceptedClientBuilds[i].Build == build)
                return &PreBcAcceptedClientBuilds[i];

        return NULL;
    }
};
