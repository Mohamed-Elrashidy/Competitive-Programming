#include <bits/stdc++.h>

using namespace std;


int main()
{ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
   int n,l,k;
cin >> n >> l >>k;
int a[n+1],b[n];
for (int i=0;i<n;i++)
{
    cin >> a[i];
}
a[n]=l;

for (int i=0;i<n; i++)
    cin >>b[i];

   int dp[n+1][k+1];
   memset(dp,'?',sizeof dp);
dp[0][0]=0;
for(int i=1;i<=n;i++)
{
    for(int j=0;j<=k;j++)
    {//cout << i << ' '<< j <<endl;
       // cout << (a[i]-a[i-1-j])*b[i-1-j]<<endl;

       {for (int f=0;f<=min(j,i-1);f++)
       {
           dp[i][j]=min(dp[i][j],dp[i-1-f][j-f]+(a[i]-a[i-1-f])*b[i-1-f]);
       }

            }
    }
}

int ans = dp[n][0];
for(int i=0;i<=k;i++)
{ans=min(ans,dp[n][i]);

}
cout << ans <<endl;
    return 0;
}
/*cout << dp[i-1-j][j]<<endl;
        dp[i][j]=min(dp[i][j],dp[i-1-j][j]+(a[i]-a[i-1-j])*b[i-1-j]);
        cout << dp[i][j]<<endl;*/
