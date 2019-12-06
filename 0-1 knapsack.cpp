#include<bits/stdc++.h>
using namespace std;


int n,w[1000],p[1000],mx,dp[1000][1000],profit;

int knapsack(int i,int weight)
{
    if(i==n+1) 
    return 0;
    
    int cost1=0,cost2=0;

    if(w[i]+weight<=mx) 
    {
    cost1=p[i]+knapsack(i+1,weight+w[i]);
    }

    cost2=knapsack(i+1,weight);
    profit=max(cost1,cost2);
    
    return profit;
}

int main()
{
    int i,j,m;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>w[i]>>p[i];
    }
    cin>>mx;

    m=knapsack(1,0);
    cout<<"Maximum profit : "<<m<<endl;
    return 0;
}
/*
input
6
3 17
2 12
1 5
7 40
5 27
4 23
14*/