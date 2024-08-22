#ifndef ACTION_H
#define ACTION_H

#include "entity/entity.h"
#include "text_engine.h"
#include "entity/monster.h"

void Attack(Entity&, Entity&);
void Block(Entity&);
void Talk(Monster&);
void Other(Entity&, Entity&, Action);

#endif