#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int p = 31;
const int mod = 1e9 + 7;

vector<int> rabin_karp(string &s, string &pattern){ ////hard logic
    vector<int> ans;
    int value;
    long long power = 1;
    long long soo;
    long long hash_pattern = 0;

    //hash of pattern
    for(int i=0; i<pattern.size(); i++){

        value = pattern[i] - 'a' + 1;

        hash_pattern = (hash_pattern * p + value) % mod;
    }
    power = 1;

    int k = pattern.size(); long long hash = 0;
    
    long long highestPower = 1;
    
    for(int i = 0; i < k-1; i++){
        highestPower = (highestPower * p) % mod;
    }

    //hash of first fixed window
    
    for(int i=0; i<k; i++){

        int value = s[i] - 'a' + 1;

        hash = (hash * p + value) % mod;
    }

    if(hash == hash_pattern){
        ans.push_back(0);
    }

    for(int i=k; i<s.size(); i++){
        // remove left char contribution
        hash = (hash - ((s[i-k]-'a'+1) * highestPower)%mod + mod) % mod;

        // shift powers
        hash = (hash * p) % mod;

        // add new char
        hash = (hash + (s[i]-'a'+1)) % mod;

        if(hash == hash_pattern){

        ans.push_back(i-k+1);
        }
    }


    return ans;
}

int main(){
string s = {"dsfbcdkjcdfscdbfbcd"};
string pattern = {"bcd"};

vector<int> res = rabin_karp(s, pattern);

for(int x: res){
    cout<<x<<" ";
}

return 0;
}