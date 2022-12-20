#include<iostream>
using namespace std;
int gcd(int x, int y){
    while(y^=x^=y^=x%=y);
    return x;
}