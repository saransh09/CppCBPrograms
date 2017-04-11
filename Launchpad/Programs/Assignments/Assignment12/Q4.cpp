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

void kRev(Node *& head,int k)
{
    Node *p0=head,*p1=head,*p2,*p3=head,*p4=head;
    int i=k;
    for(i;i>1;i--)
    {
        p3 = p3->next;
        p4 = p4->next;
    }
    i = k;
    for(i;i>1;i--)
    {
        p4 = p4->next;
    }

    while(p1!=p3)
    {
        if(p1==p0)
        {
            p2 = p1->next;
            p1 -> next = NULL;
            p1 = p2;
        }
        else
        {

        }
    }
}

int main()
{
    Node* head = NULL;
    InsertAtEnd(head,3);
    InsertAtEnd(head,4);
    InsertAtEnd(head,5);
    InsertAtEnd(head,2);
    InsertAtEnd(head,6);
    InsertAtEnd(head,1);
    InsertAtEnd(head,9);
    PrintList(head);
    cout<<"Enter a Number less than 4 : ";
    int k;
    cin>>k;
    return 0;
}

