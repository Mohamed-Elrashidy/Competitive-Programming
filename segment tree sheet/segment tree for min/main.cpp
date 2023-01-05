#include <bits/stdc++.h>
using namespace std;
int N=1;
long long tree[4*100000];
void build()
{

    for(int i=N-1;i>0;i--)
    {//cout <<i<<2<< " "<< tree[i<<]<< " "<< tree[(i<<2)|1]<<endl;
        tree[i]=min(tree[i<<1],tree[(i<<1)|1]);
    }
}
long long segmenttreeans(int l,int r,int s,int e)
{
    // cout << l << " "<< r << " " << s <<  "  " << e << endl;
    if(l==r&&s<=l&&e>=r)
    {//cout << tree[N+l-1]<<endl;
        return tree[N+l-1];
    }
    if(s<=l&&e>=r)
    {
        int div=r-l+1;
        int node=N+l-1;
        while(div>1)
        {
            node>>=1;
            div>>=1;
        }
        // cout << tree[node]<<endl;
        return tree[node];
    }
    else if(s>r||l>e)
    {//cout << 0<< endl;
        return 1e18;}
    else {
        int mid=(l+r)>>1;
        return min(segmenttreeans(l,mid,s,e), segmenttreeans(mid+1,r,s,e));
    }

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
            tree[node]=min(min(tree[node<<1],tree[(node<<1)|1]),val);
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
    memset(tree,'?',sizeof tree);
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
        cin>> x>>y>>z;
        if(x==1)
        {
            updatenode(1,N,y+1,z);
        }
        else
        {
            cout << segmenttreeans(1,N,y+1,z)<<endl;
        }
        //  cout << " 1"<<endl;
    }
    return 0;
}
