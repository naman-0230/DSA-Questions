// Problem:

// For each day, how many days until warmer temperature?

// Example:
// [73,74,75,71,69,72,76,73]
// → [1,1,4,2,1,1,0,0]

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextTemp(vector<int> &v){    
    int n = v.size();
    vector<int> ans(n, 0);
    stack<int> st; 

    for(int i = 0; i < n; i++){                      
       while(!st.empty() && v[i] > v[st.top()]){
        ans[st.top()] = i - st.top();
        st.pop();
       }
       st.push(i);
    }

    return ans;
}

int main(){
    vector<int> v = {73,74,75,71,69,72,76,73};
    vector<int> res = nextTemp(v);

    for(int x: res){
        cout<<x<<" ";
    }
}