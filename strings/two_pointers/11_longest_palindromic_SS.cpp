#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;

int lengthPalindrome(string &s){
    int length = 0, max_length = 0;
    
    for(int i=0; i<s.size(); i++){

        //odd palindromes
        int left = i, right = i;
        while(left >= 0 && right < s.size() && s[left] == s[right]){

            length = right-left+1;
            max_length = max(max_length, length);

            left--;
            right++;
        }
        //even palindromes
        left = i ; right = i+1;
        while(left >= 0 && right < s.size() && s[left] == s[right]){

            length = right-left+1;
            max_length = max(max_length, length);

            left--;
            right++;
        }
    }
    
    return max_length;
}

int main(){
string s = {"babadabacej"};

cout<<lengthPalindrome(s);

return 0;
}