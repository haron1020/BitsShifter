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
        std::cout<<"1 - char\n2 - short\n3 - int\n4 - long long\n5 - float\n6 - double\n";
        std::cin>>choice;
        switch (choice) {
            case '1':
                doProgram<char>(readAndPrint<char>());
                break;
            case '2':
                doProgram<short>(readAndPrint<short>());
                break;
            case '3':
                doProgram<int>(readAndPrint<int>());
                break;
            case '4':
                doProgram<long long>(readAndPrint<long long>());
                break;
            case '5':
                doProgram<float>(readAndPrint<float>());
                break;
            case '6':
                doProgram<double>(readAndPrint<double>());
                break;
            default:
                break;
        }
        std::cout<<"Y - повторить: ";
        std::cin>>choice;
    } while (strchr("yY", choice));
    return 0;
}
