#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
bool equalCheck(string &a, string &b){

    if(a.size() != b.size()) return false;
    int i = 0;
    int j = 0;
    while(i<a.size()){
        if(a[i] != b[j]) return false;
            j++;
            i++;
    }
    return true;
}
int main(){
string a= {"abc"};
string b= {};
cout<< equalCheck(a,b);
return 0;
}