#include<iostream>
#include<vector>
#include<string>
using namespace std;
string removechar(string &s, char ch, int i){
    if(i>=s.size()) return "";

    //take the char
    if(s[i] != ch){
        return s[i] + removechar(s,ch,i+1);
    }
    //skip the ch char
    else{
        return removechar(s,ch,i+1);
    }
}
int main(){
    string s = "abcxdexgxxhix";
    char ch = 'x';
    int i = 0;
    cout<<removechar(s,ch,i);

return 0;
}