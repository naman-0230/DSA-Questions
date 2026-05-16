#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
void compressedString(string &s){
    if(s.size() <= 1) return;

    int i = 0;
    int j = 1;
    while(i < s.size() && j < s.size()){

        if(s[j] == s[i]){
            j++;
        }
        else if(((j-i) > 1)){

           int length = j - i;
           string temp = to_string(length);

           s.erase(i+1, length-1);
           s.insert(i+1, temp);

           i = i + temp.size();
           j = i + 1;
        }
        else{
            i++;
            j++;
        }
    }
    //// special handling for conditions like aaaaaa or abccc i.e. last elements compression
    
    if(((j-i) > 1)){

           int length = j - i;
           string temp = to_string(length);

           s.erase(i+1, length-1);
           s.insert(i+1, temp);

           i = i + temp.size();
           j = i + 1;
        }
    
}
int main(){
string s = {"aaabccdccc"};
compressedString(s);
cout<< s;

return 0;
}