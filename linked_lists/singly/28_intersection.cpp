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



Node* getIntersection(Node* headA, Node* headB){
    Node* a = headA;
    Node* b = headB;

    while(a != b){
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
    }

    return a;
}

int main(){

    //(intersection part)
    Node* c1 = new Node(8);
    Node* c2 = new Node(9);
    c1->next = c2;

    // List A: 1 → 2 → 8 → 9
    Node* a1 = new Node(1);
    Node* a2 = new Node(2);

    a1->next = a2;
    a2->next = c1;

    Node* headA = a1;

    // List B: 3 → 4 → 8 → 9
    Node* b1 = new Node(3);
    Node* b2 = new Node(4);

    b1->next = b2;
    b2->next = c1;

    Node* headB = b1;

    cout << "List A: ";
    print(headA);

    cout << "List B: ";
    print(headB);

    Node* ans = getIntersection(headA, headB);

    if(ans)
        cout << "Intersection Node: " << ans->data << endl;
    else
        cout << "No intersection\n";

    return 0;
}