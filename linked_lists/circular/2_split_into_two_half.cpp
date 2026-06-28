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

pair<Node*, Node*> split(Node* head){   //or if you wanna return two heads.. pass as parameter by reference and update it..
                                        // split(Node* head, Node**head1, Node* &head2)
    if(head == nullptr) return {nullptr, nullptr};
    if(head->next == head) return {head, nullptr}; 

    Node* slow = head;
    Node* fast = head;  
    
    while(fast->next != head && fast->next->next != head){

        slow = slow->next; 
        fast = fast->next->next; 
    };

    Node* frontslow = slow->next;
    slow->next = head;

    if(fast->next != head) fast = fast->next;
    fast->next = frontslow;

    return {head, frontslow};

}

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = first;

    Node* head = first;

    auto p = split(head);
    Node* head1 = p.first;
    Node* head2 = p.second;

    printcll(head1);
    cout<<endl;
    printcll(head2);

return 0;
}