#ifndef BLOCSEQUENCE_H
#define BLOCSEQUENCE_H

#include "BlocComposite.h"

namespace BehaviourTree
{
    class BlocSequence : public BlocComposite
    {
    public:

		virtual result operator()(BlackBoard &bboard)
        {

            for (int i = 0; i < getNbChild(); ++i)
            {
				if (((*children[i])(bboard)) == result::FAIL)
                {
                    return result::FAIL;
                }
            }
            return result::SUCCESS;
        }

    };
}



#endif //!BLOCSEQUENCE_H
