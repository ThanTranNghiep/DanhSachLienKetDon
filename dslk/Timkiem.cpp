#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int Data;
    Node*next;
};
struct List
{
    Node*head;
    Node*tail;
};
void CreateList(List &l){
    l.head=NULL;
    l.tail=NULL;
}
Node*CreateNode(int x){
    Node *a=new Node();
    if(a!=NULL){
        a->Data=x;
        a->next=NULL;
    }
    return a;
}
void addTail(List &l,Node*x){
    if(l.head==NULL){
        l.head=l.tail=x;
    }
    l.tail->next=x;
    l.tail=x;
}
bool Find(List l,Node*x){
    Node*i=l.head;
    while (i!=NULL)
    {
        if(i->Data==x->Data){
            return true;
        }
        i=i->next;
    }
    return false;
}
void GetNode(List &l,int n){
    for(int i=1;i<=n;i++){
        int temp;
        cout<<"Nhap phan tu thu "<<i<<": ";
        cin>>temp;
        Node*a=CreateNode(temp);
        addTail(l,a);
    }
}
void Display(List l){
    cout<<endl;
    Node*i=l.head;
    while (i!=NULL)
    {
        cout<<i->Data<<" ";
        i=i->next;
    }
}
int main(){
    int n,f;
    List l;
    CreateList(l);
    cout<<"Nhap n: ";
    cin>>n;
    GetNode(l,n);
    Display(l);
    cout<<"\nFind ?  ";
    cin>>f;
    Node*b=CreateNode(f);
    if(Find(l,b)==true){
        cout<<"\nTrue";
    }
    else{
        cout<<"\nFalse";
    }
}

