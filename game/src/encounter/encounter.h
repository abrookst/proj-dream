#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include "../action.h"

enum EncounterType {
    BATTLE,
    EVENT
};

class Encounter {
public:
    EncounterType GetType() { return encType; }
    virtual void Next(Action) = 0;
protected:
    static Encounter* instance;
    EncounterType encType;
};

#endif
