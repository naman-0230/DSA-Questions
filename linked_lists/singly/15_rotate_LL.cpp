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
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* merge(Node* l1, Node* l2){
    
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    Node dummy(0);
    Node* tail_ans = &dummy;
    
    Node* curr1 = l1;
    Node* curr2 = l2;

    if(l1->data <= l2->data){
        tail_ans->next = l1;
        curr1 = l1->next;
    } 
    else{
        tail_ans->next = l2;
        curr2 = l2->next;
    }

    tail_ans = tail_ans->next;

    while(curr1 != nullptr && curr2 != nullptr){

        if(curr1->data < curr2->data){

            tail_ans->next = curr1;
            tail_ans = tail_ans->next;
            curr1 = curr1->next;
        }

        else{

            tail_ans->next = curr2;
            tail_ans = tail_ans->next;
            curr2 = curr2->next;
        }
    }

    //for remaining nodes
    while(curr1 != nullptr){
        tail_ans->next = curr1;
        tail_ans = tail_ans->next;
        curr1 = curr1->next;
    }
    while(curr2 != nullptr){
        tail_ans->next = curr2;
        tail_ans = tail_ans->next;
        curr2 = curr2->next;
    }

    return dummy.next;
}

int main(){

    // List 1: 1 -> 3 -> 5 -> 7
    Node* a1 = new Node(1);
    Node* a2 = new Node(3);
    Node* a3 = new Node(5);
    Node* a4 = new Node(7);

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;

    Node* l1 = a1;


    // List 2: 2 -> 4 -> 6 -> 8
    Node* b1 = new Node(2);
    Node* b2 = new Node(4);
    Node* b3 = new Node(6);
    Node* b4 = new Node(8);

    b1->next = b2;
    b2->next = b3;
    b3->next = b4;

    Node* l2 = b1;


    // Call your function
    Node* ans = merge(l1, l2);

    print(ans);

    return 0;
}