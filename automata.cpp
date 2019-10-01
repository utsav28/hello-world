#include<iostream>
#include<string.h>
#include<string>
#include<set>
using namespace std;
int suffix(string a)
{
    int m=a.length();
    int n=m- 1;
    int i,k;
    while(n)
    {   for(i=0,k=m-n;i<n;i++,k++)
        {
            if(a[i]!=a[k])
              break;
        }
        if(i==n)
         break;
        n--;
    }
    return n;
}
int main()
{
    string pattern;
    cin>>pattern;
    string text;
    cin>>text;
    set<char> x;
    for(int i=0;i<pattern.length();i++)
    {
        x.insert(pattern[i]);
    }
    int count = x.size();

    int automata[pattern.length()+1][count];

    for(int i=0;i<=pattern.length();i++)
      for(int j=0;j<count;j++)
          automata[i][j] = -1;

    for(int i=0;i<pattern.length();i++)
    {   set<char>::iterator j = x.begin();
        int k;
        for(k=0;j!=x.end();j++,k++)
        {
            if(( *j) == pattern[i])
              break;
        }
        automata[i][k] = i+1;
    }

    for(int i=0;i<=pattern.length();i++)
    {   string s="";
        for(int k=0;k<i;k++)
                s = s + pattern[k];

        for(int j=0;j<count;j++)
        {   string temp=s;
            set<char>::iterator l = x.begin();
            int k;
            for(k=0;k<j;l++,k++);
            temp += (*l);
            if(automata[i][j]==-1)
            {
                automata[i][j]= suffix(temp);
            }
        }
    }
    cout<<"\nAutomata table :\n";
    for(int i=0;i<=pattern.length();i++)
    { for(int j=0;j<count;j++)
           cout<<" "<<automata[i][j];
      cout<<"\n";
    }

    int state=0,i,cnt=0;
    for(i=0;i<text.length();i++)
    {
        int k;
        set<char>::iterator j = x.begin();
        for(k=0;j!=x.end();j++,k++)
        {
            if(( *j) == text[i])
              break;
        }
        if(j==x.end())
            state=0;
        else
            state = automata[state][k];

        cout<<state<<" ";
        if(state==pattern.length())
        {   cnt++;
        }
    }
    cout<<"\n\nPattern Found "<<cnt<<" times\n";


    return 0;
}
