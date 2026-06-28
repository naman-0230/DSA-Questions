#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node(int x){
        next = nullptr;
        data = x;
    }
};

void printcll(Node* head){

    if(head == nullptr) return;

    Node* current = head;

    do{
        cout<< current->data<<" ";
        current = current->next;
    }
    while(current != head);
}

Node* insertbeg(Node* head, int x){
    Node* newNode = new Node(x);

    if(head == nullptr){
        newNode->next = newNode;
        return newNode;
    }

    //updating
    newNode->next = head;

    //go to tail
    Node* current = head;

    do{
        current = current->next;
    }
    while(current->next != head);
    
    //updating
    current->next = newNode;

    return newNode;
}

Node* insertBegADVANCE(Node* head, int x){     //O(1)

    Node* newNode = new Node(x);

    if(head == nullptr){
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;

    swap(head->data, newNode->data);

    return head;
}



//for insert at end do exact same thing insert at beg and then return head->next.. same thing


//for delete at end mainly cant do the O(1) trick

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = first;

    Node* head = first;

    Node* newNode = insertbeg(head, 0);

    printcll(newNode);

return 0;
}