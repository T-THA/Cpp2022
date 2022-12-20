#include<iostream>
using namespace std;
class A{
public:
 int x = 0;
//  A(int x){
//     x = x;
//  };
 A(int x) :x(x){};
};
int main(){
    A a = 1;
    cout << a.x;
}