#include<iostream>
#include<cmath>

using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.size(), sum = 0;
    for(int i = 0; i < len ; i++){
        sum += (int)(s[i]- 48) * pow(2 , len-i-1);
    }
    cout << sum ;
}