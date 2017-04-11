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

struct mypair
{
    Node * addr;
    bool ans;
};

mypair CheckP(Node * head, Node * curr)
 {
     mypair var;
    if(curr->next==NULL)
    {
        if(curr->data==head->data)
        {
            var.addr=head->next;
            var.ans=1;
            return var;
        }
        else
        {
            var.addr=NULL;
            var.ans=0;
            return var;
        }
    }

    mypair subvar = CheckP(head,curr->next);

    if(subvar.ans==0)
    {
        return subvar;
    }

    if(subvar.addr->data!=curr->data)
    {
        var.addr=NULL;
        var.ans=0;
        return var;
    }

    var.addr=subvar.addr->next;
    var.ans=1;
    return var;
 }

int main()
{
    Node* head = NULL;
    InsertAtEnd(head,5);
    InsertAtEnd(head,4);
    InsertAtEnd(head,3);
    InsertAtEnd(head,4);
    InsertAtEnd(head,5);
    PrintList(head);
    if(CheckP(head,head).ans==1)
        cout<<"YESSSSSSS";
    //ReverseIt(head);
    //PrintList(head);
    return 0;
}

