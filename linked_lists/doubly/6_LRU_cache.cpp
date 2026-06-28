#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    int key;
    Node* next;
    Node* prev;

    Node(int key, int x){
        data = x;
        this->key = key;
        next = nullptr;
        prev = nullptr;
    }
};

class LRU_cache{
    private:
    int capacity;
    Node* head;
    Node* tail;
    int count;
    unordered_map<int, Node*> map;

    public:
    LRU_cache(int x){
        capacity = x;
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void put(int key, int x){

        if(map.find(key) != map.end()){

            Node* ans = map[key];
            ans->data = x;
            //same get copy paste
            if(ans == tail) return;
    
            if(ans->prev) ans->prev->next = ans->next;
            else {
                head = head->next;
                if(head) head->prev = nullptr;
            }
            if(ans->next) ans->next->prev = ans->prev;
    
            ans->next = nullptr;
            ans->prev = tail;
    
            if(tail) tail->next = ans;
            tail = ans;

            return;
        }
        
        if(count < capacity){
            Node* newNode = new Node(key, x);
            map[key] = newNode;
            if(tail) tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            if(!head) head = newNode;

            count++;
        }
        else{

            Node* newNode = new Node(key, x);
            map[key] = newNode;
            map.erase(head->key);
            
            Node* temp = head;
            if(head->next) head->next->prev = nullptr;
            head = temp->next;
            if(!head) tail = nullptr;
            delete temp;
            
            if(tail) tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            if(!head) head = newNode;
        }
    }

    int get(int key){
        if(map.find(key) == map.end()) return -1;

        Node* ans = map[key];
        int ansdata = ans->data;

        if(ans == tail) return ansdata;

        if(ans->prev) ans->prev->next = ans->next;
        else {
            head = head->next;
            if(head) head->prev = nullptr;
        }

        if(ans->next) ans->next->prev = ans->prev;

        ans->next = nullptr;
        ans->prev = tail;

        if(tail) tail->next = ans;
        tail = ans;

        return ansdata;
    }
};

int main(){
    

return 0;
}