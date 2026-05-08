#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){


// vector<int>v ={2,4,1,2,5,4,5};
// unordered_map<int, int> m;

// for (int x : v) {
//     m[x]++;
// }

// for (auto it : m) {
//     if (it.second == 1) {
//         cout<< it.first;
//     }
// }


//MAIN METHOD HERE IS    XOR    AS ITS SPACE COMPLEXITY IS O(1)   map one is O(n)


vector<int>v ={2,4,1,2,5,4,5};
int ans = 0;

for(int i=0; i< v.size(); i++){
   ans^= v[i];
}

cout<<ans;
return 0;
}