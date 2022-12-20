#include <iostream>
#include <vector>
using namespace std;
string toString(vector<char> x);
void myprint(vector<char> &x);
int loca = 0;
int len = 0;
int N, C, ISN, L;
// C：缓冲区容量大小 ISN： seqno起始值 L-1：seqno的最大值
int main(){
    cin >> N >> C >> ISN >> L;
    len = L - 1;
    vector<char> my;
    for(int i = 0; i < len; i++) my.push_back('#');
    while(--N >= 0){
        int seqno;
        string str;
        cin >> seqno >> str;
        for(int i = 0; i < str.length(); i++){
            int editloca = seqno - ISN + i;
            if(seqno < ISN) editloca = editloca + L;
            if(editloca >= loca && editloca < C && my[editloca]=='#') my[editloca] = str[i];
        }
        if(loca < len && my[loca] != '#'){
            myprint(my);
            cout << " "<< toString(my) << endl;
        }else{
            cout << "0 null " << toString(my) << endl;
        }
    }
    return 0;
}
string toString(vector<char> x){
    string ret = "";
    if(x.size() < C){
        for(int i = 0; i < x.size(); i++)  ret += x[i];
        for(int i = 0; i < C-x.size(); i++) ret += "#";
    }else{
        for(int i = 0; i < C; i++) ret += x[i];
    }
    return ret;
}
void myprint(vector<char> &x){
    cout << (loca+1) << " ";
    while(loca < len && x[loca] != '#'){
        cout << x[loca];
        x[loca] = '#';
        loca++;
    }
}