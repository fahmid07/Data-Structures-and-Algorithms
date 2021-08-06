// Shortest Path - BFS

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> graph[100];
vector<int> path;
int n, e, t;
int visited[100]={0};
int dist[100], p[100];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    dist[s] = 0;
    p[s] = s;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<graph[x].size(); i++){
            if(!visited[graph[x][i]]){
                int v = graph[x][i];
                q.push(v);
                visited[v] = 1;
                dist[v] = dist[x] + 1;
                p[v] = x;
            }
        }
    }

    if(!visited[t]) return;

    path.push_back(t);
    int cr = t;
    while(cr!=s){
        cr = p[cr];
        path.push_back(cr);
    }
    reverse(path.begin(), path.end());
}

void solve(){
    int x, y, s;
    cin >> n >> e >> s >> t;

    for(int i=0; i<e; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        //graph[y].push_back(x);
    }

    bfs(s);
    for(auto i:path) cout << i << " ";
    cout << "\n";
}

int main()
{
    FAST
    solve();
    return 0;
}

/*
4 5 2 3
0 2
2 0
0 1
1 3
0 3
*/
