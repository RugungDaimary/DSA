//Qn) printing binary of negative numbers
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[32]={0};
    int i=1;
    int dec;
    if(n>=0)
    {
        dec=n;
    }
    else dec=(-1)*n;
    while(dec>0)
    {
        a[32-i]=dec%2;
        dec=dec/2;
        i++;
    }
    if(n>=0) 
    {
        for(int i=0;i<32;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    else
    {
        //cout<<endl;
        int b[32];
        for(int i=0;i<32;i++) b[i]=1;
        for(int i=0;i<32;i++)
        {
            a[i]=a[i]^b[i];
        }
        // for(int i=0;i<32;i++) cout<<a[i]<<" ";
        // cout<<endl;
        a[31]=a[31]+1; 
        for(int i=31;i>=0;i--)
        {
            if(a[i]==2)
            {
                a[i]=0;
                a[i-1]+=1;
            }
        }
        for(int i=0;i<32;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
   return 0;
}

