#ifndef TEXT_ENGINE_H
#define TEXT_ENGINE_H 

#include <utility>
#include <string.h>
#include <stdio.h>
#include <string>
#include <sstream>

class TextEngine
{
    std::string writeBuffer;
public:
    void Write(const std::string&);
    bool IsDone();
};


#endif
