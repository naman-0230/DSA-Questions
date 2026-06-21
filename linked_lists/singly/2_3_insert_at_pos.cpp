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

Node* insert(Node* head, int num, int pos){
    
    if(head == nullptr && pos>1) return nullptr;

    Node* n = new Node(num);
    Node* current = head;

    if(head == nullptr && pos == 1){
        return n;
    }

    if(pos == 1){
        n->next = head;
        return n;
    }

    int k = pos-1;
    while(current->next != nullptr && --k > 0){
        current = current->next;
    }
    if(k > 0) return nullptr;

    n->next = current->next;
    current->next = n;
    return head;

}

void print(Node* head){

    Node* current = head;
    while(current != nullptr){
        cout<< current->data <<" ";
        current = current->next;
    }
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;

    int num = 3;
    int pos = 6;

    Node* temp = insert(head, num, pos);

    if(temp != nullptr) head = temp;
    
    else{
        cout<<"invalid position";
        return 0;
    } 

    print(head);

return 0;
}