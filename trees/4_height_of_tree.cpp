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

int maxDepth(Node* root){

    if(root == nullptr) return 0;

    return 1 + max(maxDepth(root->right), maxDepth(root->left));

}

int main(){
    Node* root = new Node(10);
    root->right = new Node(20);
    root->left = new Node(5);

    cout<< maxDepth(root);

return 0;
}