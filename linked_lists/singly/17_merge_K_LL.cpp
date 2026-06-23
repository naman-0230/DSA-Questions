#include <iostream>
#include <vector>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;   // Min Heap
    }
};

Node* mergeKLists(vector<Node*>& lists) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Put head of every list into heap
    for(Node* head : lists) {
        if(head != nullptr)
            pq.push(head);
    }

    Node dummy(0);
    Node* tail = &dummy;

    while(!pq.empty()) {

        Node* smallest = pq.top();
        pq.pop();

        tail->next = smallest;
        tail = tail->next;

        if(smallest->next != nullptr)
            pq.push(smallest->next);
    }

    return dummy.next;
}

int main(){

    // List 1 : 1 -> 4 -> 7
    Node* a1 = new Node(1);
    Node* a2 = new Node(4);
    Node* a3 = new Node(7);

    a1->next = a2;
    a2->next = a3;

    // List 2 : 2 -> 5 -> 8
    Node* b1 = new Node(2);
    Node* b2 = new Node(5);
    Node* b3 = new Node(8);

    b1->next = b2;
    b2->next = b3;

    // List 3 : 3 -> 6 -> 9
    Node* c1 = new Node(3);
    Node* c2 = new Node(6);
    Node* c3 = new Node(9);

    c1->next = c2;
    c2->next = c3;

    vector<Node*> lists;

    lists.push_back(a1);
    lists.push_back(b1);
    lists.push_back(c1);

    Node* ans = mergeKLists(lists);

    print(ans);

    return 0;
}