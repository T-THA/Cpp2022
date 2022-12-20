#include<iostream>
#include<vector>
#include<cstdio>
#define BigNum vector<int>
using namespace std;
BigNum BigAdd(BigNum a, BigNum b);
int main(){
    int n;
    cin >> n;
    BigNum a = {1},b = {1};
    for(int i = 0; i< n; i++){
        BigNum tmp = a;
        a = b;
        b = BigAdd(tmp, b);
    }
    for(int i = a.size() - 1; i >=0; i--){
        if(i == a.size() - 1){
            cout << a[i];
        }else{
            printf("%.9d",a[i]);
        }
    }
    return 0;
}
BigNum BigAdd(BigNum a, BigNum b){
    BigNum result;
    int SLen = (a.size() > b.size())? b.size() : a.size();
    int BLen = (a.size() > b.size())? a.size() : b.size();
    int bonus = 0;
    for(int i = 0; i < BLen; i++){
        int tmp;
        if(i < SLen){
            tmp = a[i] + b[i] + bonus;
        }else{
            tmp = ( (a.size() > b.size())? a[i] : b[i] ) + bonus;
        }
        if(tmp >= 1000000000){
            bonus = 1;
            tmp -= 1000000000;
        }else{
            bonus = 0;
        }
        result.push_back(tmp);
    }
    if(bonus == 1) result.push_back(1);
    return result;
}