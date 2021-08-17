#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Data;
    Node*next;
};
struct Stack{
    Node*head;
    Node*tail;
};
void CreateStack(Stack &t){
    t.head=NULL;
    t.tail=NULL;
}
Node *CreateNode(int x){
    Node *a=new Node();
    if(a!=NULL){
        a->Data=x;
        a->next=NULL;
    }
    return a;
}
void push(Stack&t,Node*x){
    if(t.head==NULL){
        t.head=t.tail=x;
        return;
    }
    x->next=t.head;
    t.head=x;
}
void pop(Stack&t){
    if(t.head==t.tail){
        free(t.head);
        t.head=t.tail=NULL;
    }
    Node*i=t.head;
    t.head=t.head->next;
    free(i);
}
int top(Stack t){
    return t.head->Data;
}
void display(Stack t){
    cout<<endl;
    Node*i=t.head;
    while (i!=NULL)
    {
        cout<<i->Data<<" ";
        i=i->next;
    }
    
}
int main(){
    int n;
    Stack t;
    CreateStack(t);
    Node*a=CreateNode(4);
    Node*b=CreateNode(3);
    Node*c=CreateNode(2);
    Node*d=CreateNode(1);
    push(t,a);
    push(t,b);
    push(t,c);
    push(t,d);
    //pop(t);
    display(t);
    cout<<"\n"<<top(t)<<endl;
    
}