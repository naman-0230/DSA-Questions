#include<iostream>
#include<vector>

using namespace std;

int main(){
 vector<int> v ={2,3,5,1,2,4,5,2,3,7,1};
int k = 3;
int X= 10;

int sum= 0; int count= 0;
for(int i=0; i<k; i++){
    sum+= v[i];
   }

if(sum>= X){
    count++;
}

for(int i=k; i< v.size() ;i++){         //basic sliding window
   sum += v[i];
   sum -= v[i-k];

   if(sum>= X){
    count++;}
}

cout<< count;

return 0;
}