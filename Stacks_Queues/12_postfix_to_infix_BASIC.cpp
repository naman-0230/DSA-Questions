#include<iostream>
#include<stack>
#include<string>
using namespace std;

string postfixToInfix(string s){
    stack<string> st;

    for(int i = 0; i < s.size(); i++){
        char c = s[i];

        if(c == ' ') continue;

        // operand
        if(isalnum(c)){
            st.push(string(1, c));
        }
        else{ // operator
            string a = st.top(); st.pop(); // right
            string b = st.top(); st.pop(); // left

            string exp = "(" + b + c + a + ")";
            st.push(exp);
        }
    }

    return st.top();
}

int main(){
    string s = "234+*7*";
    cout << postfixToInfix(s);
}