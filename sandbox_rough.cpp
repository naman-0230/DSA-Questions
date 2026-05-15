#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool isvowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
       c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
    else return false;
}
void reverseString(string &s){
    int i = 0;
    int j = s.size()-1;
    while(i < j){
        if(isvowel(s[i]) && isvowel(s[j])){    //// can use isalpha for that i just created own function but no need 
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if(!isvowel(s[i])){
            i++;
        }
        else if(!isvowel(s[j])){
            j--;
        }
    }
}
int main(){
string s = {"cate"};
reverseString(s);
cout<<s; 

return 0;
}