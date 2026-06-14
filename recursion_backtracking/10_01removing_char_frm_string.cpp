#include<iostream>
#include<vector>
#include<string>
using namespace std;
string removechar(string &s, char ch, int i){
    if(i<0) return "";
    string ans = removechar(s,ch,i-1);
    if(s[i] != ch) ans.push_back(s[i]);

    return ans;
}
int main(){
    string s = "abcxdexgxxhix";
    char ch = 'x';
    int i = s.size()-1;
    cout<<removechar(s,ch,i);

return 0;
}