#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Time{
    int start;
    int end;
};
bool cmp(Time a, Time b){
    return a.end <= b.end;
}
int main(){
    vector<Time> val;
    int n;
    cin >> n;
    for(int i = 0;i < n; i++){
        Time tmp;
        int h, min, h2, min2;
        scanf("%d:%d-%d:%d",&h, &min, &h2, &min2);
        tmp.start = h*60 + min;
        tmp.end = h2*60 + min2;
        val.push_back(tmp);
    }
    sort(val.begin(), val.end(), cmp);
    int num = 0, record = 0;
    for(int i = 0; i < n;i++){
        if(val[i].start >= record){
            num++;
            record = val[i].end;
        }
    }
    cout << n - num;
    return 0;
}