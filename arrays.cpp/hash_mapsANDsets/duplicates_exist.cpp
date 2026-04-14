#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int>v = {2,3,4,5,2,4,5,7,3};
    unordered_map<int, int> m;

    bool flag=true;

    for(int i=0; i<v.size(); i++){             //same logic as counting frequencies 
        m[v[i]]++;         

     //checking inside here {optimized} instead of checking of making map
        if(m[v[i]] > 1){
        cout<<"duplicates exist";
        flag=false;
        break;                                     
        }
    }
    if(flag){                                  //classic bool
        cout<<"no duplicates found";
    }

return 0;
}

    // vector<int> v ={2,3,5,3,1,3,5,8};
    // unordered_set<int> s;
  
    // bool flag=true;
    // for(int i =0; i<v.size(); i++){
    //     if(s.find(v[i])==s.end()){         
    //      s.insert(v[i]);
    //     }                                                    /////SET IS PREFERRED FOR JUST THE EXISTENCE CHECKING
    //     else{
    //         cout<<"duplicate is found";
    //         flag = false;
    //         break;
    //     }
    // }
    //  if(flag){
    //     cout<<"no duplicates";
    //  }