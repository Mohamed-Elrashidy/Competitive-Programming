#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
int const N =2*100000+2;
vector<int>adj[N];
map<int,int> target;
void getdata()
{
    cin >>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
bool vis[N];
int better;
bool flag=true;
int dfs(int parent)
{
vis[parent]=true;

int ret=0;
if(target.count(parent))
{ret=1;
target.erase(parent);
}
int check=0;
for(int i=0;i<adj[parent].size();i++)
{
    if(!vis[adj[parent][i]])
    {
        check+=dfs(adj[parent][i]);
    }
}
if(check>1)
{
    if(parent!=better)
    {
        flag=false;
    }
    else if(check>2)
        flag=false;
}

if(check>=1)
    ret=1;
vis[parent]=false;

return ret;
}

void solve()
{

    int m;
    cin >> m;
    while(m--)
    {
        int x;
        cin >> x;
        int y;
        cin >> y;
        target[y]++;
        better=y;
        int sz=adj[y].size();
        for(int i=0;i<x-1;i++)
        {cin >> y;
            if(adj[y].size()<sz)
            {
                better=y;
                sz=adj[y].size();
            }
            target[y]++;
        }
        dfs(better);
      //  cout << target.size()<< " "<< flag<<endl;
        if(target.size()==0&&flag)
        {
            cout <<"YES"<<endl;
        }
        else
            cout <<"NO"<<endl;

        flag=true;
        target.clear();

    }

}
int main() {
getdata();
solve();
    return 0;
}
