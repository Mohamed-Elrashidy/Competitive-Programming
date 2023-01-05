#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<vector<int>>adjlist;
vector<bool>vis;

void dfs(int i){
    vis[i]=true;
    for(auto x:adjlist[i]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int main() {


    int n;
    cin>>n;
    map<int,int>mp;
    adjlist.resize(n+1);
    vis.resize(n+1,0);
    vector<pair<pair<int,int>,vector<int>>>v(n);
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        v[i].first.first=c;
        v[i].second.resize(c);
        v[i].first.second=i+1;
        for(int j=0;j<c;j++){
            int a;
            cin>>a;
            mp[a]++;
            v[i].second[j]=a;
        }
    }
    sort(v.rbegin(),v.rend());
    set<pair<int,int>>res;
    bool flg=false;
    int root;
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].first.first;j++){
            if(!flg){
                flg=true;
                root=v[i].first.second;
            }

            if(mp[v[i].second[j]]==1){

                res.insert({v[i].first.second,v[i].second[j]});
                adjlist[v[i].first.second].push_back(v[i].second[j]);
//                adjlist[v[i].second[j]].push_back(v[i].first.second);
                mp[v[i].second[j]]--;
            }else{
                mp[v[i].second[j]]--;
            }

        }
    }
    dfs(root);
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            flag=false;
            break;
        }
    }
    if(res.size()==n-1&&flag) {
        cout << "YES" << endl;
        for (auto re:res) {
            cout << re.first << " " << re.second << endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}