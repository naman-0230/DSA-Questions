#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &v, int D, int mid){
    
    int days = 1;        // start with day 1
    int load = 0;

    for(int i = 0; i < v.size(); i++){

        if(load + v[i] <= mid){
            load += v[i];   // add to current day
        }
        else{
            days++;               // need new day
            load = v[i];    // start with this package

            if(days > D) return false;  
        }
    }

    return true;

}

int maxVector(vector<int> &v){
 int maxElement = 0;
 for(int i=0; i< v.size(); i++){

   maxElement = max(maxElement,v[i]);
 }
 return maxElement;
}
int sumVector(vector<int> &v){
 int sumElement = 0;
 for(int i=0; i< v.size(); i++){

   sumElement += v[i];
 }
 return sumElement;
}

int minCapacity(vector<int> &v, int n){
 
    int low = maxVector(v);
    int high = sumVector(v);
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
int D = 3;

cout<< minCapacity(v,D);
return 0;
}