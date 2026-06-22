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

void print(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
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


Node* reverseKGroup(Node* head, int k) {

    if(head == nullptr || k <= 1)
        return head;

    Node dummy(0);
    dummy.next = head;

    Node* prevGroup = &dummy;

    while(true) {

        // Step 1: Check if k nodes exist
        Node* kth = prevGroup;
        for(int i = 0; i < k; i++) {
            kth = kth->next;
            if(kth == nullptr)
                return dummy.next;
        }

        // Step 2: Identify boundaries
        Node* groupStart = prevGroup->next;
        Node* nextGroup = kth->next;

        // Step 3: Detach current group
        kth->next = nullptr;

        // Step 4: Reverse current group
        Node* newHead = reverse(groupStart);

        // Step 5: Reconnect
        prevGroup->next = newHead;
        groupStart->next = nextGroup;

        // Step 6: Move to next group
        prevGroup = groupStart;
    }
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

    int k = 2;

    head = reverseKGroup(head,k);
    print(head);

return 0;
}