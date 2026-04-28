// Stock Span Problem
// 🧾 Problem Statement

// You are given an array prices[] where prices[i] is the stock price on day i.

// For each day, find the span:

// Number of consecutive days (including today) where price was ≤ today’s price

// 📌 Example
// prices = [100, 80, 60, 70, 60, 75, 85]
// Output:
// span =   [1,   1,  1,  2,  1,  4,  6]

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> spanOfDays(vector<int> &v){    ///imppp logicccc
    int n = v.size();
    vector<int> ans(n);
    stack<int> st; // stores indices

    for(int i = 0; i < n; i++){                      
        while(!st.empty() && v[st.top()] <= v[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i] = i + 1;
        } else {
            ans[i] = i - st.top();
        }

        st.push(i);
    }

    return ans;
}

int main(){
    vector<int> v = {100,80,60,70,60,75,85};
    vector<int> res = spanOfDays(v);

    for(int x: res){
        cout<<x<<" ";
    }
}