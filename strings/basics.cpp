#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
void reverseString(string &s){
 int i = 0;
 int j= s.length()-1;
 while(i<j){
    swap(s[i], s[j]);
    i++;
    j--;
 }
}

string concatenateString(string &a, string &b){
 string s = a + b;
 return s;
}

int main(){
cout<< "enter the string"<<endl;
string s;
cin >> s;

reverseString(s);
cout<< s<<endl;


string a("abcd");
string b("qwerty");
cout<< concatenateString(a,b);
return 0;
}