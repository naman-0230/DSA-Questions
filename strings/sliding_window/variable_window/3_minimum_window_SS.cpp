#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;
string minimumSS(string &s, string &target){

    string ans;
    unordered_map<char, int> current;
    unordered_map<char, int> need;
    int j = 0; int formed = 0;
    int length = 0;
    int min_length = INT_MAX;
    int index = -1;

    for(int i=0; i< target.size(); i++){
        need[target[i]]++;
    }

    int required = need.size();

    for(int i=0; i<s.size(); i++){

        current[s[i]]++;

        if(current[s[i]] == need[s[i]]){

            formed++;

            if(formed == required){
                length = i-j+1;

                if(length < min_length){
                    index = j;
                }
                min_length = min(min_length , length);
        }
            
        }


        while(formed == required){
            
            length = i-j+1;
            if(length < min_length){
            index = j;
            }
            min_length = min(min_length,length);

            current[s[j]]--;

            if(current[s[j]] < need[s[j]]){
                formed--;
            }

            j++;
        }

    }
    ans = s.substr(index, min_length);

    if(index == -1) return "";
    return ans;

}

int main(){
string s = {"abbbaabbaa"};
string target = {"aab"};

cout<<minimumSS(s, target);
return 0;
}