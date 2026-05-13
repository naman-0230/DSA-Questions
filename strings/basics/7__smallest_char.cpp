#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

char smallestChar(string &s){
    char smallest = s[0]; 
    for(char c:s){
        if(c < smallest){
        smallest = c;
        }
    } 
    return smallest;
}
char largestChar(string &s){
    char largest = s[0]; 
    for(char c:s){
        if(c > largest){
        largest = c;
        }
    } 
    return largest;
}
int main(){
string s("programming");

cout<< smallestChar(s)<<" "<< largestChar(s);

return 0;
}