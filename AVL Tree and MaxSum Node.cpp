#include<bits/stdc++.h>
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
void printTree(Node*root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	printTree(root->left);
	printTree(root->right);
}

class HBPair{
    public:
    int height;
    bool balance;
};

HBPair isHeightBalanced(Node*root){
    //BC
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }

    //RC
    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);

    if(abs(left.height-right.height)<=1 and left.balance and right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    p.height = max(left.height, right.height) + 1;
    return p;
}

class PairIE{
public:
    int inc;
    int exc;
};

PairIE maxSum(Node*root){
    //BC
    PairIE p;
    if(root == NULL){
        p.inc = p.exc = 0;
        return p;
    }

    //RC
    PairIE L, R;
    L = maxSum(root->left);
    R = maxSum(root->right);

    p.inc = root->data + L.exc + R.exc;
    p.exc = max(L.inc, L.exc) + max(R.inc, R.exc);
    return p;
}

int main(int argc, char const *argv[])
{
	Node*root = buildTree();
	printTree(root);
	cout<<endl;
	if(isHeightBalanced(root).balance){
        cout<<"Yes HB";
    }
    else{
        cout<<"Not HB";
    }
    cout<<endl;
    PairIE p = maxSum(root);
    cout<<max(p.inc, p.exc)<<endl;
	return 0;
}