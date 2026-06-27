#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node* random;

    Node(int x)
    {
        data = x;
        next = nullptr;
        random = nullptr;
    }
};

void print(Node *head){

    while (head)
    {

        cout << "Node: " << head->data << " ";

        if (head->random)
            cout << "Random: " << head->random->data;
        else
            cout << "Random: NULL";

        cout << endl;

        head = head->next;
    }
}

Node* copyRandomList(Node* head){

    if(head == nullptr) return nullptr;

    Node* current = head;
    while(current != nullptr){

        Node* newNode = new Node(current->data);
        newNode->next = current->next;
        current->next = newNode;

        current = current->next->next;
    }
    //random handling
    current = head;
    while(current != nullptr){
        if(current->random){
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    Node* frontcurrent = head->next;
    Node* headcopy = head->next;
    current = head;
    while(frontcurrent != nullptr && current != nullptr){
        current->next = current->next->next;
        if(frontcurrent->next) frontcurrent->next = frontcurrent->next->next;

        current = current->next;
        frontcurrent = frontcurrent->next;
    }
    
    return headcopy;

}


int main(){

    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    // next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // random pointers
    n1->random = n3;
    n2->random = n1;
    n3->random = n4;
    n4->random = n2;

    Node *head = n1;

    Node *clone = copyRandomList(head);

    cout << "Original\n";
    print(head);

    cout << "\nClone\n";
    print(clone);

    return 0;
}