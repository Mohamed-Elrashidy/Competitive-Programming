#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n>>m;
    int a[n-1];
    for(int i=0;i<n-1;i++)
        cin >> a[i];
    int i=0;
    bool flag=false;
    while(i<n-1)
    {
        if(i+1==m)
            flag=true;
        i+=a[i];
    }
    if(i+1==m)
        flag=true;
    if(flag)
        cout <<"YES"<<endl;
    else cout << "NO"<<endl;

    return 0;
}
