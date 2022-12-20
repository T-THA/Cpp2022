#include<iostream>

using namespace std;

int main(){
    int n = 0, m = 1, step = 1, stock = 1;
    cin >> n;
    while(1){
        if(m == n) break;
        for(int i = 0; i < step; i++){
            stock += 1;
            m += 1;
            if(m == n) break;
        }
        if(m == n) break;
        step += 1;
        stock -= 1;
        m += 1;
        if(m == n) break;

    }
    cout << stock;
}