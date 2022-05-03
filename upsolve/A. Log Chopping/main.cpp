#include <bits/stdc++.h>

using namespace std;
multimap <int,pair<int,int>>mp;
int grid[5007][3];
int dp[5001][2];
int n,m,tot;
long long solve(int pos,int lst)
{
    int ch=0;
    if(grid[pos][0]>=lst)
        ch=1;
    if(pos==tot)
        return 0;
    if(dp[pos][ch]!=-1)
        return dp[pos][ch];
    long long ret=solve(pos+1,lst);
    if(grid[pos][0]>=lst)
    {
        ret=max(ret,grid[pos][2]+solve(pos+1,grid[pos][1]));
    }
    return dp[pos][ch]=ret;

}


int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
memset(dp,-1,sizeof dp);
    cin >> n>> m;
    while(n--)
    {
        int x,y,z;
        cin >> x >> y>> z;
        while(z--)
        {
            int v;
            cin >> v;
         mp.insert(make_pair(v,make_pair(v+y,x)));

        }
    }
   tot=0;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
       grid[tot][0]=i->first;
        grid[tot][1]=i->second.first;
        grid[tot][2]=i->second.second;
        tot++;
    }
    cout << solve(0,-1)<<endl;



    return 0;
}
