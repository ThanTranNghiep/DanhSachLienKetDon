#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node* createNode(int a)
{
	Node *n = new Node();
	n->data = a;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void addNode(Node* &tree, Node *a)
{
	if(tree == NULL)
	{
		tree = new Node();
		tree = a;
		return;
	}
	if(tree->data > a->data)
	{
		addNode(tree->left,a);
		return;
	}
	addNode(tree->right,a);
	return;
}

void LMR(Node* tree)
{
	if(tree == NULL)
		return;
	LMR(tree->left);
	cout << tree->data << "\t";
	LMR(tree->right);
}

void RML(Node* tree)
{
	if(tree == NULL)
		return;
	RML(tree->right);
	cout << tree->data << "\t";
	RML(tree->left);
}

bool search(Node* tree, int value)
{
	if(tree == NULL)
		return false;
	if(tree->data == value)
		return true;
	if(tree->data > value)
		return search(tree->left,value);
	if(tree->data < value)
		return search(tree->right,value);
}

int countLeaves(Node* tree)     // Đếm lá
{
	if(tree == NULL)
		return 0;
	if(tree->left == NULL && tree->right == NULL)
		return 1;
	return countLeaves(tree->left) + countLeaves(tree->right);
}

int height(Node* tree)
{
	if(tree == NULL)
		return 0;
	return max(1+height(tree->left),1+height(tree->right));
}
void GetTree(Node* &tree,int n){
    for(int i =1;i<=n;i++){
        int temp;
        cout<<"Nhap : ";
        cin>>temp;
        Node *a=createNode(temp);
        addNode(tree,a);
    }

}
int main()
{
	Node* tree = NULL;
    int n;
	cout<<"Nhap n: ";
    cin>>n;
    GetTree(tree,n);
    LMR(tree);
    cout<< countLeaves(tree);
}

//btvn
//tinh tong cay
//ting tong nut la
//dem so luong nut >x <y (x, y do nguoi dung nhap)