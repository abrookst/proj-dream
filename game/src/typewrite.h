#ifndef typewrite_h
#define typewrite_h

#include <utility>
#include <string.h>
#include <stdio.h>
#include <string>
#include <sstream>

/** 
 * Adds one character of text per frame and adds newlines when required 
 * This is only used for rendering one character per delay period and is
 * to be modified later
 * 
 * @param {char*} fullText      - the desired final text. to be formatted with FormatStringToDialogue
 * @param {char*} buffer        - the text output buffer. should be size 28
 * @param {char*} hidBuff       - hidden buffer without the added characters
 * @param {int&} frameCount     - counts how many frames has it taken to print
 * @param {int&} lineState      - tracks which line the buffer is on [0 is first, 1 is second, 2 indicates pause]
 * @param {int&} pauseCount     - counts the frames before the text continues rendering. initialize to -1 outside
 * @param {int} [delay = 0]     - frames between when each character is drawn
 * @param {int} [pause = 0]     - delay count numbers between reset and drawing
 * @return {bool} has the text finished rendering
 * 
 * Example:
 * 
 * DrawTextEx(mainFont, buffer, Vector2{ 3, 47 }, 6, 1, WHITE);
 * Writer(text, buffer, hidBuff, frameCount, displacemeCount, pauseCount, 5, 20);
 * 
 */

//TODO: divide on word boundaries based on space or using a dash
//      this could also be done via. us manually formatting text
//      or some outside function which takes a string and formats it in the correct way
//      so maybe the goal is make a reformat function for text
//      which would depricate the need to add the newlines
//TODO: make outside pause until propmpted + scroll outside. this is a base

bool Writer(
    char* fullText, 
    char* buffer, 
    char* hidBuff, 
    int& frameCount, 
    int& lineState, 
    int& pauseCount, 
    int delay = 0, 
    int pause = 0) 
{
    if (delay && frameCount % delay) 
    {
        frameCount++;
        return false;
    }
    if (strcmp(fullText, hidBuff)) 
    {
        int len = strlen(hidBuff);
        int bufferLen = strlen(buffer);
        if (lineState == 2 && frameCount > 0 && pauseCount >= 0) 
        {
            pauseCount++;
            if (pause != 0 && !(pauseCount % pause)) 
            {
                memset(buffer, 0, strlen(buffer));
                pauseCount = -1;
                lineState = 0;
            }
            return false;
        }
        buffer[bufferLen] = fullText[len];
        hidBuff[len] = fullText[len];
        if (len + 1 < strlen(fullText) && fullText[len + 1] == '\n') 
        {
            buffer[bufferLen + 1] = '\n';
            buffer[bufferLen + 2] = '\0';
            hidBuff[len + 1] = '\n';
            hidBuff[len + 2] = '\0';
            if (lineState) 
            {
                pauseCount = 0;
            }
            lineState++;
        }
        else 
        {  
            buffer[bufferLen + 1] = '\0';
            hidBuff[len + 1] = '\0';
        }
        frameCount++;
        return false;
    }
    frameCount = 0;
    lineState = 0;
    pauseCount = -1;
    return true;
}

/** 
 * Takes an existing string and reformats it so it has newlines and dashes where required
 * 
 * @param {char*} inputString   - the text to reformat
 * @param {char*} outputString  - the new string with correct newlines and dashes
 * 
 */
void FormatStringToDialogue(
    char* inputString, 
    char* outputString) 
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
    strcpy(outputString, output.c_str());
}

#endif