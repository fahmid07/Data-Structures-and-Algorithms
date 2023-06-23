// UVA 572 - Oil Deposits
// DFS - Number of connected components

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
typedef unsigned long long ul;

#define pii  pair<lli, lli>
#define PI acos(-1.0)
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define YES cout << "YES" << "\n";
#define NO cout << "NO" << "\n";
#define yes cout << "Yes" << "\n";
#define no cout << "No" << "\n";
#define mnp cout << "-1" << "\n";
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SORT(vec) sort(vec.begin(),vec.end())
#define CLR(vec) vec.clear()
#define REV(vec) reverse(vec.begin(),vec.end())
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))

vector<lli> adj[200000];

vector<bool> visited(200000);

void dfs(lli v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

void solve(){
    while(true){
    lli n, m, x, y;
    cin >> m >> n;
    if(m==0) break;

    lli ara[107][107];

    char ch;
    for(lli i=1; i<=m; i++){
        for(lli j=1; j<=n; j++){
            cin >> ch;
            if(ch=='*') ara[i][j] = 0;
            else ara[i][j] = 1;
        }
    }
    map<lli, lli> mm;
    for(lli i=1; i<=m; i++){
        for(lli j=1; j<=n; j++){
            if(ara[i][j]==0) continue;
            x = i*1000;
            x += j;

            mm[x]++;
            lli mi = i-1;
            lli pi = i+1;

            lli mj = j-1;
            lli pj = j+1;

            if(mi>=1 && ara[mi][j]==1){
                y = mi*1000;
                y += j;

                adj[x].push_back(y);
                adj[y].push_back(x);
                mm[y]++;
            }

            if(pi<=m && ara[pi][j]==1){
                y = pi*1000;
                y += j;

                adj[x].push_back(y);
                adj[y].push_back(x);
                mm[y]++;
            }

            if(mj>=1 && ara[i][mj]==1){
                y = i*1000;
                y += mj;

                adj[x].push_back(y);
                adj[y].push_back(x);
                mm[y]++;
            }

            if(pj<=n && ara[i][pj]==1){
                y = i*1000;
                y += pj;

                adj[x].push_back(y);
                adj[y].push_back(x);
                mm[y]++;
            }

            if(mi>=1 && mj>=1 && ara[mi][mj]==1){
                y = mi*1000;
                y += mj;

                adj[x].push_back(y);
                adj[y].push_back(x);
                mm[y]++;
            }

            if(mi>=1 && pj<=n && ara[mi][pj]==1){
                y = mi*1000;
                y += pj;

                adj[x].push_back(y);
                adj[y].push_back(x);
                mm[y]++;
            }

            if(pi<=m && mj>=1 && ara[pi][mj]==1){
                y = pi*1000;
                y += mj;

                adj[x].push_back(y);
                adj[y].push_back(x);
                mm[y]++;
            }

            if(pi<=m && pj<=n && ara[pi][pj]==1){
                y = pi*1000;
                y += pj;

                adj[x].push_back(y);
                adj[y].push_back(x);
                mm[y]++;
            }
        }
    }
    lli cnt = 0;
    for(auto it:mm){
        visited[it.first] = false;
    }
    for(auto it:mm){
        //cout << it.first << endl;
        if(!visited[it.first]){
            //yes
            //cout << it.first << endl;
            dfs(it.first);
            cnt++;
        }
    }
    cout << cnt << endl;
    for(auto it:mm) adj[it.first].clear();
    }
}


int main()
{
    FAST

    lli t;

    /*cin >> t;
    while(true){
        solve();
    }*/
    solve();

    return 0;
}

