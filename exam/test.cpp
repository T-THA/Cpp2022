#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#define strvec vector<string>
using namespace std;

struct Floor{
    string val;
    int len;
};
vector<Floor> my;
int maxlen = 0;
void add(string s);
void del(string s);
void print();
void sprint(int addr, int len);
strvec split(char c, string s);
int main(){
    int n = 0;
    cin >> n;
    n++;
    while(--n >= 0){
        string s;
        getline(cin, s);
        strvec sv = split(' ', s);
        if(sv.size()<= 2){
            switch(sv[0][0]){
                case 'a':
                    add(sv[1]);
                    break;
                case 'd':
                    del(sv[1]);
                    break;
                case 'p':
                    print();
                    break;
                default:
                    break;
            }
        }else{
            int tmp1 = stoi(sv[1]), tmp2 = stoi(sv[2]);
            sprint(tmp1, tmp2);
        }
    }
    return 0;
}
void add(string s){
    Floor tmp;
    tmp.val = s.substr(2, s.length()-2);
    tmp.len = (s.length()-2) /2;
    my.push_back(tmp);
    if(tmp.len > maxlen){
        maxlen = tmp.len;
    }
}
void del(string s){
    string cmp = s.substr(2, s.length()-2);
    for(int i = 0; i< my.size(); i++){
        if(my[i].val == cmp){
            my.erase(my.begin() + i);
            break;
        }
    }
    maxlen = 0;
    for(int i = 0; i <my.size(); i++){
        if(my[i].len>maxlen) maxlen = my[i].len;
    }
}
void print(){
    int remainlen = maxlen;
    for(int i = 0; i < my.size(); i++){
        if(i == 0) cout << "0x";
        if(my[i].len <= remainlen){
            cout << my[i].val;
            remainlen -= my[i].len; 
        }else{
            for(int j = 0; j < remainlen*2; j++){
                cout << "C";
            }
            cout << endl;
            cout << "0x" << my[i].val;
            remainlen = maxlen - my[i].len;
        }
        if(i == my.size() && remainlen != 0){
            for(int j = 0; j < remainlen*2; j++) cout << "C";
        }
    }
    cout << endl;
}
void sprint(int addr, int len){
    int remainlen = maxlen;
    string ret = "";
    for(int i = 0; i < my.size(); i++){
        if(my[i].len <= remainlen){
            ret+= my[i].val;
            remainlen -= my[i].len; 
        }else{
            for(int j = 0; j < remainlen*2; j++){
                ret+= "C";
            }
            ret += my[i].val;
            remainlen = maxlen - my[i].len;
        }
    }
    for(int j = 0; j < len*2; j++){
        ret+= "C";
    }
    cout << ret.substr(addr*2, len*2);
}
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