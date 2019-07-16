#include <iostream>
using namespace std;

class Node{
public:
	const int data;
	Node*next;

	Node(int d): data(d), next(NULL){}
	~Node(){}
};

void insertAtHead(Node*&head, int data){ 
	if (head == NULL){
		head =  new Node(data); //if tail also then head=tail=new Node
		return;
	}
	Node*n = new Node(data);
	n->next = head;
	head =  n;
	return;
}

Node* ReverseLLRecursive(Node*&head){
	if (head == NULL or head->next == NULL){
		return head;
	}

	//Rec Case
	Node* ChotaHead = ReverseLLRecursive(head->next);
	////Overkill Code - increases complexity - n^2
	//Node *temp = ChotaHead;
	// while(temp->next != NULL){
	// 	temp = temp->next;
	// }
	Node* temp = head->next; // or head->next->next = head;
	//above line decreses the complexity
	temp->next = head;
	head->next = NULL;
	return ChotaHead;
}

void ReverseLLIterative(Node*&head){
	Node*current = head;
	Node*Next = head->next;
	Node*prev = NULL;
	while(current != NULL){
		Next = current->next;
		current->next = prev;
		prev = current;
		current = Next;
	}
	head = prev;	
}

int search(Node*head, int key){
	if(head==NULL){
		return -1;
	}
	if (head->data == key){
		return 0;
	}
	int NextIndex = search(head->next, key);
	if (NextIndex == -1)
	{
		return -1;
	}
	return NextIndex+1;
}

void printLL(Node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Node*head = NULL;
	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	insertAtHead(head, 4);
	printLL(head);
	// head = ReverseLLRecursive(head);
	// printLL(head);
	ReverseLLIterative(head);
	printLL(head);

	//cout<<"Index of search 4: "<<search(head, 4);
	return 0;
}