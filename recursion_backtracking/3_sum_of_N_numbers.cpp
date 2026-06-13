#include<iostream>
#include<vector>
using namespace std;
void sumofN(int n, int &sum){
   if(n==0) return;
    sum += n;
    sumofN(n-1, sum);
}

int main(){
    int n = 10;
    int sum = 0;
    sumofN(n, sum);
    cout<<sum;

return 0;
}