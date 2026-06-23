#include<iostream>
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
    Node* current = head;
    while(current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
}

Node* rotateRight(Node* head, int k) {

    if(!head || !head->next || k == 0)
        return head;

    // Step 1: find length
    int n = 1;
    Node* tail = head;

    while(tail->next) {
        tail = tail->next;
        n++;
    }

    // Step 2: normalize k
    k = k % n;
    if(k == 0) return head;

    // Step 3: make circular
    tail->next = head;

    // Step 4: find new tail (n-k steps)
    int steps = n - k;
    Node* newTail = head;

    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: new head
    Node* newHead = newTail->next;

    // Step 6: break circle
    newTail->next = nullptr;

    return newHead;
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;


    head = rotateRight(head,3);
    print(head);

return 0;
}