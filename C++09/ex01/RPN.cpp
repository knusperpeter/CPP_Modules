#include "RPN.hpp"

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int calculate(int x, int y, char c) {
    long long a = x;
    long long b = y;
    long long res;

    switch(c) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("division by 0");
            res = a / b;
            break;
        default:
            throw std::runtime_error("invalid operator");
    }
    
    if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
        throw std::runtime_error("int overflow");
        
    return res;
}