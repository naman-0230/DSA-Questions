#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;
string removeInvalid(string &s){
    stack<int> st;
    vector<bool> remove(s.size(), false);
    string ans;
    
    for(int i=0; i<s.size(); i++){

        char c = s[i];
        if(c == '{' || c == '(' || c == '['){
            st.push(i);
        }
        else if(c == '}' || c == ')' || c == ']'){
            if(st.empty()) remove[i] = true;
            else{
                st.pop();
            }
        }
    }
    while(!st.empty()){
        remove[st.top()] = true;
        st.pop();
    }

    for(int i=0; i<s.size(); i++){
        if(!remove[i]) ans.push_back(s[i]);
    }
    return ans;
}

int main(){
string s = "()())()";
cout<<removeInvalid(s);

return 0;
}