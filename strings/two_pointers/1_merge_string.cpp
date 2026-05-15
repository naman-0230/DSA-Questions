#include<iostream>
#include<vector>
#include<string>
using namespace std;
string mergedString(string &a , string &b){
    string ans;
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < a.size() && j < b.size()){
       ans.push_back(a[i]);
       ans.push_back(b[j]);
       i++;
       j++;
    }
    while(i < a.size()){    //for remaining elements
        ans.push_back(a[i]);
        i++;
    }
    while(j < b.size()){
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}

int main(){
string a = {"abcd"};
string b = {"efgh"};
cout<< mergedString(a, b);

return 0;
}