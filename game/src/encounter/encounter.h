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
    static Encounter* GetInstance( ) { return instance; };
protected:
    bool started = false;
    bool finished = false;
    static Encounter* instance;
    EncounterType encType;
};

#endif
