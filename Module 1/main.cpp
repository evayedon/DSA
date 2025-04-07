#include <iostream>
#include <cctype>
#include "romanType.h"
#include "romanType.cpp"

using namespace std;

int main()
{
    RomanType roman;
    char romanNumeral[100];
    int choice;

    cout << "Select an option: " << endl;
    cout << "1. Convert a decimal number to a Roman numeral" << endl;  
    cout << "2. Convert a Roman numeral to a decimal number\n"
         << "Enter your choice (1 or 2): " << endl;

    while (true)
    {
        cin >> choice;
        if (!cin.good()) {
            cout << "Invalid Input. Try again!" << endl;
            cin.clear();
            cin.ignore();
        }
        else if (choice < 1 || choice > 2) {
            cout << "Invalid Input. Try again!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        else
            break;
    }
    
    if (choice == 1)
    {
        int decimalNum;
        cout << "Enter a decimal number: ";
        cin >> decimalNum;
        if (!cin.good()) {
            cout << "Invalid Input. Try again!" << endl;
            cin.clear();
            cin.ignore();
            return 1;
        }
        roman.convertToRoman(decimalNum);
        roman.printRomanNum(decimalNum);
    }
    else if (choice == 2)
    {
        cout << "Enter a Roman numeral (capital letters): ";
        cin >> romanNumeral;
        if (!isupper(*romanNumeral)) {
            cout << "Invalid Input. Input should be capital letters" << endl;
            return 1;
        }
        roman.convertToDecimal(romanNumeral);
        roman.printDecimalNum(romanNumeral);
    }


    return 0;
}