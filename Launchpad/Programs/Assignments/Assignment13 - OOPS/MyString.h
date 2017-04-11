// You need to complete this class as assignment - 13
// This is a header file for your flexible string. I have already included function declarations.
// All you need to do is complete the functions.
// Make sure to append null character to end of the array!!

#ifndef MYSTRING_H
#define MYSTRING_H
class MyString {
    char * arr;     // Pointer variable to store address of the dynamic allocated memory
    int len;        // To store length of the string
    int capcity;    // To store the capacity of the string
    public:
    // This is the zero parameterized constructor. It should create a empty string of initial length 0 and capacity 10;
    MyString() : len(0), capacity(10) {
        arr = new char[10];
        char[0]='\0';
    }

    // Another constructor which takes a 'C' type string [ character array terminated by Null Character] and creates an object
    // which is same as str.
    MyString(const char *str) arr(0) {
        if(str[0]=='\0')
            return;

        int temp = 0;
        while(str[temp]!='\0')
        {
            temp++;
        }
        arr = new char[temp+1];
        capacity = temp+2;
        len = temp+1;
    }

    // Copy constructor
    MyString(MyString & b) {
        arr = new char[b.capcity];
        len = b.len;
        int i=0;
        while(*(b.arr+i)!='\0')
        {
            arr[i] = *(b.arr+i);
            i++;
        }
    }

    // Destructor
    ~MyString() {
        delete[] arr;
    }

    // Copy Assignment Operator
    MyString & operator=(const MyString & b) {
        delete[] arr;
        capacity = b.capacity;
        len = b.len;
        arr = new char[capacity];
        int i=0;
        while(b[i]!=0)
        {
            arr[i] = b[i];
            i++;
        }
        arr[i]= '\0';

        return *this;
    }

    // It adds ch at the end of the string
    void append(char ch) {
        if(len<capacity-1)
        {

        }

    }

    // It adds all characters of 'C' type string str to the end.
    void append(const char *str) {
    }

    // It adds all character of string b to the end.
    void append(const MyString & b) {
        if(capacity>(len+b.len))
        {
            int i = len-1,j=0;
            while(*(b.arr+j)!='\0')
            {
                arr[i] = *(b.arr+j);
                i++;j++;
            }
            arr[i]='\0';
        }
        else
        {
            int c = 2*capacity;
            char * a = new char[c];
            int i=0;
            while(arr[i]!='\0')
            {
                a[i] = arr[i];
                i++;
            }
            int j=0;
            while(*(b.arr+j)!='\0')
            {
                arr[i] = *(b.arr+j);
                i++;j++;
            }
            arr[i]='\0';
            delete[] arr;
            char * arr = new char[c];
            arr = a;
            delete a;
            capacity = c;
            len = i;
        }
    }

    // returns length of the string
    int length() const {
        return len;
    }

    // returns capacity of the string
    int capacity() const {
        return capacity;
    }

    // returns true if string is empty
    bool empty() const {
        if(*arr='\0')
            return true;

        else
            return false;
    }

    // empty the content - free the allocated memory and reset your state to empty string
    void clear() {
        delete[] arr;
        arr=0;
        len=0;
        capacity=0;
    }

    // It removes the last character
    void pop_back() {
        arr[len-1] = '\0';
        len--;
    }

    // It removes characters of the string from start to end
    void remove(int start, int end) {
        if(end>len||start<0)
        {
            cout<<"The index is out of bounds";
            return;
        }

        int i = end+1;

        if(arr[i]=='\0')
        {
            arr[start] = '\0'
            len = len-(end-start);
            return;
        }
        while(arr[i]!='\0')
        {
            arr[start] = arr[i];
            i++;
        }
        arr[i] = '\0';
    }

    // It removes characters of the string from start to len
    void remove(int start) {
        arr[start]='\0';
        len = len-(len-start);
    }

    // It deletes characters at the index.
    void deleteAt(int index) {
        int i=index;
        if(arr[index+1]='\0')
        {
            arr[index]='\0';
        }
        else
        {
            while(a[i+1]!=0)
            {
                a[i]=a[i+1];
                i++;
            }
            a[i]='\0';
        }
    }

    // Returns a MyString Object which has characters of this string from start to end
    MyString substring(int start, int end) const {

    }

    // Returns a MyString Object which has characters of this string from start to length
    MyString substring(int start) const {
    }

    // Returns character at the index
    char getAt(int index) const {
        return *(arr+index);
    }

    // Returns first index of string b in this string after pos index
    int find(const MyString &b, int pos = 0) const {
    }

    // Returns first index of "C" type string str in this string after pos index
    int find(const char *str, int pos = 0) const {
    }

    // Compare function for "C" type string
    int compare(const char * str) const {
    }

    // Compare function for MyString type string
    int compare(const MyString & b) const {
    }

    // return reference of the first character
    char & front() {
    }

    // same as above but for constant string
    const char & front() const {
    }

    // return reference of the last character
    char & back() {
    }

    // same as above but for constant string
    const char & back() const {
    }


    //Operator Overloading

    bool operator==(const MyString &b) const {
        int i=0;
        while(arr[i]!='\0')
        {
            if(arr[i]==*(MyString.arr+i))
                continue;
            else
                break;
        }
    }

    MyString & operator+=(char ch) {
    }

    MyString & operator+=(const char * str) {
    }

    MyString & operator+=(const MyString & b) {
    }

    const char & operator[](int index) const {
    }

    char & operator[](int index) {
    }

    // Return a new string which is concatination of the two
    MyString operator+(const MyString & b) const {
        int l = len + b.len - 1;
        char * a = new char[l];
        capacity = 2*l;
        int i=0;
        while(arr[i]!='\0')
        {
            a[i] = arr[i];
            i++;
        }
        int j=0;
        while(*(b.arr+j)!='\0')
        {
            a[i] = *(b.arr+j);
            i++;j++;
        }
        return *this;
    }

    MyString operator+(const char * str) const {
    }

};
