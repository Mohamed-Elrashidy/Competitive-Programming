#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<vector<int>> adj;
int n;
int val[1000002];
int av[100002];
bool flag=true;
ll ans=0;
void getdata()
{
    cin >> n;
    adj.resize(n);
    for(int i=1;i<n;i++)
    {int x;
        cin >> x;
        adj[x-1].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        cin >> val[i];
    }
}
void dfs(int parent,int preparent)
{if(adj[parent].size()==0)
    {
        av[parent]=max(0,val[parent]-val[preparent]);
    }
    else{
        if(av[parent]==-1)
        {set<int>st;
            for(auto i:adj[parent])
            {
                st.insert(val[i]-val[preparent]);
            }
            if(*st.begin()<0)
                return ;
            av[parent]=*st.begin();
            val[parent]=*st.begin()+val[preparent];
            for(auto i:adj[parent])
            {
                av[i]=val[i]-val[preparent]-av[parent];
                dfs(i,parent);
            }
        }
        else
        {
            for(auto i:adj[parent])
            {
                dfs(i,parent);
            }
        }}
}
void solve()
{
    av[0]=val[0];

    for(auto i:adj[0])
    {//cout << i << endl;
        dfs(i,0);
    }
    for(int i=0;i<n;i++)
    {
        ans+=av[i];
        if(av[i]==-1)
            flag=false;
    }
    if(flag)
        cout << ans << endl;
    else cout << -1 << endl;
}
int main() {
    memset(val,-1,sizeof val);
    memset(av,-1,sizeof av);
    getdata();
    solve();
    return 0;
}
