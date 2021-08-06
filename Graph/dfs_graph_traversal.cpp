#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100];
int n, e;
int ara[10][10] = { { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                    { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
                    { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
                    { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
                    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                    { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0 },
                    { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
                    { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }
                                                    };


// using adjacency list
void dfs(int s){
    int visited[100]={0};
    stack<int> st;
    vector<int> vec;
    st.push(s);
    visited[s] = 1;

    while(!isEmpty(st)){
        int x = st.top();
        st.pop();
        cout << x << " ";
        for(int i=0; i<graph[x].size(); i++){
            if(!visited[graph[x][i]]){
                visited[graph[x][i]] = 1;
                vec.push_back(graph[x][i]);
                //st.push(st);
            }
        }
        reverse(vec.begin(), vec.end());
        for(auto k:vec) st.push(k);
        vec.clear();
    }
}

// using adjacency matrix
void _dfs(int s){
    int visited[100]={0};
    stack<int> st;
    vector<int> vec;
    st.push(s);
    visited[s] = 1;

    while(!isEmpty(st)){
        int x = st.top();
        st.pop();
        cout << x+1 << " ";
        for(int i=0; i<n; i++){
            if(!visited[i] && ara[i][x]){
                visited[i] = 1;
                vec.push_back(i);
                //st.push(i);
            }
        }
        reverse(vec.begin(), vec.end());
        for(auto k:vec) st.push(k);
        vec.clear();
    }
}

int main()
{
    int x, y, s;
    cin >> n >> e >> s;
                      //  1  2  3  4  5  6  7  8  9  10
    /*int ara[10][10] = { { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
                        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }
                                                        };*/

    /*for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ara[i][j]==1){
                graph[i+1].push_back(j+1);
                //graph[j+1].push_back(i+1);
            }
        }
    }*/

    for(int i=0; i<e; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << "\n";
    dfs(s);
    cout << "\n";
    _dfs(s);
    cout << "\n";

    return 0;
}
