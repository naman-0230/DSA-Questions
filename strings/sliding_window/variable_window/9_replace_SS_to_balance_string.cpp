#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;
int lengthSS(string &s){    //////HARD ONE ... REVISE PROPERLY

    int min_length = INT_MAX, length = 0;
    int balance = s.size()/4;

    vector<int> total(26,0);

    for(int i=0; i<s.size(); i++){
        total[s[i] - 'a']++;
    }

    vector<int> curr(26,0);

    int countBad = 0;
    int j = 0;

    for(int i=0; i<s.size(); i++){

        curr[s[i] -'a']++;

        while(true){
            
            bool flag = true;
            
            for(int k=0; k < curr.size(); k++){

                if(total[k] - curr[k] > balance){
                    flag = false;
                    break;
                }     
            }
            if(flag == false) break;
            
            length = i-j+1;
            min_length = min(min_length, length);

            curr[s[j] - 'a']--;
            j++;
        }   
    }

    return min_length;
}

int main(){
    string s = {"qqqq"};

    cout<< lengthSS(s);

return 0;
}