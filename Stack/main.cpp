#include <iostream>
#include "stack.hpp"
#include <string>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
bool isBalance(string s){
    Stack stack;
    bool isError = false;
    int length = s.length();
    for(int i = 0 ; i < length; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack.push(s[i]);
        }else{
            if (stack.isEmpty()) {
                isError = true; 
                break;
            }
            char top = stack.peek();
            if (!isMatching(top, s[i])) {
                isError = true;  // mismatch type
                break;
            }else{
                stack.pop();
            }
        }
    }
    if (!isError && stack.isEmpty()) {
        cout << "balanced brackets" << endl;
    } else {
        cout << "unbalanced brackets" << endl;
    }
}
int main(){
    isBalance("{)");
}