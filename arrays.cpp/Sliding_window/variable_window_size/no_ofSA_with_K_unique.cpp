#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSA(vector<int> &v , int k){
    unordered_map<int,int> m;
 int j=0;  
 int count = 0;                              ////imp problem////

 for(int i=0; i< v.size(); i++){

    m[v[i]]++;

    while(m.size()>k){
        m[v[j]]--;
        if(m[v[j]]==0){
        m.erase(v[j]);
        }
        j++;
    }
    if(m.size()<=k){          // first of all for count of SA ==k , you cant do count++
                              // need to do count i-j+1.... but this is for all SA <=k
                              // so we call the function for and get <=k and then <=k-1
                              // then subtract it to get =k one

        count += i-j+1 ;      //important count for variable window//
    }
 }
 return count;
}

int main (){
  vector<int> v ={2,5,3,2,8,2,4,3};
 int k=3;
 
 int ans = countSA(v,k)-countSA(v, k-1);

    return 0;
}
