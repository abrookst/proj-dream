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
 * @param {const std::string&} fullText - the desired final text. to be formatted with FormatStringToDialogue
 * @param {std::string&} buffer         - the text output buffer. should be size 28
 * @param {std::string&} hidBuff        - hidden buffer without the added characters
 * @param {int&} frameCount             - counts how many frames has it taken to print
 * @param {int&} lineState              - tracks which line the buffer is on [0 is first, 1 is second, 2 indicates pause]
 * @param {int&} pauseCount             - counts the frames before the text continues rendering. initialize to -1 outside
 * @param {int} [delay = 0]             - frames between when each character is drawn
 * @param {int} [pause = 0]             - delay count numbers between reset and drawing
 * @return {bool} has the text finished rendering
 * 
 * Example:
 * 
 * DrawTextEx(mainFont, buffer, Vector2{ 3, 47 }, 6, 1, WHITE);
 * Writer(text, buffer, hidBuff, frameCount, displacemeCount, pauseCount, 5, 20);
 * 
 */

bool Writer(
    const std::string& fullText, 
    std::string& buffer, 
    std::string& hidBuff, 
    int& frameCount, 
    int& lineState, 
    int& pauseCount, 
    int delay = 0, 
    int pause = 0,
    bool entered = false) 
{
    if (fullText != hidBuff) 
    {
        if (delay && frameCount % delay) 
        {
            frameCount++;
            return false;
        }
        int len = hidBuff.length();
        int bufferLen = buffer.length();
        if (!entered && lineState == 2) {
            return false;
        }
        if (lineState == 2 && frameCount > 0 && entered)
        {
            buffer = "";
            pauseCount = -1;
            lineState = 0;
            return false;
        }
        buffer += fullText[len];
        hidBuff += fullText[len];
        if (len + 1 < fullText.length() && fullText[len + 1] == '\n') 
        {
            buffer += '\n';
            hidBuff += '\n';
            if (lineState) 
            {
                pauseCount = 0;
            }
            lineState++;
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
 * @param {std::string&} inputString    - the string to reformat
 * 
 */
void FormatStringToDialogue(
    std::string& inputString) 
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
    output = output.substr(0, output.length() - 1);
    //strcpy(outputString, output.c_str());
    inputString = output;
}

#endif