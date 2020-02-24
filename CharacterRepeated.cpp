// CharacterRepeated.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>

using namespace std;

bool CharacterRepeated(char* str);
#define NUM_INTS_NEEDED (256/(CHAR_BIT*4))
#define NUM_BITS_PER_INT (32)


int main()
{
    char testStr1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\\*%()0123456789!@#$^&[]{}|:;'\".<>,?-~`";
    char testStr2[] = "The Quick Brown Fox Jumps Over The Lazy Dog!";

    cout << "================== Test 1 ==================" << endl;
    cout << "String: " << testStr1 << endl;
    cout << "Repeat: ";
    if (CharacterRepeated(testStr1) == true) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    cout << endl << endl;

    cout << "================== Test 2 ==================" << endl;
    cout << "String: " << testStr2 << endl;
    cout << "Repeat: ";
    if (CharacterRepeated(testStr2) == true) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    cout << endl << endl;

    return 0;
}


bool CharacterRepeated(char* str) {
    uint32_t charMap[256/NUM_BITS_PER_INT];
    uint32_t index;
    uint32_t mask;
    bool repeated = false;

    memset(charMap, 0, sizeof(uint32_t)*(256 / NUM_BITS_PER_INT));

    while (*str) {
        index = *str / NUM_BITS_PER_INT;
        mask = (1 << (*str % NUM_BITS_PER_INT));
        
        //character was seen before
        if (charMap[index] & mask) {
            repeated = true;
            break;
        }
        
        charMap[index] |= mask;
        str++;
    }
    
    return repeated;
}
