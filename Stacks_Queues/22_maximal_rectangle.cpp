// You are given a binary matrix (0 and 1):   matrix[i][j] ∈ {0,1}

// 👉 Find the largest rectangle containing only 1’s

// Return:
// maximum area
#include<iostream>
#include<stack>
#include<vector>
#include<climits>
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
    vector<int> nextSmaller(v.size(), v.size());   
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

int maximalArea(vector<vector<int>> &m){

    int row_ans = 0;
    int maximumArea = 0;
    
    if(m.empty() || m[0].empty()) return -1;

    vector<int> height(m[0].size(), 0);

    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[0].size();j++){

           if(m[i][j]==0) height[j] = 0;
           else height[j]++;

        }
       row_ans = maxArea(height);
       maximumArea = max(maximumArea, row_ans);
    }
    return maximumArea;
}

int main(){
 vector<vector<int>> matrix = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };

    cout << maximalArea(matrix);

return 0;
}