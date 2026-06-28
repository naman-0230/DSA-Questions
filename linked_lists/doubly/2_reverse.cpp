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

Node* reverse(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* current = head;
    Node* temp = nullptr;
    Node* newhead = head;
    while(current != nullptr){
        if(current->next == nullptr) newhead = current;
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }
    return newhead;
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

    Node* haha = reverse(head);
    printforward(haha);

return 0;
}