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

void print(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
}

Node* reverse(Node* head){
    if(head == nullptr) return nullptr;
    if(head-> next == nullptr) return head;

    Node* current = head;
    Node* prev = nullptr;
    Node* forward = head;

    while(current != nullptr){
        forward = forward->next;
        current->next = prev;

        prev = current;
        current = forward;
    }

    return prev;
}

Node* reverseLR(Node* head, int L, int R){

    if(L == R) return head;
    if(head == nullptr) return nullptr;
    if(L<1 || R<1) return head;

    Node dummy(10);             //imp concept
    dummy.next = head;
    Node* prevleft = &dummy;

    //reaching the L;
    for(int i=1; i<L; i++){
        prevleft = prevleft->next;
        if(prevleft == nullptr) return head;
    }
    //defining L
    Node* start = prevleft->next;
    if(start == nullptr) return head;

    Node* end = start;
    for(int i=L; i<R; i++){
        if(end->next == nullptr) return head;
        end = end->next;
    }

    //defining afterend
    Node* after = end->next;
    //imp step to disconnect end
    end->next = nullptr;

    Node* new_head =  reverse(start);

    prevleft->next = new_head;
    start->next = after;

    return dummy.next;
    
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

    int L=2;
    int R = 4;
    head = reverseLR(head,L,R);
    print(head);

return 0;
}