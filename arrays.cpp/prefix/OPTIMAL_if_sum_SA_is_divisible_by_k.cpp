#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool checkSubarraySum(vector<int> &v , int k){

    // special case                        /////very important handling
    if(k == 0){
        for(int i = 1; i < v.size(); i++){
            if(v[i] == 0 && v[i-1] == 0){
                return true;
            }
        }
        return false;
    }

    unordered_map<int, int> m;
    m[0] = -1;

    int sum = 0;

    for(int i = 0; i < v.size(); i++){

        sum += v[i];
        int rem = sum % k;

        if(rem < 0) rem += k;

        if(m.find(rem - 0) != m.end()){
            int j = m[rem - 0];
            if(i - j >= 2){              ///early checkout no need for max_length/////
                return true;
            }
        } 
        if(m.find(rem)==m.end()){
          m[rem]= i; 
        }            
    }

    return false;
}

int main (){
    vector<int> v ={1,2,0,1,1,0,3,0,1};
    int k=2;

    cout << checkSubarraySum(v,k);
}