#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool isLetter(char &c){
    if((c >= 97 && c <= 122)||(c <= 90 && c >= 65)) return true;
    else return false;
}
void reverseString(string &s){
    int i = 0;
    int j = s.size()-1;
    while(i < j){
        if(isLetter(s[i]) && isLetter(s[j])){    //// can use isalpha for that i just created own function but no need 
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if(!isLetter(s[i])){
            i++;
        }
        else if(!isLetter(s[j])){
            j--;
        }
    }
}
int main(){
string s = {"a-bC-dEf-ghIj"};
reverseString(s);
cout<<s; 

return 0;
}