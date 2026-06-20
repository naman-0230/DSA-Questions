#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> ans;

bool isPossible(string &s, int dot, int start, int end){

    if(s[start] == '0' && start != end) return false;

    if((end - start + 1) > 3) return false;

    int num = 0;
    for(int i=start; i<=end; i++){
        num = num*10 + (s[i]-'0');
    }
    if(num > 255) return false;

    return true;
}

void restore(string &s, int dot, int start, string &curr){

    if(start > s.size()) return;

    int rem = s.size() - start;
    if(rem < dot || rem > dot * 3) return;    //good pruning optimization by gpt not my own instinct so remind this one


    if(start == s.size() && dot == 0){
        // curr.pop_back();                                it will try to pop back . again after returning to for loop which will crash
        ans.push_back(curr.substr(0, curr.size()-1));     //only storing till before .
        return;
    }

    if(dot == 0) return;
    
    for(int end = start; end < s.size(); end++){

        if(!isPossible(s, dot, start, end)) continue;

        curr += s.substr(start, end-start+1);
        curr.push_back('.');
        restore(s, dot-1, end+1, curr);

        curr.pop_back();
        curr.erase(curr.size() - (end-start+1));
    }
}

int main(){
    string s = "25525511135";

    string curr;

    restore(s,4,0,curr);

    for(auto x: ans){
        cout<<x<<endl;
    }
return 0;
}