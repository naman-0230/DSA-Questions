#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSA(vector<int> &v , int k){       
unordered_map<int, int> m;                
int length = 0, max_length = 0;
int sum = 0;
 
m[0] = -1;                                    // index is now stored in map according to the problem 
for(int i=0; i< v.size(); i++){

    sum += v[i];                             //prefix sum
    
    if(m.find(sum - k)!=m.end()){
     int j = m[sum-k];
    length = i-j;                           //imp its not i-j+1 cause we already are getting prefix[j-1]
    max_length = max(max_length, length);
    }

  if(m.find(sum)==m.end()){                // important condition to only store first occurrence
      m[sum] = i;
  }  

}

 return max_length;

}
int main (){
  vector<int> v ={1,2,0,1,1,0,3,0,1};
 int k=2;
 
 cout<<countSA(v,k);
    return 0;
}
