#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int Data;
    Node*Left;
    Node*Right; 
};
Node* CreateNode(int x){
    Node *a=new Node();
    if(a!=NULL){
        a->Data=x;
        a->Left=a->Right=NULL;
    }
    return a;
}
void addNode(Node* &tree,Node*x){
    if(tree == NULL){
        tree = new Node();
        tree = x;   
        return;
    }
    if(tree->Data < x->Data){
        addNode(tree->Right,x);
        return;
    }
    else{
        addNode(tree->Left,x);
        return;
    }
}
void LMR(Node*tree){
    if(tree==NULL)
        return;
    LMR(tree->Left);
    cout<<tree->Data<<"  ";
    LMR(tree->Right);
}
void RML(Node*tree){
    if(tree==NULL){
        return;
    }
    RML(tree->Right);
    cout<<tree->Data<<" ";
    RML(tree->Left);
}
void GetTree(Node* &tree,int n){
    for(int i =1;i<=n;i++){
        int temp;
        cout<<"Nhap : ";
        cin>>temp;
        Node *a=CreateNode(temp);
        addNode(tree,a);
    }

}
int Tong(Node*tree){
    if(tree==NULL)
        return 0;
    return tree->Data + Tong(tree->Left) +Tong(tree->Right);
}
int TongNutLa(Node*tree){
    if(tree==NULL)
        return 0;
    if(tree->Left==NULL && tree->Right == NULL)
        return tree->Data ;    
    return TongNutLa(tree->Left) + TongNutLa(tree->Right);
}
int TongX_Y(Node*tree,int x,int y){
    if(tree==NULL)
        return 0;
    TongX_Y(tree->Left,x,y);
    if(tree->Data > x && tree->Data < y)
        return tree->Data + TongX_Y(tree->Left,x,y) + TongX_Y(tree->Right,x,y);
    return TongX_Y(tree->Right,x,y);
}

int main(){
    Node*tree =NULL;
    int n,x,y;
    cout<<"\nNhap n: ";
    cin>>n;
    GetTree(tree,n);
    LMR(tree);
    cout<<"\nTong: "<<Tong(tree);
    cout<<"\nTong Nut La: "<<TongNutLa(tree);
    cout<<"\nTong Nut Tu x -> y La: "<<TongX_Y(tree,5,10);

}
