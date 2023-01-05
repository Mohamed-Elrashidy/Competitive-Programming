#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {int n,k;
        cin >> n >> k;
        string s;
        cin >>s;
        int mn=n;
        int f=3;
        char checker[3][3]={'R','G','B',
                            'G','B','R',
                            'B','R','G'};
        while(f--)
        {int curr=0;
        for(int i=0;i<k;i++)
        {
         if(s[i]!=checker[f][i%3])
             curr++;
        }
        mn=min(mn,curr);
        int j=k;
        while(j<n)
        {
            if(s[j]!=checker[f][j%3])
                curr++;
            if(s[j-k]!=checker[f][(j-k)%3])
                curr--;
            mn=min(mn,curr);
            j++;
        }

        }
        cout << mn << endl;
    }
    return 0;
}
