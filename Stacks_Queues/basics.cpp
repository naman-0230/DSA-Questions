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
