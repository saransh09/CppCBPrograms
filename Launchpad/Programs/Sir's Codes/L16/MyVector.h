#ifndef MYVECTOR_H
#define MYVECTOR_H
template <typename T>
class MyVector {
    T * ptr; 
    unsigned int s; 
    unsigned int c; 
    static void copyHeapSpace(const T * src, T * dest, unsigned int N) {
        for (int i = 0; i < N; i++) {
            dest[i] = src[i];
        }
    }
    public:
    MyVector() : ptr(0), s(0), c(0) {
    }
    MyVector(unsigned int N, const T & el ) : ptr(0) , s(N), c(N) {
        ptr = new T[c];
        for (int i = 0; i < s; i++) {
            ptr[i] = el;
        }
    }
    MyVector(const MyVector & V) : s(V.s), c(V.c), ptr(0) {
        ptr = new T[c];
        copyHeapSpace(V.ptr, ptr, s);
    }
    void clear() {
        if (!empty()) {
            delete ptr; 
            s = c = 0;
        }
    }
    ~MyVector() {
        clear();
    }
    MyVector & operator=(const MyVector & V) {
        clear();
        c = V.c;
        s = V.s;
        ptr = new T[c];
        copyHeapSpace(V.ptr, ptr, s);
        return *this;
    }
    unsigned int  size() const {
        return s;
    }
    bool empty() const {
        return s == 0;
    }
    void push_back(const T & el) {
        if (s == c) {
            int newc = c == 0 ? 1 : 2*c;
            T * newmemory = new T[newc];
            copyHeapSpace(ptr, newmemory, s);
            clear();
            ptr = newmemory;
            s = newc/2;
            c = newc;
        }
        ptr[s] = el;
        s++;
    }
    void pop_back() {
        if (empty()) {
            throw "Vector is Empty!! How dare you!!";
        }
        s--;
    }
    T & operator[](int index) {
        if (index <0 || index >= s) {
            throw "Index Out of Bounds";
        }
        return ptr[index];
    }
    const T & operator[](int index) const {
        if (index <0 || index >= s) {
            throw "Index Out of Bounds";
        }
        return ptr[index];
    }
    template <typename V>
    friend ostream & operator << (ostream &, const MyVector<V> &);
};
template <typename T>
ostream & operator << (ostream & out, const MyVector<T> & B) {
    for (int i = 0; i < B.s; i++) {
        out << B.ptr[i] << " ";
    }
}







#endif
