#include<iostream>
#include<limits>
#include<cmath>
using namespace std;
int main(){
    int n=0,i=0;
    int max = numeric_limits<int>::max();
    int min = numeric_limits<int>::min();
    long long rn=0;
    cin >> n;
    int n2=n;
    while(n2 != 0){
        n2 = n2 / 10;
        i+=1;
    }
    while(n != 0){
        i-=1;
        rn += (n % 10) * pow(10 , i);
        n = n / 10;
    }
    if(rn > max || rn < min){
        cout << -1;
    }else{
        cout << rn;
    }
}