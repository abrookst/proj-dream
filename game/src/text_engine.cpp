#include "text_engine.h"

TextEngine::TextEngine()
{
   finalBuffer = new char[30]; 
}

TextEngine::~TextEngine()
{
    delete finalBuffer;
    while (!writeQueue.empty())
    {
        delete writeQueue.front();
        writeQueue.pop();
    }
}

void TextEngine::Write(const std::string&)
{

}
