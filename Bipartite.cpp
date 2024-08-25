// Can we divide this graph in 2 equal parts so no node sharing same edge have same color?

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

vector<vector<ll>>vec1(N+1);
vector<bool>vis(N+1,0),color(N+1,0);

bool dfs(int node,int col){
    vis[node]=true;
    color[node]=col;

    for(auto child:vec1[node]){
        if(!vis[child]){
            if(dfs(child,!col)==false){
                return false;
            }
        }
        else if(color[node]==color[child]){
            return false;
        }
    }
    return true;
}

void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        vec1[x].push_back(y);
        vec1[y].push_back(x); 
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(!dfs(i,0)) flag=false;
        }
    }   
    if(!flag){
        cout<<"Suspicious bugs found!";
    }   
    else cout<<"No suspicious bugs found!";
    cout<<endl;
}

int main(){
    FAST;
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}