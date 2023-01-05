#include <bits/stdc++.h>
using namespace std;
int N=1;
long long tree[4*100000];
void build(int a[])
{

    for(int i=N-1;i>0;i--)
    {//cout <<i<<2<< " "<< tree[i<<]<< " "<< tree[(i<<2)|1]<<endl;
        tree[i]=tree[i<<1]+tree[(i<<1)|1];
    }
}
long long segmenttreeans(int l,int r,int s)
{
    // cout << l << " "<< r << " " << s  << endl;
    if(l==r&&s==1)
    {//cout << tree[N+l-1]<<endl;
        return l-1;}
    else if(l==r)
        return -1;

    int mid=(l+r)>>1;
    int node=mid+N-1;
    int dif=mid-l+1;
    while(dif>1)
    {
        node>>=1;
        dif>>=1;
    }
  //  cout << node<<" "<<tree[node] << endl;

 if(tree[node]<s)
 {
     return segmenttreeans(mid+1,r,s-tree[node]);
 }
 else return segmenttreeans(l,mid,s);

}
void updatenode(int l,int r,int pos,int val)
{
    if(l==r&&l==pos)
    {
        int dif=val-tree[N+l-1];
        tree[N+l-1]=val;
        int node=N+l-1;
        while(node>0)
        {
            node>>=1;
            tree[node]+=dif;
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
        cin>> tree[i+N];
    build(a);

    while(q--)
    {
        int x,y;
        cin>> x>>y;
        if(x==1)
        {
            if(tree[N+y]==1)
            updatenode(1,N,y+1,0);
            else
                updatenode(1,N,y+1,1);

        }
        else
        {
            cout << segmenttreeans(1,N,y+1)<<endl;
        }
        //  cout << " 1"<<endl;
    }
    return 0;
}
