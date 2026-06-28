#include<iostream>
#include<utility>
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

Node* insert(Node* head, int k){
    if(head == nullptr){
        Node* newNode = new Node(k);
        newNode->next = newNode;
        return newNode;
    }
    if(k <= head->data){
        Node* newNode = new Node(k);
        newNode->next = head->next;
        head->next = newNode;

        swap(head->data , newNode->data);
        return head;
    }

    //main logic
    Node* current = head;
    Node* frontcurrent = head->next;

    Node* newNode = new Node(k);

    do{
        if(current->data <= k && frontcurrent != head && frontcurrent->data >= k){
            current->next = newNode;
            newNode->next = frontcurrent;
            return head;
        }
        else if(current->data <= k && frontcurrent == head){
            newNode->next = head;
            current->next = newNode;
            return head;
        }
        current = current->next;
        frontcurrent = frontcurrent->next;
    }
    while(current != head);

    return head;
}

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

    Node* ans = insert(head, 2);

    printcll(ans);

return 0;
}