/*
* Copyright (C) Likan Mod 2012-2013 <https://github.com/ChaosDevLikan/>
* Copyright (C) 3server 2005-2013 <https://cata.3server>
 *
 * World of Warcraft: Cataclysm 
 * You can edit but you can not delete this copyright.
 * 3server Emulator - 3server Database 
 *
 *
 * By Likan Developer Core C++, SQL (FUN, WoTLK, Cata Realm) of 3server Server
 */

#ifndef _MAP_UPDATER_H_INCLUDED
#define _MAP_UPDATER_H_INCLUDED

#include <ace/Thread_Mutex.h>
#include <ace/Condition_Thread_Mutex.h>

#include "DelayExecutor.h"

class Map;

class MapUpdater
{
    public:

        MapUpdater();
        virtual ~MapUpdater();

        friend class MapUpdateRequest;

        int schedule_update(Map& map, ACE_UINT32 diff);

        int wait();

        int activate(size_t num_threads);

        int deactivate();

        bool activated();

    private:

        DelayExecutor m_executor;
        ACE_Thread_Mutex m_mutex;
        ACE_Condition_Thread_Mutex m_condition;
        size_t pending_requests;

        void update_finished();
};

#endif //_MAP_UPDATER_H_INCLUDED
