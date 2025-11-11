#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class Queue {
    int front;
    int rear;
    char arr[MAX];
public:
    Queue() {
        rear = -1;
        front = -1;
    }

    void enQueue(char x) {
        if (rear == MAX - 1) {
            cout << "Queue overflow" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            arr[++rear] = x;
        }
    }

    void deQueue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
        } else {
            cout << "Delete " << arr[front++] << " from queue" << endl;
        }
    }
};
