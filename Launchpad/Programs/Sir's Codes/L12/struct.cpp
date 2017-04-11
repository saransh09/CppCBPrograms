#include<iostream>
using namespace std;
struct address {
    char street_name[100];
    char city[100];
    int pincode;
};
struct student {
    char name[100];
    float marks;
    int age;
    address addr;
    student * neighbour;
};
void printInfo(student t) {
    cout << t.name << endl;
    cout << t.marks << ", "  << t.age << endl;
    cout << t.addr.street_name << ", " << t.addr.city << " - " << t.addr.pincode<< endl;
    return;
}
student readInfo() {
    student t;
    cout << "Enter student name ";
    cin.getline(t.name, 100);
    cout << "Enter Marks ";
    cin >> t.marks;
    cout << "Enter Age ";
    cin >> t.age;
    cin.get();
    cout << "Enter street address ";
    cin.getline(t.addr.street_name, 100);
    cout << "Enter City ";
    cin.getline(t.addr.city, 100);
    cout << "Enter Pincode ";
    cin >> t.addr.pincode;
    return t;
}
//void readStudents(student * slist, int N) 
void readStudents(student slist[], int N ) {
    for (int i = 0; i < N; i++) {
        readInfo(slist[i]);
    }
    return;
}
student * createStudenLL() {
    int N;
    cin >> N;
    student first = readInfo();
    for(int i = 1; i < N; i++) {
        student s = readInfo();
        first.neighbour = &s;
        s.neighbour = 0;


    }
    return &first;
}


int main() {
    student s1, s2, s3;

    s1.neighbour = &s2;
    s2.neighbour = &s3;

    student * ptr = &s1;

    /*
    student slist[100];
    cout << slist << endl;
    cout << &slist[0] << endl;
    readStudents(slist, 2);
    student t = readInfo();
    printInfo(t);

    student * ptr = new student;
    cin.getline((*ptr).name, 100);
    cin.getline(ptr->name, 100);
    cin >> *ptr.marks;
*/

    /*
    student t;
    cout << &t << endl;
    student *ptr;
    // ptr = &t;
    ptr = new student;
    readInfo(*ptr);
    readInfo(t);
    printInfo(t);*/
    return 0;
}
