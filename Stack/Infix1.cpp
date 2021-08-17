#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char Data;
    Node*next;
};
struct Stack1
{
    Node *head;
    Node*tail;
};
struct Stack
{
    Node *head;
    Node*tail;
};
void CreateStack1(Stack1 &t1){
    t1.head=NULL;
    t1.tail=NULL;
}

void CreateStack(Stack &t){
    t.head=NULL;
    t.tail=NULL;
}
Node*CreateNode(int x){
    Node*a=new Node();
    if(a!=NULL){
        a->Data=x;
        a->next=NULL;
    }
    return a;
}
void push(Stack &t,Node *x){
    if(t.head==NULL){
        t.head=t.tail=x;
    }
    else{
        x->next=t.head;
        t.head=x;
    }
}


int main(){
    string n;
    Stack t;
    CreateStack(t);
    cout<<"\n Nhap Bieu Thuc: ";
    cin>>n;
    
}
