#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>adj[100001];
int cutpoint=-1;
void getdata()
{
    cin >> n >> m;
    while(m--)
    {
        int u,v;
        cin >> u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void checkleaf()
{
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==1)
        {
            cutpoint=i;
            adj[i].clear
        }
    }
}
int main() {
    getdata();
    checkleaf();
    return 0;
}
