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

Node* reverse(Node* current, Node* prev, Node* forward){

    if(current == nullptr) return prev;

    forward = current->next;
    current-> next = prev;

    prev = current;
    current = forward;

    return reverse(current, prev, forward);

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

    Node* current = head;
    Node* prev = nullptr;
    Node* forward = head;

    head = reverse(current, prev, forward);
    print(head);

return 0;
}