#include <iostream>
#include <string>
#include <map>
#define CHECK false

using namespace std;

int getval(string line, map<string, int> mp)
{
    int val;
    if (mp.count(line))
    {
        val = mp[line];
    }
    else
    {
        int len = line.length() - 1;
        for (int i = 0; i < len; i++)
        {
            if (!(line[i] >= '0' && line[i] <= '9'))
            {
                cout << "error";
                if(CHECK) cout << " type: undefined var " << line;
                exit(0);
            }
        }
        val = atoi(line.c_str());
    }
    return val;
}

int operate(int op1, int op2, char opr)
{
    switch(opr)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/':
            if (op2 == 0)
            {
                cout << "error";
                if(CHECK) cout << " type: /0";
                exit(0);
            }
            else return op1 / op2;
        default : 
            cout << "error";
            if(CHECK) cout << " type: unknown opr";
            exit(0);
    }
}

int main(void)
{
    int n = 0;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        string name = "";
        if(line != "print")
        {
            char eq; cin >> eq;//擦除等式右值前的"="
            name = line;
            getline(cin, line);
            line.erase(0, 1);
            if (line.find("+") == std::string::npos && line.find("-") == std::string::npos &&
                line.find("*") == std::string::npos && line.find("/") == std::string::npos)
            {
                mp[name] = getval(line, mp);
            }
            else//处理算术运算和赋值
            {
                int opr_pos = ((line.find('+') + 1)|(line.find('-') + 1)|(line.find('*') + 1)
                              |(line.find('/') + 1)) - 1;
                char opr = line[opr_pos];
                string op1 = line.substr(0, opr_pos - 1);
                string op2 = line.substr(opr_pos + 2, line.length() - opr_pos - 1);
                //cout << op1 << ' ' << op2 << endl;
                int op_num1 = getval(op1, mp);
                int op_num2 = getval(op2, mp);
                //cout << op_num1 << ' ' << op_num2 << endl;
                int val = operate(op_num1, op_num2, opr);
                mp[name] = val;
            }
            //cout << mp[name] << endl;
        }
        else
        {
            cin >> name;
            if (mp.count(name))
            {
                cout << mp[name] << endl;
            }
            else
            {
                cout << "error";
                if(CHECK) cout << " type: print undefined var " << name;
                exit(0);
            }
        }
    }
}