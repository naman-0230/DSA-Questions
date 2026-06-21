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


int length_of_Loop(Node* head){

    int length = 0;

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(fast == nullptr || fast->next == nullptr) return -1;

    //choosing fast for movement
    while(true){
        fast = fast->next;
        length++;
        if(slow == fast) break;
    }
    return length;

}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth-> next = fourth;

    cout<< length_of_Loop(head);
   

return 0;
}