#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;           /// "overwrite in place" method of same problem.. more cleaner less tricky and stable
void compressString(string &s){

    int i = 0;
    int k = 0;

    while(i < s.size()){

        char current = s[i];
        int count = 0;

        // count duplicates

        while(i < s.size() && s[i] == current){

            count++;
            i++;
        }

        // write character

        s[k] = current;
        k++;

        // write count if > 1

        if(count > 1){

            string temp = to_string(count);

            for(char c : temp){

                s[k] = c;
                k++;
            }
        }
    }

    // remove extra leftover part

    s.resize(k);
}

int main(){

    string s = "aaabccdccc";

    compressString(s);

    cout << s;

    return 0;
}