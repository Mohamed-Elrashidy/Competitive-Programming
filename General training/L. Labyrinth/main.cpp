#include <bits/stdc++.h>

using namespace std;
int n,m,s;
vector <int>adj[2*100000+9];
vector<int> ans,check;
bool flag;
bool vis[2*100000+9];
void dfs(int i,int p)

{if(flag)
return;
vis[i]=true;
for(int k=0;k<adj[i].size();k++)
{
    if(!vis[adj[i][k]] )
    {
        check.push_back(adj[i][k]);
        dfs(adj[i][k],i);
        if(flag)
            return ;
        check.pop_back();
    }
    else
    {
        if(adj[i][k]==s&&p!=s)
        {
            flag=true;
            ans=check;
            return;
        }
    }
}
 vis[i]=false;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n>> m>>s;
while(m--)
{
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
check.push_back(s);
dfs(s,0);
if(flag)
{
    cout << "Possible"<<endl;
    cout << 2<<endl;
    cout << s << " " << ans[ans.size()-1]<<endl;
    cout << ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i];
        if(i==ans.size()-1)
        {
            cout << endl;
        }
        else cout << " ";

    }


}
else cout << "Impossible"<<endl;

    return 0;
}
