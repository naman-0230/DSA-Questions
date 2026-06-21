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

int length(Node* head){
    
    if(head == nullptr) return 0;

    return 1 + length(head->next);
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;

    cout<< length(head);


return 0;
}