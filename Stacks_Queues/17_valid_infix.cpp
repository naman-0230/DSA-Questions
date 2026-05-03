#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

bool isOperator(char &c){
    return (c=='+' || c=='-' || c=='/' || c=='*' || c=='^');
}

bool validity(string &s){
  stack<char> st;
  char prev = '#';
  for(char c : s){
    if(c== '{' ||c== '(' ||c== '['){
        st.push(c);
        if(isalnum(prev)) return false;             //for alnum(
        prev = c;
    }
    else if(c== '}' ||c== ')' ||c== ']'){           //for nomral parantheses validity
        if(st.empty()) return false;
        
        char top = st.top();
        if(c== '}' && top != '{' ||
           c== ')' && top != '(' ||
           c== ']' && top != '[')
           return false; 

        if(isOperator(prev)) return false;                 // for op )
        prev = c;

        st.pop();          //popping after validation is better then popping first
        }
     
    else if(isOperator(c)){                                                          //for op+op pr (op
      if(isOperator(prev) || prev == '#' || prev== '{' || prev== '(' || prev== '[') return false;
      prev = c;
    }
    else if(isalnum(c)){                                                            //for alnum+alnum or )alnum
        if(isalnum(prev) || prev== '}' || prev== ')' || prev== ']') return false; 
        prev = c;
    }

    else{
        return false;      ///invalid characters
    }
   }
   if(isOperator(prev)) return false;
  return st.empty();
}


int main(){
string s = "{a+*(c-d)}";
cout<< validity(s);

return 0;
}