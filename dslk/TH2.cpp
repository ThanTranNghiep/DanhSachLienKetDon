#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Data;
    Node*next;
};
struct List{
    Node*tail;
    Node*head;
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
void AddHead(List &l,Node*x){
    if(l.head==NULL){
        l.head=l.tail=x;
    }
    x->next=l.head;
    l.head=x;
}
void AddTail(List &l,Node*x){
    if(l.head==NULL){
        l.head=l.tail=x;
    }
    l.tail->next=x;
    l.tail=x;
}
void SubHead(List&l){
    if(l.head==l.tail){
        l.head=l.tail=NULL;
    }
    Node*x=l.head->next;
    free(l.head);
    l.head=x;
}
void SubTail(List&l){
    if(l.head==l.tail){
        l.head=l.tail=NULL;
    }
    Node*i=l.head;
    while (i->next->next!=NULL)
    {
        i=i->next;
    }
    free(i->next);
    i->next=NULL;
    l.tail=i;
}
void SubNode(List &l,int pos){
    Node*j=l.head;
    for(int i=1;i<pos;i++){
        j=j->next;
        if(j==NULL){
            cout<<"\nError !\n";
            return;
        }
    }
    if(j==l.head){
        Node*a=l.head->next;
        free(l.head);
        l.head=a;
        
    }
    if(j==l.tail){
        Node*b=l.head;
        while (b->next->next!=NULL)
        {
            b=b->next;
        }
        free(b->next);
        b->next=NULL;
        l.tail=b;
    }
    Node *c=j->next;
    j->next=j->next->next;
    free(c);
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
void GetNode(List&l,int n){
    cout<<endl;
    for(int i=1;i<=n;i++){
        int temp;
        cout<<"Nhap phan tu: ";
        cin>>temp;
        Node*a=CreateNode(temp);
        AddTail(l,a);
    }

}
void Display(List l){
    Node*i;
    cout<<endl;
    for(i=l.head;i!=NULL;i=i->next){
        cout<<i->Data<<" ";
    }
}
int main(){
    List l;
    int n,pos,v;
    CreateList(l);
    cout<<"Nhap so luong phan tu: ";
    cin>>n;
    GetNode(l,n);
    Display(l);
    // Them node a vao dau danh sach
    Node*a=CreateNode(9);
    // Them Node vao vi tri bat ki
    Node*b=CreateNode(111);
    AddNode(l,a,n,0);
    Display(l);

    return 0;
}