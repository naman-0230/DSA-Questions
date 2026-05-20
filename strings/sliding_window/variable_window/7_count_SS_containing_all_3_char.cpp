#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;
int countSS(string &s){
    int count = 0;
    int j = 0;
    int countA = 0, countB = 0, countC = 0;  

    for(int i=0; i<s.size(); i++){

        if(s[i] == 'a') countA++;
        else if(s[i] == 'b') countB++;
        else countC++;

        while(countA >= 1 && countB >= 1 && countC >= 1){
            
            count += s.size() - i;            //// important counttttt  .. also imp to do count one time inside while not before while too

            if(s[j] == 'a') countA--;
            else if(s[j] == 'b') countB--;
            else countC--;

            j++;

        }

    }
    return count;
}

int main(){

    string s = {"abcabaaaccccbccaaabc"};
    cout<< countSS(s);

return 0;
}