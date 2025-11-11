#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class Stack{
    int top ;
    char arr[MAX];
    public:
    Stack(){top = -1;}
    void push(char x){
        if(top >= MAX - 1){
            cout<<"Stack overflow!"<<endl;
        }else{
            arr[++top] = x;
        }
    }
    void pop(){
        if(top <= -1){
            cout<<"Stack underflow"<<endl;
        }else{
            arr[top--];
        }
    }
    char peek(){
        if(top < 0){
            cout<<"There is nothing in stack"<<endl;
        }else{
            return arr[top];
        }
    }
    bool isEmpty(){
        return top < 0 ;
    }
};