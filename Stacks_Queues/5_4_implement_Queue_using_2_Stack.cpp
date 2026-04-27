#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> in, out;

public:

    void push(int x) {
        in.push(x);
    }

    void move() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

    void pop() {
        move();
        if (!out.empty())
            out.pop();
    }

    int front() {
        move();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl; // 10
    q.pop();

    cout << q.front() << endl; // 20
}