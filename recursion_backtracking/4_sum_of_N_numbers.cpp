#include<iostream>
#include<vector>
using namespace std;
int sumofN(int n){
    if(n==0) return 0;
    
    return n + sumofN(n-1);
}
int main(){
    int n = 10;
    cout<<sumofN(n);

return 0;
}