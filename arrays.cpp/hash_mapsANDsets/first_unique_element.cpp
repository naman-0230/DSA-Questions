#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int>v = {2,3,4,5,2,4,5,7,3};
    unordered_map<int, int> m;

    for(int i=0; i<v.size(); i++){                            //same logic as counting frequencies 
        m[v[i]]++;
    }
  
    //traverse frequency map and see which value is 1 first but order can be messy 
    // and different from original vector

    // for(auto x : m){     
                                       
    //     if(x.second == 1){
    //     cout<<x.first;
    //     break;  }
    // }

    for(int i = 0; i < v.size(); i++){      //traversing through vector itself while checking
       if(m[v[i]] == 1){                    // map values so it ensures the order
        cout << v[i];
        break;
    }
}

return 0;
}