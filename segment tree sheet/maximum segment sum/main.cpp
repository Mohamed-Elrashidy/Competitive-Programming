#include <bits/stdc++.h>
using namespace std;
int N=1;
long long tree[4*100000],bestprefix[4*100000],bestsuffix[4*100000],bestsegment[4*100000];
void build()
{

    for(int i=N-1;i>0;i--)
    {//cout <<i<<2<< " "<< tree[i<<]<< " "<< tree[(i<<2)|1]<<endl;
        tree[i]=tree[i<<1]+tree[(i<<1)|1];
        bestsegment[i]=
                max({bestsegment[i<<1],
                     bestsegment[(i<<1)|1],
                     tree[i<<1]+bestprefix[(i<<1)|1],
                     tree[(i<<1)|1]+bestsuffix[i<<1],
                     bestsuffix[i<<1]+
                     bestprefix[(i<<1)|1]});
        bestprefix[i]=max(bestprefix[i<<1],tree[i<<1]+bestprefix[(i<<1)|1]);
        bestsuffix[i]=max(bestsuffix[(i<<1)|1],tree[(i<<1)|1]+bestsuffix[i<<1]);

    }
}

void updatenode(int l,int r,int pos,int val)
{
    if(l==r&&l==pos)
    {

        tree[N+l-1]=val;
        int node=N+l-1;
        bestsegment[node]=tree[node];
        bestprefix[node]=tree[node];
        bestsuffix[node]=tree[node];
        while(node>0)
        {
            node>>=1;
            tree[node]=tree[node<<1]+tree[(node<<1)|1];
            bestsegment[node]=
                    max({bestsegment[node<<1],
                         bestsegment[(node<<1)|1],
                         tree[node<<1]+bestprefix[(node<<1)|1],
                         tree[(node<<1)|1]+bestsuffix[node<<1],
                         bestsuffix[node<<1]+
                         bestprefix[(node<<1)|1]});
            bestprefix[node]=max(bestprefix[node<<1],tree[node<<1]+bestprefix[(node<<1)|1]);
            bestsuffix[node]=max(bestsuffix[(node<<1)|1],tree[(node<<1)|1]+bestsuffix[node<<1]);

        }

    }

    else if(pos<l||pos>r)
        return;
    else
    {
        int mid=(l+r)>>1;
        if(pos>=l&&pos<=mid)
        {
            updatenode(l,mid,pos,val);
        }
        else
        {
            updatenode(mid+1,r,pos,val);
        }
    }

}

int main() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    while(n>N)
    {
        N<<=1;
    }
    int a[N];
    for(int i=0;i<n;i++)
    {cin>> tree[i+N];
    bestsegment[i+N]=tree[i+N];
    bestprefix[i+N]=tree[i+N];
    bestsuffix[i+N]=tree[i+N];
    }
    build();
cout <<max((long long)0, bestsegment[1])<<endl;
    while(q--)
    {
      int x,y;
      cin >> x >> y;
      tree[N+x]=y;
      bestsegment[N+x]=y;
      bestsuffix[N+x]=y;
      bestprefix[N+x]=y;
        updatenode(1,N,x+1,y);
        cout <<max((long long)0, bestsegment[1])<<endl;

    }
    return 0;
}
