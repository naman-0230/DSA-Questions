
#include<iostream>
#include<vector>
#include<stack>
#include<cctype>
#include<cmath>
using namespace std;

int prec(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
return 0;                       
}

int applyExp(int a, int b, char c){
    int res;
    if(c== '+') res = a+b;
   else if(c== '-') res = a-b;
   else if(c== '*') res = a*b;
   else if(c== '/') res = a/b;
   else if(c== '^') res = (int)pow(a,b);

   return res;
}

int expCalc(string &s){
  stack<int> Dig;
  stack<char> Op;
  for(int i= 0; i< s.size(); i++){
    char c = s[i];

    if(c == ' '){continue;}

    else if(isdigit(c)){
        int num = 0;
        while(i<s.size() && isdigit(s[i])){   //for handling multidigit numbers
            num = num*10 + (s[i]-'0');
            i++;    
        }
        i--;

        Dig.push(num);

    }
    else if(c == '('){            ////proper ( ) handling
    Op.push(c);
    }

    else if(c == ')'){
    while(!Op.empty() && Op.top() != '('){
        int a = Dig.top(); Dig.pop();
        int b = Dig.top(); Dig.pop();
        int fresh = applyExp(b, a, Op.top());
        Dig.push(fresh);
        Op.pop();
       }
    Op.pop(); 
    }

    else{
       
        while(!Op.empty() && (prec(Op.top()) > prec(c) || (prec(Op.top())== prec(c) && c!= '^'))){    /// for ^ right associativity handling  //put op.top() first always in condtion
            
            int a = Dig.top(); Dig.pop();
            int b = Dig.top(); Dig.pop();
           int fresh = applyExp(b,a,Op.top());
           Dig.push(fresh);
            
            Op.pop();
        }
        
        Op.push(c);        
        }
          
        }    
  

  while(!Op.empty()){                 // for remaining elements after traversal
    int a = Dig.top(); Dig.pop();
    int b = Dig.top(); Dig.pop();
    char c = Op.top(); Op.pop();
    int fresh = applyExp(b,a,c);
    Dig.push(fresh);
  }


  return Dig.top();
 }

int main(){
string s = {"10 + (2 * 3^2) - 4"};

 cout<< expCalc(s);

return 0;
}