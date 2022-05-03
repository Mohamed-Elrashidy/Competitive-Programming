#include <bits/stdc++.h>

using namespace std;

int main()
{
int t;
cin >> t;
while(t--)
{

long long a,b,c;
cin >> a >> b>> c;
bool flag=false;
while(a>0&&b>0)
{if(c==a||c==b)
flag=true;
    if(b>a)
        swap(a,b);
    if(a>=c&&c>=b)
    {
        if(a%b==c%b)
        {
            flag=true;
        }
    }
    a=a%b;

}
if(flag)
    cout <<"YES"<<endl;
else cout<<"NO"<<endl;
}

return 0;
}
