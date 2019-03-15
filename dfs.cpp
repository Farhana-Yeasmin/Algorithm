#include<bits/stdc++.h>
using namespace std;
#define mx 1000000
vector<int> graph[mx];
bool visit[mx];


void dfs(int s)
{
    visit[s]=true;
    cout<<s<<" ";
    for(int i=0;i<graph[s].size();i++)
    {
        if(visit[graph[s][i]] == false)
        dfs(graph[s][i]);
    }
}



int main()
{

    int nodes,edges,x,y;
    cin>>nodes;
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        
    }
       
        for(int i=0;i<mx;i++)
        visit[i]=false;
        for(int i=1;i<=nodes;i++)
        {
            if( visit[i]==false)
            dfs(i);
        }


    
    return 0;
}



