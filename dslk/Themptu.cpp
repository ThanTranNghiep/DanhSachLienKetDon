#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Data;
    Node*next;
};
struct List{
    Node*head;
    Node*tail;
};
Node*CreateNode(int x){
    Node *n=new Node();
    if(n!=NULL){
        n->Data=x;
        n->next=NULL;
    }
    return n;
}
void initList(List &l){
    l.head=NULL;
    l.tail=NULL;
}
void addHead(List &l,Node* x){
    if(l.head==NULL){
        l.head=x;
        l.tail=x;
    }
    x->next= l.head;
    l.head=x;
}
void addTail(List &l,Node *x){
    if(l.head==NULL){
        l.head=x;
        l.tail=x;
    }
    l.tail->next=x;
    l.tail=x;
}
void addNode(List &l,Node *x,int pos){
    Node *i=l.head;
    for(int j=1;j<pos;j++){
        i=i->next;
    }
    x->next=i->next;
    i->next=x;
}
void AddNode(List &l,Node*x,int n,int pos){
    if(l.head==NULL){
        l.head=l.tail=x;
    }
    if(pos ==2){
        x->next=l.head->next;
        l.head->next=x;
        return;
    }
    if(pos <=0 || pos > n){
        cout<<"\nError !\n";
    }
    Node *j=l.head;
    for(int i=1;i<pos-1;i++){
        j=j->next;
    }
    if(j==l.head){
        x->next=l.head;
        l.head=x;
        return;
    }
    x->next=j->next;
    j->next=x;
}
void Display(List l){
   Node *i=l.head;
    for(i;i!=NULL;i=i->next){
        cout<<i->Data<<" ";
    } 
}
int main(){
    List l;
    int n;
    cout<<"\nNhap so luong phan tu: ";
    cin>>n;
    initList(l);
    for(int i=0;i<n;i++){
        int temp;
        cout<<"\nPhan tu: ";
        cin>>temp;
        Node *a=CreateNode(temp);
        addTail(l,a);
    }
    Display(l);
    
}