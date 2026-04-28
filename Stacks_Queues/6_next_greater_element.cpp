// 🧾 Problem statement

// Given an array, for each element, find the next element to the right that is greater than it.
// If no such element exists, return -1.

// 📌 Example
// arr = [2, 1, 2, 4, 3]
// Output:
// [4, 2, 4, -1, -1]

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> next_greater_ele(vector<int> &v){

  stack<int> st;
  vector<int> ans(v.size(), -1);
 
  for(int i=0; i< v.size(); i++){                //understand why this loop logic occurs again
   while(!st.empty() && v[i] > v[st.top()]){
    ans[st.top()] = v[i];
    st.pop();
   }
   st.push(i);
  }

 return ans;
}
int main(){
vector<int> v = {2,1,2,4,3};

vector<int> res = next_greater_ele(v);

for(int x: res){
    cout<<x<<" ";
}

return 0;
}