#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int lengthSA(vector<int> &v , int k){
   
 int j=0;                         
 int min_length=INT_MAX, length=0;
 int sum = 0;
                  
 
 for(int i=0;i< v.size(); i++){
   sum += v[i];

//    if(sum>=k){
//     length= i-j+1;                              --->> redundant idk why i did it
//     min_length = min(min_length, length);
//       }

   while(sum>=k){
       length= i-j+1;                              //first this then update j
       min_length = min(min_length, length); 
    
       sum -= v[j];
       j++;
   }

 }

 return (min_length == INT_MAX)? 0 : min_length;         //when there is no minimum
}

int main (){
  vector<int> v ={0,1,2,1,0,2,1,0};
 int k=5;
 
 cout<<lengthSA(v,k);
    return 0;
}
