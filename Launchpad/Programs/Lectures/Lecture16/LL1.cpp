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



int main()
{
    Node * head = NULL;
    InsertAtEnd(head,1);
    InsertAtEnd(head,9);
    InsertAtEnd(head,8);
    InsertAtEnd(head,5);
    return 0;
}
