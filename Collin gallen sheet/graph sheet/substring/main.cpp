#include <bits/stdc++.h>
using namespace std;

int const N=300010;
vector<int>graph[N],reversegraph[N];
int n,m;
string s;
bool cycle;
bool vis[N],recstack[N];
int freq[26];
int ans=0;
bool iscycle(int parent)
{
    bool flag=false;
    recstack[parent]=true;
    vis[parent]=true;
    for(int i=0;i<graph[parent].size();i++)
    {
        if(recstack[graph[parent][i]])
            return true;
        if(!vis[graph[parent][i]])
        {
            flag|= iscycle(graph[parent][i]);
        }
    }
    recstack[parent]=false;
    return flag;
}
int dp[300001];
int dfs(int parent,int cha)
{
    if(dp[parent]!=-1)
        return dp[parent];
   int ret=0;

    ans=max(ans,  freq[s[parent-1]-'a']);

    for(int i=0;i<graph[parent].size();i++)
    {
        ret=max(ret,dfs(graph[parent][i],cha));

    }
    if(s[parent-1]-'a'==cha)
        ret++;

    return dp[parent]=ret;

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    cin >> s;

    while(m--)
    {
        int u,v;
        cin >>  u>> v;
        graph[u].push_back(v);
        reversegraph[v].push_back(u);

    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            bool flag=iscycle(i);
            if(flag)
            {
                cout << -1<<endl;
                return 0;
            }

        }
    }
    for(int f=0;f<26;f++)
    {memset(dp,-1,sizeof dp);
        for (int i = 1; i <=n; ++i) {
        if(reversegraph[i].size()==0)
        {
         ans=max(ans,   dfs(i,f));
        }
    }


    }
    cout << ans << endl;
    return 0;
}
