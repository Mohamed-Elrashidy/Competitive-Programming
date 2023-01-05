#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int>tap,result;
int n,m;
bool flag;
map<vector<int>,int>mp;
void solve()
{
//    cout << tap.size()<<endl;
//for(int i=0;i<tap.size();i++)
//    cout << tap[i]<< " ";
//cout << endl;

    if(mp.count(tap))
        return;
    mp[tap]++;

    if(tap.size()<result.size())
        return ;
    if(flag)
        return ;


    if(tap==result)
        flag=true;

    vector<int> curr=tap;
    reverse(tap.begin(),tap.end());

    solve();
    tap=curr;
    for(int i=(tap.size()-1)/2;i<tap.size();i++)
    {
        int k=i;

for(int f=i+1;f<tap.size()&&k>=0;f++)
{
    tap[k]+=tap[f];
k--;
}
//cout << i+1<<endl;
//        for(int d=0;d<tap.size();d++)
//            cout << tap[d]<< " ";
//        cout <<endl;
        while(tap.size()>i+1)
            tap.pop_back();
solve();
tap=curr;
    }



}

int main() {
    cin >> n;
    for(int i=0;i<n;i++)
    {
       int x;
       cin >> x;
       tap.push_back(x);
    }
    int x;
    cin >> m ;
    for(int i=0;i<m;i++)
    {

       cin >> x ;

       result.push_back(x);
    }

    solve();
    if(flag)
        cout << "S"<<endl;
    else cout <<"N"<<endl;

    return 0;
}

