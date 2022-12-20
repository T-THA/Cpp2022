#include<iostream>
#include<limits>

using namespace std;

int main(){
    int max = numeric_limits<int>::max();
    int n = 0;
    long long ans = 1;
    cin >> n;
    for(int i = 0; i< n ; i++){
        int tmp;
        cin >> tmp; 
        ans *= tmp;
        if(ans > max){
            cout << -1 ;
            break;
        }else{
            cout << ans << " ";
        }
    }
}