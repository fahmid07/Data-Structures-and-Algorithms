#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int n, s, e, t, x, y, c;

vector<pair<int, pii>> graph;
int cost[107][107];
int parent[107];
vector<pii> mst;

int find(int r){
    if(parent[r] == r) return r;
    parent[r] = find(parent[r]);
    return parent[r];
}

void kruskal(){
    for(auto i:graph){
        if(find(i.second.first) != find(i.second.second)){
            parent[parent[i.second.first]] = parent[parent[i.second.second]];
            mst.push_back({i.second.first, i.second.second});
        }
    }
}

int main()
{
    for(int i=0; i<=107; i++) parent[i] = i;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> x >> y >> c;
        graph.push_back({c, {x, y}});
        //graph.push_back({c, {y, x}});
    }
    sort(graph.begin(), graph.end());
    kruskal();
    for(auto j:mst) cout << char(j.first+64) << " " << char(j.second+64) << endl;
    return 0;
}

/*

5 7
1 2 4
1 4 7
2 3 3
2 4 3
2 5 2
3 5 4
4 5 1

4 10
1 2 1
1 3 3
2 1 1
2 3 1
2 4 4
3 1 3
3 2 1
3 4 1
4 2 4
4 3 1
*/
