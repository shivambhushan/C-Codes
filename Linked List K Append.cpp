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

void AppendLL(Node*&head, int k){
	if (head == NULL || head->next == NULL){
		return;
	}
        Node*current = NULL;
        Node*Next = head;
    while(k--){
        while(Next->next != NULL){
            current = Next;
            Next = Next->next;
        }
        current->next = NULL;
        Next->next = head;
        head = Next;
    }
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
    int n, data;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        insertAfterHead(head, data);
    }
    int k;
    cin>>k;
    //printLL(head);
    AppendLL(head, k);
    printLL(head);
    
	return 0;
}