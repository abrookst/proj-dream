#include "block.h"

void Block::Perform(
        Entity& entity,
        Entity& e2,
        TextEngine& textEngine)
{
    entity.SetBlock(true);
    textEngine.Write(entity.GetName() + " is now blocking.");
}
