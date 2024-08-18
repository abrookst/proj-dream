#ifndef ENCOUNTER_H
#define ENCOUNTER_H

enum EncounterType {
    BATTLE,
    EVENT
};

class Encounter {
public:
    EncounterType GetType() { return encType; }
    bool IsDone() { return isDone; }
    void SetDone(bool d) { isDone = d; }
protected:
    static Encounter* instance;
    EncounterType encType;
    bool isDone;
};

#endif
