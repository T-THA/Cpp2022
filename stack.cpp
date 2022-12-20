#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> stack;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        if(tmp[1] == 'u'){
            string val;
            cin >> val;
            stack.push_back(val);
        }else if(tmp[1] == 'o'){
            stack.pop_back();
        }
    }
    if(stack.size() == 0) cout << -1;
    else{
        for(int i = stack.size() - 1; i >= 0; i--) cout << stack[i] << " ";
    }
    return 0;
}