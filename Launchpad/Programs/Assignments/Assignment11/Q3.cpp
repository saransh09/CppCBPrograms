#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

/*void InsertAtEnd(Node * &head,int data)
{
    Node * temp;
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

}*/

void InsertAtBeg(Node * & head,int data)
{
    Node *temp = new Node;
    temp -> data = data;
    temp -> next = head;
    head = temp;
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

void EliminateDuplicates(Node * & head)
{
    Node * temp = head;
    while(temp->next->data!=temp->next->next->data)
    {
        temp = temp->next;
    }
    while(temp->next->data==temp->next->next->data)
    {
        Node * temp2 = temp->next;
        temp->next=temp2->next;
        delete temp2;
    }
}

int main()
{
    Node * head = NULL;
    InsertAtBeg(head,1);
    InsertAtBeg(head,2);
    InsertAtBeg(head,3);
    InsertAtBeg(head,4);
    InsertAtBeg(head,4);
    InsertAtBeg(head,4);
    InsertAtBeg(head,4);
    InsertAtBeg(head,5);
    InsertAtBeg(head,6);
    InsertAtBeg(head,7);
    EliminateDuplicates(head);
    PrintList(head);
    return 0;
}
