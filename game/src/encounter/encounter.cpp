#include "encounter.h"

Encounter* Encounter::instance = nullptr;

void Encounter::SelectNextEncounter() {
  TextEngine* textEngine = TextEngine::GetInstance();
  textEngine->Write("Where will you go next?");
}