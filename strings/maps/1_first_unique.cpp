#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;
char firstUnique(string &s){

unordered_map<char, int> m;
for(char c: s){
    m[c]++;
}
for(char c: s){
    if(m[c] == 1) return c;
}
return '\0';              //imp works as -1 but for char
}

int main(){
string s ={"coddec"};
cout<< firstUnique(s);
return 0;
}