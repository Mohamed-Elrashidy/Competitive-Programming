#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2*100000 +1;
int n;
bool flag=true;

vector<int>adj[N];
bool vis[N];
void getdata()
{flag=true;
    cin >> n;
    for(int i=0;i<=n;i++)
    {
        adj[i].clear();
        vis[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(a==b)
            flag=false;

    }

}
ll  dfs(int parent)
{
vis[parent]=true;
if(adj[parent].size()!=2)
    flag=false;

for(int i=0;i<adj[parent].size();i++)
{
    if(!vis[adj[parent][i]])
    {
     return dfs(adj[parent][i])+1;
    }
}
    return 1;
}

void solve()
{
    for(int i=1;i<=n;i++)
    {//cout << i << endl;
        if(!vis[i])
        {//cout << flag << endl;
            ll z =dfs(i);
           // cout << z << endl;
            if(z%2)
                flag=false;
        }
    }
    if(flag)
        cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        getdata();
        solve();

    }return 0;
}
