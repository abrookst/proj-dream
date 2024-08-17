#ifndef EVENT_ENCOUNTER_H
#define EVENT_ENCOUNTER_H

#include "../encounter.h"

class EventEncounter : public Encounter {
protected:
public:
    EventEncounter() { encType = EVENT; }
    virtual void startEvent() = 0;
};

#endif
