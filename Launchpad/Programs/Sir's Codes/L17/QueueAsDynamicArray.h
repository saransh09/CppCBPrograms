#ifndef QUEUE_AS_ARRAY
#define QUEUE_AS_ARRAY
template <typename T>
class Queue {
    T * ptr; 
    unsigned int c,s;
    int f,r;
    public:
    Queue() : ptr(0), c(0), s(0), f(-1), r(0) {
    }
    int size() const {
        return s;
    }
    bool empty() const {
        return s == 0;
    }
    void clear() {
        if (ptr) {
            delete ptr; 
            ptr = 0;
            s = c = 0; 
            f = -1;
            r = 0;
        }
    }
    ~Queue() {
        clear();
    }
    Queue(const Queue & Q) : c(Q.c), s(Q.s), f(Q.f), r(Q.r) {
        ptr = new T[c];
        for (int i = 0; i < c; i++) {
            ptr[i] = Q.ptr[i];
        }
    }
    Queue & operator=(const Queue & Q) {
        clear();
        c = Q.c;
        s = Q.s;
        f = Q.f;
        r = Q.r;
        ptr = new T[c];
        for (int i = 0; i < c; i++) {
            ptr[i] = Q.ptr[i];
        }
        return *this;
    }
    T & front() {
        if  (empty()) {
            throw "Queue is Empty!";
        }
        return ptr[f];
    }
    const T & front() const {
        if  (empty()) {
            throw "Queue is Empty!";
        }
        return ptr[f];
    }
    void enqueue(const T & el ) {
        if (s == c) {
            if (c == 0) {
                c = 1; 
                ptr = new T[c];
            } else {
                int newc = 2 *c;
                T * newmemory = new T[newc];
                int k = 0;
                for (int i = f; i < c; i++, k++) {
                    newmemory[k] = ptr[i];
                }
                for (int i = 0; i <= r -1; i++, k++) {
                    newmemory[k] = ptr[i];
                }
                delete ptr;
                f = 0;
                r = s;
                ptr = newmemory;
                c = newc;
            }
        }
        ptr[r] = el;
        r = (r +1)%c;
        s++;
        if (s == 1) {
            f = 0;
        }
    }
    void dequeue() {
        if(empty()) {
            throw "Queue is Empty";
        }
        f = (f+1)%c;
        s--;
        if (s == 0) {
            f = -1;
            r = 0;
        }

    }
};
#endif
