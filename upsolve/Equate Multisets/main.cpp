#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int> a,b;
int n;
void getdata()
{a.clear();
    b.clear();
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }

}
map<int,int>mp;
void divide()
{mp.clear();
   for(int i=0;i<n;i++)
   {

       while(!(a[i]&1))
       {
           a[i]>>=1;
       }
       mp[a[i]]++;
   }

}
bool modify()
{
sort(b.rbegin(),b.rend());
for(int i=0;i<n;i++)
{
 while(b[i]>=1)
 {
     if(mp.count(b[i]))
     {
         mp[b[i]]--;
         if(mp[b[i]]==0)
             mp.erase(b[i]);
         break;
     }
     else
     {b[i]/=2;

     }
 }
}
//cout << mp.size()<<endl;
if(mp.size()==0)
    return true;
return false;
}
bool solve()
{
   divide();
return     modify();
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        getdata();
        if (solve()) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }return 0;
}
