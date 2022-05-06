#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::syne_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
map<string,int>mp;
int vita[1001];
int cost[1001];
int distinct=0;
long long dp[1001][8];
int generate_msk(string s)
{
    int msk=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')
            msk|=(1);
        else if(s[i]=='B')
            msk|=2;
        else msk|=4;
    }
    return msk;
}
void generate_start()
{
    for(int i=1;i<8;i++)
    {
if((i&vita[0])==i)
{    dp[0][i]=cost[0];}

    }
}
long long min_previous(int i,int msk)
{
    long long x=1e9;
    for(int f=1;f<(1<<8);f++)
    {
        int j=f;
        int coun=1;
        int msk2=0;
        long long tot=0;
        while(j)
        {
            if(j&1)
            {
                if(min(dp[i][coun],dp[i+1][coun])>1e9)
                    goto c;
                else
                    tot+=min(dp[i][coun],dp[i+1][coun]);
                msk2|=(coun);

            }
            coun++;
            j>>=1;
        }
        if((msk2&msk)==msk)
        {
            x=min(x,tot);

        }
        c:;
    }
    return x;
}
void solve()
{
    memset(dp,'?',sizeof dp);

    generate_start();
    for(int i=1;i<distinct;i++)
    {
        for(int f=1;f<8;f++)
        {

if((vita[i]&f)==f)
    dp[i][f]=cost[i];

        }
        for(int f=1;f<8;f++)
        {
            dp[i][f]=min(dp[i][f],min_previous(i-1,f));

        }
    }

}


int main() {
cin >> n;
for(int i=0;i<n;i++)
{string s;
    int m;
    cin >> m>>s;
    sort(s.begin(),s.end());
    if(mp.count(s))
    {
        mp[s]=min(mp[s],m);
    }
    else mp[s]=m;


}
    while(mp.size())
    {
        vita[distinct]= generate_msk(mp.begin()->first);
        cost[distinct]=mp.begin()->second;
        distinct++;
        mp.erase(mp.begin());
    }
    solve();

    if(dp[distinct-1][7]>1e8)
    {
        cout << -1<<endl;
    }
    else cout << dp[distinct-1][7]<<endl;

    return 0;
}
