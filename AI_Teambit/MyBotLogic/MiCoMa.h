#ifndef MICOMA_H
#define MICOMA_H

#include "Singleton.h"
#include "Objective.h"

#include "Logger.h"
#ifdef _DEBUG
#define BOT_LOGIC_DEBUG_MICOMA
#endif

#ifdef BOT_LOGIC_DEBUG_MICOMA
#define BOT_LOGIC_MICOMA_LOG(logger, text, autoEndLine) logger.Log(text, autoEndLine)
#else
#define BOT_LOGIC_MICOMA_LOG(logger, text, autoEndLine) 0
#endif

#include <vector>
#include <algorithm>
#include <map>



class Npc;
struct LevelInfo;
struct TurnInfo;
struct NPCInfo;
class MiCoMa : Singleton
{

    std::vector<Npc*> mNpcs;
	std::map<unsigned int, unsigned int> findBestGoalByNpc(const std::map<unsigned int, NPCInfo>& npcInfo, std::vector<unsigned int>& targetList);
	std::map<unsigned int, unsigned int> findBestGoalByGoal(std::map<unsigned int, NPCInfo> npcInfo, const std::vector<unsigned int>& targetList);
	
	Logger mLogger;

public :
    static MiCoMa* getInstance()
    {
        static MiCoMa instance;
        return &instance;
    }

    void init(const LevelInfo&);
    void update(const TurnInfo&);
};

#endif //MICOMA_H
