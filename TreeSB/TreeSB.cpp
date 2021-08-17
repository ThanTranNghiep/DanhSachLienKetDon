#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int Data;
    Node*left;
    Node*right;
};
Node*CreateNode(int x){
    Node*a=new Node();
    if(a!=NULL){
        a->Data=x;
        a->left=a->right=NULL;
    }
    return a;
}
void ADDNode(Node*&tree,Node*x){
    if(tree==NULL){
        tree=new Node();
        tree=x;
        return;
    }
    if(tree->Data >x->Data){
        ADDNode(tree->left,x);
        return;
    }
    else{
        ADDNode(tree->right,x);
        return;
    }
}
void GetNode(Node*&tree,int n){
    for(int i=0;i<n;i++){
        int temp;
        cout<<"Nhap : ";
        cin>>temp;
        Node*a=CreateNode(temp);
        ADDNode(tree,a);    
    }
}
void InOrder(Node*tree){
    if(tree==NULL)
        return;
    InOrder(tree->left);
    cout<<tree->Data<<" ";
    InOrder(tree->right);
}
bool Seach(Node*tree,int x){
    if(tree==NULL)
        return false;
    if(tree->Data==x)
        return true;
    if(x < tree->Data)
        Seach(tree->left,x);
    else
        Seach(tree->right,x);
}
int main(){
    int n,x;
    Node*tree=NULL;
    cout<<"\nNhap n: ";
    cin>>n;
    GetNode(tree,n);
    InOrder(tree);
    if(Seach(tree,4)==true){
        cout<<"\nTim Thay !";
    }
    else{
        cout<<"\nKo tim thay!";
    }
    cout<<"\nKet qua tim kiem: "<<Seach(tree,3);
    return 0;
}