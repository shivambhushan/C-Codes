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

Node* insertInBST(Node*root, int d){
    if(root == NULL){
        Node*n = new Node(d);
        return n;
    }

    //Insert in left subtree if data<root->data
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

bool search(Node*root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node* deleteNode(Node*root, int key){
    //BC
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        // delete Node
        //3 cases - leaf Node, single child and double child
        if(root->left == NULL  and root->right ==  NULL){
            delete root;
            return NULL;
        }
        else if(root->left != NULL and root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->right != NULL and root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else{
            Node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, root->data);
            return root;
        }
    }
    else if(root->data > key){
        root->left = deleteNode(root->left, key);
        return root;
    }
    else{
        root->right = deleteNode(root->right, key);
        return root;
    }
}

//Height Balanced BST
Node* arrayToBST(int arr[], int s, int e){
    if(s > e){
        return NULL;
    }
    int m = (s+e)/2;
    Node*root = new  Node(arr[m]);
    root->left = arrayToBST(arr, s, m-1);
    root->right = arrayToBST(arr, m+1, e);
    return root;
}

//BST to LL
class LLPair{
    public:
    Node* head;
    Node* tail;
};

LLPair tree2LL(Node*root){
    //BC
    LLPair l;
    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }
    if(root->left == NULL and root->right == NULL){
        l.head = l.tail = root;
        return l;
    }

    //RC
    if(root->left!=NULL and root->right==NULL){
        LLPair LeftLL = tree2LL(root->left);
        LeftLL.tail->right = root;
        l.head = LeftLL.head;
        l.tail = root;
        return l;
    }
    if(root->right!=NULL and root->left==NULL){
        LLPair RightLL = tree2LL(root->right);
        root->right = RightLL.head;
        l.head = root;
        l.tail = RightLL.tail;
        return l;
    }
    else{
        //post order traversal (Bottom Up Approach)
        LLPair LeftLL = tree2LL(root->left);
        LLPair RightLL = tree2LL(root->right);
        LeftLL.tail->right = root;
        root->right = RightLL.head;
        l.head = LeftLL.head;
        l.tail = RightLL.tail;
        return l;
    }
}

Node* preorderToBST(int *pre, int *inx, int s, int e){
    static int x = 0; //initialization only one time
    if(s > e){
        return NULL;
    }
    Node*root = new  Node(pre[x]);
    //search the index of x in preorder
    int j;
    for(j = s; j <= e; j++){
        if(inx[j] == pre[x]){
            break;
        }
    }
    x++;
    //j---> knows the index of pre[x] in order
    root->left = preorderToBST(pre, inx, s, j-1);
    root->right = preorderToBST(pre, inx, j+1, e);
    return root;
}

int countBST(int n){
    if(n == 0){
        return 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += countBST(i-1)*countBST(n-i);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    Node*root = takeInput();
    // int d;
    // cin>>d;
    cout<<"before"<<endl;
    levelOrderPrint(root);
    cout<<endl;
    // //search(root, 6);
    // cout<<"after"<<endl;
    root = deleteNode(root, 3);
    root = deleteNode(root, 10);
    root = deleteNode(root, 7);
    levelOrderPrint(root);
    // int arr[] = {1, 3, 5, 7, 9, 10, 11};
    // int n = sizeof(arr)/sizeof(int);
    // Node* root = arrayToBST(arr, 0, n-1);
    // levelOrderPrint(root);
    // LLPair l = tree2LL(root);
    // Node* temp = l.head;
    // while(temp != NULL){
    //     cout<<temp->data<<"->";
    //     temp = temp->right;
    // }
    // int pre_arr[] = {7, 3, 1, 5, 10, 9, 11};
    // int n = sizeof(pre_arr)/sizeof(int);
    // int in_arr[] = {1, 3, 5, 7, 9, 10, 11};    
    // Node* root = preorderToBST(pre_arr, in_arr, 0, n-1);
    // levelOrderPrint(root);
    // cout<<endl<<countBST(3);
    return 0;
}