#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

int prec(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

// same infix to postfix logic
string infixToPostfix(string s){
    string ans = "";
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        char c = s[i];

        if(c == ' ') continue;

        if(isalnum(c)){        ///for multidigit, needs token based parsing like string stream soo laterzz
            ans += c;
            ans += ' ';
        }

        else if(c == '('){
            st.push(c);
        }

        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                ans += ' ';
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && 
                 (prec(st.top()) > prec(c) || 
                 (prec(st.top()) == prec(c) && c != '^'))){

                ans += st.top();
                ans += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        ans += st.top();
        ans += ' ';
        st.pop();
    }

    return ans;
}

string infixToPrefix(string s){

    // 1. reverse
    reverse(s.begin(), s.end());

    // 2. swap brackets
    for(char &c : s){
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    // 3. postfix
    string postfix = infixToPostfix(s);

    // 4. reverse result
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main(){
    string s = "(A+B)*C";
    cout << infixToPrefix(s);
    return 0;
}