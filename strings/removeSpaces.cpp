#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
void removeSpaces(string &s){
   int x= 0;
   for(int i=0; i<s.size(); i++){
    if(s[i] != ' '){
        s[x] = s[i];
        x++;
    }
   }
   s.resize(x);                 ////imppp step to resize it
}
int main(){
string s = "i wanna go there";
removeSpaces(s);
cout<<s;
return 0;
}