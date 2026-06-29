#include<iostream>
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

void preorder(Node* root){
    if(root == nullptr) return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root == nullptr) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root == nullptr) return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root = new Node(10);
    root->right = new Node(20);
    root->left = new Node(5);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

return 0;
}