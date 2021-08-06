// Number of component - BFS

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> graph[100];
int n, e;
int visited[100]={0};

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<graph[x].size(); i++){
            if(!visited[graph[x][i]]){
                visited[graph[x][i]] = 1;
                q.push(graph[x][i]);
            }
        }
    }
}

void solve(){
    int x, y, s, c = 0;
    cin >> n >> e;

    for(int i=0; i<e; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bfs(i);
            c++;
        }
    }

    cout << c << "\n";
}

int main()
{
    FAST
    solve();
    return 0;
}

/*
7 7
6 4
4 3
4 5
3 2
5 2
2 1
5 2
*/
