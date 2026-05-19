// Given a binary array:
// Return:
// minimum swaps required
// to group all 1s together.

#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int minSwaps(string &s){
    int minSwaps = INT_MAX, swaps = 0;
    int ones = 0;
    //first get the total number of ones to make fixed window of that size..
    //  then traverse.. return where we get max current 1s
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1') ones++;
    }

    if(ones == 0) return -1;     

    int curr = 0;
    for(int i=0; i< ones; i++){
        if(s[i] == '1') curr++;
    }
    swaps = ones - curr;
    minSwaps = min(minSwaps, swaps);

    for(int i=ones; i<s.size(); i++){

        if(s[i-ones] == '1') curr--;
        if(s[i] == '1') curr++;

        swaps = ones - curr;
        minSwaps = min(minSwaps, swaps);
    }
    
    return minSwaps;
}

int main(){
string s = {"1001110110111"};

cout<< minSwaps(s);

return 0;
}