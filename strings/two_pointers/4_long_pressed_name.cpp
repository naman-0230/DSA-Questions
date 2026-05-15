// Given two strings:
// name
// typed
// Return:
// true
// if typed could be a long-pressed version of name.
// Otherwise return:
// false
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
bool isLongPressed(string &name, string &typed){
    if(typed.size() < name.size()) return false;
    int i = 0;
    int j = 0;
    while(i < name.size() && j < typed.size()){
        if(name[i] == typed[j]){
            i++; 
            j++;
        }
        else{
            
            if(j>0 && typed[j] == typed[j-1]){
                j++;
            }
            else return false;
        }
    }
    while(j < typed.size()){      ///remainihg elements of typed
        if(typed[j] == typed[j-1]){
            j++;
        }
        else return false;
    }
    return i==name.size();     ////imppp concept to check if name is totally traversed
}
int main(){
string name = {"alex"};
string typed = {"aalexx"};

cout<<isLongPressed(name , typed);

return 0;
}