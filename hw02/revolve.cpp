#include<iostream>
#include<vector>
#define matrix vector<vector<int>>
using namespace std;
int main(){
    int n, angle;
    cin >> n >> angle;
    matrix My;
    for(int i = 0 ; i < n ;i++){
        vector<int> tmp;
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            tmp.push_back(val);
        }
        My.push_back(tmp);
    }
    switch ((angle % 360) / 90)
    {
    case 0:
        for(int i = 0; i < n; i++){
            for(int j = 0; j< n; j++){
                if(j != 0) cout << " ";
                cout << My[i][j];
            }
            cout << endl;
        }
        break;
    case 1:
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                if(j != n-1) cout << " ";
                cout << My[j][i];
            }
            cout << endl;
        }
        break;
    case 2:
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(j != n-1) cout << " ";
                cout << My[i][j];
            }
            cout << endl;
        }
        break;
    case 3:
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(j != 0) cout << " ";
                cout << My[j][i];
            }
            cout << endl;
        }
        break;
    default:
        break;
    }
}