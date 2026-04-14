#include<iostream>
#include<vector>
using namespace std;

vector<int> unionArray(vector<int> &v1, vector<int> &v2){
    vector<int> temp;
    int i=0;
    int j=0;
 
 while(i< v1.size() && j< v2.size()){
    if(v1[i]==v2[j]){
        if(temp.size()==0 || temp.back()!=v1[i]){
            temp.push_back(v1[i]); }
     i++;
     j++;
    }
    else if(v1[i]<v2[j]){
          if(temp.size()==0 || temp.back()!=v1[i]){
            temp.push_back(v1[i]); }                                      // removing duplicacy
       i++;                                                           // for main elements
    }
    else{
        if(temp.size()==0 || temp.back()!=v2[j]){
            temp.push_back(v2[j]); }
     
        j++;
    }
 }
 while(i<v1.size()){
     if(temp.size()==0 || temp.back()!=v1[i]){
        temp.push_back(v1[i]); }                                 // removing duplicacy
    i++;                                                       // for remaining element
  }

  while(j<v2.size()){
    if(temp.size()==0 || temp.back()!=v2[j]){
    temp.push_back(v2[j]);}
    j++;
  }

  
return temp;
}
int main(){
 vector<int> v1 = {3,4,4,4,5,5};
 vector<int> v2 = {4,4,5,5};

 vector<int> ans = unionArray(v1,v2);
 for(int val : ans){
  cout<< val<<" ";
 }
}