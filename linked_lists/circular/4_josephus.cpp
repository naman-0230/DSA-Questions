#include<iostream>
#include<utility>
using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node(int x){
        next = nullptr;
        data = x;
    }
};

void printcll(Node* head){

    if(head == nullptr) return;

    Node* current = head;

    do{
        cout<< current->data<<" ";
        current = current->next;
    }
    while(current != head);
}

Node* remaining(Node* head, int k){
    if(k<=0 || head == nullptr || head->next == head) return head;
    if(k==1){
        Node* current = head;
        while(current->next != head){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        current->next = current;
        return current;
    }

    //main logic
    Node* prev = head;
    Node* front = head;

    do{
        for(int i = 0; i < k-1; i++){
        prev = front;
        front = front->next;
        }

        if(front == head) head = front->next;
        Node* temp = front;
        prev->next = front->next;
        front = front->next;
        delete temp;
    }
    while(prev != front);

    return prev;
}

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = first;

    Node* head = first;

    Node* ans = remaining(head, 2);

    printcll(ans);

return 0;
}