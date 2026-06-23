#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node* merge(Node* l1, Node* l2){
    
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    Node dummy(0);
    Node* tail_ans = &dummy;
    
    Node* curr1 = l1;
    Node* curr2 = l2;

    if(l1->data <= l2->data){
        tail_ans->next = l1;
        curr1 = l1->next;
    } 
    else{
        tail_ans->next = l2;
        curr2 = l2->next;
    }

    tail_ans = tail_ans->next;

    while(curr1 != nullptr && curr2 != nullptr){

        if(curr1->data < curr2->data){

            tail_ans->next = curr1;
            tail_ans = tail_ans->next;
            curr1 = curr1->next;
        }

        else{

            tail_ans->next = curr2;
            tail_ans = tail_ans->next;
            curr2 = curr2->next;
        }
    }

    //for remaining nodes
    while(curr1 != nullptr){
        tail_ans->next = curr1;
        tail_ans = tail_ans->next;
        curr1 = curr1->next;
    }
    while(curr2 != nullptr){
        tail_ans->next = curr2;
        tail_ans = tail_ans->next;
        curr2 = curr2->next;
    }

    return dummy.next;
}

Node* sorting(Node* head){
    
    if(head == nullptr || head->next == nullptr) return head;
    
    Node* slow = head;
    Node* prevslow = nullptr;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        prevslow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prevslow != nullptr) prevslow->next = nullptr;

    Node* l1 = sorting(head);
    Node* l2 = sorting(slow);
    return merge(l1,l2);
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(40);
    head->next->next = new Node(20);
    head->next->next->next = new Node(45);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(0);

    cout << "Original list: ";
    print(head);

    cout << "After sorting: ";
    Node* ans = sorting(head); 
    print(ans);

    return 0;
}