#include<iostream>
#include<vector>
using namespace std;

vector<int> intersection(vector<int> &v1, vector<int> &v2){
    vector<int> temp;
    int i=0;
    int j=0;
 
 while(i< v1.size() && j< v2.size()){
    if(v1[i]==v2[j]){
      if(temp.size()==0 || temp.back()!=v1[i]){
       temp.push_back(v1[i]);                               // removing duplicacy
      }
     i++;
     j++;
                          
    }
    else if(v1[i]<v2[j]){
       i++;                              
    }
    else{
        j++;
    }
 }


  
return temp;
}
int main(){
 vector<int> v1 = {3,4,4,4,5,5};
 vector<int> v2 = {4,4,5,5};

 vector<int> ans = intersection(v1,v2);
 for(int val : ans){
  cout<< val<<" ";
 }
}