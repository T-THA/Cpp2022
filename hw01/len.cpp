#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main(){
    int n;
    stringstream ss;
    string tmp;
    vector<int> vec;
    while (cin >> tmp)
    { 
        vec.push_back(tmp.size());
    }
    ss << tmp;
    ss >> n;
    vec.pop_back();
    cout << vec[ vec.size() -n];
}