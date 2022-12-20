#include<iostream>
#include<cmath>
using namespace std;

struct Node{
    long long hashCode;
    int key;
    string val;
    Node* next;
};

struct Entry{
    long long size;
    Node* front;
};

int judge(Entry* map);
void add(Entry* map, int Key, string Val);
void del(Entry* map, int Key);
void search(Entry* map, int loca);
void enlarge(Entry* &map);
int L = 0, N = 0;
int main(){
    cin >> L >> N;
    Entry* map = (Entry*)malloc(L*sizeof(Entry));
    for(int i = 0; i < L; i++){
        map[i].front = nullptr;
        map[i].size = 0;
    }
    while(--N>=0){
        string s, tmpS;
        int tmpI = 0;
        cin >> s;
        switch(s[0]){
            case 'a':
                cin >> tmpI >> tmpS;
                add(map, tmpI, tmpS);
                while(judge(map)) enlarge(map);
                break;
            case 'd':
                cin >> tmpI;
                del(map, tmpI);
                break;
            case 's':
                cin >> tmpI;
                search(map, tmpI);
                break;
            default:
                break;
        }
    }
    return 0;
}

void enlarge(Entry* &map){
    L = L*2 + 1;
    Entry* oldmap = map;
    map = (Entry*)malloc(L*sizeof(Entry));
    for(int i = 0; i < L; i++){
        map[i].front = nullptr;
        map[i].size = 0;
    }
    for(int i = 0;i < (L-1)/2 ; i++){
        Node*p = oldmap[i].front;
        while(p != nullptr){
            add(map, p->key, p->val);
            p = p->next;
        }
    }
}
void add(Entry* map, int Key, string Val){
    Node*tmp = new Node;
    tmp->hashCode = (long long)abs(3*pow(Key, 3) + 5*pow(Key, 2) + 7*Key + 11);
    tmp->key = Key;
    tmp->val = Val;
    tmp->next = nullptr;
    int loca = tmp->hashCode % L;
    
    if(map[loca].front == nullptr){
        map[loca].front = tmp;
    }else{
        Node*help = map[loca].front;
        if(help->key >= Key){
            tmp->next = map[loca].front;
            map[loca].front = tmp;
        }else{
            while(help->next != nullptr && help->next->key < Key){
                help = help->next;
            }
            if(help->next == nullptr){
                help->next = tmp;
            }else{
                tmp->next = help->next;
                help->next = tmp;
            }
        }
    }
    map[loca].size++;
}

void del(Entry* map, int Key){
    int loca = ((long long)abs(3*pow(Key, 3) + 5*pow(Key, 2) + 7*Key + 11)) % L;
    Node *p = map[loca].front;
    if(p->next != nullptr){
        if(p->key == Key){
            map[loca].front = map[loca].front->next;
        }else{
            while(p->next->key != Key && p->next !=nullptr){
                p = p->next;
            }
            if(p -> next != nullptr)
                p->next = p->next->next;
        }
    }else{
        map[loca].front = nullptr;
    }
    map[loca].size--;
}

void search(Entry* map, int loca){
    Node *p = map[loca].front;
    if(p == nullptr){
        cout << "null" << endl;
    }else{
        cout << p->key << ":" << p->val;
        p = p->next;
        while(p != nullptr){
            cout << "->" << p->key << ":" << p->val;
            p = p->next;
        }
        cout << endl;
    }
}

int judge(Entry* map){
    int flag = 0, sizeAll = 0;
    for(int i = 0; i < L; i++){
        sizeAll += map[i].size;
        if(map[i].size > 4){
            flag = 1;
            break;
        }
    }
    if(sizeAll > L) flag = 1;
    return flag;
}