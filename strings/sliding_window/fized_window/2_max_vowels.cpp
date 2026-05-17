#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
bool isVowel(char c){
    c= tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    else return false;
}

int max_vowels(string &s, int k){

    if(k > s.size()) return 0;

   int maxii = 0;
   int count = 0;
   for(int i=0; i<k; i++){
    if(isVowel(s[i])){
        count++;
    }
   }
   maxii = count;

   for(int i=k; i< s.size(); i++){
    if(isVowel(s[i-k])) count--;
    if(isVowel(s[i])) count++;

    maxii = max(maxii, count);
   }
   return maxii; 
}

int main(){
string s = {"sothisisthemaxioutripyoudid"};
int k = 5;
cout<< max_vowels(s, k);

return 0;
}