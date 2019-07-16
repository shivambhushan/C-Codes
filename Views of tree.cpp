#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node*left;
	Node*right;

	Node(int d){
		data = d;
		left = right = NULL;
	}
};

Node* insertInBST(Node*root, int d){
	if(root == NULL){
		Node*n = new Node(d);
		return n;
	}

	if(d < root->data){
		root->left = insertInBST(root->left, d);
	}
	else{
		root->right = insertInBST(root->right, d);
	}
	return root;
}

Node* takeInput(){
	int d;
	cin>>d;
	Node*root = NULL;
	while(d != -1){
		root = insertInBST(root, d);
		cin>>d;
	}
	return root;
}

void leftView(Node* root,int level, int *max_level){
	if(root == NULL){
		return;
	}
	if(*max_level < level){
		cout<<root->data<<" ";
		*max_level = level;
	}
	leftView(root->left, level+1, max_level);
	leftView(root->right, level+1, max_level);
}

void rigthView(Node*root, int level, int *max_level){
	if(root == NULL){
		return;
	}
	if(*max_level < level){
		cout<<root->data<<" ";
		*max_level = level;
	}
	rigthView(root->right, level+1, max_level);
	rigthView(root->left, level+1, max_level);
}


int main(int argc, char const *argv[])
{
	Node*root = takeInput();
	int max_level = 0;
	int level = 1;
	//leftView(root, level, &max_level);
	rigthView(root, level, &max_level);
	return 0;
}