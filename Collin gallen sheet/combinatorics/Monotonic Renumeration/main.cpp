#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
const int N=2*100000;
int orginal[N];

ll  const mod=998244353;
vector <pair<int,int>> intervals;
void getdata()
{
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> orginal[i];
    }
}
map<int,int>firstappear,lastappear;

void modifyintervals()

{
    for(auto i=firstappear.begin();i!=firstappear.end();i++)
    {
        intervals.push_back({i->second,lastappear[i->first]});
    }
}

void createintervals()
{
    for(int i=0;i<n;i++)
    {
        if(firstappear.count(orginal[i]))
        {
            lastappear[orginal[i]]=i;
        }
        else
            firstappear[orginal[i]]=i;
    }
    modifyintervals();

}
ll result(int n)
{
    ll ans =1;
    n=max(n,0);
    while(n--)
    {
        ans=(ans%mod *2)%mod;
        ans%=mod;
    }
    return ans;
}

ll numberofintervals() {
    ll numberofintervals = 0;
    if (intervals.size()) {
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i + 1].first <= intervals[i].second) {
                intervals[i + 1].second = max(intervals[i].second, intervals[i + 1].second);
            } else {
                numberofintervals++;
            }
        }


    }
    return numberofintervals;
}
ll solve()
{
    createintervals();
    return result( numberofintervals());
}
int main() {
    fast
    getdata();

    cout << solve()<<endl;
    return 0;
}
