#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> st;

public:
    void push(int x) {
        stack<int> temp;

        // move all to temp
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        // insert new element
        st.push(x);

        // move back
        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }

    void pop() {
        if(!st.empty())
            st.pop();
    }

    int front() {
        return st.top();
    }

    bool empty() {
        return st.empty();
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