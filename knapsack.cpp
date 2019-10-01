#include<iostream>
using namespace std;
int main()
{
    int n=3;
    int w[]={4,8,2};
    int v[]={7,8,3};
    int c=11;
    int sol[n];
    int k;
    int maxx=0;
    int table[n+1][c+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)
        {   maxx=0;
            if(j==0 || i==0)
            {
              table[i][j] = 0;
            }
            else
            {   if(table[i-1][j] > maxx)
                   {maxx = table[i-1][j];}
                if(table[i][j-1] > maxx)
                   {maxx = table[i][j-1];}
                k = j/w[i-1];
                while(k>0)
                { if( (table[i][j-k*w[i-1]] + k*v[i-1] ) > maxx)
                    {maxx  = table[i][j- k*w[i-1]] + k*v[i-1];}

                    k--;
                }
            }
            table[i][j]=maxx;
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}


