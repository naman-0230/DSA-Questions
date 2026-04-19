#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& v) {

    int n = v.size();
    vector<int> ans(n, 1);

    // Step 1: Prefix product
    int prefix = 1;
    for(int i = 0; i < n; i++){
        ans[i] = prefix;
        prefix *= v[i];
    }

    // Step 2: Suffix product
    int suffix = 1;
    for(int i = n - 1; i >= 0; i--){
        ans[i] *= suffix;
        suffix *= v[i];
    }

    return ans;
}

int main(){
    vector<int> v= {1,2,3,4};

    vector<int> ans = productExceptSelf(v);

    for(int x : ans){
        cout << x << " ";
    }
}