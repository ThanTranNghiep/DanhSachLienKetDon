#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Data;
    Node*next;
};
struct Stack
{
    Node*head;
    Node*tail;
};
void CreateStack(Stack&t){
    t.head=NULL;
    t.tail=NULL;
}
Node*CreateNode(int x){
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
    }
    else{
        x->next=t.head;
        t.head=x;
    }
}
void pop(Stack&t){
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
void GetNode(Stack&t,int n){
    while (n!=0)
    {
        int d=n%16;
        Node*a=CreateNode(d);
        push(t,a);
        n/=16;
    }
    
}

void Display(Stack t){
    cout<<"\nKet qua tu he co so 10 -> 16 la: ";
    Node*i=t.head;
    while (i!=NULL)
    {
        
        switch (i->Data)
        {
        case 10:
            cout<<'A';
            break;
        case 11:
            cout<<'B';
            break;
        case 12:
            cout<<'C';
            break;
        case 13:
            cout<<'D';
            break;
        case 14:
            cout<<'E';
            break;
        case 15:
            cout<<'F';
            break;
        default:
            cout<<i->Data;
        }
        i=i->next;
    }
    
}
int main(){
    int n;
    Stack t;
    CreateStack(t);
    cout<<"Nhap he co so 10: ";
    cin>>n;
    GetNode(t,n);
    Display(t);
}