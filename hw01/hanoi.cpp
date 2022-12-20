#include <iostream>
using namespace std;

int main(){
    int n=0,ans=1;
    cin >> n;
    for(int i=0;i<n;i++){
        ans*=2;
    }
    ans-=1;
    cout << ans;
}