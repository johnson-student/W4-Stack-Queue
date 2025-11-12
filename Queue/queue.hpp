#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100
#define NAME_LEN 50

class Queue {
private:
    char people[MAX][NAME_LEN];
    int front;
    int rear;

    bool isFull() const {
        return rear == MAX;
    }

    bool isEmpty() const {
        return front == rear;
    }

    // Compact: shift elements toward the front
    void compact() {
        if (front > 0) {
            int j = 0;
            for (int i = front; i < rear; i++, j++) {
                strcpy(people[j], people[i]);
            }
            rear -= front;
            front = 0;
            cout << "Compaction done to reclaim space.\n";
        }
    }

public:
    // Constructor: initialize queue
    Queue() {
        front = 0;
        rear = 0;
    }

    // Add a person to the queue
    void enqueue(const char* name) {
        if (isFull()) {
            if (front > 0) {
                compact();
            } else {
                cout << "Buffet line is full! " << name << " cannot join.\n";
                return;
            }
        }

        strcpy(people[rear], name);
        rear++;
        cout << name << " joined the buffet line.\n";
    }

    // Serve the next person
    void dequeue() {
        if (isEmpty()) {
            cout << "No one left to serve.\n";
            return;
        }
        cout << people[front] << " got their food and left the line.\n";
        front++;
    }

    // Display queue
    void showQueue() const {
        if (isEmpty()) {
            cout << "The buffet line is empty.\n";
            return;
        }

        cout << "\nCurrent buffet line: ";
        for (int i = front; i < rear; i++) {
            cout << people[i];
            if (i < rear - 1) cout << " <- ";
        }
        cout << "\n";
    }
};
