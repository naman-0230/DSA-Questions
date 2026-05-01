#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

int prec(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
return 0;                       
}

string infixToPostfix(string s){
    string ans = "";
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        char c = s[i];

        if(c == ' ') continue;

        // operand
        if(isdigit(c)){
            int num = 0;
            while(i< s.size() && isdigit(s[i])){   //for handling multidigit numbers
            num = num*10 + (s[i]-'0');
            i++;    
        }
        i--;
           ans += to_string(num);
           ans += " ";
        }
        //for alpha
        else if(isalpha(c)){
            ans += c;
            ans += " ";
        }

        else if(c == '('){ // operator
           st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top()!= '('){
              ans += st.top();
              ans += " ";
              st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && (prec(st.top()) > prec(c) || (prec(st.top()) == prec(c) && c!= '^'))){
                ans += st.top();
                ans += " ";
                st.pop();
            }
            st.push(c);
        }
    }
    
    //for remaining operators in stack
    while(!st.empty()){
        if(st.top() == '(') return "Invalid Expression";  //for alone ( in stack
        ans += st.top();
        ans += " ";
        st.pop();
    }
  
    if(!ans.empty()){      //handling last extra space
      ans.pop_back();
    }

    return ans;
}

int main(){
    string s = "2 + 3 * 5 - 6";
    cout <<infixToPostfix(s);
}