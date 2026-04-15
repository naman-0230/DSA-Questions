#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){
  
    vector<int> v ={2,3,5,3,1,3,5,8};
    unordered_set<int> s;
  
    bool flag=true;
    for(int i =0; i<v.size(); i++){
        if(s.find(v[i])==s.end()){         
         s.insert(v[i]);
        }
        else{
            cout<<"duplicate is found";
            flag = false;
            break;
        }
    }
     if(flag){
        cout<<"no duplicates";
     }
    
    return 0;
}

