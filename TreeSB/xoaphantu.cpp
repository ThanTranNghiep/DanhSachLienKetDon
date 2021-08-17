#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int Data;
    Node*left,*right;
};
Node*CreateNode(int x){
    //Node*a=new Node();
    Node*a= (Node *) malloc(sizeof(Node));
    if(a!=NULL){
        a->Data=x;
        a->left=NULL;
        a->right=NULL;
    }
    return a;
}

void ADDNode(Node*&tree,Node*x){
    if(tree==NULL)
    {
        tree=new Node();
        tree=x;
        return;
    }
    if(tree->Data < x->Data){
        ADDNode(tree->right,x);
        return;
    }
    else
    { 
        ADDNode(tree->left,x);
        return;
    }
}
/*
void ADDNode(Node*&tree,Node*x){
    if(tree==NULL)
    {
        tree=new Node();
        tree=x;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        if(tree->Data < x->Data)
            return ADDNode(tree->right,x);
        else
            return ADDNode(tree->left,x);
        
    }
}
*/
void GetNode(Node*&tree,int n){
    for(int i=0;i<n;i++){
        cout<<"Nhap: ";
        int temp;
        cin>>temp;
        Node*a=CreateNode(temp);
        ADDNode(tree,a);
    }
}
void Display_InOrder(Node*tree){
    if(tree==NULL)
        return;
    Display_InOrder(tree->left);
    cout<<tree->Data<<" ";
    Display_InOrder(tree->right);
}
// xoa la
void XoaPhanTu(Node*&tree,Node*x){
    
}
int main(){
    int n;
    Node*tree=NULL;
    cout<<"\nNhap n: ";
    cin>>n;
    GetNode(tree,n);
    Display_InOrder(tree);
    Node *c = CreateNode(4);
    XoaPhanTu(tree,c);
    cout<<endl;
    Display_InOrder(tree);
}
