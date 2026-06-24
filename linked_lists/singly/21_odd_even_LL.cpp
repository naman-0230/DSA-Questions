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
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node* oddEvenList(Node* head){

    if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;

    Node* odd = head;
    Node* headeven = head->next;
    Node* even = head->next;

    while(even != nullptr && even->next != nullptr){

        odd->next = even->next;
        odd = odd->next;

        even->next = even->next->next; 
        even = even->next;
    }

    odd->next = headeven;
    
    return head;
}


int main(){

    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* n1 = new Node(1);
    Node* n2 = new Node(4);
    Node* n3 = new Node(3);
    Node* n4 = new Node(2);
    Node* n5 = new Node(5);
    Node* n6 = new Node(2);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    Node* head = n1;

    cout << "Original: ";
    print(head);

    head = oddEvenList(head);

    cout << "After: ";
    print(head);

    return 0;
}