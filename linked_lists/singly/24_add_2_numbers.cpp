#include <iostream>
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
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* addTwoNumbers(Node* l1, Node* l2){

    Node* tail_1 = l1;
    Node* tail_2 = l2;
    
    Node dummy(0);
    Node* prevTail = &dummy; 
    
    int carry = 0;
    while(tail_1 != nullptr || tail_2 != nullptr || carry){       //imp condition

        int sum = carry;

        if(tail_1){
            sum += tail_1->data;
            tail_1 = tail_1->next;
        } 
        if(tail_2){
            sum += tail_2->data;
            tail_2 = tail_2->next;
        } 

        int new_sum = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(new_sum);
        prevTail->next = newNode;
        prevTail = prevTail->next;

    }  
    
    return dummy.next;
}

int main(){

    // First number: 2 -> 4 -> 3
    Node* a1 = new Node(2);
    Node* a2 = new Node(4);
    Node* a3 = new Node(3);

    a1->next = a2;
    a2->next = a3;

    Node* l1 = a1;


    // Second number: 5 -> 6 -> 4
    Node* b1 = new Node(5);
    Node* b2 = new Node(6);
    Node* b3 = new Node(4);

    b1->next = b2;
    b2->next = b3;

    Node* l2 = b1;


    cout << "Number 1: ";
    print(l1);

    cout << "Number 2: ";
    print(l2);

    Node* ans = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    print(ans);

    return 0;
}