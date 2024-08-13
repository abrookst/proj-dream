#ifndef BATTLE_ENCOUNTER_H
#define BATTLE_ENCOUNTER_H

#include "encounter.h"
#include "../entity/monster.h"
#include "../entity/player.h"
#include "../action/action.h"
#include "../text_engine.h"
#include <cstdint>
#include <string>

class BattleEncounter : public Encounter
{
    Monster* monster;
    Player* player;
    TextEngine* textEngine;
    std::string writeBuffer = "";
    std::string writeHidBuffer = "";
    int writeFrameCount = 0;
    int writeLineState = 0;
    int writePauseCount = 60;

public:
    BattleEncounter(Monster&, TextEngine&);
    void NextTurn(Action*);

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
