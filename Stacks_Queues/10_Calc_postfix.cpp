
#include<iostream>
#include<vector>
#include<stack>
#include<cctype>
using namespace std;

int expCalc(string &s){

  stack<int> st;
  for(char c: s){
    if(isdigit(c)){
        st.push(c - '0');
    }
    else{
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        int res;
        if(c=='+') res =b + a;
        else if(c=='-') res =b - a;
        else if(c=='*') res =b * a;
        else if(c=='/') res =b / a;
        st.push(res);
    }
  }
  
  return st.top();
}
int main(){
string s = {"45+67**"};

 cout<< expCalc(s);

return 0;
}