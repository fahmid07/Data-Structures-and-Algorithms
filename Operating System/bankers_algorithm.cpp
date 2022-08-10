#include<bits/stdc++.h>
using namespace std;

int main(){
    int p, r, x;

    cin >> p >> r;

    vector<int> allocation[p+7];
    vector<int> maximum[p+7];
    vector<int> available[p+7];
    vector<int> need[p+7];

    vector<int> sequence;


    vector<int> maxR;
    vector<int> avR(r+7, 0);
    for(int i=0; i<r; i++){
        cin >> x;
        maxR.push_back(x);
    }

    for(int i=0; i<p; i++){
        vector<int> temp;
        for(int j=0; j<r; j++){
            cin >> x;
            temp.push_back(x);
            avR[j] += x;
        }
        allocation[i] = temp;
    }

    for(int i=0; i<p; i++){
        vector<int> temp;
        for(int j=0; j<r; j++){
            cin >> x;
            temp.push_back(x);
        }
        maximum[i] = temp;
    }

    for(int i=0; i<p; i++){
        vector<int> temp;
        for(int j=0; j<r; j++){
            x = maximum[i][j] - allocation[i][j];
            temp.push_back(x);
        }
        need[i] = temp;
    }

    for(int i=0; i<r; i++){
        x = avR[i];
        avR[i] = maxR[i] - x;
    }

    int visited[p+7] ={0};
    for(int i=0; i<p; i++){
        int indx = -1;
        for(int j=0; j<p; j++){
            if(visited[j]==0){
                int flag = 0;
                for(int q=0; q<r; q++){
                    if(need[j][q] <= avR[q]) continue;
                    else{
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){
                    indx = j;
                    break;
                }
            }
        }
        if(indx!=-1){
            visited[indx] = 1;
            sequence.push_back(indx);
            for(int k=0; k<r; k++){
                avR[k] += allocation[indx][k];
            }
        }
    }

    if(sequence.size()!=p) cout << "The system is currently not in safe state" << endl;
    else{
        cout << "The system is currently in safe state" << endl;
        for(int i=0; i<sequence.size(); i++) cout << "P" << sequence[i] << " ";
        cout << endl;
    }

    return 0;
}

/*

5 3
10 5 7
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3

5 4
3 17 16 12
0 1 1 0
1 2 3 1
1 3 6 5
0 6 3 2
0 0 1 4
0 2 1 0
1 6 5 2
2 3 6 6
0 6 5 2
0 6 5 6

4 5
3 17 16 12
0 1 1 0
1 2 3 1
1 3 6 5
0 6 3 2
0 0 1 4
0 2 1 0
1 6 5 2
2 3 6 6
0 6 5 2
0 6 5 6

5 4
3 17 16 12
0 1 1 0 0 2 1 0
1 2 3 1 1 6 5 2
1 3 6 5 2 3 6 6
0 6 3 2 0 6 5 2
0 0 1 4 0 6 5 6






*/
