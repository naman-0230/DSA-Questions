#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
int compare(string &a, string &b){
    int i = 0;
    int j = 0;
    while(i < a.size() || j < b.size()){         //imp for handling as versions can have more revisions than other
        string temp1;
        string temp2;
        int x;
        int y;
        while(i < a.size() && a[i] != '.'){      //imp to again put boundary check
            temp1.push_back(a[i]);
            i++;
        }
        if(i < a.size()) i++;                    //cleaner handling

        if(!temp1.empty()) x = stoi(temp1);      //imp handling when one has more revision than other.
        else x = 0;

        while(j < b.size() && b[j] != '.'){
            temp2.push_back(b[j]);
            j++;
        }
        if(i < a.size()) j++;

        if(!temp2.empty()) y = stoi(temp2);
        else y = 0;

        if(x > y) return 1;
        else if(x < y) return -1;
    }
    return 0;
}
int main(){
string version1 = {"1.2"};
string version2 = {"1.10"};
cout << compare(version1, version2);

return 0;
}