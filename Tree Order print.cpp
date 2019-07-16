#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*left;
	Node*right;

	public:
		Node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
};

Node* buildTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	Node*root = new Node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

//preorder print
void preOrder(Node*root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node*root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(Node*root){
	if(root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";

}


int main(int argc, char const *argv[])
{
	Node*root = buildTree();
	preOrder(root);
	cout<<endl;
	inOrder(root);
	cout<<endl;
	postOrder(root);
	cout<<endl;
	
	return 0;
}