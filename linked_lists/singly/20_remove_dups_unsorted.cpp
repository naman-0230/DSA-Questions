#include<iostream>
#include<unordered_map>
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

    unordered_map<int, int> map;
    Node* current = head;
    Node dummy(0);
    Node* prevcurrent = &dummy;
    prevcurrent->next = current;

    while(current != nullptr){

        if(map.find(current->data) == map.end()){
            map[current->data]++;
            prevcurrent = current;
            current = current->next;
        }
        else{
            map[current->data]++;
            Node* temp = current;
            prevcurrent->next = current->next;
            current = current->next;
            delete temp;
        }
    }
    return head;

}


int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(10);
    head->next->next->next = new Node(25);
    head->next->next->next->next = new Node(20);
    head->next->next->next->next->next = new Node(30);

    cout << "Original list: ";
    print(head);

    cout << "After sorting: ";
    Node* ans = removedups(head); 
    print(ans);

    return 0;
}