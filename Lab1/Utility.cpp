//
//  Utility.cpp
//  Lab1
//
//  Created by Andrey Nazarov on 25/02/16.
//  Copyright © 2016 Andrey Nazarov. All rights reserved.
//

#import <iostream>
#import "Utility.hpp"

double safeDoubleInput() {
    char input[255];
    char inpChar;
    int chCount = 0;
    bool usedE = false;
    bool usedComma = false;
    do
    {
        inpChar = getchar();
        if ((isdigit(inpChar) || (inpChar == '-' && (chCount == 0 || usedE == true)) ||
             (inpChar == '.' && !usedComma ) || (((inpChar == 'e' || inpChar == 'E') && !usedE && chCount > 0) && chCount < 255)))
        {
            switch (inpChar)
            {
                case 'e': usedE = true; break;
                case 'E': usedE = true; break;
                case '.': usedComma = true; break;
                default: break;
            }
            input[chCount] = inpChar;
            chCount++;
        } else if ((inpChar == 127 || inpChar == 8) && chCount > 0)
        {
            switch (input[chCount-1]) {
                case 'e' : usedE = false; break;
                case 'E': usedE = false; break;
                case '.': usedComma = false;  break;
                default: break;
            }
            input[chCount-1] = 0;
            chCount--;
            std::cout << "\b \b";
        }
    } while (inpChar != '\n'  || chCount == 0);
    input[chCount] = '\0';
    std::cout<<std::endl;
    return strtod(input, nullptr);
}

int safeIntInput() {
    char input[255];
    char inpChar;
    int chCount = 0;
    bool usedE = false;
    do
    {
        inpChar = getchar();
        if ((isdigit(inpChar) || (inpChar == '-' && (chCount == 0 || usedE == true)) ||
             (((inpChar == 'e' || inpChar == 'E') && !usedE && chCount > 0) && chCount < 255)))
        {
            switch (inpChar)
            {
                case 'e': usedE = true; break;
                case 'E': usedE = true; break;
                default: break;
            }
            input[chCount] = inpChar;
            chCount++;
        } else if ((inpChar == 127 || inpChar == 8) && chCount > 0)
        {
            switch (input[chCount-1]) {
                case 'e' : usedE = false; break;
                case 'E': usedE = false; break;
                default: break;
            }
            input[chCount-1] = 0;
            chCount--;
            std::cout << "\b \b";
        }
    } while (inpChar != '\n'  || chCount == 0);
    input[chCount] = '\0';
    std::cout<<std::endl;
    return atoi(input);
}
