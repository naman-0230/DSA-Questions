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


Node* middle(Node* head){

    Node* one = head;
    Node* two = head;

    while(two != nullptr && two->next != nullptr){
        one = one->next;
        two = two->next->next;
    }
    return one;

}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    Node* ans = middle(head);
    cout<< ans->data; 

return 0;
}