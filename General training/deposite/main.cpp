#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
ll n ,a,b;
map<int,int>dp;
ll dpgenerate(int bank )
{//cout << bank << endl;
    if(bank<=0)
        return 0;
    if(dp.count(bank))
        return dp[bank];
    ll ret=0;
    dp[bank]=0;
    if(bank>=a)
    {if(dp.count(bank-a)==0)
        ret=max(ret,a+ dpgenerate(bank-a));}
    if(n-bank>b)
    {if(dp.count(bank+b)==0)
        ret=max(ret, -b+dpgenerate(bank+b));}
    return dp[bank]=ret;
}
int main() {
cin >> n >> a >>b;
cout << dpgenerate(n)<<endl;

    return 0;
}
