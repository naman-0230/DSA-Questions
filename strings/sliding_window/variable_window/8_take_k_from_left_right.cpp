#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;
int min_moves(string &s, int k){
    int moves;
    int length = 0, max_length = 0;
    int j = 0;

    int countA_window = 0, countB_window = 0, countC_window = 0;
    int countA_total = 0, countB_total = 0, countC_total = 0;

    //for counting total frequencies of abc;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'a') countA_total++;
        else if(s[i] == 'b') countB_total++;
        else if(s[i] == 'c') countC_total++;
    }

    if(countA_total < k || countB_total < k || countC_total < k) return -1;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'a') countA_window++;
        else if(s[i] == 'b') countB_window++;
        else if(s[i] == 'c') countC_window++;

        while((countA_total - countA_window < k) || (countB_total - countB_window < k) 
            || (countC_total - countC_window < k)){

            if(s[j] == 'a') countA_window--;
            else if(s[j] == 'b') countB_window--;
            else if(s[j] == 'c') countC_window--;

            j++; 
        }
        length = i-j+1;
        max_length = max(max_length, length);
    }
    
    moves = s.size() - max_length;

    return moves;
}

int main(){
string s = {"aabacabbacbc"};
int k = 2;

cout<<min_moves(s, k);

return 0;
}