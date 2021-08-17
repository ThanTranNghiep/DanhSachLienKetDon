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
void initList(List &l){
    l.head=NULL;
    l.tail=NULL;
}
// khoi tao node
Node *createNode(int a){
    Node *n=new Node();
    if(n != NULL)
    {
        n->Data=a;
        n->next=NULL;
    }
    return n;
}
// them node vao dau list
void addHead(List &l,Node *a){
    if(l.head==NULL)
    {
        l.head =a;
        l.tail=a;
    }
    a->next=l.head;
    l.head=a;
}
// them phan tu vao cuoi list
void addTail(List &l,Node *a){
    if(l.head==NULL)
    {
        l.head=a;
        l.tail=a;
    }
    l.tail->next=a;
    l.tail=a;
}
int main(){
    List l;
    int n;
    initList(l);
    cout<<"Nhap n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cout<<"\nPhan tu thu "<<i<<": ";
        cin>>temp;
        Node*a=createNode(temp);
        addTail(l,a);
    }
    for(Node *i=l.head;i!=NULL;i=i->next){
        cout<<i->Data<<" ";
    }
    return 0;
}