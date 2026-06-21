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

Node* insert(Node* head, int num){
    
    Node* n = new Node(num);
    Node* current = head;

    if(head == nullptr){
        return n;
    }

    while(current->next != nullptr){
        current = current->next;
    }
    current->next = n;
    return head;
}

void print(Node* head){

    Node* current = head;
    while(current != nullptr){
        cout<< current->data <<" ";
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

    int num = 5;

    head = insert(head, num);
    print(head);

return 0;
}