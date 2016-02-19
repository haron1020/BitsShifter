//
//  Utility.cpp
//  Lab1
//
//  Created by Andrey Nazarov on 18/02/16.
//  Copyright © 2016 Andrey Nazarov. All rights reserved.
//

#import "Utility.hpp"
#import <iostream>

void showBits(void *arg, int sizeOfType) {
    for (int i = sizeOfType * 8 - 1; i >= 0; --i) {
        std::cout << ((((char *)arg)[i / 8] >> (i % 8)) & 1);
        if(i % 8 == 0) std::cout<<' ';
    }
}

//
//    void rightShift(int bits) {
//        unsigned char t = 0;
//        bits = bits % 8;
//        for (int i = 0; i < bits; ++i) {
//            t = t << 1;
//            t = t | 1;
//        }
//        unsigned char temp = 0;
//        temp = data & t;
//        data = data >> bits;
//        temp = temp << (8 - bits);
//        data = data | temp;
//    }
//
//    void leftShift(int bits) {
//        unsigned char t = 0;
//        bits = bits % 8;
//        for (int i = 0; i < bits; ++i) {
//            t = t >> 1;
//            t = t | 128;
//        }
//        unsigned char temp = 0;
//        temp = data & t;
//        data = data << bits;
//        temp = temp >> (8 - bits);
//        data = data | temp;
//    }
//
//void leftShiftGroup(int startIndex, int endIndex, int bits) {//start = 5, end = 3
//    bits = bits % abs(startIndex - endIndex + 1);
//    unsigned char a = 0, b = 0;
//    for (int i = 0; i < 7 - startIndex; ++i) {
//        a = a >> 1;
//        a = a | 128;
//    }
//    for (int i = 0; i < endIndex; ++i) {
//        b = b << 1;
//        b = b | 1;
//    }
//    unsigned char left = 0;
//    unsigned char right = 0;
//    
//    left = data & a;
//    right = data & b;
//    
//    
//    
//    
//    showBits(&left, 1);
//    showBits(&right, 1);
//}

