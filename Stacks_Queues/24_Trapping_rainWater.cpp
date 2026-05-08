#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int trappedWater(vector<int> &v){

    int water = 0;
    stack<int> st;
    for(int i=0; i<v.size(); i++){

      while(!st.empty() && v[st.top()] < v[i]){           /// decreasing monotonic stack
       int bottom = v[st.top()];
       st.pop();
       if(st.empty()) break;

       int width = i - st.top() -1;                      /// main this concept for 5,0,0,2 understand without height it will not calc water of 2nd index zero so mainly for equal values

       int height = min(v[st.top()], v[i]) - bottom;
       water += height * width;
      }
      st.push(i);
    }
    return water;
}

int main(){
    vector<int> v = {5,0,0,2};
    cout<< trappedWater(v);
    return 0;
}