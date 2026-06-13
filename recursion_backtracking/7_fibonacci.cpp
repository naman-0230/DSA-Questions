#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    return fib(n-1) + fib(n-2);
}
int main(){
int n=6;
cout<<fib(n);

return 0;
}