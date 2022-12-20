#include<iostream>
#include<cstdio>
using namespace std;
int vec[114514];
int ret[101];
int main(){
    int n = 0, Size = 0, Capacity = 0, ret_index = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "getSize"){
            ret[ret_index] = Size;
            ret_index++;
        }else if(s == "getCapacity"){
            ret[ret_index] = Capacity;
            ret_index++;
        }else{
            int tmp = 0;
            scanf("%d", &tmp);
            if(s == "add"){
                if(Size == 0){
                    Capacity = 10;
                }
                if(Size == Capacity){
                    Capacity += Capacity / 2;
                }
                vec[Size] = tmp;
                Size++;
            }else if(s == "remove"){
                for(int i = 0; i < Size; i++){
                    if(vec[i]==tmp){
                        for(int j = i; j < Size; j++){
                            if(j != Size - 1){
                                vec[j] = vec[j+1];
                            }else{
                                vec[j] = 0;
                            }
                        }
                        Size -= 1;
                        break;
                    }
                }
            }else if(s == "get"){
                if(tmp < 0 || tmp > Size - 1){
                    ret[ret_index] = -1;
                    ret_index++;
                }else{
                    ret[ret_index] = vec[tmp];
                    ret_index++;
                }
            }
        }
    }
    for(int i = 0; i < ret_index; i++){
        cout << ret[i] << endl;
    }
    return 0;
}