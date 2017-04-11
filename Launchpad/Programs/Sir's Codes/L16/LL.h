#ifndef LL_H
#define LL_H
#include<iostream>
using namespace std;
template<typename T>
class LinkedList;

template <typename type>
class Node {
    type data;
    Node * next;
    public:
//    static int datamember;
    Node() : next(0) {}
    Node(const type  & d) : next(0), data(d) {}
    void setData(const type & val) {
        data = val;
    }
    const type & getData() {
        return data;
    }
    template <typename T>
    friend class LinkedList;
    template <typename T>
    friend bool operator==(const LinkedList<T> &, const LinkedList<T> &);
    template<typename T>
    friend ostream & operator<<(ostream &, const LinkedList<T> &);
};
//template<typename T>
//int Node<T>::datamember = 0;


template<typename T>
class LinkedList {
    Node<T> * head;
    Node<T> * tail;
    static int staticdatamember;
    void clear() {
        while(head) {
            Node<T> * temp = head->next;
            delete head;
            head = temp;
        }
        head = tail = 0;
    }
    public:
    static const char * getClassName() {
        return "LinkedList";
    }
    static int getStaicDataMember() {
        return staticdatamember;
    }
    LinkedList() : head(0), tail(0) {}
    // Create a constructor with nodes from 1 to N
    LinkedList(int N): head(0), tail(0) {

    }
    LinkedList(const LinkedList & L2) : head(0), tail(0) {
        if (L2.head == 0) return;
        const Node<T> * it = L2.head;
        while (it != NULL) {
 //           insertAtEnd(*(it).data);
            Node<T> * cur = new Node<T>(it->data);
            if (head == 0) {
                head = tail = cur;
            } else{
                tail->next = cur;
                tail = cur;
            }
            it = it->next;
        }
    }
    ~LinkedList() {
        clear();
    }
    LinkedList & operator=(const LinkedList &L) {
        clear();
        const Node<T> * it = L.head;
        while (it != NULL) {
            insertAtEnd((*it).data);
            it = it->next;
        }
        return *this;
    }
    LinkedList & operator+=(const T & el) {
        insertAtEnd(el);
        return *this;
    }
    T & operator[](int index) {
        Node<T> *it = head;
        while(index && it) {
            index--;
            it = it->next;
        }
        if (!it) {
            throw "Index out of bounds";
        }
        return it->data;
    }
    const Node<T> * findMid() const {
        const Node<T> * it1 = head;
        const Node<T> * it2 = head;
        while (it2 && it2->next) {
            it1 = it1->next;
            it2 = it2->next->next;
        }
        return it1;
    }
    LinkedList & operator+=(const LinkedList & L) {
        const Node<T> * it = L.head;
        while(it) {
            insertAtEnd(it->data);
            it = it->next;
        }
        return *this;
    }
    void reversePrint() const {
        reversePrintHelper(head);
    }
    private:
    static void reversePrintHelper(const Node<T> *it) {
        if(it == NULL) {
            return;
        }
        reversePrintHelper(it->next);
        cout << it->data << " ";
        return;
    }
    public:
    void insertAtEnd(const T & el) {
        Node<T> * cur = new Node<T>(el);
        if (head == 0) {
            head = tail = cur;
            return;
        }
        tail->next = cur;
        tail = cur;
        return;
    }
    void insertAtHead(const T & el) {
        Node<T> * cur = new Node<T>(el);
        if (head == 0) {
            head = tail = cur;
            return;
        }
        cur->next = head;
        head = cur;
        return;
    }
    void deleteFromHead() {
        if (head == 0) {
            return;
        }
        Node<T> * temp = head;
        head = head->next;
        delete temp;
        if (head == 0) {
            tail = 0;
        }
    }
    LinkedList operator+(const LinkedList &L) const {
        LinkedList ans = *this;
        ans+=L;
        return ans;
    }
    // Post Increment
    LinkedList operator++(int val) {
        LinkedList ans = *this;
        ++(*this);
        return ans;
    }
    // Pre Increment
    LinkedList & operator++() {
        Node<T> *it = head;
        while (it) {
            ++(it->data);
            it = it->next;
        }
        return *this;
    }
    LinkedList operator~() const {
        LinkedList ans = *this;
        Node<T> *it = ans.head;
        while (it) {
            it->data = ~(it->data);
            it = it->next;
        }
        return ans;
    }

    void printList() const {
        const Node<T> *it = head;
        while (it) {
            cout << it->data << "-->";
            it = it->next;
        }
        cout << "NULL" << endl;
        return;
    }
    // Declaration of Member Method, defined outside
    const int & operator[](int) const;
    // Declaring friend to a function which is not a member method
    template <typename U>
    friend bool operator==(const LinkedList<U> &, const LinkedList<U> &);
    template <typename U>
    friend ostream & operator<<(ostream &, const LinkedList<U> &);
};
template<typename T>
const int & LinkedList<T>::operator[](int index) const {
    const Node<T> *it = head;
    while(index && it) {
        index--;
        it = it->next;
    }
    if (!it) {
        throw "Index out of bounds";
    }
    return it->data;
}
template<typename U>
bool operator==(const LinkedList<U> & L1, const LinkedList<U> & L2)  {
    const Node<U> * it1 = L1.head;
    const Node<U> * it2 = L2.head;
    while (it1!=NULL && it2!=NULL) {
        if (it1->data != it2->data) {
            return false;
        }
        it1 = it1->next;
        it2= it2->next;
    }
    if (it1 == NULL && it2 == NULL) {
        return true;
    } else {
        return false;
    }
}
template <typename T>
ostream & operator<<(ostream & out, const LinkedList<T> & L) {
    const Node<T> * it = L.head;
    while (it ) {
        out << it->data << "-->";
        it = it->next;
    }
    out<<"NULL";
    return out;
}
#endif
