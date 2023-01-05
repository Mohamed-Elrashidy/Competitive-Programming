#include <bits/stdc++.h>
using namespace std;
int N=1;
long long tree[4*100000];
void build()
{

    for(int i=N-1;i>0;i--)
    {//cout <<i<<2<< " "<< tree[i<<]<< " "<< tree[(i<<2)|1]<<endl;
        tree[i]=max(tree[i<<1],tree[(i<<1)|1]);
    }
}
long long segmenttreeans(int l,int r,int s)
{
    // cout << l << " "<< r << " " << s <<  "  "  << endl;
    if(l==r&&tree[N+l-1]>=s)
    {//cout << tree[N+l-1]<<endl;
        return l-1;
    }
    int mid=(l+r)>>1;
    int div=mid-l+1;
    int node=N+l-1;
    while(div>1)
    {
        div>>=1;
        node>>=1;
    }
    if(tree[node]>=s)
    {
        return segmenttreeans(l,mid,s);

    }
    else
        return segmenttreeans(mid+1,r,s);

}
void updatenode(int l,int r,int pos,long long val)
{
    if(l==r&&l==pos)
    {

        tree[N+l-1]=val;
        int node=N+l-1;
        while(node>0)
        {
            node>>=1;
            tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
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
  //  memset(tree,'?',sizeof tree);
    cin >> n;
    int q;
    cin >> q;
    while(n>N)
    {
        N<<=1;
    }
    int a[N];
    for(int i=0;i<n;i++)
        cin>> tree[i+N];
    build();

    while(q--)
    {
        int x,y,z;
        cin >> x;
        if(x==1)
        {cin >> y>>z;
            updatenode(1,N,y+1,z);
        }
        else
        {cin >> y;
            if(tree[1]<y)
                cout << -1 << endl;
            else
            cout << segmenttreeans(1,N,y)<<endl;
        }
        //  cout << " 1"<<endl;
    }
    return 0;
}
