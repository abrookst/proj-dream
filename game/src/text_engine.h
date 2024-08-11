#ifndef TEXT_ENGINE_H
#define TEXT_ENGINE_H 

#include <queue>
#include <utility>
#include <string.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <raylib.h>

class TextEngine
{
    char* finalBuffer;
    std::queue<std::string*> writeQueue;
    uint8_t delay = 0;
    uint8_t pause = 0;
    uint8_t frameCount = 0;
    uint8_t lineState = 0;

    std::string FormatText(const std::string&);
public:
    TextEngine(Font&);
    ~TextEngine();
    void Write(const std::string&);
    bool IsDone() { return writeQueue.empty(); }
    uint8_t GetLineState() { return lineState; }
    void SetDelay(uint8_t d) { delay = d; }
    void SetPause(uint8_t p) { pause = p; }
    void UpdateText(bool);
};


#endif
