#include<iostream>
#include<vector>
#include<string>
using namespace std;

int length_semiSS(string &s){

    int length = 0, max_length = 0;
    int pairs = 0;
    int j = 0;  //variable window start index

    for(int i = 1; i < s.size(); i++){       ///imp loop logic

        if(s[i-1] == s[i]){
            pairs++;
        }
        while(pairs >= 2){
            
            if(s[j] == s[j+1]){
                pairs--;
            }
            j++;
        }
        length = i-j+1;
        max_length = max(max_length, length);

    }
    return max_length;
}

int main(){
string s = {"52233"};

cout<< length_semiSS(s);

return 0;
}