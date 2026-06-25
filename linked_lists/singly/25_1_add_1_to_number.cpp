
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



Node* add1(Node* l1){

    Node* newList = reverse(l1);
    
    Node dummy(0);
    Node* prevTail = &dummy; 

    int carry = 1; //imp

    while(newList != nullptr || carry){       //imp condition

        int sum2 = carry;
        if(newList) sum2 += newList->data;

        carry = sum2/10;
            
        Node* newNode2 = new Node(sum2%10);
        prevTail->next = newNode2;
        prevTail = prevTail->next;

        if(newList) newList = newList->next;
    }  
    
    return reverse(dummy.next);
    
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