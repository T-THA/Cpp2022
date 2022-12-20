#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, len;
    vector<int> val;
    cin >> n;
    for(int i = 0; i < n ; i++){
        int tmp;
        cin >> tmp;
        val.push_back(tmp);
    }
    for(int i = 0; i < n-1; i++){
        int tmp = 1;
        for(int j = i;j < n-1; j++){
            if(val[j] > val[j+1]){
                tmp++;
            }else{
                break;
            }
        }
        if(tmp >len) len = tmp;
    }
    cout << len;
    return 0;
}