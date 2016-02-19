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
        std::cout<<"1 - char\n2 - short\n3 - int\n4 - long long\n5 - float\n6 - double\n";
        std::cin>>choice;
//        switch (choice) {
//            case '1':
//                readAndPrint<char>();
//                break;
//            case '2':
//                readAndPrint<short>();
//                break;
//            case '3':
//                readAndPrint<int>();
//                break;
//            case '4':
//                readAndPrint<long long>();
//                break;
//            case '5':
//                readAndPrint<float>();
//                break;
//            case '6':
//                readAndPrint<double>();
//                break;
//            case '7':
//                rightShift(0b00100011, 8);
//                break;
//            default:
//                break;
//        }
        BitsShifter<int> *obj = new BitsShifter<int>(10123);
//        obj->leftShiftGroup(5, 3, 3);
        obj->printBits();
        //obj->findBitByIndex(20);
        obj->replaceBitByIndex(0, 0);
        //obj->printBits();
        std::cout<<"\ny - повтор\nn - выход"<<std::endl;
        std::cin>>choice;
    }while (strchr("Yy",choice));
    return 0;
}
