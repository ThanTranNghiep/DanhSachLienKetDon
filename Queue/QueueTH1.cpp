#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Data;
    Node*next;
};
struct Queue{
    Node*head;
    Node*tail;
};
void CreateQueue(Queue &q){
    q.head=NULL;
    q.tail=NULL;
}
Node*CreateNode(int x){
    Node *n=new Node();
    if(n!=NULL){
        n->Data=x;
        n->next=NULL;
    }
    return n;
}
void push(Queue &q,Node*x){
    if(q.head==NULL){
        q.head=q.tail=x;
    }
    q.tail->next=x;
    q.tail=x;
}
void pop(Queue &q){
    if(q.head==q.tail){
        free(q.head);
        q.head=q.tail=NULL;
    }
    Node*x=q.head->next;
    free(q.head);
    q.head=x;
}
void display(Queue q){
    cout<<endl;
    Node*i=q.head;
    while (i!=NULL)
    {
        cout<<i->Data<<" ";
        i=i->next;
    }
}
int main(){
    Queue l;
    CreateQueue(l);
    int n=6;
    while(n>0){
        Node *a=CreateNode(n);
        push(l,a);
        n--;
    }
    display(l);
    pop(l);
    display(l);
    
}