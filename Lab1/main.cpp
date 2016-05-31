//
//  main.cpp
//  Lab1
//
//  Created by Andrey Nazarov on 11/02/16.
//  Copyright © 2016 Andrey Nazarov. All rights reserved.
//

#import <iostream>
#import "BitsShifter.hpp"

int main(int argc, const char * argv[]) {
    
    char choice;
    do {
        system("clear");
        std::cout<<"Задание: сделать циклический сдвиг в группе битов. Вам будет предложено выбрать тип данных, начальный индекс группы, конечный индекс группы, на сколько бит сдвинуть и направление сдвига. "<<std::endl;
        std::cout<<"1 - char\n2 - short\n3 - int\n4 - long long\n5 - float\n6 - double\n7 - long double";
        std::cin>>choice;
        switch (choice) {
            case '1':
                __service<char>(&main);
                doProgram<char>(readAndPrint<char>());
                break;
            case '2':
                __service<short>(&main);
                doProgram<short>(readAndPrint<short>());
                break;
            case '3':
                __service<int>(&main);
                doProgram<int>(readAndPrint<int>());
                break;
            case '4':
                __service<long long>(&main);
                doProgram<long long>(readAndPrint<long long>());
                break;
            case '5':
                __service<float>(&main);
                doProgram<float>(readAndPrint<float>());
                break;
            case '6':
                __service<double>(&main);
                doProgram<double>(readAndPrint<double>());
                break;
            case '7':
                __service<long double>(&main);
                doProgram<long double>(readAndPrint<long double>());
            default:
                break;
        }
        std::cout<<"Y - повторить: ";
        std::cin>>choice;
    } while (strchr("yY", choice));
    return 0;
}
