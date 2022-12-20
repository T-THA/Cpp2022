#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    for(int i = 0;i < n; i++){
        vec.push_back(i);
    }
    int index = vec.size() - 1;
    while(vec.size() != 1){
        index = (index + m) % vec.size();
        vec.erase(vec.begin() + index);
        if(index != 0){
            index -= 1;
        }else{
            index = vec.size() - 1;
        }
    }
    cout << vec[0];
    return 0; 
}