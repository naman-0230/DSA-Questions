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

Node* deleteNode(Node* head, int pos){
    
    if(head == nullptr) return nullptr;

    if(head->next == nullptr && pos == 1){
        delete head;
        return nullptr;
    }
    if(head->next == nullptr && pos > 1) return nullptr;

    if(pos == 1){
        Node* second = head->next;
        delete head;
        return second;
    }

    int k = pos-1;
    Node* current = head;

    while(current->next->next != nullptr && k>1){
        current = current->next;
        k--;
    }
    if(k>1) return nullptr;
    
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
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

    int pos = 3;

    head = deleteNode(head, pos);
    print(head);

return 0;
}