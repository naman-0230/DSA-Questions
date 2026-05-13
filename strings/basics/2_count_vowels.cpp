#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;

const string vowels = "aeiouAEIOU";             ////global variable so that no need to declare it inside both the functions 

int consonantCount(string &s){
    int count = 0;
    //old method
    // for(int i=0; i<s.size(); i++){                  
    //     if(s[i] == ' ') continue;
    //     else if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
    //         count ++;
    //     }
    // }
    //new method
   
    for(char c : s){
        if(c == ' ') continue;
        else if(vowels.find(c) == string::npos){
           count++;
        }
    }
    return count;
}
int vowelsCount(string &s){
   int count = 0;
    for(char c : s){
        if(c == ' ') continue;
        else if(vowels.find(c) != string::npos){
           count++;
        }
    }
    return count;
}
int main(){
string s = "cars of two";
cout<<consonantCount(s)<<endl;
cout<< vowelsCount(s);
return 0;
}