#include <iostream>
using namespace std;

class Node{
    public:
    const int data;
    Node*next;

    Node(int d):data(d), next(NULL){}
    ~Node(){}
};

// void insertAtHead(Node*&head, int data){
//     if(head==NULL){
//         head = new Node(data);
//         return;
//     }
//     Node*n = new Node(data);
//     n->next = head;
//     head = n;
//     return;
// }

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
 
Node* IterativeReverse(Node*&head, int k){
    Node* current = head;
    Node* Next = NULL;
    Node* prev = NULL;
    int count = 0;
    while(current != NULL and count < k){
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
        count++;
    }
    if(Next != NULL){
        head->next = IterativeReverse(Next, k);
    }
    return prev;
}

void printLL(Node*head){
    while(head!=NULL){
        cout<<head->data;
        cout<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    Node*head = NULL, *temp = NULL;
    int n;
    cin>>n;
    int k;
    cin>>k;
    int data;
    for(int i=0; i<n; i++){
        cin>>data;
        insertAfterHead(head, data);
    }
    printLL(head);
    cout<<" & "<<endl;
    head = IterativeReverse(head, k);
    printLL(head);
    return 0;
}
