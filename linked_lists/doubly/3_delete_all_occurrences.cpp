#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void printforward(Node* head){
    while(head != nullptr){
        cout<< head->data << " ";
        head = head->next;
    }
}

Node* deleteall(Node* head, int x){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr && head->data == x){
        delete head;
        return nullptr;
    }

    Node* current = head;
    while(current != nullptr){
        if(current->data == x){
            if(current->next) current->next->prev = current->prev;

            if(current->prev) current->prev->next = current->next;
            else head = current->next;

            Node* temp = current;
            current = current->next;
            delete temp;
        }
        else{
            current = current->next;
            if(head) head->prev = nullptr;
        }
    }
    return head;
}
int main(){

    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(2);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    Node* head = first;

    Node* haha = deleteall(head,2);
    printforward(haha);

return 0;
}