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


void ReverseIt(Node *& head)
{
    Node *p0=head,*p1=head,*p2=NULL;

    while(p1->next!=NULL)
    {
        if(p1==p0)
        {
            p2 = p1->next;
            p1->next=NULL;
            p1=p2;
        }
        else
        {
            p2 = p1->next;
            p1->next=p0;
            p0=p1;
            p1=p2;
        }
    }
    p1->next = p0;
    head = p1;
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
    ReverseIt(head);
    PrintList(head);
    return 0;
}
