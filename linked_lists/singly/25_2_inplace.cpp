
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



Node* add1(Node* head){

    Node* newHead = reverse(head);
    
    if(newHead == nullptr) return head;

    Node* current = newHead;
    Node dummy(0);
    Node* prevcurrent = &dummy;
    prevcurrent->next = current;

    int carry = 1; //imp

    while(current != nullptr){       //imp condition

        int sum = carry;
        sum += current->data;

        carry = sum/10;
        current->data = sum % 10;

        current = current->next;
        prevcurrent = prevcurrent->next;
    }  

    if(carry){
        Node* newNode = new Node(carry);
        prevcurrent->next = newNode;
    }
    
    return reverse(newHead);
    
}

int main(){

    // First number: 2 -> 4 -> 3
    Node* a1 = new Node(9);
    Node* a2 = new Node(9);
    Node* a3 = new Node(9);

    a1->next = a2;
    a2->next = a3;

    Node* l1 = a1;

    cout << "Number 1: ";
    print(l1);

    Node* ans = add1(l1);

    cout << "Resultant: ";
    print(ans);

    return 0;
}