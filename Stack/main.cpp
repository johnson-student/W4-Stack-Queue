#include <iostream>
#include "stack.hpp"
#include <string>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBracket(char c) {
    return (c == '[' || c == ']' ||
            c == '(' || c == ')' ||
            c == '{' || c == '}');
}

bool isBalance(string s) {
    Stack stack;
    bool isError = false;
    int pos = -1;
    bool inSingleQuote = false;
    bool inDoubleQuote = false;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // Toggle quote flags
        if (c == '\'' && !inDoubleQuote) {
            inSingleQuote = !inSingleQuote;
            continue;
        }
        if (c == '"' && !inSingleQuote) {
            inDoubleQuote = !inDoubleQuote;
            continue;
        }

        // Ignore brackets inside quotes
        if (inSingleQuote || inDoubleQuote) continue;

        // Process brackets
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) {
                pos = i;
                isError = true;
                cout << "Error: closing bracket '" << c 
                     << "' at position " << pos 
                     << " has no opening pair." << endl;
                break;
            }
            char top = stack.peek();
            if (!isMatching(top, c)) {
                pos = i;
                isError = true;
                cout << "Error: bracket '" << c
                     << "' at position " << pos
                     << " does not match '" << top << "'" << endl;
                break;
            } else {
                stack.pop();
            }
        }
    }

    if (!isError && stack.isEmpty()) {
        cout << "Balanced brackets" << endl;
        return true;
    } else if (!isError && !stack.isEmpty()) {
        cout << "Missing closing bracket(s)" << endl;
        return false;
    } else {
        cout << "Unbalanced brackets at position: " << pos << endl;
        return false;
    }
}


int main() {
    isBalance("{}{(()}"); // test
}
