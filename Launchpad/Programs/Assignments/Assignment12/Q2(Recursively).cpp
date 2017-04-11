#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void InsertAtEnd(Node * & head,int data)
{
    Node * temp = new Node;
    temp -> data = data;
    if(head==NULL)
    {
        head = temp;
        temp ->next = NULL;
        return;
    }

    Node * il = head;
    while(il->next!=NULL)
    {
        il = il-> next;
    }
    il -> next = temp;
    temp->next = NULL;

}

void PrintList(Node *head)
{
    Node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<endl;
}

Node * ReverseRec(Node *& head,Node *& curr)
{
    if(curr->next==NULL)
    {
        head = curr;
        return curr;
    }
    ReverseRec(head,curr->next);
    Node * temp = curr->next;
    temp->next = curr;
    curr->next=NULL;
}

int main()
{
    Node* head = NULL;
    InsertAtEnd(head,5);
    InsertAtEnd(head,4);
    InsertAtEnd(head,3);
    InsertAtEnd(head,2);
    InsertAtEnd(head,1);
    PrintList(head);
    ReverseRec(head,head);
    PrintList(head);
    return 0;
}
