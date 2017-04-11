#include<iostream>
using namespace std;

int SearchWord(char str[][100],char *word,int n)
{
    for(int i=0;i<n;i++)
    {
        int j=0,k;
        while(str[i][j]!='\0')
        {
            k=j;
            while(str[i][k]==' ' || str[i][k]=='\t')
            {
                k++;
            }

        int g=0;
        for(int l=j;l<k;l++)
        {
            if(word[g]==str[i][l])
            {
                g++;
                if(word[g]=='\0')
                {
                    return i+1;
                }
            }
            else
                break;
        }
        j++;
        }
    }
}

int main()
{
    char word[25];
    char str[100][100];
    cout<<"Enter the number of strings you want to enter : ";
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++)
    {
        cin.getline(str[i],100);
    }
    cout<<endl<<"Enter the word : ";
    cin.getline(word,25);

    int p = SearchWord(str,word,n);

    cout<<endl<<"words found : "<<p;
    return 0;
}
