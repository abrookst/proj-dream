#ifndef typewrite_h
#define typewrite_h

#include <utility>
#include <string.h>
#include <stdio.h>

/** 
 * Adds one character of text per frame and adds newlines when required 
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

#endif