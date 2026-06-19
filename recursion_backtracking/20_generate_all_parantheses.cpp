#include<iostream>
#include<vector>
using namespace std;

void parantheses(int &open, int &close, vector<char> &curr, int n, vector<vector<char>> &ans){

    if(curr.size() == 2*n && open == close){
        ans.push_back(curr);
        return;
    }
    if(open < n){
        curr.push_back('(');
        open++;
        parantheses(open, close, curr, n, ans);
        curr.pop_back();
        open--;
    }
    if(close < open){
        curr.push_back(')');
        close++;
        parantheses(open, close, curr, n, ans);
        curr.pop_back();
        close--;
    }

}

int main(){

    vector<vector<char>> ans;
    vector<char> curr;
    int n = 3;
    int open = 0;
    int close = 0;

    parantheses(open, close, curr, n, ans);

    for(auto x: ans){
        for(char y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

return 0;
}