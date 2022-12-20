#include<iostream>
#include<vector>
#define matrix vector<vector<int>>

using namespace std;
int printMatrix(matrix My, matrix Flag, int dir, int idx_x, int idx_y);
int main(){
    int n, m;
    cin >> n >> m;
    matrix My;
    matrix Flag;
    for(int i = 0; i < n ; i++){
        vector<int> tmp;
        for(int j = 0;j < m; j++){
            tmp.push_back(1);
        }
        Flag.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        vector<int> tmp;
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            tmp.push_back(val);
        }
        My.push_back(tmp);
    }
    cout << My[0][0] << " ";
    Flag[0][0]=0;
    printMatrix(My, Flag, 0, 0, 1);
    return 0;
}
int printMatrix(matrix My, matrix Flag, int dir, int idx_x, int idx_y){
    int flag=0;
    for(int i = 0;i<My.size();i++){
        for(int j = 0;j<My[0].size();j++){
            flag += Flag[i][j];
        }
    }
    if(flag == 0){
        return 1;
    }else if(dir == 0){
        while(idx_y < My[0].size() && Flag[idx_x][idx_y]!=0){
            Flag[idx_x][idx_y] =0;
            cout << My[idx_x][idx_y] << " ";
            idx_y++;
        }
        printMatrix(My, Flag, 1, idx_x+1, idx_y-1);
    }else if(dir == 1){
        while(idx_x < My.size() && Flag[idx_x][idx_y]!=0){
            Flag[idx_x][idx_y] =0;
            cout << My[idx_x][idx_y] << " ";
            idx_x++;
        }
        printMatrix(My, Flag, 2, idx_x-1, idx_y-1);
    }else if(dir == 2){
        while(idx_y >=0 && Flag[idx_x][idx_y]!=0){
            Flag[idx_x][idx_y] =0;
            cout << My[idx_x][idx_y] << " ";
            idx_y--;
        }
        printMatrix(My, Flag, 3, idx_x-1, idx_y+1);
    }else if(dir == 3){
        while(idx_x >=0 && Flag[idx_x][idx_y]!=0){
            Flag[idx_x][idx_y] =0;
            cout << My[idx_x][idx_y] << " ";
            idx_x--;
        }
        printMatrix(My, Flag, 0, idx_x+1, idx_y+1);
    }else{
        return -1;
    }
}