#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(string &s, int left, int right){

    while(left < right){
        if(s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}

void partition(string &s, int start,
               vector<string> &curr,
               vector<vector<string>> &ans){

    // Entire string has been partitioned
    if(start == s.size()){
        ans.push_back(curr);
        return;
    }

    // Try every possible substring starting from 'start'
    for(int end = start; end < s.size(); end++){

        // Only continue if current substring is palindrome
        if(isPalindrome(s, start, end)){

            // Choose
            curr.push_back(s.substr(start, end - start + 1));

            // Explore remaining string
            partition(s, end + 1, curr, ans);

            // Backtrack
            curr.pop_back();
        }
    }
}

int main(){

    string s = "aab";

    vector<vector<string>> ans;
    vector<string> curr;

    partition(s, 0, curr, ans);

    for(auto &x : ans){
        for(auto &y : x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}