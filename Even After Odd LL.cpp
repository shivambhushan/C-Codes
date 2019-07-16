#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d): data(d), next(NULL){}
    ~Node(){}
};

void insertAfterHead(Node*&head, int data){
    if(head == NULL)
    {
        head =  new Node(data);
        return;
    }
    else
    {
        Node*ptr = head;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        Node*n = new Node(data);
        ptr->next = n;
    }
}

void printLL(Node*&head)
{
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void EvenAfterOdd(Node*&head){
    Node*ptr =head;
    Node*a = NULL;
    Node*b = NULL;
    while(ptr!=NULL)
    {
        if((ptr->data%2) == 0)
        {
            insertAfterHead(b, ptr->data);
            ptr = ptr->next;
        }
        else
        {
            insertAfterHead(a, ptr->data);
            ptr = ptr->next;
        }
    }
    printLL(a);
    printLL(b);
}


int main(int argc, char const *argv[])
{
    Node*head = NULL;
    Node*a = NULL;
    Node*b = NULL;
    int n, data;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        insertAfterHead(head, data);
    }
    EvenAfterOdd(head);
    return 0;
}