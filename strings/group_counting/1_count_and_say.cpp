#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;
string sayString(int n){
    vector<string> sequence(n+1);
    sequence[0] = "1";

    for(int i=0; i<n; i++){

        int j = 0 , k = 1;

        int count = 1;

        while(j < sequence[i].size() && k <= sequence[i].size()){
 
            if(k == sequence[i].size() || sequence[i][k] != sequence[i][j]){

                // sequence[i+1].push_back(count);
                sequence[i+1] += to_string(count);
                sequence[i+1].push_back(sequence[i][j]);
                j = k;
                k++;
                count = 1;
            }
            else{
                count++;
                k++;
            }
        } 

    }

    return sequence[n-1];
}

int main(){
    int n = 4;
    cout<< sayString(n);

return 0;
}