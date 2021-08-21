#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Data;
    Node *next;
};
struct List{
    Node*head;
    Node*tail;
};
void initList(List &l){
    l.head=NULL;
    l.tail=NULL;
}
Node* createNode(int x){
    Node *n = new Node();
    if(n!=NULL){
        n->Data=x;
        n->next=NULL;
    }
    return n;
}
void addHead(List &l,Node *x){
    if(l.head==NULL)
    {
        l.head=x;
        l.tail=x;
    }
    x->next=l.head;
    l.head=x;
}
void addtail(List &l,Node *x){
    if(l.head==NULL)
    {
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
int main(){
    List l;
    int n;
    initList(l);
    cout<<"\nNhap n: ";
    cin>>n;
    for(int i=1;i<n;i++){
        int temp;
        cout<<"Phan tu thu "<<i<<": ";
        cin>>temp;
        Node *a=createNode(temp);
        addtail(l,a);
    }
    for(Node *i=l.head;i!=NULL;i=i->next){
        // cout<<i->Data<<" ";
        printf("%4d",i->Data);
    }
    printf("\n");
    Node *b= createNode(12);
    addNode(l,b,2);
    for(Node *i=l.head;i!=NULL;i=i->next){
        cout<<i->Data<<" ";
    }
}