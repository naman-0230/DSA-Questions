#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

bool validParentheses(string &s){
 stack<int> st;
 for(char c: s){
  if(c=='(' || c== '{' || c== '['){
    st.push(c);
  }
  else{
    if(st.empty())
        return false;
    int x = st.top(); 
    if(c==')' && x !='(' || c== '}' && x != '{' || c== ']' && x != '['){
        return false;
    }  
    st.pop();
  }
 }
 return st.empty();
 }






int main(){
string s = "{}";
cout<< validParentheses(s);

return 0;
}