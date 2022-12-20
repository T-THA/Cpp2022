#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main(void)
{
    string cmd;
    uint8_t data[2000];
    int stack[2000];
    for (int i = 0; i < 2000; i++){
        data[i] = 0;
        stack[i] = 0;
    }
    int p = 1000;
    int stack_p = 0;
    getline(cin, cmd);
    int i = 0;
    while(cmd[i] != '\0'){
        switch (cmd[i]){
            case '+': data[p] += 1; break;
            case '-': data[p] -= 1; break;
            case '>': p++; break;
            case '<': p--; break;
            case '.': cout << (char)data[p]; break;
            case ',':
                char c;
                if (cin.get(c)){
                    data[p] = (uint8_t)c;
                }
                else{
                    data[p] = 0;
                }
                break;
            case '[':
                if (data[p] != 0){
                    stack[++stack_p] = i;
                }else{
                    while(cmd[i] != ']') i++;
                }
                break;
            case ']':
                if (data[p] != 0){
                    i = stack[stack_p];
                }else{
                    stack_p--;
                }
                break;
        }
        i++;
    }
}