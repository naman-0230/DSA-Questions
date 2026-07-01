#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
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

int minDepth(Node* root){

    if(root == nullptr) return 0;

    if(root->left && root->right)
       return 1 + min(minDepth(root->left), minDepth(root->right));
    
    if(root->left) return 1 + minDepth(root->left);
    if(root->right) return 1 + minDepth(root->right);

    // if(!root->left && !root->right)
    return 1;

}

int main(){
    Node* root = new Node(10);
    root->right = new Node(20);
    root->left = new Node(5);
    root->right->right = new Node(40);

    cout<< minDepth(root);

return 0;
}