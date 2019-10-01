#include<iostream>
#include<string.h>
#include<string>
using namespace std;
void lcs(string s1,string s2)
{
    int n=s1.length();
    int m=s2.length();

    int table[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                table[i][j]=0;
            else if(s1[i-1] == s2[j-1])
                table[i][j]=table[i-1][j-1] +1;
            else
                table[i][j] = max(table[i-1][j],table[i][j-1]);

            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }

    int len = table[n][m],k=0;
    char arr[len+1];
    int x=n,y=m;
    while(1)
    {
        if(table[x][y]== table[x][y-1])
            y=y-1;
        else if(table[x][y]==table[x-1][y])
            x=x-1;
        else if(table[x][y] == table[x-1][y-1]+1)
        {   arr[k++]=s1[x-1];
            x=x-1;
            y=y-1;
        }

        if(table[x][y] ==0)
            break;
    }
    arr[len]=0;
    for(int i=len-1;i>=0;i--)
    {
        cout<<arr[i];
    }
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    lcs(s1,s2);
}
