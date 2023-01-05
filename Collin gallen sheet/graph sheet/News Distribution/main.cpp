#include <bits/stdc++.h>
using namespace std;
#define ll  long long
const int N =5*100000+2;
int n,m;
vector <int> groupitems;
bool connected[N];
vector<int> graph[N];
int groupsize[N];

void dfs(int parent)
{
    groupitems.push_back(parent);
    connected[parent]=true;
    for(int i=0;i<graph[parent].size();i++)
    {
        if(!connected[graph[parent][i]])
        {
           dfs(graph[parent][i]);
        }
    }

}



void getdata()
{
    cin >> n>> m;
    while(m--)
    {
        int sz;
        cin >> sz;
        int par=-1;
        while(sz--)
        {
            int x;
            cin >> x;
            if(par==-1)
            {
                par=x;
            }
            else
            {
              graph[x].push_back(par);
              graph[par].push_back(x);

            }
        }
    }
}
void modifysize()
{
    for(int i=0;i<groupitems.size();i++)
    {
        groupsize[groupitems[i]]=groupitems.size();
    }
    groupitems.clear();
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        if(!connected[i])
        {
            dfs(i);
            modifysize();
        }
    }

}
int main() {

    getdata();
    solve();
    for(int i=1;i<=n;i++)
    {
        cout << groupsize[i];
        if(i==n)
            cout << endl;
        else cout << " ";
    }
    return 0;
}
