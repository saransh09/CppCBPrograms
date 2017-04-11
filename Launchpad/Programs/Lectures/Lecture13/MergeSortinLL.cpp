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

 Node * PreviousOfMid(Node * head)
{
    Node *it1 = head;
    Node *it2 = head;
    Node *PrevOfIt = 0;
    while(it2 && it2->next)
    {
        PrevOfIt = it1;
        it1 = it1->next;
        it2 = it2->next->next;
    }
    return PrevOfIt;
}


void MergeSort(Node *& head)
{
    if(head == NULL || head->next == NULL)
        return;

    Node * PrevOfMid = PreviousOfMid(head);
    Node * head1 = head;
    Node * head2 = PrevOfMid->next;
    PrevOfMid->next = NULL;
    MergeSort(head1);
    MergeSort(head2);
    head = MergeSortedLL(head1,head2);
}


int main()
{
    Node * head1 = NULL;
    Node * head2 = NULL;
    InsertAtEnd(head1,0);
    InsertAtEnd(head1,2);
    InsertAtEnd(head1,4);
    InsertAtEnd(head1,6);
    InsertAtEnd(head1,8);
    InsertAtEnd(head2,1);
    InsertAtEnd(head2,3);
    InsertAtEnd(head2,5);
    InsertAtEnd(head2,7);
    InsertAtEnd(head2,9);
    PrintList(head1);
    PrintList(head2);
    PrintList(MergeSortedLL(head1,head2));
    return 0;
}
