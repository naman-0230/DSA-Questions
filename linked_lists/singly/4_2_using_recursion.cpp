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

    if(head == nullptr) return false;
    
    if(head->data == x) return true;
   
    return find(head->next, x);
    
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