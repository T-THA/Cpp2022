
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int len;
    cin >> len;
    vector<vector<char>> vec;
    for(int i = 0; i < len; i++){
        vector<char> ch;
        string tmp;
        cin >> tmp;
        for(int j = 0; j < tmp.length(); j++){
            ch.push_back(tmp[tmp.length()-j-1]);
        }
        vec.push_back(ch);
    }
    string output = "";
    for(int i = 0; i < vec[0].size(); i++){
        char tmp = vec[0][i];
        int flag = 1;
        for(int j = 1; j < vec.size(); j++){
            if(vec[j][i] != tmp){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            break;
        }else{
            output = tmp + output;
        }
    }
    cout << output;
}