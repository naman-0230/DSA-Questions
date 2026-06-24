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


Node* removedups(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* current= head->next;
    Node* prevcurrent = head;

    while(current != nullptr){

        if(current->data == prevcurrent->data){
            Node* temp = current;
            prevcurrent->next = current->next;
            current = current->next;
            delete temp;
        }
        else{
            prevcurrent = current;
            current = current->next;
        }
    }
    return head;

}


int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(25);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(30);

    cout << "Original list: ";
    print(head);

    cout << "After sorting: ";
    Node* ans = removedups(head); 
    print(ans);

    return 0;
}