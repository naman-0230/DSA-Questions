#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;                        //one more thing this problem can be solved by helper stack and string but this is optimized as space complexity O(1)
bool compareString(string s, string t){    /// imp pass by valuee
    int i = 0;
    int j = 0;
    while(i < s.size() && j < t.size()){
       if(s[i] == '#'){
        if(i==0){
            s.erase(i,1);        //imp when nothing before #
        }              
        else{
            s.erase(i-1,2);
            i--;
        }
        continue;         //imp here
       } 

       if(t[j] == '#'){
        if(j==0){
            t.erase(j,1);
        } 
        else{
            t.erase(j-1,2);
            j--;
        }
        continue;    
       } 

    //    if(t[j] != '#' && s[i] != '#'){    not necessary cause of continue thingy
        i++;
        j++;
       
    }
    //remaining elements
    while(i < s.size()){
       if(s[i] == '#'){
       if(i==0){
            s.erase(i,1);
        }              
        else{
            s.erase(i-1,2);
            i--;
        }
       }  
       else i++;
    }
    while(j < t.size()){
       if(t[j] == '#'){
        if(j==0){
            t.erase(j,1);
        } 
        else{
            t.erase(j-1,2);
            j--;
        }
       } 
       else j++;
    }

    return s==t;
}

int main(){
string s = {"ab##"};
string t = {"c#d#"};

cout<< compareString(s,t);

return 0;
}