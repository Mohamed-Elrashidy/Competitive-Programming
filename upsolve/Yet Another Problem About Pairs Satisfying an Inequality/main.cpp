#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int const N=2*100000+1;
int n;
int valid [N];
int current=0;
int arr[N];
ll dp[N];
void getdata()
{current=0;
cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
}
void validpairs(int pos)
{

     dp[pos]=lower_bound(valid,valid+current,arr[pos])-valid;
}
void result()
{ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=dp[i];
    }
    cout << ans << endl;
}
void solve()
{
    for(int i=0;i<n;i++)
    {dp[i]=0;
        //cout << arr[i]<< " "<< i+1<<endl;
    if(arr[i]<i+1)
    {if(current>0)
        validpairs(i);
        valid[current]=i+1;

        current++;
        if(current>1&&valid[current-1]<valid[current-2])
        sort(valid,valid+current);
    }

    }
    result();
}
int main() {
    fast;
    int t;
    cin >> t;
    while(t--) {
        getdata();
        solve();

    }return 0;
}
