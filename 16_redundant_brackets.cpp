#include<iostream>
#include<stack>
using namespace std;

bool hasRedundantBrackets(string s){
    stack<char> st;

    for(char c : s){
        if(c == ')'){
            bool hasOperator = false;

            while(!st.empty() && st.top() != '('){
                char top = st.top();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    hasOperator = true;
                }
                st.pop();
            }

            if(!hasOperator) return true; // redundant

            st.pop(); // remove '('
        }
        else{
            st.push(c);
        }
    }

    return false;
}

int main(){
    string s = "((a+b))";
    cout << hasRedundantBrackets(s);
}