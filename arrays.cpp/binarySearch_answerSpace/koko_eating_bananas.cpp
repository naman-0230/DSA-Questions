#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &v, int n , int mid){
   
    int time = 0;
    for(int i=0; i< v.size(); i++){
     time += ((v[i]+mid-1)/mid);        ///imp ceil formula most optimal
    }

    if(time <= n){
        return true;
    }
    else{
        return false;
    }
}

int maxVector(vector<int> &v){
 int maxElement = 0;
 for(int i=0; i< v.size(); i++){

   maxElement = max(maxElement,v[i]);
 }
 return maxElement;
}

int minSpeed(vector<int> &v, int n){
 
    int low = 1;
    int high = maxVector(v);
    int ans = high;

    while(low <= high){
    int mid = low + (high-low)/2;
  
    if(isPossible(v,n,mid)){
        ans = mid;
        high = mid - 1;
    }
    else{
        low = mid + 1;
    }
    }
   
    return ans;
}

int main(){
vector<int> v = {3,4,5,8,1,4};
int total_time = 10;


cout<<"min speed required per hour is"<<" "<< minSpeed(v,total_time);
return 0;
}