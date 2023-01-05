#include <bits/stdc++.h>
using namespace std;
#define  fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
ll v1,v2;
ll t,d;
ll dp[101][2001];
void start()
{
    dp[1][v1]=v1;
}
void generate_dp(int time)
{
    for(int i=1;i<2000;i++) {
        if(dp[time-1][i]!=0)
        {
            for(int f=i;f>=max((ll)0,i-d);f--)
            {
                dp[time][f]=max(dp[time][f],dp[time-1][i]+f);
            }
            for(int f=i;f<=min((ll)2000,i+d);f++)
            {
                dp[time][f]=max(dp[time][f],dp[time-1][i]+f);
            }

        }
    }
}
void solve()
{
start();
for(int i=2;i<=t;i++)
generate_dp(i);
}
int main() {
    fast

    cin >> v1>>v2;
    cin >> t >> d;
   solve();

   cout << dp[t][v2]<<endl;
    return 0;
}
