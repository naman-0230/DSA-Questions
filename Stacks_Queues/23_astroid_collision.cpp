#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

bool collision(int x, int y){
    if(x > 0 && y < 0)return true;
    else return false;
}

vector<int> astroidCollision(vector<int> &v){

    stack<int> st;
    for(int i=0; i<v.size(); i++){

     while(!st.empty() && (collision(st.top(), v[i])) && abs(st.top()) < abs(v[i])){
        st.pop();
     }
     if(st.empty() || !collision(st.top(), v[i])) 
     st.push(v[i]);

     else if(st.top() == -v[i]) st.pop();
    }
    vector<int> res;

    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(),res.end());
    
    return res;
}

int main(){
vector<int> v = {10,2,-5};

vector<int> ans = astroidCollision(v);
for(int x: ans){
    cout<<x<<" ";
}
return 0;
}