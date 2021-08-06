#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int n, s, e, t, x, y, c;

vector<vector<pii>> graph(100007);
int dist[100007];
int p[100007];
vector<int> path;

void dijkstra(int s, int t){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({s, 0});
    dist[s] = 0;
    p[s] = s;

    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();

        for(auto i:graph[u]){
            if(dist[u] + i.second < dist[i.first]){
                dist[i.first] = dist[u] + i.second;
                pq.push({i.first, dist[i.first]});
                p[i.first] = u;
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
    for(int i=0; i<100007; i++) dist[i] = INT_MAX;

    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> x >> y >> c;
        graph[x].push_back({y, c});
    }

    dijkstra(1, 5);
    for(auto i:path) cout << i << " ";
    cout << endl;

    return 0;
}
