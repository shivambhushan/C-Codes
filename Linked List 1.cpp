#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;

	//initialization list if memory declared and assigned value and assignment works on already declared memory
	Node(int d):data(d), next(NULL){}
	~Node(){
		if(next!=NULL){
			delete next; //deletes all the LL
			//recursive calling of destructor for next Node
		}
		cout<<"Deleting Node "<<data<<": ";
	}
};

//&head for pass by reference wherver its value is to be changed again and again
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

int length(Node*head){
	int count = 0;
	while(head!=NULL){
		count++;
		head = head->next;
	}
	return count;
}

//& can and cannot be considered if p=0 then we need to change the head pointer so &head is helpfull
void insertInMiddle(Node*&head, int data, int pos){ 
	if(pos == 0){
		insertAtHead(head, data);
		return;
	}
	if(pos>length(head)){
		return;
	}
	Node*t = head;
	for (int jump = 1; jump <= pos-1; jump++){
		t = t->next;
	}
	Node*n = new Node(data);
	n->next = t->next;
	t->next = n;
	return;
}

// void insertAfterHead(Node*&head, int data){
//     if(head==NULL){
//         head = new Node(data);
//         return;
//     }
//     Node*n = new Node(data);
//     Node*ptr = head;
//     while(ptr->next!=NULL){
//         ptr = ptr->next;
//     }
//     ptr->next=n;
//     return;
// }


void deleteLL(Node*&head){
	delete head;
	head = NULL;
}

void deleteInMiddle(Node*&head, int pos){
	if(pos == 0){
		Node*t = head->next;
		head->next = NULL;
		delete head;
		head = t;
		return;
	}
	Node *prev = NULL, *temp = head;
	for(int jump = 1; jump <= pos; jump++){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	temp->next = NULL;
	delete temp;
	return;
}

void printLL(Node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[]){
	Node*head = NULL;
	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	printLL(head);
	insertInMiddle(head, 4, 0);
	printLL(head);
	deleteInMiddle(head, 3);
	printLL(head);
	//deleteLL(head);
	return 0;
}