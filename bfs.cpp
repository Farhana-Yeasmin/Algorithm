#include <bits/stdc++.h>
using namespace std;
#define mx 100000
vector<int> graph[mx];
bool visit[mx];
int dis[mx];
int bfs(int node, int s, int d)
{
    for (int i = 0; i < node; i++)
    {
        visit[i] = 0;
    }
    queue<int> q;
    q.push(s);
    visit[s] = 1;
    dis[s]=0;

    while ((!q.empty()))
    {
        int u = q.front();
        q.pop();

        if (u == d)
        {
            return u;
        }
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (v == 0)
            {
                visit[v] = 1;
                dis[v]=dis[u]+1;// it means current node distance +path cost =new node cost 
                q.push(v);
            }
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s, d;
    cin >> s >> d;
    int res = bfs(n, s, d);
    cout << res << endl;

    return 0;
}