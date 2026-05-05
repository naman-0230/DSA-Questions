#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

class MinStack{
    vector<int> v;
    stack<int> st;
    public: 
    void push(int x){
        v.push_back(x);
        if(st.empty() || v[st.top()] >= x){
            st.push(v.size()-1);
        }
    }
    void pop(){
        if(v.empty()) return;
        
        if(!st.empty() && st.top() == v.size()-1){
            st.pop();
        }
        v.pop_back();
    }
    int top(){
        if(!v.empty()) return v.back();
        else return -1; 
    }

    int getMin(){
        if(!st.empty()) return v[st.top()];
        else return -1;
    }
};



int main(){
MinStack st;
st.push(5);
st.push(3);
st.push(2);
st.pop();
cout<< st.getMin();
return 0;
}