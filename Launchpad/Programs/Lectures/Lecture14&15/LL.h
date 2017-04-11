#ifndef LL_H
#define LL_H
#include<iostream>

using namespace std;

class LinkedList;

template<typename type>

class Node
{
    type data;
    Node * next;
    public:
    Node() : next(0){}
    Node(const type & d) : next(0),data(d){}
    void SetData(const type & val)
    {
        data = val;
    }
    int GetData()
    {
        return data;
    }
    friend class LinkedList;
};

class LinkedList
{
    Node * head;
    Node * tail;
    static int staticdatamember;
    public:
    LinkedList() : head(0), tail(0) {}
    //Create a Constructor with nodes from 1 to N
    /*LinkedList(int N) : head(0), tail(0)
    {

    }*/
    void InsertAtEnd(int el)
    {
        Node * current = new Node(el);
        if(head==0)
        {
            head = tail = current;
            return;
        }
        tail->next = current;
        tail = current;
        return;
    }

    void InsertAtHead(int el)
    {
        Node * cur = new Node(el);
        if(head==0)
        {
            head = tail = cur;
            return;
        }
        cur->next = head;
        head = cur;
    }

    LinkedList(const LinkedList & L2) : head(0), tail(0)
    {
        if(L2.head==NULL)
            return;


        Node * temp = L2.head;
        while(temp)
        {
            InsertAtEnd(temp->data);
            temp = temp->next;
        }
    }

    void DeleteFromHead()
    {
        if(head==0)
            return;

        Node *temp = head;
        head = head -> next;
        delete temp;

        if(head==NULL)
        {
            tail=NULL;
        }
    }

    ~LinkedList()
    {
        Node * temp = head;
        while(temp!=NULL)
        {
            head=temp;
            temp = temp->next;
            delete head;
        }
    }

    void PrintList()
    {
        Node *it = head;
        while(it)
        {
            cout<<it->data<<" ";
            it=it->next;
        }
        cout<<"NULL";
        return;
    }

    /*bool operator==(const LinkedList & L) const
    {
        const Node * it1 = head;
        const Node * it2 = L.head;
        while(it1!=NULL && it2!=NULL)
        {
            if(it1->data != it2->data)
            {
                return false;
            }
            it1 = it1->next;
            it2 = it2->next;
        }
        if(it1 == NULL && it2 == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }*/

    LinkedList operator+(const LinkedList &L)const
    {
        LinkedList ans = *this;
        const Node* it = L.head;
        while(it!=NULL)
        {
            ans.InsertAtEnd(it->data);
            it = it->next;
        }
        return ans;
    }

    LinkedList operator~() const
    {
        LinkedList ans = *this;
        Node * it = ans.head;
        while(it)
        {
            it->data = -(it->data);
            it = it->next;
        }
        return ans;
    }

    LinkedList & operator=(const LinkedList &L)  //Had it not been returned by reference A copy would have been returned
    {
        while(head)
        {
            Node * temp = head->next;
            delete head;
            head = temp;
        }
        head = tail = 0;
        const Node * it = L.head;
        while (it!=NULL)
        {
            InsertAtEnd(it->data);
            it = it->next;
        }
        return *this;
    }

    LinkedList & operator+=(int el)
    {
        InsertAtEnd(el);
        return *this;
    }

    LinkedList & operator+=(const LinkedList & L)
    {
        const Node* it = L.head;
        while(it)
        {
            InsertAtEnd(it->data);
            it = it->next;
        }
        return *this;
    }

    const Node * FindMid() const
    {
        const Node * it1 = head;
        const Node * it2 = head;
        while(it2 && it2->next)
        {
            it = it1->next;
            it2 = it2->next->next;
        }
        return it1;
    }

    LinkedList operator++(int val)     //PostIncrement
    {
        LinkedList ans = *this;
        ++(*this);
        return ans;
    }

    LinkedList & operator++()           //PreIncrement
    {
        Node *it = head;
        while(it)
        {
            ++(it->data);
            it = it->next;
        }
        return *this;
    }
    int & operator[](int index) //const
    {
        Node * it = head;
        while(index&&it)
        {
            index--;
            it = it->next;
        }
        if(!it)
        {
            throw "Index Out of Bounds";
        }
        return it->data;
    }

    const int & LinkedList::operator[](int index) const;

    friend bool operator==(const LinkedList &,const LinkedList &) const;
    friend ostream & operator<<(osetream &, const LinkedList & L);
};

static int LinkedList::staticdatamember=5;                 //Have to be explicitly allocated

bool operator==(const LinkedList & L1,const LinkedList & L2) const
    {
        const Node * it1 = L1.head;
        const Node * it2 = L2.head;
        while(it1!=NULL && it2!=NULL)
        {
            if(it1->data != it2->data)
            {
                return false;
            }
            it1 = it1->next;
            it2 = it2->next;
        }
        if(it1 == NULL && it2 == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

const int & LinkedList::operator[](int index) const
    {
        const Node * it = head;
        while(index&&it)
        {
            index--;
            it = it->next;
        }
        if(!it)
        {
            throw "Index out of bounds";
        }
        return it->data;
    }

/*osetream & operator<<(osetream & out,const LinkedList & L)
{
    const Node * it = L.head;
    while(it)
    {
        out<<it->data<<"-->";
    }
    return;
}*/
#endif // LL_H
