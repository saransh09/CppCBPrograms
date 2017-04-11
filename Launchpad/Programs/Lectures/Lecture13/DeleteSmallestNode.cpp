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

void DeleteSmallestNode(Node * & head)
{
    Node * small=head;
    Node * prev=NULL ;
    Node * pres=head;
    while(pres->next!=NULL)
    {
        if(pres->next->data<small->data)
        {
            small = pres->next;
            prev = pres;
        }
        pres = pres->next;
    }
    if(prev==NULL)
    {
        head = head->next;
        delete small;
    }
    else
    {
        prev ->next = small -> next;
        delete small;
    }

}

int main()
{
    Node * head = NULL;
    InsertAtEnd(head,0);
    InsertAtEnd(head,7);
    InsertAtEnd(head,1);
    InsertAtEnd(head,6);
    InsertAtEnd(head,4);
    InsertAtEnd(head,3);
    DeleteSmallestNode(head);
    PrintList(head);
    return 0;
}
