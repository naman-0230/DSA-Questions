#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lengthSA(vector<int> &v , int k){
    unordered_map<int,int> m;
 int j=0;  
                            
 int max_length=0, length=0;
 
 for(int i=0;i< v.size(); i++){
   m[v[i]]++;
   while(m[0]>k){

    m[v[j]]--;                                       //////////BUT MAP IS UNNCECESSary
                                                  ///////refer to another 2Nd solution in the list
    if(m[v[j]]==0){
        m.erase(v[j]);
    }
    j++;
   }

 length = i-j+1;
 max_length = max(length, max_length);
 }

 return max_length;
}

int main (){
  vector<int> v ={1,0,0,1,1,0,1,0,1};
 int k=2;
 
 cout<<lengthSA(v,k);
    return 0;
}
