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

void pairsum(Node* head, int x){
    if(head == nullptr) return;
    
    Node* front = head;
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    while(front != tail && front != tail->next){
        if(front->data + tail->data < x) front = front->next;
       else if(front->data + tail->data > x) tail = tail->prev;
       else{
        cout<< front->data<< " "<< tail->data<<endl;
        front = front->next;
        tail = tail->prev;
       }
    }
}

int main(){
    Node* zeroth = new Node(0);
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    zeroth->next = first;
    first->prev = zeroth;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    Node* head = zeroth;

    pairsum(head,3);

return 0;
}