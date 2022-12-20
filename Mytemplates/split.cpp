#include<iostream>
#include<cstdio>
#include<vector>
#include<ctype.h>
#include<string>
#define strvec vector<string>
using namespace std;
strvec split(char c, string s){
    strvec ret;
    s = s+c;
    unsigned long long loca;
    while((loca = s.find(c)) != s.npos){
        ret.push_back(s.substr(0, loca));
        s=s.substr(loca+1, s.size() - loca - 1);
    }
    return ret;
}
int main(){
    int n = 0;
    cin >> n;
    getchar();
    while(--n >= 0){
        string s;
        getline(cin, s);
        strvec sv = split(' ', s);
        //do
    }
    return 0;
}