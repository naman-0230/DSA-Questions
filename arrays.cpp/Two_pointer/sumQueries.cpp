#include<iostream>
using namespace std;
int rangeSum(int arr[], int n, int l, int r){
int sum;
    if(l == 0) {
        sum = arr[r];
    } else {
        sum = arr[r] - arr[l-1];
    }
    return sum;
}

int main() {
    int arr[] = {2, 4, 5, 7, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int prefix[n];               //PREFIX sum METHOD

    // build prefix sum
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    int L,R;
    cin>>L>>R;

    cout<<rangeSum(prefix,n,L,R);

    return 0;
}

// can do by normal printSumArray function with parametrized range but it will call that fucntion
//everytime it will execute, since we query it multiple times , its better to use prefix method 