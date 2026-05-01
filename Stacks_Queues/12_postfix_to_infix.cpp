#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

string postfixToInfix(string s){
    stack<string> st;

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
            st.push(to_string(num));
        }
        //for alpha
        else if(isalpha(c)){
            st.push(string(1,c));
        }

        else{ // operator
            if(st.size() < 2) return "invalid expression";

            string a = st.top(); st.pop(); // right
            string b = st.top(); st.pop(); // left

            string exp = "(" + b + c + a + ")";
            st.push(exp);
        }
    }
    if(st.size()!= 1) return "invlaid expression";
    return st.top();
}

int main(){
    string s = "22 3 c + * 7 *";
    cout << postfixToInfix(s);
    return 0;
}