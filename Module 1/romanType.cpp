#include <iostream>
#include <cstring>
#include "romanType.h"

using namespace std;

RomanType::RomanType()
{
}

int RomanType::getDecimalNum()
{
    return decimalNum;
}

char* RomanType::getRomanNumeral()
{
    return romanNumeral;
}

int RomanType::convertToDecimal(const char romanNumeral[])
{
    int values[] = {1000, 500, 100, 50, 10, 5, 1};
    const char romanChars[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int decimalNum = 0;

    int length = strlen(romanNumeral);

    for (int i = 0; i < length; i++) {
        int currentVal = 0, nextVal = 0;

        for (int j = 0; j < 7; j++) {
            if (romanNumeral[i] == romanChars[j]) {
                currentVal = values[j];
                break;
            }
        }

        if (i + 1 < length) {
            for (int j = 0; j < 7; j++) {
                if (romanNumeral[i + 1] == romanChars[j]) {
                    nextVal = values[j];
                    break;
                }
            }
        }

        if (currentVal < nextVal) {
            decimalNum -= currentVal;
        } else {
            decimalNum += currentVal;
        }
    }
    return decimalNum;
}

std::string RomanType::convertToRoman(int decimalNum)
{
    int values[] = {1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1};
    const char* romanNumerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string romanNumeral = "";

    for (int i = 0; i < 13; i++)
    {
        while (decimalNum >= values[i])
        {
            decimalNum -= values[i];
            romanNumeral+= romanNumerals[i];
        }
    }
    return romanNumeral;
}

void RomanType::printRomanNum(int decimalNum)
{
    cout << "The Roman numeral is " << convertToRoman(decimalNum) << endl;
}

void RomanType::printDecimalNum(char romanNumeral[])
{
    cout << "The decimal number is  " << convertToDecimal(romanNumeral) << endl;
}
