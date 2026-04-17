#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int sumK(vector<int> &v ,int k){
    int j=0, count =0;
    int sum=0;

for(int i=0; i< v.size(); i++){
    sum += v[i];
    while(sum>k){
        sum -= v[j];
        j++;
    }
    count += i-j+1;     // typical count of SA whose sum <=k
}
return count;
}

int main(){
 vector<int> v ={2,4,5,1,0,5,3};     //this is applicable for arrrays other than binary one too..except negative no.
int k =5;

long long total_SA = 1LL* (v.size())*(v.size()+1)/2;       //long long concept of 1LL

long long ans = total_SA - sumK(v,k);  // so ans we will be (total) - (count where <=k)
cout<< ans;
return 0;
}