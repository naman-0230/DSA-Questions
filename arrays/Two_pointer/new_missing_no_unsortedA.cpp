#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int missing(vector<int> &v){
    for(int i =0; i<v.size(); i++){
       while(v[i]>=1 && v[i]<v.size() && v[i] != v[v[i]-1]){
        swap(v[v[i]-1], v[i]);
       }
    }
    for(int i =1; i<v.size(); i++){
        if(v[i] != v[v[i]-1]) return i+1;
    }
    return -1;
}

int main(){
vector<int> v ={2,-3,9,0,4,5,3,6,1};
cout<< missing(v);

return 0;
}