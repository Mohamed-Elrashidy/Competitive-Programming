#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m,d,startrow,startcolumn,finishrow,finishcoloum;
int rowdir[4]={1,-1,0,0};
int columndir[4]={0 ,0,1,-1};
vector<vector<char>>mapdes;
vector<vector<int>>bfsresult;
vector<pair<int,int>>monspostion;
void getdata()
{
    cin >> n>> m>> d;
    mapdes.resize(n);
    bfsresult.resize(n);
    for(int i=0;i<n;i++)
    {
        for(int f=0;f<m;f++)
        {
            char x;
            cin >> x;
            bfsresult[i].push_back(-1);
            if(x=='S')
            {
                startrow=i;
                startcolumn=f;
            }
            if(x=='F')
            {
                finishrow=i;
                finishcoloum=f;
            }
            if(x=='M')
            {
                monspostion.push_back({i,f});
                bfsresult[i][f]=0;
            }
            mapdes[i].push_back(x);
        }
    }
}
void bfsmon()
{int row;
    int coulumn;
    queue<pair<int,pair<int,int>>>q;
    for(int pos=0;pos<monspostion.size();pos++)

{row=monspostion[pos].first;
   coulumn=monspostion[pos].second;

    q.push({0,{row,coulumn}});}
    while(q.size())
    {int state=q.front().first;
        row=q.front().second.first;
        coulumn=q.front().second.second;
       // cout << state << endl;
        q.pop();
        if(state==d)
        {
            continue;}
        for(int i=0;i<4;i++)
        {
            if(row+rowdir[i]<0||row+rowdir[i]>=n||coulumn+columndir[i]<0||coulumn+columndir[i]>=m)
                continue;
            else
            {
                if(bfsresult[row+rowdir[i]][coulumn+columndir[i]]==-1)
                {bfsresult[row+rowdir[i]][coulumn+columndir[i]]=state+1;
                    q.push({state+1,{row+rowdir[i],coulumn+columndir[i]}});
                }
            }
        }
    }
}
void monsterattack()
{

        bfsmon();

}
void bfssafe()
{
    int row=startrow;
    int coulumn=startcolumn;
    queue<pair<int,pair<int,int>>>q;
    q.push({-1,{row,coulumn}});
    while(q.size())
    {int state=q.front().first;
        row=q.front().second.first;
        coulumn=q.front().second.second;
        if(row==finishrow&&coulumn==finishcoloum)
            return;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(row+rowdir[i]<0||row+rowdir[i]>=n||coulumn+columndir[i]<0||coulumn+columndir[i]>=m)
                continue;
            else
            {
                if(bfsresult[row+rowdir[i]][coulumn+columndir[i]]==-1)
                {bfsresult[row+rowdir[i]][coulumn+columndir[i]]=state-1;
                    q.push({state-1,{row+rowdir[i],coulumn+columndir[i]}});
                }
            }
        }
    }

}
int main() {
fast
  getdata();

  monsterattack();
  if(bfsresult[finishrow][finishcoloum]!=-1||bfsresult[startrow][startcolumn]!=-1)
  {
      cout << -1<<endl;
  return 0;
  }
  bfssafe();
if(bfsresult[finishrow][finishcoloum]!=-1)
{
    cout << -1*bfsresult[finishrow][finishcoloum]-1<<endl;
}
else
    cout <<-1<< endl;


    return 0;
}
