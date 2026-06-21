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


Node* firstNode_inLoop(Node* head){

    Node* slow = head;
    Node* fast = head;
    Node* tempo = head;

    while(fast != nullptr && fast->next != nullptr){
        
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(fast == nullptr || fast->next == nullptr) return nullptr;

    //lets choose fast for next phase
    while(fast != tempo){
        tempo = tempo->next;
        fast = fast->next;
    }
    return tempo;

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

    Node* temp = firstNode_inLoop(head);
    cout<<temp->data;

return 0;
}