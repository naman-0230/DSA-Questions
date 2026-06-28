#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void printforward(Node* head){
    while(head != nullptr){
        cout<< head->data << " ";
        head = head->next;
    }
}

void printbackward(Node* head){
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    while(tail != nullptr){
        cout<< tail->data << " ";
        tail = tail->prev;
    }
}

Node* insert_beginning(Node* head, int x){
    if(head == nullptr){
        Node* newNode = new Node(x);
        return newNode;
    }

    Node* newNode = new Node(x);
    newNode->next = head;
    newNode->prev = nullptr;
    head->prev = newNode;
    head = newNode;

    return newNode;
}

int main(){

    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    Node* head = first;

    Node* haha = insert_beginning(head, 0);
    printforward(haha);

return 0;
}