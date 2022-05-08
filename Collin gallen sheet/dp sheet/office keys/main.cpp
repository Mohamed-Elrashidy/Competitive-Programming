#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
int n_people,n_keys,dist;
int people[1001],keys[2001];
int dp[1001][2001];
void start()
{
    for(int i=0;i<n_keys;i++)
    {
        dp[0][i]=abs(people[0]-keys[i])+abs(dist-keys[i]);
        if(i>0)
            dp[0][i]=min(dp[0][i],dp[0][i-1]);
    }
}
void generate_min(int k)
{
    for(int i=k;i<n_keys;i++)
    {
        dp[k][i]=max(abs(people[k]-keys[i])+abs(dist-keys[i]),dp[k-1][i-1]);
        if(i>0)
            dp[k][i]=min(dp[k][i],dp[k][i-1]);
    }
}
void solve()
{
    start();
    for(int i=1;i<n_people;i++)
    {
        generate_min(i);
    }
}
int_fast32_t main() {
    cin >> n_people >> n_keys >> dist;
    for (int i = 0; i < n_people; i++)
        cin >> people[i];
    for (int i = 0; i < n_keys; i++)
        cin >> keys[i];
    sort(people, people + n_people);
    sort(keys, keys + n_keys);
    memset(dp, '?', sizeof dp);
    int ans = 2*1e9;

    solve();

 ans=dp[n_people-1][0];
    for(int i=0;i<n_keys;i++)
        ans=min(ans,dp[n_people-1][i]);
    cout << ans <<endl;
    return 0;
}
