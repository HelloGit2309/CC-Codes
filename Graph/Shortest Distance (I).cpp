/* Code to print shortest distance from source node to destination node in an undirected unweighted graph (USING BFS) */

#include<bits/stdc++.h>
using namespace std;
int bfs(int start,int end, vector<int>v[], bool vis[], int lvl[] , int dist)
{
    queue<int>q;
    q.push(start);
    vis[start] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        if(p == end)
        return lvl[end];
        for(int i = 0; i < v[p].size(); i++)
        {
            if(vis[v[p][i]] == false)
            {
                q.push(v[p][i]);
                vis[v[p][i]] = true;
                lvl[v[p][i]] = lvl[p] + 1;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>> n >> m;
    vector<int>v[n+1];
    while(m--)
    {
        int a,b;
        cin>> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int s,d;
    cin>>s>>d;
    bool vis[n+1] = {false};
    int lvl[n+1] = {0};
    int ans = bfs(s,d,v,vis,lvl,0);
    cout<<ans;
}
