#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,m;
    cin >> n>> m;
    int board [n][m];
    map<int,int>mp;
    for (int i=0;i< n;i++)
    {int cnt=0;
        for(int f=0;f<m;f++)
        {
            cin >> board[i][f];
            if(board[i][f]==1)
                cnt++;
        }
        mp[cnt]++;
        mp[m-cnt]++;
    }
for(int f=0;f<m;f++)
{int cnt =0;
    for(int i=0;i<n;i++)
    {
        if(board[i][f]==1)
            cnt++;
    }
    mp[cnt]++;
    mp[n-cnt]++;
}

if(mp.begin()->first==0)
{
    mp.erase(mp.begin());
}
ll ans=n*m;

for(auto i=mp.begin();i!=mp.end();i++)
{ans-=i->first*i->second;
    ans+=(pow(2,i->first)-1)*i->second;
}
cout << ans << endl;
    return 0;
}
