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

Node* mid(Node* l){
	Node* slow = l;
	Node* fast = l->next;
	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* mergeSort(Node* l){
	//Base case
	if(l == NULL || l->next == NULL){
		return l;
	}

	//Rec case
	Node* m = mid(l);
	Node* a = l;
	Node* b = m->next;
	m->next = NULL;
	a = mergeSort(a);
	b = mergeSort(b);
	return mergeLL(a, b);
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
	insertAtHead(head, 8);
	insertAtHead(head, 7);
	insertAtHead(head, 4);
	insertAtHead(head, 1);
	insertAtHead(head, 12);
	insertAtHead(head, 10);
	insertAtHead(head, 2);
	insertAtHead(head, 0);
	mergeSort(head);
	printLL(head);
	return 0;
}