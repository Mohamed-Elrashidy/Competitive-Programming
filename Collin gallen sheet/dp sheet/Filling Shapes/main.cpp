#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
   fast;
   int n;
   cin >> n;
   long long dp[n+1];
   dp[1]=0;
   dp[2]=2;
   for(int i=3;i<=n;i++)
   {
       if(i%2)
           dp[i]=0;
       else
           dp[i]=dp[i-2]*2;
   }
   cout << dp[n]<<endl;
    return 0;
}
