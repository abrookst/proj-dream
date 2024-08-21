#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include "../action.h"
#include "../text_engine.h"

enum EncounterType {
    BATTLE,
    EVENT
};

class Encounter {
public:
    EncounterType GetType() { return encType; }
    virtual void Next(Action) = 0;
    void SetStarted(bool strt) { started = strt; }
    bool GetStarted() { return started; }
    bool GetFinished() { return finished; }
    void SetFinished(bool fnshed) {finished = fnshed; }
protected:
    bool started = false;
    bool finished = false;
    static Encounter* instance;
    EncounterType encType;
    void SelectNextEncounter();
};

#endif
