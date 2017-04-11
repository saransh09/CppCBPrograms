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

Node * MergeSortedLL(Node * & head1,Node * & head2)
 {
     Node * it1 = head1,*it2 = head2;
     Node * SortHead = NULL;
     Node * SortTail = NULL;
     while(it1!=NULL && it2!=NULL)
     {
         Node * smallest = 0;
         Node *temp1=head1,*temp2=head2;
         if(it1->data<it2->data)
         {
            smallest = it1;
            it1 = it1->next;
         }
         else
         {
             smallest = it2;
             it2 = it2->next;
         }
         smallest->next=NULL;
         if(SortHead==NULL)
         {
             SortHead = SortTail = smallest;
         }
         else
         {
             SortTail ->next = smallest;
             SortTail = smallest;
         }
     }

     if(it1!=NULL)
     {
         SortTail->next = it1;
     }
     else if(it2!=NULL)
     {
         SortTail->next = it2;
     }
     head1 = 0;
     head2 = 0;
     return SortHead;
 }


int main()
{
    Node * head1 = NULL;
    Node * head2 = NULL;
    InsertAtEnd(head1,9);
    InsertAtEnd(head1,7);
    InsertAtEnd(head1,5);
    InsertAtEnd(head1,3);
    InsertAtEnd(head1,1);
    InsertAtEnd(head2,8);
    InsertAtEnd(head2,6);
    InsertAtEnd(head2,4);
    InsertAtEnd(head2,2);
    InsertAtEnd(head2,0);
    return 0;
}
