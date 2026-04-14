#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int>v1 = {2,3,4,2,2,4,2,7,2};
    unordered_map<int, int> m;

    for(int i=0; i<v1.size(); i++){                            //same logic as counting frequencies 
        m[v1[i]]++;
    }

    bool flag=true;
    for(auto x : m){     
         
        if(x.second > (int)v1.size()/2){                  //normal condition of value is greater than n/2
        cout<<x.first;                                 //typecaasting as v.size gives unsigned long value
        flag=false;
    } 
    }

    if(flag)
    cout<< "no such element found";

return 0;
}