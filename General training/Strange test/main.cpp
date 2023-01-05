#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int countbits(int x)
{int coun=0;
    while(x)
    {x>>=1;
        coun++;
    }
    return coun;
}
ll solve(int a,int b)
{
    int ans=0;
   int coun= countbits(b);
   for(int i=coun;i>=0;i--)
   {
       if((b&(1<<i)))
           ans^=(1<<i);
       else if((a&(1<<i)))
       {
           ans^=(1<<i);
           break;
       }
   }//cout << ans << endl;
   return ans;

}
int main() {
    int t;
    cin>>t;
    while(t--) {
       int a,b;
       cin >> a>>b;

       ll ans=1-b-a;
       set<int>st;
       st.insert(b-a+-1*(1-b-a));
       for(int i=a;i<=b;i++)
       {int b1=solve(i,b);
           st.insert(i+(i|b1));
       }
     //  cout << *st.begin()<<endl;
    cout << *st.begin()+ans<<endl;
    }

    return 0;
}
