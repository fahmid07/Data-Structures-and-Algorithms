#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int n, s, e, t, x, y, c;

vector<vector<pii>> graph(107);
int cost[107][107];
int visited[107]={0};
int dist[107];
int pr[107];
vector<pii> mst;

void prims(int s){
    priority_queue<pii> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = 1;
        mst.push_back({u, pr[u]});

        for(auto i:graph[u]){
            if(visited[i.second]) continue;
            if(i.first < dist[i.second]){
                pq.push({i.first*(-1), i.second});
                dist[i.second] = i.first;
                pr[i.second] = u;
            }
        }

    }
}

int main()
{
    for(int i=0; i<107; i++) dist[i] = INT_MAX;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> x >> y >> c;
        graph[x].push_back({c, y});
        graph[y].push_back({c, x});
    }
    prims(1);
    for(int i=0; i<n; i++){
        cout << dist[i] << endl;
        int q = i;
        while(pr[q]!=1){
            cout << " " << dist[q] << endl;
            q = pr[q];
        }
    }
    //for(auto j:mst) cout << j.first << " " << j.second << endl;
    return 0;
}

/*
6 9
1 2 6
1 5 5
2 5 7
2 3 1
5 3 8
5 4 14
3 4 9
4 6 3
3 6 2
*/
