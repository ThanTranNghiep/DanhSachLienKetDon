#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char Data;
    Node*next;
};
struct Stack
{
    Node*head;
    Node*tail;
};
void CreateStack(Stack &t){
    t.head=NULL;
    t.tail=NULL;
}
Node*CreateNode(char x){
    Node *a=new Node();
    if(a!=NULL){
        a->Data=x;
        a->next=NULL;
    }
    return a;
}
void push(Stack &t,Node*x){
    if(t.head==NULL){
        t.head=t.tail=x;
        return;
    }
    x->next=t.head;
    t.head=x;
}
void pop(Stack&t){
    if(t.head==NULL){
        cout<<"\nStack is Empty\n";
        return;
    }
    if(t.head==t.tail){
        free(t.head);
        t.head=t.tail=NULL;
    }
    else{
       Node*i=t.head;
       t.head=t.head->next;
       free(i);
    }
}
bool GetNode(Stack&t,string n){
    int length=n.size();
    Node*top=CreateNode('#');
    push(t,top);
    for(int i=0;i<length;i++){
    
        if(n[i]=='('){
            Node*a=CreateNode('(');
            push(t,a);
        }
        else if(n[i]=='[' ){
            Node*a=CreateNode('[');
            push(t,a);
        }
        else if(n[i]=='{' ){
            Node*a=CreateNode('{');
            push(t,a);
        }
        else{
            if(t.head->Data=='#'){
                return false;
            }
            else{
                if( n[i]==')' && t.head->Data=='(' ) {
                    pop(t);
                }
                else if ( n[i]=='}' && t.head->Data=='{' )      
                {
                    pop(t);
                }
                else if ( n[i]==']' && t.head->Data=='[' )      
                {
                    pop(t);
                }
                else{
                    return false;
                }
            }
        }
    }
    if(t.head->Data!='#')
        return false;
    else
        return true;
}

void Display(Stack t){
    cout<<endl;
    Node*i=t.head;
    while (i!=NULL)
    {
        cout<<i->Data<<" ";
        i=i->next;
    }
}
int main(){
    string n;
    Stack t;
    CreateStack(t);
    cout<<"Nhap chuoi gom cac dau ngoac \" {},[],() \" : ";
    cin>>n;
    if(GetNode(t,n)==true){
        cout<<"\nTrue";
    }
    else{
        cout<<"\nFalse";
    }
}
