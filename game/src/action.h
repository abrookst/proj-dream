#include "entity/entity.h"
#include "text_engine.h"
#include "entity/monster.h"

void Attack(Entity&, Entity&, TextEngine&);
void Block(Entity&, TextEngine&);
void Talk(Monster&, TextEngine&);
void Other(Entity&, Entity&, Action, TextEngine&);
