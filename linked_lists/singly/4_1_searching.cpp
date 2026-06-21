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

bool find(Node* head, int x){

    Node* current = head;
    while(current != nullptr){
        if(current->data == x) return true;
        current = current->next;
    }
    return false;
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

    int x = 20;

    cout<< find(head, x);

return 0;
}