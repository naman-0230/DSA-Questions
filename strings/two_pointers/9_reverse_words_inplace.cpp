#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

// void reverseWords(string &s){     //did it for fun .. logical issues lol
//     stringstream ss(s);
//     string words;
//     int size = s.size();
//     while(ss >> words){
//         s.insert(0, words);
//         s.insert(words.size()," ");
//     }
//     s.resize(size);
// }

void reverseWords(string &s){

    int i = 0;                //swapping whole string
    int j = s.size()-1;
    while(i<j){
        swap(s[i], s[j]);
        i++;
        j--;
    }

    int x = 0;
    stringstream ss(s);     //putting in ss for word seperation
    string word;

    while(ss >> word){

        reverse(word.begin(), word.end());       // reversing individual words

        int y = 0;
        while(y < word.size()){                 //overwriting new word in original string
        s[x] = word[y];
        x++;
        y++;
        }

        s[x] = ' ';                            //adding spaces after each word
        x++;
    }
    s.resize(x-1);                            //for last extra space .. resize
}

int main(){

string s = {"i love playing guitar"};
reverseWords(s);
cout<<s; 

return 0;
}