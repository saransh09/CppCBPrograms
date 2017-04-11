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

void OddAfterEven(Node *& head)
{
    Node *l1=head,*l2=head;
    while(l1->next!=NULL)
    {
        l1=l1->next;
        l2=l2->next;
    }

    Node * curr = head;
    Node * prev = NULL;
    while(curr!=l1)
    {
        if(head->data%2==1)
        {
            head = head->next;
            curr->next=NULL;
            l2->next = curr;
            l2 = l2->next;
            curr = head;
            continue;
        }
        if(curr->data%2==0)
        {
            prev = curr;
            curr=curr->next;
            continue;
        }
        else
        {
            prev->next = curr->next;
            curr->next = NULL;
            l2->next = curr;
            l2 = l2->next;
            curr = prev->next;
            continue;
        }
    }
}

int main()
{
    Node* head = NULL;
    InsertAtEnd(head,7);
    InsertAtEnd(head,3);
    InsertAtEnd(head,1);
    InsertAtEnd(head,8);
    InsertAtEnd(head,4);
    InsertAtEnd(head,9);
    PrintList(head);
    OddAfterEven(head);
    PrintList(head);
    return 0;
}

