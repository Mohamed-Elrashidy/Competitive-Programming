#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cost[100001];
int n,m;
vector<int> friends[100001];
bool connected[100001];
void getdata() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    while (m--)
    {
     int x,y;
     cin >> x >>  y;
     x--;
     y--;
     friends[x].push_back(y);
     friends[y].push_back(x);
    }
}
 ll dfs(int parent)
 {
    ll mincost=cost[parent];
    connected[parent]=true;
    for(int i=0;i<friends[parent].size();i++)
    {
        if(!connected[friends[parent][i]])
        {
            mincost=min(mincost,dfs(friends[parent][i]));
        }
    }
    return mincost;
 }
ll solve()
{ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(!connected[i])
        {
            ans+=  dfs(i);

        }
    }
    return ans;
}
int main() {
getdata();
cout << solve()<<endl;
    return 0;
}
