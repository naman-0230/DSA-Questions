#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool swapEquality(string &a, string &b){
    if(a.size() != b.size()) return false;
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < a.size() && j < b.size()){

        if(a[i] != b[j]) count++;
        i++;
        j++;
    }
    if(count == 0)return true;
    if(count != 2) return false;
    char x , y;
    i = 0;
    j = 0;

    while(i < a.size() && j < b.size()){

    if(count == 2){

        if(a[i] != b[j]){
            x = a[i];
            y = b[j];
            count--;
        }
        i++;
        j++;
    }

    else{

        if(a[i] != b[j]){

            if(a[i] == y && b[j] == x) return true;
            else return false;
        }
        i++;
        j++;
    } 
    }
 return false;
}

int main(){
string a = {"banking"};
string b = {"bgnkina"};

cout<< swapEquality(a, b);

return 0;
}