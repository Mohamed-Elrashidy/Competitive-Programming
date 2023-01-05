#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
int n;
const int N=3000;
ll fontsize[N];
ll cost[N];
ll maxfontsize[N][3];
ll mincost[N][3];
void getdata()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> fontsize[i];
    }
    for(int i=0;i<n;i++)
       cin >>  cost[i];
}
void intialize()
{
    maxfontsize[0][0]=fontsize[0];
    mincost[0][0]=cost[0];

    maxfontsize[1][0]=fontsize[1];
    mincost[1][0]=cost[1];
    if(fontsize[0]<fontsize[1])
    {
     maxfontsize[1][1]=max(fontsize[1],fontsize[0]);
     mincost[1][1]=cost[0]+cost[1];
    }
}
void  generatestate2(int state)
{bool flag=false;

    int mncost=1000000000;
    for(int i=state-1;i>=0;i--)
    {
       if(maxfontsize[i][0]<maxfontsize[state][0])
       {
           flag=true;
           if(mincost[i][0]<mncost)
           {
               mncost=mincost[i][0];

           }

       }
    }
    if(flag)
    {
        mincost[state][1]=cost[state]+mncost;
        maxfontsize[state][1]=fontsize[state];
    }
}
void  generatestate3(int state)
{bool flag=false;

    int mncost=1000000000;
    for(int i=state-1;i>=0;i--)
    {
        if(maxfontsize[i][1]<maxfontsize[state][0]&&maxfontsize[i][1]!=0)
        {
            flag=true;
            if(mincost[i][1]<mncost)
            {
                mncost=mincost[i][1];

            }

        }
    }
    if(flag)
    {
        mincost[state][2]=cost[state]+mncost;
        maxfontsize[state][2]=fontsize[state];
    }
}
void generatestate(int state)
{
    generatestate2(state);
    generatestate3(state);
}
void overallmincost()
{
for(int i=2;i<n;i++)
{
mincost[i][0]=cost[i];
maxfontsize[i][0]=fontsize[i];
    generatestate(i);
}
}
void printsolution()
{
    ll ans=-1;
    for(int i=0;i<n;i++)
    {
        if(mincost[i][2]>0)
        {
            if(ans==-1)
                ans=mincost[i][2];
            else
                ans=min(ans,mincost[i][2]);
        }
    }
    cout << ans << endl;
}

int main() {
    fast
getdata();
intialize();
overallmincost();
printsolution();
    return 0;
}
