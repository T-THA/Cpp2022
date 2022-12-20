#include<iostream>
using namespace std;

int main(){
    char ch;
    int flag = 0;
    int cnts = 0,words = 0,lines = 0;
    while(cin.get(ch)){
        cnts++;
        switch (ch){
        case ' ':
            if(flag) words++;
            flag= 0;
            break;
        case '\n':
            lines++;
            if(flag) words++;
            flag = 0;
            break;
        default:
            flag = 1;
            break;
        }
    }
    cout << cnts << " " << words << " " << lines;
}