#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
int val[1001];

int main(){
    int Clen = 0, Cindex = 0, Vindex = 0, tmp = 0, count = 0;
    string s;
    getline(cin , s);
    Clen  = s.size();
    // char *c;
    // c = const_cast <char *>(s.data());
    const char *c = s.data();
    while(Cindex < Clen){
        switch (c[Cindex])
        {
        case '>':
            Vindex++;
            break;
        case '<':
            Vindex--;
            break;
        case '+':
            val[Vindex]++;
            break;
        case '-':
            val[Vindex]--;
            break;
        case ',':
            if((tmp = getchar()) == EOF)
                val[Vindex] = '\0';
            else 
                val[Vindex] = tmp;
            break;
        case '.':
            printf("%c", val[Vindex]);
            break;
        case '[':
            if(val[Vindex] == 0){
                count = 1; // count [
                Cindex ++;
                for(;count != 0;Cindex++){
                    if(c[Cindex]  == '['){
                        count += 1;
                    }else if(c[Cindex] == ']'){
                        count -= 1;
                    }
                }
                Cindex--;
            }
            break;
        case ']':
            if(val[Vindex] != 0){
                count = 1; // count ]
                Cindex--;
                for(;count != 0;Cindex--){
                    if(c[Cindex]  == ']'){
                        count += 1;
                    }else if(c[Cindex] == '['){
                        count -= 1;
                    }
                }
                Cindex ++;
            }
            break;
        default:
            break;
        }
        Cindex++;
    }
    return 0;
}