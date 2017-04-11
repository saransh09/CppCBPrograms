#include<iostream>
using namespace std;
struct Node {
    int data;
    Node * next;
};
void insertAtTheBegining(Node * &head, int el) {
    Node * temp = new Node;
    temp->data = el;
    temp->next = head;
    head = temp;
}
/*void insertAtTheBegining(Node **head, int el) {
    Node * temp = new Node;
    temp->data = el;
    temp->next = *head;
    *head = temp;
}*/
void printList(Node * head) {
    while (head != NULL) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
void reversePrint(Node *head) {
    if(head == NULL) {
        return;
    }
    reversePrint(head->next);
    cout << head->data << " ";
    return;
}
void deleteFromEnd(Node * & head) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = 0;
        return;
    }
    Node *it = head;
    while (it->next->next != NULL) {
        it = it->next;
    }
    delete it->next;
    it->next = 0;
    return;
}
int main() {
    Node * head = 0;
    insertAtTheBegining(head, 1);
    insertAtTheBegining(head, 2);
    insertAtTheBegining(head, 3);
    printList(head);
    reversePrint(head);
    return 0;
}
