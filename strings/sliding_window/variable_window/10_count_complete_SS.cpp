#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:

    // solve one valid segment
    int solveSegment(string &s, int k){

        int n = s.size();
        int ans = 0;

        // distinct chars possible = 1 to 26
        for(int distinct = 1; distinct <= 26; distinct++){

            int windowSize = distinct * k;

            if(windowSize > n) break;

            vector<int> freq(26, 0);

            int currDistinct = 0;
            int exactK = 0;

            int j = 0;

            for(int i = 0; i < n; i++){

                int idx = s[i] - 'a';

                // add right char
                freq[idx]++;

                if(freq[idx] == 1)
                    currDistinct++;

                if(freq[idx] == k)
                    exactK++;

                else if(freq[idx] == k + 1)
                    exactK--;

                
                // maintain fixed window
                if(i - j + 1 > windowSize){

                    int leftIdx = s[j] - 'a';

                    if(freq[leftIdx] == k)
                        exactK--;

                    else if(freq[leftIdx] == k + 1)
                        exactK++;

                    freq[leftIdx]--;

                    if(freq[leftIdx] == 0)
                        currDistinct--;

                    j++;
                }

                
                // valid complete substring
                if(i - j + 1 == windowSize &&
                   currDistinct == distinct &&
                   exactK == distinct){

                    ans++;
                }
            }
        }

        return ans;
    }

    
    int countCompleteSubstrings(string word, int k) {

        int ans = 0;

        int start = 0;

        // split into valid segments
        for(int i = 1; i < word.size(); i++){

            if(abs(word[i] - word[i-1]) > 2){

                string segment = word.substr(start, i - start);

                ans += solveSegment(segment, k);

                start = i;
            }
        }

        // last segment
        string lastSegment = word.substr(start);

        ans += solveSegment(lastSegment, k);

        return ans;
    }
};


int main(){

    Solution obj;

    string word = "igigee";
    int k = 2;

    cout << obj.countCompleteSubstrings(word, k);

    return 0;
}