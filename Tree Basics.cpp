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

//level by level print of tree
void printTreeLevel(Node*root, int k){
	//Base Case
	if(root == NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printTreeLevel(root->left, k-1);
	printTreeLevel(root->right, k-1);
}

int height(Node*root){
    //return root==NULL?0:1+max(height(root->left), height(root->right));
    if (root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2)+1;
}

void printAllLevels(Node*root){
    int levels = height(root);
    for (int k = 0; k <= levels; ++k){
        printTreeLevel(root, k);
        cout<<endl;
    }
}

int countNodes(Node*root){
    if(root ==  NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumNodes(Node*root){
    if(root == NULL){
        return 0;
    }
    return root->data + sumNodes(root->left)+sumNodes(root->right);
}

int replaceNodesBySum(Node*root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL and root->right == NULL){
        return root->data;
    }
    int temp = root->data;
    root->data = replaceNodesBySum(root->left) + replaceNodesBySum(root->right);
    return root->data + temp; 
}

//level order print
void levelOrderPrint(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* f = q.front();
        if(f == NULL){
            q.pop();
            cout<<endl;        
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<f->data<<" ";
            if(f->left != NULL){
                q.push(f->left);
            }
            if(f->right != NULL){
                q.push(f->right);
            }
        }
    }
}

//When input to a tree is level wise
Node* buildTreeLevelOrder(){
	queue<Node*> q;    
    int d;
	cin>>d;
	if(d==-1){
		return NULL;
	} 
	Node*root = new Node(d);
    q.push(root);
    while(!q.empty()){ //jb tk q empty nahi hai
        int c1, c2;
        cin>>c1>>c2;
        Node* f = q.front();
        q.pop();
        if(c1 != -1){
            f->left = new Node(c1);
            q.push(f->left);
        }
        if(c2 != -1){
            f->right = new Node(c2);
            q.push(f->right);    
        }
    }
	return root;
}

int treeDiameter(Node*root){ //O(n^2) complexity
    //BC
	if (root == NULL){
		return 0;
	}
    //RC
	int h = height(root->left) + height(root->right);
    int H = max(treeDiameter(root->left), treeDiameter(root->right));
    return max(h, H); 
}

class MyPair{
    public:
    int height;
    int diameter;
};

MyPair treeDiameterOptimised(Node*root){
    //BC
    MyPair p; // p is root and working or postorder traversal
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }

    //RC
    MyPair left = treeDiameterOptimised(root->left);
    MyPair right = treeDiameterOptimised(root->right);
    p.height = max(left.height, right.height) + 1;
    p.diameter = max(max(left.diameter, right.diameter), left.height+right.height);
    return p;
}

void root2Leaf(Node*root, vector<int> &v){
    //BC
    if(root == NULL){
        return;
    }
    if(root->left == NULL and root->left == NULL){
        v.push_back(root->data);
        //print the vector
        for(int x:v){
            cout<<x<<"->";
        }
        cout<<endl;
        v.pop_back();
        return;
    }
    
    //RC
    v.push_back(root->data);
    root2Leaf(root->left, v);
    root2Leaf(root->right, v);
    v.pop_back();
    return;
}

void mirror(Node*root){
    if(root == NULL){
        return;
    }
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
    return;
}

Node* insertInBST(Node*root, int d){
    if(root= NULL){
        Node*n = new Node(d);
        return n;
    }

    //Insert in left subtree if data<root->data
    if(d<root->data){
        root->left = insertInBST(root->left, d);
    }
    else{
        root->right = insertInBST(root->right, d);
    }
    return root;
}

int main(int argc, char const *argv[])
{
	//Node*root = buildTree();
    // MyPair p;
    Node*root = buildTreeLevelOrder();
	// printTree(root);
	// cout<<endl;
	// printTreeLevel(root, 2);
	// cout<<endl;
	// cout<<height(root);
	// cout<<endl;
	// printAllLevels(root);
    //cout<<endl;
    // cout<<countNodes(root);
    // cout<<endl;
    // cout<<sumNodes(root);
    // cout<<endl;
    replaceNodesBySum(root);
    printAllLevels(root);
    //cout<<endl;
    //levelOrderPrint(root);
    //cout<<treeDiameter(root);
    // p = treeDiameterOptimised(root); //capture the result of function
    // cout<<p.diameter;
    // vector<int> v;
    // root2Leaf(root, v);
    // cout<<endl;
    // mirror(root);
    // levelOrderPrint(root);
    // cout<<endl;
    // printTree(root);
	return 0;
}