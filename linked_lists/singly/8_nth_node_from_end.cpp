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


Node* nthNode(Node* head, int n){

    if(n<=0) return nullptr;

    Node* one = head;
    Node* two = head;
    int k = n;

    while(k>0 && two != nullptr){
        two = two->next;
        k--;
    }
    if(k>0) return nullptr;

    while(two != nullptr){
        one = one->next;
        two = two->next;
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

    int n = 4;
    Node* ans = nthNode(head, n);
    cout<< ans->data; 

return 0;
}