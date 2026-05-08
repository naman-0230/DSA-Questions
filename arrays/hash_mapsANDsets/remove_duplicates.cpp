#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){

    // vector<int> v ={2,4,3,5,2,4,8,7,1};
    // unordered_set<int> s = {v.begin(),v.end()};

    // for(int x : s){
    //    cout<<x<<" ";                                 // removing duplicates but order is messed up
    // }

    
    
    vector<int> v ={2,4,3,5,2,4,8,7,1};
    unordered_set<int> s;
    vector<int> result;
    for(int i =0; i<v.size(); i++){
        if(s.find(v[i])==s.end()){         // order is preserved
         result.push_back(v[i]);
         s.insert(v[i]);
        }
    }
    
    for(int x : result){
        cout<<x<<" ";
    }
    return 0;
}

//unordered_map<int, int> m;
// vector<int> result;                // by maps but its not much preferred because of 
                                               // only existence is asked not number of frequencies
// for (int x : v) {
//     if (m[x] == 0) {
//         result.push_back(x);
//     }
//     m[x]++;
// }