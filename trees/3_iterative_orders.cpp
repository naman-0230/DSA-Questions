#include<iostream>
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

vector<int> preorder(Node* root){
    
    if(!root) return {};

    vector<int> ans;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()){

        Node* temp = st.top();
        st.pop();

        ans.push_back(temp->data);

        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }

    return ans;
}

vector<int> inroder(Node* root){

    if(!root) return {};
    vector<int> ans;
    stack<Node*> st;    

    while(root != nullptr || !st.empty()){
        while(root != nullptr){
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();
        ans.push_back(root->data);

        root = root->right;
    }

    return ans;
}

vector<int> postorder(Node* root){
    
}

int main(){
    Node* root = new Node(10);
    root->right = new Node(20);
    root->left = new Node(5);

    vector<int> res = preorder(root);
    for(int x: res){
        cout<<x<<" ";
    }

return 0;
}