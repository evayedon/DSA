#include <iostream>
#include <stack>
#include <string>
#include <cctype>

class InfixToPostfix {
private:
    std::string infix;
    std::string postfix;
    
    // Helper function to determine operator precedence
    bool precedence(char op1, char op2) {
        int prec1 = (op1 == '*' || op1 == '/') ? 2 : 1;
        int prec2 = (op2 == '*' || op2 == '/') ? 2 : 1;
        return prec1 >= prec2;
    }

public:
    // Constructor
    InfixToPostfix() : infix(""), postfix("") {}
    
    // Destructor
    ~InfixToPostfix() {}
    
    // Store the infix expression
    void getInfix(const std::string& expr) {
        infix = expr;
        postfix = "";
    }
    
    // Output the infix expression
    void showInfix() const {
        std::cout << "Infix Expression: " << infix << std::endl;
    }
    
    // Output the postfix expression
    void showPostfix() const {
        std::cout << "Postfix Expression: " << postfix << std::endl;
    }
    
    // Convert infix to postfix
    void convertToPostfix() {
        std::stack<char> opStack;
        postfix = "";
        
        for (char sym : infix) {
            if (sym == ' ') continue; // Skip spaces
            
            if (isalpha(sym)) {
                // Operand - add to postfix
                postfix += sym;
            }
            else if (sym == '(') {
                // Left parenthesis - push to stack
                opStack.push(sym);
            }
            else if (sym == ')') {
                // Right parenthesis - pop until '('
                while (!opStack.empty() && opStack.top() != '(') {
                    postfix += opStack.top();
                    opStack.pop();
                }
                opStack.pop(); // Remove the '('
            }
            else if (sym == '+' || sym == '-' || sym == '*' || sym == '/') {
                // Operator - handle precedence
                while (!opStack.empty() && opStack.top() != '(' && 
                       precedence(opStack.top(), sym)) {
                    postfix += opStack.top();
                    opStack.pop();
                }
                opStack.push(sym);
            }
        }
        
        // Pop remaining operators
        while (!opStack.empty()) {
            postfix += opStack.top();
            opStack.pop();
        }
    }
};




// Main function to demonstrate the conversion

int main() {
    InfixToPostfix converter;
    std::string expressions[] = {
        "A+B-C",
        "(A+B)*C",
        "(A+B)*(C-D)",
        "A+((B+C)*(E-F)-G)/(H-I)",
        "A+B*(C+D)-E/F*G+H"
    };
    
    for (const auto& expr : expressions) {
        converter.getInfix(expr);
        converter.convertToPostfix();
        converter.showInfix();
        converter.showPostfix();
        std::cout << std::endl;
    }
    
    return 0;
}