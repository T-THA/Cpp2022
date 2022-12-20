#include<iostream>
#include<vector>
using namespace std;
struct squ{
    int val;
    pair<int, int> loca_1;
    pair<int, int> loca_2;
    pair<int, int> loca_3;
    int flag;
};
int main(){
    vector<squ> Bsqu;
    int x = 0, y = 0;
    cin >> x >> y;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            squ tmp;
            int tmpval;
            cin >> tmpval;
            tmp.val = tmpval;
            tmp.loca_1.first = j;
            tmp.loca_1.second = i;
            tmp.loca_2.first = j;
            tmp.loca_2.second = (10 - i) + 9;
            tmp.loca_3.first = (10 - j) + 9;
            tmp.loca_3.second = (10 - i) + 9;
            tmp.flag = 0;
            Bsqu.push_back(tmp);
        }
    }
    int sum = 0;
    for(int i = 0;i < Bsqu.size(); i++){
        if( (y*Bsqu[i].loca_1.first < x * (Bsqu[i].loca_1.second + 1))
        || (x*Bsqu[i].loca_1.second < y*(Bsqu[i].loca_1.first + 1))) Bsqu[i].flag = 1;
        if( (y*Bsqu[i].loca_2.first < x * (Bsqu[i].loca_2.second + 1))
        || (x*Bsqu[i].loca_2.second < y*(Bsqu[i].loca_2.first + 1))) Bsqu[i].flag = 1;
        if( (y*Bsqu[i].loca_3.first < x * (Bsqu[i].loca_3.second + 1))
        || (x*Bsqu[i].loca_3.second < y*(Bsqu[i].loca_3.first + 1))) Bsqu[i].flag = 1;
        if(Bsqu[i].flag == 1) sum += Bsqu[i].val;
    }
    cout << sum;
    return 0;
}