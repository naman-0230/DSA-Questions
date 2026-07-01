#include<iostream>
#include<queue>
using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;

// Node(int x) : data(x), left(nullptr), right(nullptr) {}  another method to do it in c++

    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void bfs(Node* root){
    if(!root) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){

        Node* temp = q.front();

        cout<< temp->data<< " ";

        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main(){
    Node* root = new Node(10);
    root->right = new Node(20);
    root->left = new Node(5);

    bfs(root);

return 0;
}