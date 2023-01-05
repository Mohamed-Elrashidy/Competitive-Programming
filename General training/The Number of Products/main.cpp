#include <bits/stdc++.h>
using namespace std;

int main() {
 int n;
 cin >> n;
 int a[n];
 long long positive=0,negative=0;
 int last=-1;
 vector<int>negposition;
 for(int i=0;i<n;i++)
 {
     cin >> a[i];
     if(a[i]<0)
     {
         last=i;
         negposition.push_back(i);
     }
 positive+=i-last;

 }
negposition.push_back(n);
 long long revisitedval[negposition.size()];
 if(negposition.size()>1)
 {
     revisitedval[0]=negposition[0]+1;
     negative+=revisitedval[0]*(negposition[1]-negposition[0]);
 }
 if(negposition.size()>2)
 {
     revisitedval[1]=negposition[1]-negposition[0];
     positive+=(revisitedval[0])*(negposition[2]-negposition[1]);
     negative+=revisitedval[1]*(negposition[2]-negposition[1]);
 }
 if(negposition.size()>3)
 {
     revisitedval[2]=negposition[2]-negposition[1]+revisitedval[0];
     positive+=revisitedval[1]*(negposition[3]-negposition[2]);
     negative+=revisitedval[2]*(negposition[3]-negposition[2]);
 }
 for(int i=3;i<negposition.size()-1;i++)
 {
     revisitedval[i]=negposition[i]-negposition[i-1]+revisitedval[i-2];
     positive+=revisitedval[i-1]*(negposition[i+1]-negposition[i]);
     negative+=revisitedval[i]*(negposition[i+1]-negposition[i]);
 }

 cout << negative<<" "<< positive<<endl;
    return 0;
}
