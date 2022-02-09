#include<bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define N 5
int n[107][107];
//vvi dist(107, vector<int>(107));



void floyd_warshall(vvi graph){
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(graph[i][j] > graph[i][k] + graph[k][i]){
                    graph[i][j] = graph[i][k] + graph[k][i];
                    n[i+1][j+1] = n[k+1][j+1];
                }
            }
        }
    }
}

vector<int> _path(int i, int j){
    vector<int> path;
    path.push_back(i);
    while(i!=j){
        i = n[i][j];
        path.push_back(i);
    }
    return path;

}

void printPath(int i, int j){
    if (n[i][j] == i) {
        return;
    }

    printPath(i, n[i][j]);
    cout << n[i][j] << " ";
}

int main()
{
    vvi graph{
              {0,5, INT_MAX, 9, 1},
              {5, 0, 2, INT_MAX, INT_MAX},
              {INT_MAX, 2, 0, 7, INT_MAX},
              {9, INT_MAX, 7, 0, 2},
              {1, INT_MAX, INT_MAX, 2, 0}
    };
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(graph[i-1][j-1] != 0 && graph[i-1][j-1]!=INT_MAX) n[i][j] = i;
            else n[i][j] = 0;
        }
    }
    floyd_warshall(graph);
    printPath(1, 4);
    return 0;
}
