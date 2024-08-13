#include "text_engine.h"

TextEngine::TextEngine(
        Font& font)
{
    mainFont = &font;
    // finalBuffer = new std::string();
    DrawTextEx(*mainFont, finalBuffer.c_str(), Vector2{ 3, 47 }, 6, 1, color);
}

TextEngine::~TextEngine(
        void)
{
    // delete finalBuffer;
    while (!writeQueue.empty())
    {
        std::string* tmpPtr = writeQueue.front();
        writeQueue.pop();
        delete tmpPtr;
    }
}


std::string TextEngine::FormatText(
    const std::string& inputString) 
{
    std::stringstream textStream((std::string(inputString)));
    std::string output = "";
    std::string temp = "";
    int currWidth = 0;

    while (textStream >> temp) 
    {
        //printf("word: %s\ncurrWidth: %d\n", temp.c_str(), currWidth);
        while (temp != "") {
            if (temp.length() > 14 && currWidth == 0) 
            {
                std::string word =  temp.substr(0, 13);
                temp = temp.substr(13);
                output += word + "-";
                currWidth = 14;
            }
            if (currWidth + temp.length() > 14) 
            {
                currWidth = 0;
                output += "\n";
            }
            else 
            {   
                output += temp;
                currWidth += temp.length();
                temp = "";
            }
        }
        if (currWidth != 14) 
        {
            output += temp + " ";
            currWidth++;
        }
    }
    return output.substr(0, output.length() - 1);
}

void TextEngine::Write(const std::string& input)
{
    std::string* ptr = new std::string(FormatText(input));
    writeQueue.push(ptr);
}

void TextEngine::UpdateText(
        bool userPressedEnter)
{
    if (writeQueue.empty())
    {
        DrawTextEx(*mainFont, finalBuffer.c_str(), Vector2{ 3, 47 }, 6, 1, color);
        return; 
    }
    else if (writeQueue.front()->empty()) 
    {
        std::string* tmpPtr = writeQueue.front();
        writeQueue.pop();
        delete tmpPtr;
        frameCount = 0;
        lineState = 3;
        return;
    } 
    else if (delay && frameCount % delay) 
    {
        DrawTextEx(*mainFont, finalBuffer.c_str(), Vector2{ 3, 47 }, 6, 1, color);
        frameCount++;
        return;
    }
    else if (lineState == 2 )
    {
        if (userPressedEnter && frameCount > 0) 
        {
            writeQueue.front()->erase(0,1);
            finalBuffer.clear();
            DrawTextEx(*mainFont, finalBuffer.c_str(), Vector2{ 3, 47 }, 6, 1, color);
            lineState = 0;
        }
        DrawTextEx(*mainFont, finalBuffer.c_str(), Vector2{ 3, 47 }, 6, 1, color);
        return; 
    }
    else if (lineState == 3)
    {
        if (userPressedEnter)
        {
            finalBuffer.clear();
            lineState = 0;
        }
        DrawTextEx(*mainFont, finalBuffer.c_str(), Vector2{ 3, 47 }, 6, 1, color);
        return;
    }

    finalBuffer += writeQueue.front()->front(); 
    writeQueue.front()->erase(0,1);

    if (writeQueue.front()->front() == '\n') { lineState++; }

    frameCount++;
    DrawTextEx(*mainFont, finalBuffer.c_str(), Vector2{ 3, 47 }, 6, 1, color);
    return;
}
