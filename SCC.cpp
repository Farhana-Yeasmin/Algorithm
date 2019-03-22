#include <bits/stdc++.h>
using namespace std;

const int NODE = 10000;
vector<int> graph[NODE], reverseGraph[NODE];
int node, edge;
bool visit[NODE];
stack<int> topologicalList;

void clearVisitedNode()
{
    for (int i = 0; i <= node; i++)
    {
        visit[i] = 0;
    }
}
void dfsOnMainGraph(int node)
{

    visit[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextNode = graph[node][i];
        if (visit[nextNode] == false)
        {
            dfsOnMainGraph(nextNode);
        }
        topologicalList.push(node);
    }
}

void dfsOnReverseGraph(int node)
{
    cout<<node<<" ";
    visit[node] = true;
    int sz = reverseGraph[node].size();
    for (int i = 0; i < sz; i++)
    {
        int nextNode = reverseGraph[node][i];
        if (visit[nextNode] == false)
        {
            dfsOnReverseGraph(nextNode);
        }
    }
}

int main()

{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> node >> edge;
        for (int i = 0; i < edge; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            reverseGraph[v].push_back(u);
        }

        cout << "print original graph" << endl;
        for (int i = 1; i <= node; i++)
        {

            cout << i << " : ";
            for (auto x : graph[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }

        cout << "print reverse graph" << endl;
        for (int i = 1; i <= node; i++)
        {

            cout << i << " : ";
            for (auto x : reverseGraph[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }

        clearVisitedNode();

        for (int i = 0; i <= node; i++)
        {
            if (visit[i] == false)
            {
                dfsOnMainGraph(i);
            }
        }
        clearVisitedNode();
        int groupNumber = 1;
        while (!topologicalList.empty())
        {

            int node = topologicalList.top();
            topologicalList.pop();
            if (visit[node] == false)
            {
                cout << "group number  " << groupNumber << " : ";
                dfsOnReverseGraph(node);
                groupNumber++;
                cout << endl;
            }
        }
    }

    return 0;
}