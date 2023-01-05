#include <bits/stdc++.h>
using namespace std;
int n,m;
int grid[300][300];

map<int,int>column,line;
bool check()
{
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        set<int>l;
        for(int f=0;f<m;f++)
        {
            l.insert(line[grid[i][f]]);
        }
        if(l.size()!=1)
            flag=true;
    }
    //cout <<flag<<endl;
    for(int i=0;i<m;i++)
    {
        set<int>c;
        for(int f=0;f<n;f++)
        {
            c.insert(column[grid[f][i]]);
        }
        if(c.size()!=1)
            flag=true;
    }
    //cout << flag << endl;

    return flag;
}
int solvelines()
{
    int ans=0;
    for(int i=0;i<n;i++)
    {

        if(i!=line[grid[i][0]])
        {//cout << i << ' ' << grid[i][0]<<endl;
            ans++;

            for(int k=i;k<n;k++)
            {
            if(i==line[grid[k][0]])
            {


            for(int f=0;f<m;f++)
            {
             swap(grid[i][f],grid[k][f]);

            }
            break;
            }
            }
        }
    }
  //  cout << ans << endl;
    return ans;
}
int solvecolumn()
{
    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(i!=column[grid[0][i]])
        {

            ans++;
            for(int k=i;k<m;k++)
            {
                if(i==column[grid[0][k]])
                {
            for(int f=0;f<n;f++)
            {
                swap(grid[f][i],grid[f][k]);

            }}}
        }
    }
    return ans;
}
int main() {
    cin >> n>> m;
    int x=1;
    for(int i=0;i<n;i++)
    {
        for(int f=0;f<m;f++)
        {
            cin >> grid[i][f];
        column[x]=f;
        line[x]=i;
        x++;
        }
    }
    bool flag= check();
    if(flag)
    {
        cout << '*'<<endl;
    }
    else
    {
        int ans=0;
        ans+=solvelines();
        ans+=solvecolumn();
        cout << ans << endl;
    }
    return 0;
}
