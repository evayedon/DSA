#include <iostream>
#include "infixToPostFix.h"
#include <stack>
#include <string>

using namespace std;

   
InfixToPostfix::InfixToPostfix() {
    infx = "";
    pfx = "";
}

InfixToPostfix::~InfixToPostfix() {
    // Destructor
}
// Store infix expression
void InfixToPostfix::getInfix(const string& expression) {
    infx = expression;
    pfx = "";
    while (!opStack.empty()) opStack.pop();
}

void InfixToPostfix::showInfix() {
    cout << "Infix Expression: " << infx << endl;
}

// Show postfix expression
void InfixToPostfix::showPostfix() {
    cout << "Postfix Expression: " << pfx << endl;
}

void InfixToPostfix::convertToPostfix() {
    for (char sym : infx) {
        if (sym == ' ') continue; // Skip spaces
        
        if (isalpha(sym)) { // Operand
            pfx += sym;
        }
        else if (sym == '(') { // Left parenthesis
            opStack.push(sym);
        }
        else if (sym == ')') { // Right parenthesis
            while (!opStack.empty() && opStack.top() != '(') {
                pfx += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Remove '(' from stack
        }
        else if (sym == '+' || sym == '-' || sym == '*' || sym == '/') { // Operator
            while (!opStack.empty() && opStack.top() != '(' && precedence(opStack.top(), sym)) {
                pfx += opStack.top();
                opStack.pop();
            }
            opStack.push(sym);
        }
    }
    
    // Pop remaining operators
    while (!opStack.empty()) {
        pfx += opStack.top();
        opStack.pop();
    }
}
