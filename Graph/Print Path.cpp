/* Code to print all paths from source to destination in a  graph (directed / undirected) */

#include<bits/stdc++.h>
using namespace std;
queue<vector<int> > ans;
void path(vector<int>v[], bool vis[],vector<int>p, int source, int dest) 
{
    if(source == dest)
    {
        ans.push(p);
        return;
    }
    else
    {
        vis[source] = true;
        for(int i = 0; i < v[source].size(); i++)
        {
            int y = v[source][i];
            if(vis[y] == 0)
            {
                p.push_back(y);
                path(v, vis, p, y, dest);
                p.pop_back();
            }
        }
    }
    vis[source] = false;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>v[n+1];
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool vis[n+1] = {false};
    vector<int>vec;
    int source,dest;
    cin>> source >> dest;
    vec.push_back(source);
    path(v, vis, vec, source, dest);
    while(!ans.empty())
    {
        vector<int> p = ans.front();
        ans.pop();
        for(int i = 0; i < p.size(); i++)
        cout<<p[i]<<" ";
        cout<<endl;
    }
   
}
