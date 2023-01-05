#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
char grid[100][100];
void getdata()
{
    cin >> n;
    for(int i=0;i<n;i++)
        for(int f=0;f<n;f++)
        {
            cin >> grid[i][f];
        }
}
int mini(int row,int coulmn)
{int coun=0;
if(grid[row][coulmn]=='1') // row 0 coulmn 1
    coun++;
if(grid[coulmn][n-1-row]=='1') //row 1 coulmn n-1;
    coun++;
int z=coulmn;

coulmn=n-1-row;
row = z;
if(grid[coulmn][n-1-row]=='1') //row  n-1 coulmn n-1-row
    coun++;
z=coulmn;
coulmn=n-1-row;
row=z;
if(grid[coulmn][n-row-1]=='1')
    coun++;
return min(coun,4-coun);

}
/*int secondarydiagonal(int row ,int coulmn)
{int coun=0;
    if(grid[row][coulmn]=='1')
coun++;
    if(grid[n-1-row][n-1-coulmn]=='1')
        coun++;
    return min(coun,2-coun);
}*/
int midline()
{int ans=0;
    int coulmn=n/2;

    for(int i=0;i<n/2;i++)
    { int coun=0;
if(grid[i][coulmn]=='1')
    coun++;
if(grid[n-1-i][coulmn]=='1')
    coun++;
if(grid[coulmn][n-i-1]=='1')
    coun++;
if(grid[coulmn][i]=='1')
    coun++;
ans+=min(coun,4-coun);

    }
    return ans;
}
int solve()
{int ans=0;
    int x;

    for(int i=0;i<n/2;i++)
    {
        for(int f=0;f<n/2;f++)
        {
            ans+=mini(i,f);
        }
    }
   /* for(int i=0;i<n;i++)
    {
        ans+=secondarydiagonal(i,n-1-i);
    }*/

    if(n%2)
    {
        ans+=midline();
    }
    return ans;
}
int main() {
    fast
    int t;
    cin >> t;
    while(t--)
    {
        getdata();
        cout << solve()<< endl;
    }

    return 0;
}
