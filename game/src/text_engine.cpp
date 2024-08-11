#include "text_engine.h"

TextEngine::TextEngine(
        Font& mainFont)
{
   finalBuffer = new char[30];
   for (int i=0; i<30; i++)
   {
       finalBuffer[i] = '0';
   }
   DrawTextEx(mainFont, finalBuffer, Vector2{ 3, 47 }, 6, 1, RED);
}

TextEngine::~TextEngine(
        void)
{
    delete finalBuffer;
    while (!writeQueue.empty())
    {
        delete writeQueue.front();
        writeQueue.pop();
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
    std::string* ptr = new std::string;
    *ptr = FormatText(input);
    writeQueue.push(ptr);
}

void TextEngine::UpdateText(
        bool userPressedEnter)
{
    if (writeQueue.front()->empty()) 
    {
        frameCount = 0;
        lineState = 0;
        return;
    } 
    else if (delay && frameCount % delay) 
    {
        frameCount++;
        return;
    }
    if (!userPressedEnter && lineState == 2) {
        return;
    }
    if (lineState == 2 && frameCount > 0 && userPressedEnter)
    {
        finalBuffer = "";
        lineState = 0;
        return;
    }

    char tempChar = writeQueue.front()->front(); 
    *finalBuffer += tempChar;
    writeQueue.front()->erase(0);

    if (writeQueue.front()->front() == '\n')
    {
        finalBuffer += '\n';
        lineState++;
  }
    frameCount++;
    return;
}
