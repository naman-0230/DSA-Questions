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

Node* deleteNode(Node* head, int num){
    
    if(head == nullptr) return nullptr;

    if(head->next == nullptr && head->data == num){
        delete head;
        return nullptr;
    }
    if(head->next == nullptr && head->data != num) return head;

    if(head->data == num){
        Node* second = head->next;
        delete head;
        return second;
    }

    Node* current = head;
    Node* prev;

    while(current != nullptr && current->data != num){
        prev = current;
        current = current->next;
    }
    if(current == nullptr) return head;

    prev->next = current->next;
    delete current;
    return head;
}


void print(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
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

    int num = 20;

    head = deleteNode(head, num);
    
    print(head);

return 0;
}