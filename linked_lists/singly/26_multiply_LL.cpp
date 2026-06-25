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

long long MOD = 1e9+7;         //imp mod
long long tonumber(Node* head){

    Node* current = head;
    long long aa = 0;
    while(current != nullptr){
        aa = (aa * 10 + current->data)% MOD;
        current = current->next;
    }
    return aa;
}

long long multiplyTwoNumbers(Node* l1, Node* l2){

   long long a = tonumber(l1);
   long long b = tonumber(l2);

    return (a*b) % MOD; 
    
}

int main(){

    // First number: 2 -> 4 -> 3
    Node* a1 = new Node(2);
    Node* a2 = new Node(4);


    a1->next = a2;

    Node* l1 = a1;


    // Second number: 5 -> 6 -> 4
    Node* b1 = new Node(5);
    Node* b2 = new Node(6);

    b1->next = b2;

    Node* l2 = b1;


    cout << "Number 1: ";
    print(l1);

    cout << "Number 2: ";
    print(l2);

    cout<<multiplyTwoNumbers(l1, l2);

    return 0;
}