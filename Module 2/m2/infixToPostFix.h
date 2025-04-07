#ifndef   INFIX_TO_POSTFIX_H
#define   INFIX_TO_POSTFIX_H

#include <stack>
#include <string>

using namespace std;

class InfixToPostfix
{
    public:
        InfixToPostfix();
        ~InfixToPostfix();  
        void getInfix(const string& expression);
        void convertToPostfix();
        void showInfix();
        void showPostfix();

    private:
        string infx;
        string pfx;
        stack<char> opStack;

        // Function to determine operator precedence
        bool precedence(char op1, char op2) {
            int prec1 = (op1 == '*' || op1 == '/') ? 2 : 1;
            int prec2 = (op2 == '*' || op2 == '/') ? 2 : 1;
            return prec1 >= prec2;
        }

};

#endif //INFIX_TO_POSTFIX_H