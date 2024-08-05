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
 * @param {char*} fullText      - the desired final text
 * @param {char*} buffer        - the text output buffer. should be size 28
 * @param {char*} hidBuff       - hidden buffer without the added characters
 * @param {int&} frameCount     - counts how many frames has it taken to print
 * @param {int&} displacement   - counts how many extra characters have been added such as newlines
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
    int& displacement, 
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
        if (len % 28 == 0 && frameCount > 0 && pauseCount >= 0) 
        {
            pauseCount++;
            if (pause != 0 && !(pauseCount % pause)) 
            {
                memset(buffer, 0, strlen(buffer));
                pauseCount = -1;
                displacement = 0;
            }
            return false;
        }
        buffer[len % 28 + displacement] = fullText[len];
        hidBuff[len] = fullText[len];
        //check to add newline or reset it all
        //printf("char: %c\nlen: %d\nmod27: %d\nbuffer:  %s\nhidBuff: %s\n\n", fullText[len], len, len % 28, buffer, hidBuff);
        if (len % 28 == 13 && strlen(buffer) != 0) 
        {
            buffer[(len % 28) + 1] = '\n';
            buffer[(len % 28) + 2] = '\0';
            displacement++;
        }
        if (!(len % 27) && frameCount > 0) 
        {
            pauseCount = 0;
        }
        else 
        {
            buffer[len + 1 + displacement] = '\0';
        }
        hidBuff[len + 1] = '\0';
        frameCount++;
        return false;
    }
    frameCount = 0;
    displacement = 0;
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
        printf("word: %s\ncurrWidth: %d\n", temp.c_str(), currWidth);
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