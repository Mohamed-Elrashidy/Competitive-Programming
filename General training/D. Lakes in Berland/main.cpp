/*prolem link : https://codeforces.com/contest/723/problem/D*/

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
char orgrid[50][50],mogrid[50][50];
bool vis[50][50];
multimap<int,pair<int,int>>lake_size;
int n,m,k;
int transitionx []={1,-1,0,0};
int transitiony []={0,0,1,-1};

void del_mo(int x,int y)
{
    queue <pair<int,int>>q;
    q.push({x,y});
    mogrid[x][y]='*';
    while(q.size())
    {
        int a=q.front().first,b=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {if((a+transitionx[i]<0||a+transitionx[i]>=n)||b+transitiony[i]<0||b+transitiony[i]>=m)
                continue;
            if(mogrid[a+transitionx[i]][b+transitiony[i]]=='.')
            {
                mogrid[a+transitionx[i]][b+transitiony[i]]='*';
                q.push({a+transitionx[i],b+transitiony[i]});
            }
        }
    }
}
void del_or(int x,int y)
{
    queue <pair<int,int>>q;
    q.push({x,y});
    orgrid[x][y]='*';
    while(q.size())
    {
        int a=q.front().first,b=q.front().second;

        q.pop();
        for(int i=0;i<4;i++)
        {if((a+transitionx[i]<0||a+transitionx[i]>=n)||b+transitiony[i]<0||b+transitiony[i]>=m)
                continue;
            if(orgrid[a+transitionx[i]][b+transitiony[i]]=='.')
            {
                orgrid[a+transitionx[i]][b+transitiony[i]]='*';
                q.push({a+transitionx[i],b+transitiony[i]});
            }
        }
    }
}
void modify_grid()
{
    for(int i=0;i<n;i++)
    {
        if(mogrid[i][0]=='.')
        {
            del_mo(i,0);

        }
        if(mogrid[i][m-1]=='.')
        {
            del_mo(i,m-1);

        }


    }
    for(int i=0;i<m;i++)
    {
        if(mogrid[0][i]=='.')
        {
            del_mo(0,i);

        }
        if(mogrid[n-1][i]=='.')
        {
            del_mo(n-1,i);

        }

    }
}
int calc (int x,int y)
{int ans =1;
    queue<pair<int,int>>q;
    vis[x][y]=true;
    q.push({x,y});
    while(q.size())
    {
        int a=q.front().first,b=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {if((a+transitionx[i]<0||a+transitionx[i]>=n)||b+transitiony[i]<0||b+transitiony[i]>=m)
                continue;
            if(mogrid[a+transitionx[i]][b+transitiony[i]]=='.'&&!vis[a+transitionx[i]][b+transitiony[i]])
            {ans++;
                vis[a+transitionx[i]][b+transitiony[i]]=true;
                q.push({a+transitionx[i],b+transitiony[i]});
            }
        }
    }
    return ans;
}
void calc_lake_size()
{
    for(int i=0;i<n;i++)
    {
        for(int f=0;f<m;f++)
        {
            if(mogrid[i][f]=='.'&&!vis[i][f])
            {
                int val= calc(i,f);
                lake_size.insert({val,{i,f}});
            }
        }
    }
}


int main() {
    cin >> n>> m>>k;
    for (int i=0;i<n;i++)
    {
        for (int f=0;f<m;f++)
        {
            cin >> orgrid[i][f];
            mogrid[i][f]=orgrid[i][f];
        }
    }

    modify_grid();
//cout <<"Here"<<endl;
    calc_lake_size();


    int no=0;
    while(lake_size.size()>k)
    {
        int x=lake_size.begin()->second.first;
        int y=lake_size.begin()->second.second;
no+=lake_size.begin()->first;
        del_or(x,y);
        lake_size.erase(lake_size.begin());
    }
    cout << no <<endl;
    for(int i=0;i<n;i++)
    {
        for (int f=0;f<m;f++)
        {
            cout << orgrid[i][f];
        }
        cout << endl;
    }


    return 0;
}
