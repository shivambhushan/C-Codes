#include <iostream>
using namespace std;

class Node{
public:
	const int data;
	Node*next;

	Node(int d): data(d), next(NULL){}
	~Node(){}
};

void insertAfterHead(Node*&head, int data){
    if(head==NULL){
        head = new Node(data);
        return;
    }
    Node*n = new Node(data);
    Node*ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next=n;
    return;
}

Node* mergeLL(Node*&a, Node*&b){
	if (a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}
	Node* newhead;
	if(a->data <= b->data){
		newhead = a;
		newhead->next = mergeLL(a->next, b);
	}
	else{
		newhead = b;
		newhead->next = mergeLL(a, b->next);
	}
	return newhead;
}

void printLL(Node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Node*head = NULL;
    int t, data;
    cin>>t;
    for(int i = 1; i <= t; i++){
        Node*a = NULL;
        Node*b = NULL;
        int n1, n2;
        cin>>n1;
        for(int j=0; j<n1; j++){
            cin>>data;
            insertAfterHead(a, data);
        }
        cin>>n2;
        for(int k=0; k<n2; k++){
            cin>>data;
            insertAfterHead(b, data);
        }
        head = mergeLL(a,b);
    	printLL(head);
    }
	return 0;
}