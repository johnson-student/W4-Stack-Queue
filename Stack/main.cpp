#include <iostream>
#include "stack.hpp"
#include <string>
using namespace std;

int main(){
    string s = "()[]{}";
    Stack stack;
    for(int i = 0 ; i< s.length();i++){
        cout<<s[i];
    }   
}