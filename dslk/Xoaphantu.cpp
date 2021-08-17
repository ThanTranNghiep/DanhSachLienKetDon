#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Data;
    Node *next;
};
struct List{
    Node *head;
    Node*tail;
};
void CreateList(List &l){
    l.head=NULL;
    l.tail=NULL;
}
Node *CreateNode(int x){
    Node *a=new Node();
    if(a!=NULL){
        a->Data=x;
        a->next=NULL;
    }
    return a;
}
void addHead(List &l,Node *x){
    if(l.head==NULL){
        l.head=l.tail=x;
    }
    x->next=l.head;
    l.head=x;
}
void addTail(List &l,Node*x){
    if(l.head==NULL){
        l.head=l.tail=x;
    }
    l.tail->next=x;
    l.tail=x;
}
// xoa dau
void subHead(List &l){
    if(l.head ==l.tail){
        delete(l.head);
        l.head=l.tail=NULL;
    }
    Node*x;
    x=l.head->next;
    delete(l.head);
    l.head=x;
}
void subTail(List &l){
    if(l.head==l.tail){
        free(l.head);
        l.head=l.tail=NULL;
    }
    else{
        Node*j=l.head;
        while (j->next->next  !=NULL)
        {
            j=j->next;
        }
        
        free(j->next);
        j->next=NULL;
        l.tail=j;
    }
}
void SubNode(List &l,int pos){
    Node*i=l.head;
    for(int j=1;j<pos-1;j++){
        i=i->next;
        if(i==NULL){
            cout<<"\nNgoai pham vi \n";
            return;
        }
    }
    if(i==l.head)
    {
        Node*a=l.head->next;
        free(l.head);
        l.head=a;
    }
    if(i==l.tail)
    {
        subTail(l);
    }
    Node*a=i->next;
    i->next=i->next->next;
    free(a);
}
void GetNode(List &l,int n){
    for(int i=1;i<=n;i++){
        int temp;
        cout<<"Nhap phan tu: ";
        cin>>temp;
        Node *x=CreateNode(temp);
        addTail(l,x);
    }
}
void Display(List l){
    Node *i=l.head;
    while(i!=NULL){
        cout<<i->Data<<" ";
        i=i->next;
    }
}
int main(){
    List l;
    int n,pos;
    cout<<"\nNhap so phan tu: ";
    cin>>n;
    CreateList(l);
    GetNode(l,n);
    Display(l);
    subHead(l);
    cout<<endl;
    Display(l);
    cout<<endl;
    subTail(l);
    Display(l);
    cout<<endl;
    cout<<"\nNhap pos: ";
    cin>>pos;
    SubNode(l,pos);
    Display(l);
    return 0;
}