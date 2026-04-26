#include <iostream>
using namespace std;

class Stack {
    int arr[1000];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) return;
        top--;
    }

    int getTop() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};


class Queue {
    int *arr;
    int front, rear, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[cap];
        front = 0;
        rear = -1;
        size = 0;
    }

    void push(int x) {
        if (size == capacity) {
            cout << "Queue Full\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Queue Empty\n";
            return;
        }

        front = (front + 1) % capacity;
        size--;
    }

    int Front() {
        if (size == 0) return -1;
        return arr[front];
    }

    bool empty() {
        return size == 0;
    }
};
