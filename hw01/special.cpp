#include<iostream>

using namespace std;

int main(){
    int n,ans=0;
    while(cin >> n){
        ans = ans^n;
    }
    cout << ans;
}