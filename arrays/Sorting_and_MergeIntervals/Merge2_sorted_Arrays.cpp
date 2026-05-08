#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> &v1, vector<int> &v2){
    vector<int> temp;
    int i=0;
    int j=0;
 
 while(i< v1.size() && j< v2.size()){
    if(v1[i]<=v2[j]){
       temp.push_back(v1[i]);
       i++;                               // for main elements
    }
    else{
        temp.push_back(v2[j]);
        j++;
    }
 }

  while(i<v1.size()){
    temp.push_back(v1[i]);
    i++;                             // for remaining element
  }

  while(j<v2.size()){
    temp.push_back(v2[j]);
    j++;
  }
return temp;
}
