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


Node* partitionList(Node* head, int x){

    if(head == nullptr || head->next == nullptr) return head;

    Node dummylesser(0);
    Node dummygreater(0);

    Node* taillesser = &dummylesser;
    Node* tailgreater = &dummygreater;

    Node*current = head;
    while(current != nullptr){

        Node* newtemp = current->next;     //imp logic
        current->next = nullptr;           //imp logic

        if(current->data >= x){
            tailgreater->next = current;
            tailgreater = tailgreater->next;
        }
        else{
            taillesser->next = current;
            taillesser = taillesser->next;
        }
        current = newtemp;               //same logic imp
    }
    tailgreater->next = nullptr;
    taillesser->next = dummygreater.next;

    return dummylesser.next;
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

    int x = 3;

    cout << "Original: ";
    print(head);

    head = partitionList(head, x);

    cout << "After: ";
    print(head);

    return 0;
}