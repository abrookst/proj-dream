#ifndef MAGIC_BLAST_H
#define MAGIC_BLAST_H

#include "../action.h"
#include "../../entity/entity.h"

class MagicBlast : public Action
{
public:
    void Perform(
            Entity&,
            Entity&);
};

#endif
