#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    vector<int> v = {2,5,1,4,0,8,10};
 unordered_set<int> s(v.begin(), v.end()); 
 int max_length = 0; 
 
for(int x : s){
    if(s.find(x-1)==s.end()){
     int curr = x;                       // putting current cause we need consecutive elements
     int length = 1;                      // x heree is values of set so x+1 is next value of set(can be anything)
                                         // we want consecutive next value so putting it on current variable so that we can find for current +1
     while(s.find(curr + 1)!=s.end()){
       curr++;
       length++;
     }
     max_length = max(max_length, length);
    }
}
cout << max_length;

    return 0;
}