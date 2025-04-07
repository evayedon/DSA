#include <iostream>
#include <string>
#include "infixToPostFix.h"
#include "infixToPostFix.cpp"

using namespace std;

int main() {
    InfixToPostfix converter;
    
    string expressions[] = {
        "A + B - C",
        "(A + B ) * C",
        "(A + B) * (C - D)",
        "A + ((B + C) * (E - F) - G) / (H - I)",
        "A + B * (C + D) - E / F * G + H"
    };
    
    for (const string& expr : expressions) {
        converter.getInfix(expr);
        converter.convertToPostfix();
        converter.showInfix();
        converter.showPostfix();
        cout << endl;
    }
    
    return 0;
}