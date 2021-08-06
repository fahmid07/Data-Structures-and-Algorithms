#include<bits/stdc++.h>
using namespace std;

int n, s, e, t, x, y, c;
vector<pair<pair<int, int>, int>> graph;
int dist[100007];
int p[100007];
vector<int> path;

void bellmanFord(int s, int t){
    dist[s] = 0;
    p[s] = s;

    for(int j=0; j<n-1; j++){
        for(auto i:graph){
            if(dist[i.first.first] + i.second < dist[i.first.second]){
                dist[i.first.second] = dist[i.first.first] + i.second;
                p[i.first.second] = i.first.first;
            }
        }
    }

    for(auto i:graph){
        if(dist[i.first.first] + i.second < dist[i.first.second]){
            cout << "Negative cycle" << endl;
            return;
        }
    }

    path.push_back(t);
    int cr = t;
    while(cr!=s){
        cr = p[cr];
        path.push_back(cr);
    }
    reverse(path.begin(), path.end());
}

int main()
{
    for(int i=0; i<100007; i++) dist[i] = INT_MAX;

    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> x >> y >> c;
        graph.push_back({{x, y}, c});
    }

    bellmanFord(1, 5);
    for(auto i:path) cout << i << " ";
    cout << endl;

    return 0;
}
