#include<iostream>
#include<string.h>
using namespace std;

class Student
{
    int age;
    char name[100];
    int marks;
    public:
    void ReadInfo()
    {
        cout<<"Enter Name : ";
        cin.getline(name,100);
        cout<<"Enter Age : ";
        cin>>age;
        cout<<"Enter Marks";
        cin>>marks;
    }
    void PrintInfo()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age is : "<<age<<endl;
    }
    void Initialize()
    {
        name[0]='\0';
        age = 0;
        marks=0;
    }
    bool SetName(char *NewName)
    {
        if(strlen(NewName)<3)
        {
            return false;
        }
        strcpy(name,NewName);
        return true;
    }
};

int main()
{
    Student S;
    Student * ptr = new Student;
    ptr -> ReadInfo();
    S.ReadInfo();
    S.PrintInfo();
    return 0;
}
