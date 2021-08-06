#include<bits/stdc++.h>
using namespace std;


vector<int> graph[107];
//vector<vector<int>> cost(107, vector<int>(107));
int cost[107][107];
vector<int> path;
int dist[107], p[107];

void dijkstra(int s, int t){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(s);
    dist[s] = 0;
    p[s] = s;

    while(!pq.empty()){
        int u = pq.top();
        pq.pop();

        for(int i=0; i<graph[u].size(); i++){
            if(dist[u] + cost[u][graph[u][i]] < dist[graph[u][i]]){
                dist[graph[u][i]] = dist[u] + cost[u][graph[u][i]];
                pq.push(graph[u][i]);
                p[graph[u][i]] = u;
            }
        }
    }

    if(dist[t] != INT_MAX){
        path.push_back(t);
        int cr = t;
        while(cr!=s){
            cr = p[cr];
            path.push_back(cr);
        }
        reverse(path.begin(), path.end());
    }
}

int main()
{
    int n, s, e, t, x, y, c;
    for(int i=0; i<107; i++) dist[i] = INT_MAX;

    cin >> n >> e >> s >> t;
    for(int i=0; i<e; i++){
        cin >> x >> y >> c;
        graph[x].push_back(y);
        cost[x][y] = c;
        graph[y].push_back(x);
        cost[y][x] = c;
    }

    dijkstra(s, t);

    //for(int i=1; i<=n; i++) cout << dist[i] << endl;
    if(dist[t]!=INT_MAX){
        for(auto i:path) cout << i << " ";
        cout << endl;
    }
    else cout << "-1" << endl;

    return 0;
}
