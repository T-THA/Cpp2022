#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Time{
    int start;
    int end;
};
// template<typename T>
bool cmp(Time a, Time b){
    return a.start <= b.start;
}
int main(){
    vector<Time> val;
    sort(val.begin(), val.end(), cmp);
    return 0;
}