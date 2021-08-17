#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int Data;
    Node*next;
};
struct Stack
{
    Node*head;
    Node*tail;
};
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
void push(Stack &t,Node*x){
    if(t.head==NULL){
        t.head=t.tail=x;
    }
    else{
        x->next=t.head;
        t.head=x;
    }
}
void pop(Stack&t){
    if(t.head=t.tail){
        free(t.head);
        t.head=t.tail=NULL;
    }
    Node*i=t.head;
    t.head=t.head->next;
    free(i);
}
void GetNode(Stack &t,int n){
    for(int i=1;i<=n;i++){
        int temp;
        cout<<"Nhap: ";
        cin>>temp;
        Node*a=CreateNode(temp);
        push(t,a);
    }
}
void Display(Stack t){
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
    cout<<"Nhap n: ";
    cin>>n;
    GetNode(t,n);
    Display(t);
}