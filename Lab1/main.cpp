//
//  main.cpp
//  Lab1
//
//  Created by Andrey Nazarov on 11/02/16.
//  Copyright © 2016 Andrey Nazarov. All rights reserved.
//

#import <iostream>

void showBits(void *arg, int sizeOfType) {
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

void leftGroupShift(void* data, int start, int end, int bytes) {
    
}

template <typename T>
void readAndPrint() {
    T arg;
    std::cout<<"Number: ";
    std::cin>>arg;
    showBits(&arg, sizeof(T));
    replaceBitByIndex<T>(&arg, false, 0);
    showBits(&arg, sizeof(T));
}

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
        readAndPrint<int>();
        std::cout<<"\ny - повтор\nn - выход"<<std::endl;
        std::cin>>choice;
    }while (strchr("Yy",choice));
    return 0;
}
