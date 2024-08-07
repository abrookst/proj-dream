#ifndef BLOCK_H
#define BLOCK_H

#include "action.h"
#include "../entity/entity.h"

class Block : public Action
{
public:
    void Perform(
            Entity&,
            Entity&);
    void Perform(
            Entity&);
};

#endif
