#include<iostream>
#include<vector>
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

    print(head);

return 0;
}