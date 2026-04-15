#include<iostream>
#include<vector>

using namespace std;

int main(){
 vector<int> v ={2,3,5,1,2,4};
int k = 3;

int sum= 0; 
float avg = 0;
for(int i=0; i<k; i++){
    sum+= v[i];
}
avg = (float)sum/k;
cout<< avg<<endl;


for(int i=k; i< v.size() ;i++){         //basic sliding window
   sum += v[i];
   sum -= v[i-k];
   avg = (float)sum/k;
   cout<< avg<<endl;
}

return 0;
}