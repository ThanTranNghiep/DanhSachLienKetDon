#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int Data;
    Node*next;
};
typedef Node* node;
node CreateNode(int x){
    node a=(node)malloc(sizeof(Node));
    if(a!=NULL){
        a->Data=x;
        a->next=NULL;
    }
    return a;
}
void addHead(node &head,node&tail,node x){
    if(head==NULL){
        tail=head=x;
    }
    x->next=head;
    head=x;
}
void addTail(node &head,node &tail,node x){
    if(head==NULL){
        head=tail=x;
    }
    tail->next=x;
    tail=x;
}
void getnode(node&head,node &tail,int n){
    for(int i=0;i<n;i++){
        int temp;
        cout<<"Nhap: ";
        cin>>temp;
        node a=CreateNode(temp);
        addTail(head,tail,a);
    }
}
void Display(node head){
    cout<<endl;
    node i=head;
    while (i!=NULL)
    {
        cout<<i->Data<<" ";
        i=i->next;
    }  
}
int main(){
    int n;
    node tail=NULL;
    node head=NULL;
    cout<<"Nhap n: ";
    cin>>n;
    getnode(head,tail,n);
    Display(head);
    return 0;
}
