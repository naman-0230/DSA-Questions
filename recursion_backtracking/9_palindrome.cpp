#include<iostream>
#include<vector>
using namespace std;
bool palindrome(string &v, int i, int j){
    if(i>=j) return true;
    
    if(v[i] != v[j]) return false;

    // if(!palindrome(v,i+1,j-1)) return false;   //both works.. currrent one is cleaner
    // return true;

    return palindrome(v,i+1,j-1);
}

int main(){
    string v = "racecar";
    int i=0; int j=v.size()-1;
    
    cout<<palindrome(v,i,j);

return 0;
}