#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


void InsertAtBeg(Node * & head,int data)
{
    Node *temp = new Node;
    temp -> data = data;
    temp -> next = head;
    head = temp;
}

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

void InsertAtPos(Node * & head,int pos,int data)
{
    Node * temp = new Node;
    temp->data=data;
    Node * p = head;
    for(int i=0;i<pos-2;i++)
    {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
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

void ReversePrint(Node *head)
{
    if(head==NULL)
        return;

    ReversePrint(head->next);
    cout<<head->data<<' ';
}

void DeleteFromBeg(Node * & head)
{
    if(head==NULL)
        return;

    Node * temp = head;
    head = head->next;
    delete temp;
}



void DeleteFromEnd(Node * & head)
{
    if(head==NULL)
    {
        return;
    }

    if(head->next==NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node * temp = head;
    while(temp->next->next!=NULL)
    {
        temp = temp -> next;
    }
    delete temp->next;
    temp->next = NULL;
    return;
}

void DeleteAtPos(Node * & head,int k)
{
    Node * temp1 = head;
    for(int i=0;i<k-2;i++)
    {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = NULL;
    delete temp2;
}

void FindAtPos(Node *head,int k)
{
    for(int i=0;i<k;i++)
    {
        head = head->next;
    }
    cout<<head->data<<endl;
}

void FindAtMid(Node * head)
{
    Node * slow = head;
    Node * fast = head;
    while(fast->next!=NULL||fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next == NULL)
    {
        cout<<endl<<"The mid element is : "<<slow->data;
    }
    else if(fast->next->next == NULL)
    {
        cout<<endl<<"The mid elements are : "<<slow->data<<"and "<<slow->next->data;
    }
}

void SwapNodes(Node * & head,int i,int j)
{
    Node * pos1 = head;
    Node * pos2 = head;
    Node * temp1;
    Node * temp2;

    for(int k=0;k<i-2;k++)
    {
        pos1 = pos1->next;
    }
    temp1 = pos1->next;
    for(int k=0;k<j-2;k++)
    {
        pos2 = pos2->next;
    }
    temp2 = pos2->next;
    pos1 ->next = temp1->next;
    pos2 ->next = temp2->next;
    temp2 ->next = pos1 ->next;
    temp1 ->next = pos2->next;
    pos1 ->next = temp2;
    pos2 ->next = temp1;
}

int LengthofLL(Node * head)
{
    int l=0;
    while(head!=NULL)
    {
        l++;
        head = head->next;
    }

    return l;
}

int main()
{
    Node * head = NULL;
    InsertAtBeg(head,1);
    InsertAtBeg(head,2);
    InsertAtBeg(head,3);
    InsertAtBeg(head,4);
    InsertAtBeg(head,5);
    PrintList(head);
    ReversePrint(head);
    DeleteFromEnd(head);
    cout<<endl;
    PrintList(head);
    InsertAtEnd(head,1);
    PrintList(head);
    FindAtPos(head,2);
    DeleteAtPos(head,2);
    PrintList(head);
    InsertAtPos(head,2,4);
    PrintList(head);
    SwapNodes(head,2,4);
    PrintList(head);
    return 0;
}
