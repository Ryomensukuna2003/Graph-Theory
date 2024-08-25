// Single source shortest path only works on tree not on graph
// Given vertex V1. Find shortest distance from V1 to every vertex
#include <bits/stdc++.h>
using namespace std;

//                                「本 物 の 柔 術 を 見 せ て や る」

#define vll      vector<long long int>
#define ll       long long
#define pb       push_back
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;
const ll inf = 2e18;
#define all(x)   (x).begin(), (x).end()
#define FAST     ios_base ::sync_with_stdio(false); cin.tie(NULL)
#define forin(x,y) for(auto i=0;i<x;i++){int x;cin>>x;y.pb(x);}
#define forout(x)  for(auto y:x){cout<<y<<' ';}
#define value_sort(v) sort(all(v),[](auto &l,auto &r){return l.second<r.second;});

vector<vector<ll>>vec1(N);
vector<pair<int,int>>visited(N,{0,0});

void dfs(int vertex,int pos){
    visited[vertex].first=true;
    visited[vertex].second=pos;
    for(auto child:vec1[vertex]){
        if(!visited[child].first){
            dfs(child,(visited[vertex].second+1));
        }
    }
}

void solve()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        vec1[x].push_back(y);
        vec1[y].push_back(x);
    }
    for(int i=1;i<=m+1;i++){
        cout<<i<<"-> ";
        for(int j=0;j<vec1[i].size();j++){
            cout<<vec1[i][j]<<" ";
        }
        cout<<endl;
    }
    dfs(1,0);
    cout<<endl;
    for(int i=1;i<=m+1;i++){
        cout<<i<<"-> "<<visited[i].second<<endl;
    }

}

int main(){
    FAST;
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

