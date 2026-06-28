#include<iostream>
using namespace std;

class Node{
    public:
    string url;
    Node* next;
    Node* prev;

    Node(string sitename){
        url = sitename;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory{
    private: Node* current;
    public:
    BrowserHistory(string homepage){
        current = new Node(homepage);
    }

    void visit(string sites){
        if(current->next){
            Node* deleter = current->next;
            current->next = nullptr;
            while(deleter != nullptr){
                Node* deleter2 = deleter->next;
                delete deleter;
                deleter = deleter2;
            }

            Node* temp = new Node(sites);
            current->next = temp;
            temp->prev = current;
            current = current->next;
        }
        else{
            Node* temp = new Node(sites);
            current->next = temp;
            temp->prev = current;
            current = current->next;
        }
    }

    string back(int steps){
        for(int i=0; i<steps; i++){
            if(!current->prev) break;
            current = current->prev;
        }
        return current->url;
    }

    string forward(int steps){
        for(int i=0; i<steps; i++){
            if(!current->next) break;
            current = current->next;
        }
        return current->url;
    }
};

int main(){
    

return 0;
}