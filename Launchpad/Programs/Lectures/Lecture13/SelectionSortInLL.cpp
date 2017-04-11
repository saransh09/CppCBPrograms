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

Node * RemoveSmallestNode(Node * & head)
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
    }
    else
    {
        prev ->next = small -> next;
    }
    small->next=NULL;
    return small;
}

void SelectionSort(Node * & head)
{
    Node *SortHead=NULL,*SortTail=NULL;
    while(head!=NULL)
    {
        Node * small = RemoveSmallestNode(head);
        if(SortHead==NULL)
        {
            SortHead = SortTail = small;
        }
        else
        {
            SortTail->next = small;
            SortTail = small;
        }
    }
    head = SortHead;
}

int main()
{
    Node * head = NULL;
    InsertAtEnd(head,5);
    InsertAtEnd(head,7);
    InsertAtEnd(head,9);
    InsertAtEnd(head,3);
    InsertAtEnd(head,2);
    InsertAtEnd(head,-8);
    InsertAtEnd(head,6);
    PrintList(head);
    cout<<endl;
    SelectionSort(head);
    PrintList(head);
    return 0;
}
