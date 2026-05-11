#include<iostream>
using namespace std;

int main(){        ///ASCII logic

    string s = "HeLLo";

    for(int i = 0; i < s.length(); i++){

        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] - 32;
        }

        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 32;
        }
    }

    cout << s;

    return 0;
}


//using imp <cctype> library functions of islower , tolower


// #include<iostream>
// #include<cctype>                          
// using namespace std;

// int main(){

//     string s = "HeLLo WoRLd";

//     for(int i = 0; i < s.length(); i++){

//         if(islower(s[i])){
//             s[i] = toupper(s[i]);
//         }

//         else if(isupper(s[i])){
//             s[i] = tolower(s[i]);
//         }
//     }

//     cout << s;

//     return 0;
// }