#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m;
int grid[1000002];
bool flag;
map<pair<int,int>,int>mp;
void solve(int pos,int val,int rem)
{if(val==0&&rem%2)
    return;
    if(val>rem||abs(val)>rem)
        return;
    if(flag)return;

    if(pos==n*m)
    {
       // cout << val +grid[pos]<<endl;
        if(val+grid[pos]==0)
            flag=true;
        return ;
    }

    if(mp.count({pos,val}))
        return ;
    mp[{pos,val}]++;
    if(pos%m!=0)
    {solve(pos+1,val+grid[pos],rem-1);}

    if(pos+m<=n*m)
    solve(pos+m,val+grid[pos],rem-1);


}

int main() {
    fast
    int t;
    cin >> t;
    while(t--)
    {mp.clear();
        flag=false;
cin >> n>> m;
for(int i=1;i<=n*m;i++)
    cin >> grid[i];
solve(1,0,n+m-1);
if(flag)
    cout <<"YES"<<endl;
else cout <<"NO"<<endl;

    }

    return 0;
}
