#include<bits/stdc++.h>

#define mx 100000
#define pb push_back
using namespace std;
vector<int>prime;
bool isprime[mx];


void sieve()
{
    for( int i=0;i<mx;i++)
       isprime[i]=true;

    for(int i=3; i*i <mx;i+=2)
    {
        if(isprime[i])
        {
            for(int j= i*i;j<mx;j+=i+i)
            {
                isprime[j]=false;
            }
        }
    }
    prime.pb(2);
    for( int i=3;i<mx ; i+=2)
    {
        if(isprime[i])
        {
            prime.pb(i);
        }
    }
}

 int main()

 {
     int m,n;
     sieve();
     cin>>n>>m;
     int sum=prime[n-1]+prime[m-1];
     cout<<sum<<endl;
     return 0;
 }