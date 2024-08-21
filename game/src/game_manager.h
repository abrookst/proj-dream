#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "encounter/encounter.h"
#include "encounter/battle_encounter.h"
#include "ui.h"

class GameManager
{
private:
    static GameManager* instance;

    Encounter* currentEncounter = nullptr;

public:
    GameManager();

    void Next(Action action);

    void SetEncounter(Encounter& enc);

    void GoForward();

    void StartRun();

    std::vector<Monster*> monsters = {
        new Monster(20, 5, 95, 20, { ATTACK }, "ghoul"),
        new Monster(20, 5, 95, 20, { ATTACK, BLOCK }, "skeleton")
    };

    static GameManager* GetInstance() { return instance; };
};

#endif