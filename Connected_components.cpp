// Call DFS() on every vertex of graph that isn't marked true and increase count when one DFS is fully traversed (Line 42)

#include <bits/stdc++.h>
using namespace  std;

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

vector<vector<int>>vec1(N);
vector<bool> visited(N,0);
 
void dfs(int vertex){
    visited[vertex]=true;
    // cout<<vertex<<" ";
    for(auto child:vec1[vertex]){
        if(!visited[child]){
            dfs(child);
        }
    }
}
 
void solve()
{
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;cin>>x>>y;
        vec1[x].push_back(y);
        vec1[y].push_back(x);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }
    cout<<count<<endl;
    
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