#include "entity/entity.h"
#include "text_engine.h"

void Attack(Entity&, Entity&, TextEngine&);
void Block(Entity&, TextEngine&);
void Talk(Entity&, TextEngine&);
void SpecialAttack(std::string, Entity&, Entity&, TextEngine&);
void Item(std::string, Entity&, Entity&, TextEngine&);
