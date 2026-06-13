#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
using namespace std;
int sum(int a , int b){
    if(a==0) return b;
    b+= a%10; 
    sum(a/10 , b);
}

int main(){
int a= 7525; int b =0;
cout<<sum(a,b);
return 0;
}



