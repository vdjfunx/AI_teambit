#ifndef BLOC_UPDATE_NPC_TILES_H
#define BLOC_UPDATE_NPC_TILES_H

#include "GeneralAction.h"
#include "../MiCoMa.h"
#include "../Npc.h"
#include "../Map.h"

/*
	This block's purpose is to update the different tiles onto which stand the many npcs.
*/

BehaviourTree::BaseBloc* getBlocUpdateNpcTiles(BlackBoard &bboard)
{
    auto forUpdateLambda = [&bboard]()
    {
        std::vector<Action*> _actionList = bboard.getActionList();

        Map * map = Map::getInstance();
        for (Npc* npc : MiCoMa::getInstance()->getNpcs())
        {
            map->addVisitedTile(npc->getCurrentTile());
            if (npc->isArrived())
            {
                map->getNode(npc->getCurrentTile())->setType(Node::OCCUPIED);
            }
        }
        return BehaviourTree::result::SUCCESS;
    };

    return BehaviourTree::createAction(forUpdateLambda);
}
#endif //BLOC_UPDATE_NPC_TILES_H
