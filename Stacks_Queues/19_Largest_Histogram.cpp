// Find the largest rectangle area in a histogram.
#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
using namespace std;

vector<int> lastSmaller(vector<int> &v){
 vector<int> lastSmaller(v.size(), -1);
    stack<int> st;

    for(int i= v.size()-1 ; i>= 0 ;i--){
        while(!st.empty() && v[st.top()] > v[i]){  
            lastSmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return lastSmaller;
}

vector<int> nextSmaller(vector<int> &v){
    vector<int> nextSmaller(v.size(), v.size());    //imp to put default value of v.size() not -1 as default right boundary must be last considering we not finding smalller value
    stack<int> st;

    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[st.top()] > v[i]){
            nextSmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nextSmaller;
}

int maxArea(vector<int> &v){

vector<int>last = lastSmaller(v);
vector<int>next = nextSmaller(v);
int maxArea = 0;
for(int i=0; i<v.size(); i++){

  int width = next[i] - last[i] - 1;
  int height = v[i];
  int Area = height * width;
  maxArea = max(maxArea, Area);
}

return maxArea;
}




int main(){
vector<int> v = {2,1,5,6,3,5};
cout<< maxArea(v);
return 0;
}