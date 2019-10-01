#include<iostream>
using namespace std;
int bsearch(int arr[],int s,int e,int key)
{

    if(s>e)
     return 0;
    int mid=(s+e)/2;
    if(arr[mid]  <=  key)
      return mid-s + 1 + bsearch(arr,mid+1,e,key);
    else
      return bsearch(arr,s,mid-1,key);

}
int solve(int a[],int b[],int sa,int ea,int sb,int eb,int k)
{
    int mida=(sa+ea)/2;
    int count=bsearch(b,sb,eb,a[mida]);
    int midb=(sb+eb)/2;
    int count2=bsearch(a,sa,ea,b[midb]);

    if( (mida + count + 1) == k )
      return a[mida];
    else if( (mida + count +1) > k )
       return solve(a,b,sa,mida-1,sb,count-1,k);
    else
      return solve(a,b,mida+1,ea,sb+count,eb,k);
}
int main()
{
    int a[]={1,3,5,7,9,11};
    int b[]={6,8,10,10,10};
    int k=3;
    cout<<solve(a,b,0,5,0,4,1);


}
