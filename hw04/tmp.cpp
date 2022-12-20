#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class A{
    public:
    A(int x){
        id = x;
    }
    int Getid(){
        return id;
    }
    private:
    int id;
};
bool cmp(A i , A j){
    return i.Getid() < j.Getid();
}
int main(){
    vector<A> a;
    A one(1), two(2), three(3), four(4);
    a.push_back(two);
    a.push_back(three);
    a.push_back(four);
    a.push_back(one);
    for(int i = 0; i < a.size();i++){
        cout << a[i].Getid() << " ";
    }
    cout << endl;
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < a.size();i++){
        cout << a[i].Getid() << " ";
    }
    return 0;
}