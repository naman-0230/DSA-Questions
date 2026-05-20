#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int myAtoi(string s) {

    int i = 0, n = s.size();
    long long num = 0;
    int sign = 1;

    // 1. skip spaces
    while(i < n && s[i] == ' ') i++;

    // 2. sign
    if(i < n && (s[i] == '+' || s[i] == '-')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // 3. digits
    while(i < n && isdigit(s[i])){

        int digit = s[i] - '0';

        num = num * 10 + digit;

        // 4. overflow check
        if(sign * num > INT_MAX) return INT_MAX;
        if(sign * num < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(sign * num);
}

int main(){
string s = {"   -43  -4 2"};

cout<< myAtoi(s);

return 0;
}
