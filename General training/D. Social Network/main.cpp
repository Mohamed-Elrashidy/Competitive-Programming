#include <bits/stdc++.h>

using namespace std;
multiset<int>st;
int n,m;
int dsuParents[1003];
int dsuSize[1003];
 int check(int x)
{
    vector<int>vec;
    while(dsuParents[x]!=x)
    {
        vec.push_back(x);
        x=dsuParents[x];
    }
    for (int i=0;i<vec.size();i++)
    {
        dsuParents[vec[i]]=x;
    }
    return x;
}

void combine(int x,int y)
{//cout << st.size()<<endl;
    if(dsuSize[x]>dsuSize[y])
    {auto k=st.lower_bound(dsuSize[y]);

    st.erase(k);
    k=st.lower_bound(dsuSize[x]);
    st.erase(k);
        dsuSize[x]+=dsuSize[y];
        st.insert(dsuSize[x]);
        dsuParents[y]=x;
    }
    else
    { auto k=st.lower_bound(dsuSize[y]);
    //cout << 4 << endl;
    st.erase(k);
  //  cout << 4 << endl;
    k=st.lower_bound(dsuSize[x]);
   // cout << *k << endl;
   //cout << st.size()<<endl;
    st.erase(k);
    //cout << 4 <<endl;
   // cout << 4 <<endl;
        dsuSize[y]+=dsuSize[x];
          st.insert(dsuSize[y]);
        dsuParents[x]=y;

    }
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;

for(int i=0;i<=n;i++)
{
    dsuParents[i]=i;
    dsuSize[i]=1;
    st.insert(1);
}int coun=0;
while(m--)
{
    int x, y;
    cin >> x >> y;
    int z=check(x);
    int k=check(y);
    //cout << z << " "  << k <<endl;
    if(k!=z)
    combine(k,z);
    else coun++;
//cout << "here"<<endl;
    int ch=0;
    int ans=0;
    for (auto i=st.rbegin();i!=st.rend();i++)
    {
        ans+=*i;
        if(ch==coun)
            break;
        ch++;
       // cout << 1 << endl;
    }
cout << ans-1 << endl;

}

    return 0;
}
