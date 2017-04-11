#include<iostream>
using namespace std;

int main()
{
    int n;        //IF WRONG INPUT DATATYPE ENTERED, THEN ALL THE INPUT STATEMENTS WILL BE SKIPPED
    cin >> n;  //READ
    cout << "Hello World";  //PRINT
    int a = 5;  //ASSIGNMENT
    30*100; //EXPRESSION
    float b;
    b = 30*a + 4*100;  //EXPRESSION    // ONLY ROUND BRACKETS IN AN EXPRESSION
    if(a%2==0)      //IF STATEMENT
    {
        cout<<"EVEN";
        cout<<"\n";    // ALWAYS USE CURLY BRACES REGAURDLESS OF ONE STATEMENT
    }
    else            //BASIC DATATYPES :- INT, CHAR, BOOL, FLOAT
    {
        cout <<"ODD";
        cout<<"\n";
    }
    return 0;
}
