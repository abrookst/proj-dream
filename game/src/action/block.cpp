#include "block.h"

void Block::Perform(
        Entity& entity)
{
    entity.SetBlock(true);
}

void Block::Perform(
        Entity& entity,
        Entity& e2)
{
}

