#ifndef BATTLE_ENCOUNTER_H
#define BATTLE_ENCOUNTER_H

#include "encounter.h"
#include "../entity/monster.h"
#include "../entity/player.h"
#include "../action/action.h"
#include <cstdint>

class BattleEncounter : public Encounter
{
    Monster* monster;
    Player* player;

public:
    BattleEncounter(Monster& m);
    void NextTurn();

    uint8_t GetPlayerHealth() { return player->GetHealth(); }
    uint8_t GetPlayerMaxHealth() { return player->GetMaxHealth(); }
    uint8_t GetPlayerMana() { return player->GetMana(); }
    uint8_t GetPlayerMaxMana() { return player->GetMaxMana(); }
    uint8_t GetPlayerAccuracy() { return player->GetAccuracy(); }
    uint8_t GetPlayerAttackPower() { return player->GetAttackPower(); }
    std::vector<Action*>& GetPlayerActions() { return player->GetActions(); }

    uint8_t GetMonsterHealth() { return monster->GetHealth(); }
    uint8_t GetMonsterAccuracy() { return monster->GetAccuracy(); }
    uint8_t GetMonsterAttackPower() { return monster->GetAttackPower(); }

};

#endif
