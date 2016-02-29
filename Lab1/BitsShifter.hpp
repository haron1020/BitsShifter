//
//  BitsShifter.hpp
//  Lab1
//
//  Created by Andrey Nazarov on 25/02/16.
//  Copyright © 2016 Andrey Nazarov. All rights reserved.
//

#import <iostream>
#import <typeinfo>
#import <iomanip>
#import "Utility.hpp"

void showBits(void *arg, int sizeOfType) {
    std::cout<<std::endl;
    for (int i = sizeOfType*8 - 1; i>=0; --i) {
        std::cout<<i%10;
        if(i % 8 == 0) std::cout<<' ';
    }
    std::cout<<std::endl;
    for (int i = sizeOfType * 8 - 1; i >= 0; --i) {
        std::cout << ((((char *)arg)[i / 8] >> (i % 8)) & 1);
        if(i % 8 == 0) std::cout<<' ';
    }
    std::cout<<std::endl;
}

bool findBitByIndex(void* data, int index) {
    return (((char *)(data))[index / 8] >> (index % 8)) & 1;
}

template <typename T>
void replaceBitByIndex(void* data, bool arg, int index) {
    T temp = 0;
    ((char*)(&temp))[index / 8] = (((char*)(&temp))[index / 8]) | (1 << index % 8);
    if (arg == true) {
        ((char*)(data))[index / 8] = (((char*)(data))[index / 8]) | (((char*)(&temp))[index / 8]);
    } else if (arg == false) {
        ((char*)(&temp))[index / 8] = ~((char*)(&temp))[index / 8];
        ((char*)(data))[index / 8] = ((char*)(data))[index / 8] & ((char*)(&temp))[index / 8];
    }
}

template <typename T>
void rightGroupShift(void* data, int start, int end, int times) {
    for (int i = 0; i < times; ++i) {
        auto temp = findBitByIndex(data, start);
        for(int j = start; j < end; ++j) {
            replaceBitByIndex<T>(data, findBitByIndex(data, j+1), j);
        }
        replaceBitByIndex<T>(data, temp, end);
    }
}

template <typename T>
void leftGroupShift(void* data, int start, int end, int times) {
    for (int i = 0; i < times; ++i) {
        auto temp = findBitByIndex(data, end);
        for(int j = end; j >= start; --j) {
            replaceBitByIndex<T>(data, findBitByIndex(data, j), j+1);
        }
        replaceBitByIndex<T>(data, temp, start);
    }
}

template <typename T>
bool checkIndexes(int start, int end) {
    return (start >= 0 && end >= 0 && start < sizeof(T)*8 && end < sizeof(T)*8 && start < end);
}

template <typename T>
T readAndPrint() {
    T arg;
    std::cout<<"Input data: ";
    auto typeName = typeid(T).name();
    if (typeName == typeid(double).name() || typeName == typeid(float).name()) {
        arg = safeDoubleInput();
        std::cout<<std::setprecision(25);
    } else if (typeName == typeid(short).name() || typeName == typeid(int).name() || typeName == typeid(long long).name())  {
        arg = safeIntInput();
    } else if (typeName == typeid(char).name()) {
        std::cin>>arg;
    } else return 0;
    std::cout<<"Data: "<<arg<<std::endl;
    showBits(&arg, sizeof(T));
    return arg;
}

template <typename T>
void doProgram(T arg) {
    int start = 0;
    int end = 0;
    int howMuch = 0;
    bool inputIsInvalid = true;
    while (inputIsInvalid) {
        std::cout<<"Введите начальный индекс группы: ";
        start = safeIntInput();
        std::cout<<"Введите конечный индекс группы: ";
        end = safeIntInput();
        if (checkIndexes<T>(start, end)) {
            inputIsInvalid = false;
        } else std::cout<<"Неверный индекс. \n";
    }
    inputIsInvalid = true;
    while (inputIsInvalid) {
        std::cout<<"На сколько бит сдвигать?: ";
        howMuch = safeIntInput();
        if (howMuch >= 0) {
            inputIsInvalid = false;
        } else std::cout<<"Неверное количество. \n";
    }
    inputIsInvalid = true;
    while (inputIsInvalid) {
        std::cout<<"1 - влево\n2 - вправо\n";
        char choice;
        std::cin>>choice;
        switch (choice) {
            case '1':
                leftGroupShift<T>(&arg, start, end, howMuch);
                inputIsInvalid = false;
                break;
            case '2':
                rightGroupShift<T>(&arg, start, end, howMuch);
                inputIsInvalid = false;
                break;
            default:
                inputIsInvalid = true;
                break;
        }
    }
    showBits(&arg, sizeof(T));
    std::cout<<"Преобразованное число: "<<arg<<std::endl;
    
}

