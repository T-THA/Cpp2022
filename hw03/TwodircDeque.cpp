#include<iostream>
using namespace std;
struct Node{
    Node* next;
    Node* prev;
    int val;
};
struct Deque{
    int size;
    Node* front;
    Node* rear;
};
void push_front(Deque* self, int value);
void push_back(Deque* self, int value);
void pop_front(Deque* self);
void pop_back(Deque* self);
void getSize(Deque* self);
int main(){
    int n = 0;
    cin >> n;
    
    Deque* self = new Deque;
    self->size = 0;
    self->front = NULL;
    self->rear = NULL;
    
    while (--n >= 0){
        string s;
        int tmp = 0;
        cin >> s;
        switch(s[4]){
            case 'F':
                cin >> tmp;
                push_front(self, tmp);
                break;
            case 'B':
                cin >> tmp;
                push_back(self, tmp);
                break;
            case 'a':
                pop_back(self);
                break;
            case 'r':
                pop_front(self);
                break;
            case 'i':
                getSize(self);
                break;
            default:
                break;
        }
    }
    return 0;
}
void push_front(Deque* self, int value){
    Node*newNode = new Node;
    newNode->val = value;
    newNode->next = self->front;
    newNode->prev = NULL;
    self->front = newNode;
    if(self->rear == NULL)
        self->rear = newNode;
    self->size++;
}
void push_back(Deque* self, int value){
    Node*newNode = new Node;
    newNode->val = value;
    newNode->prev = self->rear;
    newNode->next = NULL;
    self->rear = newNode;
    if(self->front == NULL)
        self->front = newNode;
    self->size++;
}
void pop_front(Deque* self){
    if(self->front != NULL){
        cout << self->front->val << endl;
        if(self->front->next != NULL){ 
            self->front = self->front->next;
        }else{
            self->front = NULL;
        }
        if(self->front != NULL)
            self->front->prev = NULL;
        if(self->size == 1)
            self->rear = NULL;
        self->size--;
    }else{
        cout << -1 << endl;
    }
    
}
void pop_back(Deque* self){
    if(self->rear != NULL){
        cout << self->rear->val << endl;
        self->rear = self->rear->prev;
        if(self->rear != NULL)
            self->rear->next = NULL;
        if(self->size == 1)
            self->front = NULL;
        self->size--;
    }else{
        cout << -1 << endl;
    }
}
void getSize(Deque* self){
    cout << self->size << endl;
}