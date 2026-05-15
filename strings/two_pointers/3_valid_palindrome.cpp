#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isPalindrome(string &s){
    int i = 0;
    int j = s.size()-1;
    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
bool isNewPalindrome(string &s){
    int i = 0;
    int j = s.size()-1;
    while(i < j){
        if(s[i] != s[j]){
            string temp = s;
            temp.erase(i,1);
            if(isPalindrome(temp)) return true;
            else{
                string temp = s;
                temp.erase(j,1);
                if(isPalindrome(temp)) return true;
                else return false;
            }
        }
        i++;
        j--;
    }
    return true;
}
int main(){
string s = {"radcecar"};
cout <<isNewPalindrome(s);

return 0;
}