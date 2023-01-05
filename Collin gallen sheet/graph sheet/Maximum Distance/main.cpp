#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
int a[3];
ll dp[5001][5001];// CPP program To calculate The Value Of nCr
#include <bits/stdc++.h>
using namespace std;

int fact(int n);

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
int fact(int n)
{
    if(n==0)
        return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

// Driver code


void generatedp()
{

}
ll count (int x ,int y)
{
    ll poweredges(min(x,y));
}
int main() {
cout << nCr(100,10)<<endl;
    for(int i=0;i<3;i++)
        cin >> a[i];
    sort(a,a+3);
  /* ll ans=count(a[0],a[1]);
   ans=ans*count(a[1],a[2]);
   ans= ans*count(a[0],a[2]);
cout << ans << endl;*/
    return 0;
}
