#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

bool validParentheses(string &s){
  stack<char> st;
  for(char c : s){
    if(c== '{' ||c== '(' ||c== '['){
        st.push(c);
    }
    else{
        if(st.empty()) return false;
        
        char top = st.top();
        if(c== '}' && top != '{' ||
           c== ')' && top != '(' ||
           c== ']' && top != '[')
           return false;  
        }
        st.pop();          //popping after validation is better then popping first
  }
  return st.empty();
}

int main(){
string s = "{]}";
cout<< validParentheses(s);

return 0;
}