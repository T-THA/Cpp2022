#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(32);
    vec.push_back(322);
    vec.erase(vec.begin()+1);
    cout << vec[1] << vec.size();
    return 0;
}