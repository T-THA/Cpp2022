#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define strvec vector<string>
using namespace std;

class Square{
public:
    Square(string Type, string uid){
        type = Type;
        id = stoi(uid.substr(1));
    }
    int Getid(){
        return id;
    }
    int GetGray(){
        return R*299 + G*587 + B*114;
    }
    bool GetGroup(int id){
        for(int i = 0; i < group.size(); i++){
            if(group[i] == id) return true;
        }
        return false;
    }
    void SetGroup(int x){
        group.push_back(x);
    }
    void SetRGB(int r, int g, int b){
        if(type == "reverse"){
            R = 255 - r;
            G = 255 - g;
            B = 255 - b;
        }else if(type == "single"){
            R = r;
            G = 0;
            B = 0;
        }else{
            R = r;
            G = g;
            B = b;
        }
    }
    string toString(){
        return "P" + to_string(id) + " " + to_string(R) + " " + to_string(G) + " " + to_string(B);
    }
private:
    int id;
    vector<int> group;
    string type;
    int R{0};
    int G{0};
    int B{0};
};
class Plane{
public:
    void add(Square squ){
        table.push_back(squ);
    }
    void SortTable(string s);
    vector<Square> table;
};

bool idComp(Square i, Square j){
    return i.Getid() < j.Getid();
}
bool GrayComp(Square i, Square j){
    if(i.GetGray() == j.GetGray()){
        return idComp(i, j);
    }else return i.GetGray() < j.GetGray();
}
void Plane::SortTable(string s){
    if(s == "Normal"){
        sort(table.begin(), table.end(), idComp);
    }else if(s == "Gray"){
        sort(table.begin(), table.end(), GrayComp);
    }
}
strvec split(char c, string s);
int main(){
    int N;
    cin >> N;
    Plane my;
    getchar();
    while(--N >= 0){
        string s;
        getline(cin, s);
        strvec sv = split(' ', s);
        if(sv[0] == "Add"){
            Square tmp(sv[1], sv[2]);
            my.add(tmp);
        }else if(sv[0] == "Group"){
            int num = stoi(sv[1]);
            int gid = stoi(sv[num + 2].substr(1));
            for(int i = 2; i < num + 2; i++){
                int tmp = stoi(sv[i].substr(1));
                for(int j = 0; j < my.table.size(); j++){
                    if(my.table[j].Getid() == tmp){
                        my.table[j].SetGroup(gid);
                        break;
                    }
                }
            }
        }else if(sv[0] == "Set"){
            int id = stoi(sv[1].substr(1));
            int r = stoi(sv[2]), g = stoi(sv[3]), b = stoi(sv[4]);
            if(sv[1][0] == 'P'){
                for(int i = 0; i < my.table.size(); i++){
                    if(my.table[i].Getid() == id){
                        my.table[i].SetRGB(r, g, b);
                        break;
                    }
                }
            }else{
                for(int i = 0; i < my.table.size(); i++){
                    if(my.table[i].GetGroup(id)){
                        my.table[i].SetRGB(r, g, b);
                    }
                }
            }
        }else{
            cout << "Invalid Command!" << endl;
        }
    }
    string s;
    cin >> s;
    my.SortTable(s);
    for(int i = 0; i < my.table.size(); i++){
        cout << my.table[i].toString() << endl;
    }
    return 0;
}
strvec split(char c, string s){
    strvec ret;
    s = s + c;
    unsigned long long loca;
    while((loca = s.find(c)) != s.npos){
        ret.push_back(s.substr(0, loca));
        s = s.substr(loca + 1, s.size() - loca - 1);
    }
    return ret;
}