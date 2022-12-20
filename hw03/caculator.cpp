#include<iostream>
using namespace std;
int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int lcm(int x, int y);
int gcd(int x, int y);
int quo(int x, int y);
int res(int x, int y);
int main(){
    int (*p)(int x,int y);
    int n;
    cin >> n;
    while (--n >= 0)
    {
        int x = 0, y = 0;
        string s;
        cin >> x >> y >> s;
        switch (s[0]){
        case 'a':
            p = add;
            break;
        case 's':
            p = sub;
            break;
        case 'm':
            p = mul;
            break;
        case 'l':
            p = lcm;
            break;
        case 'g':
            p = gcd;
            break;
        case 'q':
            p = quo;
            break;
        case 'r':
            p = res;
            break;
        default:
            break;
        }
        cout << p(x,y) << endl;
    }
    
    return 0;
}
int add(int x, int y){
    return x + y;
}
int sub(int x, int y){
    return x - y;
}
int mul(int x, int y){
    return x * y;
}
int gcd(int x, int y){
    while(y^=x^=y^=x%=y);
    return x;
}
int lcm(int x, int y){
    return mul(x, y) / gcd(x, y);
}

int quo(int x, int y){
    return x / y;
}
int res(int x, int y){
    return x % y;
}