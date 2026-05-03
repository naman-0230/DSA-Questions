#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

bool redunParentheses(string &s){
  stack<char> st;
  for(char c : s){
      if(c!= '}' && c!= ')' && c!= ']'){
          st.push(c);
        }
        else{
        bool flag = true;
        while(!st.empty() && (st.top()!= '(' && st.top()!= '{' && st.top()!= '[')){
          if(st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*' || st.top() == '^'){
            flag = false;
          }
          st.pop();
        }
        if(flag){
            return flag;
        }
        st.pop();   
}
}
return false;
}

int main(){
string s = "{a+b*(c-d)}";
cout<< redunParentheses(s);

return 0;
}