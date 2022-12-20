#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int>> matrix;
matrix conv(matrix a, matrix b);
matrix a_s_m(matrix a, matrix b, string s);
void print(matrix a);
int main(){
    int n, a, b;
    cin >> n;
    matrix ma[5];
    for(int i = 0; i < n; i++){
        int wid,len;
        cin >> wid >> len;
        for(int j = 0; j< wid; j++){
            vector<int> tmp;
            for(int k = 0; k< len; k++){
                int number;
                cin >> number;
                tmp.push_back(number);
            }
            ma[i].push_back(tmp);
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s >> a >> b;
        if(s=="conv" && ma[a].size() >= ma[b].size() && ma[a][0].size() >= ma[b][0].size()){
            print(conv(ma[a], ma[b]));
        }else if(ma[a].size() !=ma[b].size() || ma[a][0].size() != ma[b][0].size()){
            cout << "error" << endl;
        }else{
            print(a_s_m(ma[a], ma[b], s));
        }
    }
}
matrix a_s_m(matrix a, matrix b, string s){
    int width = a.size(),len = a[0].size();
    matrix c;
    for(int i = 0; i < width; i++){
        vector<int> tmp;
        for(int j = 0; j < len; j++){
            if(s=="add"){
                tmp.push_back(a[i][j] + b[i][j]);
            }else if(s=="sub"){
                tmp.push_back(a[i][j] - b[i][j]);
            }else{
                tmp.push_back(a[i][j] * b[i][j]);
            }
        }
        c.push_back(tmp);
    }
    return c;
}
matrix conv(matrix a, matrix b){
    int wid_a = a.size(), len_a = a[0].size(), wid_b = b.size(), len_b = b[0].size();
    int new_wid = wid_a - wid_b + 1, new_len = len_a - len_b + 1 ;
    matrix c;
    for(int i = 0 ; i < new_wid; i++){
        vector<int> tmp;
        for(int j = 0; j< new_len; j++){
            int sum = 0;
            for(int k = 0; k < wid_b; k++){
                for(int l = 0; l < len_b; l++){
                    sum += a[i+k][j+l] * b[k][l];
                }
            }
            tmp.push_back(sum);
        }
        c.push_back(tmp);
    }
    return c;
}
void print(matrix a){
    for(int i = 0;i< a.size(); i++){
        for(int j = 0; j< a[0].size(); j++){
            if( j != 0) cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
}
