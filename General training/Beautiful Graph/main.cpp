#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m;
long long mod=998244353;
vector<int> adj[3*100000+2];
map<int,long long>mp;
int  vis[3*100000+6];
bool viss[3*100000+6];
long long fastpower(int p)
{
    if(mp.count(p))
        return mp[p];
    if(p==1)
        return 2;
    if(p<=0)
        return 1;
    long long fir=(fastpower(p/2))%mod;
    long long sec=fastpower((p+1)/2)%mod;
    return mp[p]=((fir)*(sec))%mod;
}
bool isoddcycle(int parent,int number)
{
    bool flag=false;
    vis[parent]=number;
    for(auto i:adj[parent])
    {
        if(vis[i]!=0)
        {
            if((number-vis[i])%2==0)
                flag=true;

        }
        else if(vis[i]==0)
        {
          flag|=  isoddcycle(i,number+1);

        }
    }

    return flag;
}

pair<int,int> solve(int parent,bool parity)
{
    //true mean second number

    viss[parent]=true;
pair<int,int> ret={0,0};
 if(parity)
     ret.second=1;
 else ret.first=1;

 for(auto i:adj[parent])
 {
    if(!viss[i])
    {
        pair<int,int>f=solve(i,!parity);
        ret.first+=f.first;
        ret.second+=f.second;
    }

 }

 return ret;
}

int main() {
    fast
  int t;
  cin >> t;
  while(t--)
  {

      cin >> n>> m;
      for(int i=1;i<=n;i++)
      {viss[i]=false;
          vis[i]=0;
          adj[i].clear();}

      while(m--)
      {
          int x,y;
          cin >> x >> y;
          adj[x].push_back(y);
          adj[y].push_back(x);

      }
      bool flag=false;
      for(int i=1;i<=n;i++)
      {
          if(vis[i]==0)
              flag|=isoddcycle(i,1);
      }
      if(flag)
      {
          cout << 0<<endl;
      }
      else
      {
          long long ans=1;

          for(int i=1;i<=n;i++)
              if(!viss[i]&&adj[i].size()>0)
              {
                  pair<int,int> diff=solve(i,true);

                  long long curr=((fastpower(diff.first)%mod)+(fastpower(diff.second)%mod))%mod;
                  ans=((ans%mod)*(curr%mod))%mod;
              }
          else if(!viss[i])
              ans=((ans%mod)*3)%mod;

          cout << ans << endl;
      }

  }
    return 0;
}
