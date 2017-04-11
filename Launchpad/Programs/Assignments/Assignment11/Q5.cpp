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

struct mypair
{
    Node * aadr;
    bool ans;
};

Node * CheckPalindrome(Node * head,Node * curr)
{
    if(curr->next==NULL)
    {
        mypair var;
        if(curr->data==head->data)
        {
            var.aadr = head->next;
            var.ans =  1;
            return var;
        }
        else
            var.aadr = NULL;
            var.ans = 0;
            return 0;
    }

    mypair subvar = CheckPalindrome(head,curr->next);
    if(subvar.ans==0)
    {
        return subvar;
    }
    if(subvar.addr -> data != curr->data)
    {
        var.addr = NULL;
        var.ans = 0;
        return var;
    }


   var.addr = subvar.addr.next;
   var.ans = 1;
   return var;


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


int main()
{
    Node * head = NULL;
    Node * h = NULL;
    InsertAtEnd(head,1);
    InsertAtEnd(head,2);
    InsertAtEnd(head,3);
    InsertAtEnd(head,3);
    InsertAtEnd(head,2);
    InsertAtEnd(head,1);
    PrintList(head);
    h = head;
    return 0;
}
