// Given:

// a number as string num
// an integer k

// Remove k digits such that the resulting number is smallest possible
#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
using namespace std;

string removeK(string &s, int k){

deque<char> dq;
for(char c: s){

    while(!dq.empty() &&  k!=0 && dq.back() > c){
        dq.pop_back();
        k--;
    }
    dq.push_back(c);
 }

while(!dq.empty() && k!=0){      //when k is not 0 even after string has ended
    dq.pop_back();
    k--;
}

string ans;                                  //shifting it all to ans string
for(char c: dq){
    if(ans.empty() && c == '0') continue;    //for leading zeroes handling
    ans.push_back(c);
}

return ans;
}

int main(){
string s = "12344";
int k = 3;

if(k >= s.size()){
    cout<<"0";
}
else{
cout << removeK(s, k);
}
return 0;
}