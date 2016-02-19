//
//  BitsShifter.hpp
//  Lab1
//
//  Created by Andrey Nazarov on 18/02/16.
//  Copyright © 2016 Andrey Nazarov. All rights reserved.
//

#import "Utility.hpp"
#import <cmath>

template <typename T>
class BitsShifter {
    T data;
    char castToByteByIndex(T *arg, int index) {
        return ((char*)(arg))[index / 8];
    }
public:
    void replaceBitByIndex(int arg, int index) {
        T temp = 0;
        ((char*)(&temp))[index / 8] = (((char*)(&temp))[index / 8]) | (1 << index);
        if (arg == 1) {
            ((char*)(&data))[index / 8] = (((char*)(&data))[index / 8]) | (((char*)(&temp))[index / 8]);
        } else {
            if (arg == 0) {
                ((char*)(&temp))[index / 8] = ~((char*)(&temp))[index / 8];
                ((char*)(&data))[index / 8] = ((char*)(&data))[index / 8] & ((char*)(&temp))[index / 8];
            } else return;
        }
        printBits();
    }
    
    bool findBitByIndex(int index) {
        return (((char *)(&data))[index / 8] >> (index % 8)) & 1;
    }

    
    BitsShifter(): data{0} { }
    BitsShifter(T arg): data{arg} { }
    
    void printBits() {
        showBits(&data, sizeof(T));
        std::cout<<std::endl;
    }
    
    void read() {
        std::cout<<"Число: ";
        std::cin >> data;
        std::cin.ignore();
    }
    
    
};
