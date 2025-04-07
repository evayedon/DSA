
#ifndef ROMANTYPE_H
#define ROMANTYPE_H

class RomanType
{
    public:
        RomanType();
        int getDecimalNum();
        char* getRomanNumeral();
        int convertToDecimal(const char romanNumeral[]);
        std::string convertToRoman(int decimalNum);
        void printRomanNum(int decimalNum);
        void printDecimalNum(char romanNumeral[]);

    private:
        int decimalNum;
        char romanNumeral[100];    
};

#endif