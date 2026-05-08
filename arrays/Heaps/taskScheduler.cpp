#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    vector<int> freq(26,0);                   // since value highest will go to 26 (small)
    for(char c : tasks){                      // instead of map we can use frequency vector
        freq[c - 'A']++;                         //need value from 0 to 26
    }
   int maxfreq=0;
    for(int i= 0; i< freq.size(); i++){
        maxfreq = max(maxfreq, freq[i]);
    }
    int count = 0;
    for(int f : freq){
        if(f == maxfreq){
            count++;
        }
    }
    int part = (maxfreq - 1) * (n + 1) + count;    ///// main formula of this question///

    int ans = max((int)tasks.size(), part);
    std::cout << ans;

    return 0;
}








