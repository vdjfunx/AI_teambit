#ifndef BLOCSELECT_H
#define BLOCSELECT_H

#include "BlocComposite.h"

namespace BehaviourTree
{
    class BlocSelect : public BlocComposite
    {
    public:

        virtual result operator()()
        {

            for (int i = 0; i < getNbChild(); ++i)
            {
                if (((*children[i])()) == result::SUCCESS)
                {
                    return result::SUCCESS;
                }
            }

            return result::FAIL;
        }

    };
}



#endif //!BLOCSELECT_H