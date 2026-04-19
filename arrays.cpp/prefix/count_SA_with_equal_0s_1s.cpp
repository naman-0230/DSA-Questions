#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSA(vector<int> &v){       
unordered_map<int, int> m;                
int count = 0;
 int sum = 0;

 m[0]= 1;                 //value in map is now frequency

 for(int i=0; i< v.size(); i++){
    if(v[i]==0){
    sum--;                //treating zero as -1 so can do sum+= -1 or simply sum--;
    }
    else{
       sum += v[i];      // normal prefix 
    }

    if(m.find(sum - 0)!= m.end()){            //since we want equal 0s 1s sum will become ==0 if we convert 0s to -1
     count += m[sum - 0];
    }
  m[sum]++;
 }

return count;
} 
int main (){
  vector<int> v ={1,1,0,1,1,0,0,0,1};
 
 cout<<countSA(v);
    return 0;
}
