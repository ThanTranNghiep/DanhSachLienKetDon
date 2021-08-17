#include<bits/stdc++.h>
using namespace std;
struct node
{
    int Data;
    node*left,*right;
};
node * CreateNode(int x){
    node*a= (node*)malloc(sizeof(node));
    if(a!=NULL){
        a->Data=x;
        a->left=a->right=NULL;
    }
    return a;
}
void AddTree(node*&tree,node*x){
    if(tree==NULL){
        tree=x;
        return;
    }
    if(tree->Data < x->Data){
        AddTree(tree->right,x);
        return;
    }
    else{
        AddTree(tree->left,x);
        return;
    }
}
void Addtree(node*&tree,node*x){
    if(tree==NULL){
        tree=x;
        return;
    }
    if(tree->left==NULL){
        Addtree(tree->left,x);
        return;
    }
    
}
