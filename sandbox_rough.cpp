// Next Greater Element II (Circular Array)

// 👉 Twist:

// array is circular
// you simulate by looping twice

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> next_greater_ele(vector<int> &v){

  stack<int> st;
  vector<int> ans(v.size(), -1);
  int n = v.size();
  for(int i=0; i< 2*n; i++){                //understand circular loop
   while(!st.empty() && v[i % n] > v[st.top()]){
    ans[st.top()] = v[i % n];
    st.pop();
   }
   if(i<n)          // imp step to not enter elements that we found ans again as ele who did not got ans will still be on stack
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