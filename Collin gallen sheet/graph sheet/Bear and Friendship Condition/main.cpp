#include <bits/stdc++.h>
using namespace std;
int const N=150001;
int n,m;
vector<int>adj[N];
vector<int> parents(N);
vector<int> groupsize(N);
void intilaize()
{
    for(int i=0;i<N;i++) {
        parents[i] = i;
        groupsize[i] = 1;
    }
}
int getsize(int item) {
    vector<int> groupitems;
    int par = parents[item];
    while (par != item) {
        groupitems.push_back(item);
        item = par;
        par = parents[item];
    }

    for (int i = 0; i < groupitems.size(); i++)
    {
        parents[groupitems[i]]=item;
        groupsize[groupitems[i]]=groupsize[item];
    }

    return groupsize[item];

}
int getparent(int child)
{ vector<int> groupitems;
    while(child!=parents[child])
    {groupitems.push_back(child);
        child=parents[child];}
    for(int i=0;i<groupitems.size();i++)
    {
        parents[groupitems[i]]=child;
    }
    return child;
}
void merge(int parent ,int child)
{
    if(getsize(parent)<getsize(child))
    {
        swap(parent,child);
    }
    int pp=getparent(parent);
    int cc=getparent(child);
    if(pp!=cc)
    {parents[cc]=parents[pp];
        groupsize[pp]+=groupsize[cc];

    }
}
map<pair<int,int>,int>visedge;

/*int dfs(int curr,int parent)
{int ret=0;
    visedge[{curr,parent}]++;
    visedge[{parent,curr}]++;
    for(auto i:adj[curr])
    {if(visedge.count({i,curr})==0)
            ret+= 1+ dfs(i,curr);
    }
    return ret;





}*/
int main() {
    intilaize()   ;
    cin >> n>> m;
    while(m--)
    {
        int u,v;
        cin >> u >>v;
        merge(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag=true;
    for(int i=0;i<=n;i++)
    {
        if(adj[i].size()!=groupsize[getparent(i)]-1)
        {flag=false;
        break;
        }
    }
    if(flag)
        cout <<"YES"<<endl;
    else cout <<"NO"<<endl;

    return 0;
}
