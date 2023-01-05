#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
const ll mod=10e9+7;

int main() {
    /* int p=48;
      for(int i=0;i<10;i++)
      {p=p+p%10;
      cout << p <<" ";
      }
      cout << endl;

      p=86;
      for(int i=0;i<100;i++)
      {p=p+p%10;
          cout << p <<" ";
      }
      cout << endl;*/
    fast
    int t;
    int round[9]={0,0,20,0,20,0,20,0,20};
    cin >> t;
    while(t--)
    {bool flag=false;
        int n;
        cin >> n;
        int a[n];
        set<int>st,fin;
        for(int i=0;i<n;i++)
        {

            int x;
            cin >> x;
            st.insert(x+x%10);
        }

        int x=0;
        for(auto i=st.begin();x<st.size()-1;i++)
        {
            int curr=*i;
//cout << curr << endl;
            if(*st.rbegin()-curr>round[curr%10]&&curr%10!=0)
            {
                curr=curr+round[curr%10]*((*st.rbegin()-curr)/round[curr%10]);
            }
            //  cout << curr << endl;

            fin.insert(curr);
            x++;
        }

        fin.insert(*st.rbegin());
        map<int,int>mp;

        for(auto i:fin)
        {int x=i;
            // cout << x << endl;
            for(int f=0;f<100;f++)
            {mp[x]++;
                if(mp[x]==fin.size())
                    flag=true;
                if(x%10==0)
                    break;
                x+=x%10;

            }
        }
        //   cout << mp[98]<<endl;
        if(flag)
            cout <<"Yes"<<endl;
        else
            cout <<"No"<<endl;
    }
    return 0;
}