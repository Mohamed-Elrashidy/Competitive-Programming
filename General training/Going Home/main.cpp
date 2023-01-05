#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m;
ll a[200001];
int main()
{fast
int t;
    cin >> t;
    while(t--){

      cin>> n>>m;
      for(int i=0;i<m;i++)
      {
          cin >> a[i];
      }
      sort(a,a+m);
      if(m==1)
          cout << min(2,n) << endl;
      else
      {
          a[m]=a[0]+n;
        vector<int>ranges;
          for(int i=0;i<m;i++)
          {
              ranges.push_back(a[i+1]-a[i]-1);
          }
          ll ans=m;
          sort(ranges.rbegin(),ranges.rend());
int cnt=0;
          for(int i=0;i<ranges.size();i++)
          {ans+= min(ranges[i],cnt*2);
              ranges[i]=max(0,ranges[i]-cnt*2);

              if(ranges[i]>1)
              {cnt++;
                  ans++;}
              cnt++;
          }
          cout << ans << endl;
      }
    }

    return 0;
}