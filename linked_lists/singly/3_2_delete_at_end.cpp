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

Node* deleteNode(Node* head){

    if(head == nullptr) return nullptr;

    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* current = head;
    // Node* prev;                                with additional pointer(good as well)

    // while(current->next != nullptr){             
    //     prev = current;
    //     current = current->next;
    // }
    // prev->next = nullptr;
    // delete current;
    // return head;

    while(current->next->next != nullptr){         //no extra pointer
        current = current-> next; 
    }
    delete current->next;
    current->next = nullptr;
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

    head = deleteNode(head);
    print(head);

return 0;
}