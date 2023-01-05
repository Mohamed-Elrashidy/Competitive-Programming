#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll mod=1e9+7;
ll gcdextended(ll a,ll b,ll *x,ll *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }
    ll x1,y1;
    ll gcd= gcdextended(b%a,a,&x1,&y1);
    *x= y1-b/a*x1;
    *y=x1;
    return gcd;
}
ll modinverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdextended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    return res;

}
ll nCr(int n,int r)
{
    ll res=1;
    for(ll i=n;i>max(r,n-r);i--)
    {
        res=((res%mod)*(i%mod))%mod;
    }
    for(ll i=2;i<=min(r,n-r);i++)
    {
        res=((res%mod)*(modinverse(i,mod)%mod))%mod;

    }
    return res;
}
ll fact(int n)
{
    ll res=1;
    for(int i=2;i<=n;i++)
    {
        res=((res%mod)*i)%mod;
    }
    return res;
}
ll coun(int a,int b)
{//cout << a << " "<<b<<endl;
    ll res=1;
    for(int i=1;i<=min(a,b);i++)
    {
      //  cout << i << " //"<<endl;
      int ncra= nCr(a,i);
      int ncrb= nCr(b,i);
      int f=fact(i);
        res=((res%mod+((((ncra%mod)*(ncrb%mod))%mod)*((f%mod))%mod))%mod)%mod;
    }
    return res;
}

int main() {
 //   cout << nCr(2,2)<<endl;
int a,b,c;
cin >> a >>b>>c;
ll ans=coun(a,b);
//cout <<coun(a,b)<<endl;
ans=((ans%mod)*(coun(b,c)%mod))%mod;
//cout << coun(c,b)<<endl;
ans=((ans%mod)*(coun(a,c)%mod))%mod;
//cout <<coun(a,c)<<endl;
cout << ans << endl;

    return 0;
}
