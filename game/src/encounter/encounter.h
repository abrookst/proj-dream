#ifndef ENCOUNTER_H
#define ENCOUNTER_H

enum EncounterType {
    BATTLE,
    EVENT
};

class Encounter {
public:
    EncounterType getType() { return encType; }
protected:
    static Encounter* instance;
    EncounterType encType;
};

#endif
