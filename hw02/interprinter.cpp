#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<ctype.h>
#define strvec vector<string>
using namespace std;
struct MyVal{
    string Name;
    int Value;
};
strvec split(char c, string s);
int find(vector<MyVal> x, string name);
int main(){
    int count = 0;
    cin >> count;
    vector<MyVal> MyMap;
    vector<strvec> ctrlctrl;
    MyVal zero;
    zero.Name = "error";
    zero.Value = 0;
    MyMap.push_back(zero);
    string tmp;
    getline(cin, tmp);
    for(int i = 0; i < count; i++){
        getline(cin, tmp);
        strvec ctrl = split(' ', tmp);
        ctrlctrl.push_back(ctrl);
    }
    for(int i = 0; i < count; i++){
        strvec ctrl = ctrlctrl[i];
        if(ctrl[0] == "print"){
            int tmpint = find(MyMap, ctrl[1]);
            if(tmpint == 0){
                cout << MyMap[tmpint].Name;
                return 0;
            }else{
                cout << MyMap[tmpint].Value << endl;
            }
        }else if(ctrl.size() == 3){
            const char *p = ctrl[2].data();
            if(isdigit(p[0])){
                int loca = find(MyMap, ctrl[0]);
                if(loca != 0){
                    MyMap[loca].Value = stoi(ctrl[2]);
                }else{
                    MyVal tmpval;
                    tmpval.Name = ctrl[0];
                    tmpval.Value = stoi(ctrl[2]);
                    MyMap.push_back(tmpval);
                }
            }else{
                int loca1 = find(MyMap, ctrl[0]), loca2 = find(MyMap, ctrl[2]);
                if(loca2 !=0){
                    if(loca1 !=0){
                        MyMap[loca1].Value = MyMap[loca2].Value;
                    }else{
                        MyVal tmpval;
                        tmpval.Name = ctrl[0];
                        tmpval.Value = MyMap[loca2].Value;
                        MyMap.push_back(tmpval);
                    }
                }else{
                    cout << MyMap[loca2].Name;
                    return 0;
                }
            }
        }else{
            const char *p1 = ctrl[2].data(), *p2 = ctrl[4].data();
            int val1 = 0, val2 = 0;
            if(isdigit(p1[0])){
                val1 = stoi(ctrl[2]);
            }else{
                if(find(MyMap, ctrl[2]) == 0){
                    cout << MyMap[0].Name;
                    return 0;
                }else{
                    val1 = MyMap[find(MyMap, ctrl[2])].Value;
                }
            }
            if(isdigit(p2[0])){
                val2 = stoi(ctrl[4]);
            }else{
                if(find(MyMap, ctrl[4]) == 0){
                    cout << MyMap[0].Name;
                    return 0;
                }else{
                    val2 = MyMap[find(MyMap, ctrl[4])].Value;
                }
            }
            int sum = 0;
            if(ctrl[3] == "+"){
                sum = val1 + val2;
            }else if(ctrl[3] == "-"){
                sum = val1 - val2;
            }else if(ctrl[3] == "*"){
                sum = val1 * val2;
            }else{
                if(val2 == 0){
                    cout << MyMap[0].Name;
                    return 0;
                }else{
                    sum = val1 / val2;
                }
            }
            int loca = find(MyMap, ctrl[0]);
            if(loca == 0){
                MyVal tmpval;
                tmpval.Name = ctrl[0];
                tmpval.Value = sum;
                MyMap.push_back(tmpval);
            }else{
                MyMap[loca].Value = sum;
            }
        }
    }
    
    return 0;
}
int find(vector<MyVal> x, string name){
    for(int i = 0; i< x.size(); i++){
        if(name == x[i].Name){
            return i;
        }
    }
    return 0;
}
strvec split(char c, string s){
    strvec ret;
    s = s + c;
    unsigned long long loca;
    while((loca = s.find(c)) != s.npos){
        ret.push_back(s.substr(0, loca));
        s = s.substr(loca+1, s.size() - (loca+1));
    }
    return ret;
}