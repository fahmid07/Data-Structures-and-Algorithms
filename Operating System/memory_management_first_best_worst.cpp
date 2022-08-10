#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, b, x;
    vector<int> request, block;

    cin >> r;
    for(int i=0; i<r; i++){
        cin >> x;
        request.push_back(x);
    }

    cin >> b;
    for(int i=0; i<b; i++){
        cin >> x;
        block.push_back(x);
    }

    cout << "\nFirst Fit\n";

    vector<int> first[r+7];
    vector<int> temp = block;
    int stopi = -1;

    for(int i=0; i<r; i++){
        for(int j=0; j<b; j++){
            if(request[i]<=temp[j]){
                temp[j] -= request[i];
                break;
            }
            else stopi = i;
        }
        first[i] = temp;
    }

    for(int i=0; i<r; i++) cout << request[i] << "\t";
    cout << endl;

    for(int j=0; j<b; j++){
        for(int i=0; i<r; i++){
            if(i!=stopi) cout << first[i][j] << "\t";
            else break;
        }
        cout << endl;
    }
    cout << endl;


    cout << "Best Fit\n";
    vector<int> best[r+7];
    temp = block;
    stopi = -1;

    for(int i=0; i<r; i++){
        int mn = INT_MAX, mnj = INT_MAX;
        for(int j=0; j<b; j++){
            if(request[i]<=temp[j]){
                if(temp[j]-request[i] < mn){
                    mn = temp[j]-request[i];
                    mnj = j;
                }
            }
        }
        if(mnj!=INT_MAX){
            temp[mnj] -= request[i];
        }
        else stopi = i;
        best[i] = temp;
    }

    for(int i=0; i<r; i++) cout << request[i] << "\t";
    cout << endl;

    for(int j=0; j<b; j++){
        for(int i=0; i<r; i++){
            if(i!=stopi) cout << best[i][j] << "\t";
            else break;
        }
        cout << endl;
    }

    cout << "Worst Fit\n";
    vector<int> worst[r+7];
    temp = block;
    stopi = -1;

    for(int i=0; i<r; i++){
        int mx = 0, mxj = INT_MAX;
        for(int j=0; j<b; j++){
            if(request[i]<=temp[j]){
                if(temp[j]-request[i] > mx){
                    mx = temp[j]-request[i];
                    mxj = j;
                }
            }
        }
        if(mxj!=INT_MAX){
            temp[mxj] -= request[i];
        }
        else stopi = i;
        worst[i] = temp;
    }

    for(int i=0; i<r; i++) cout << request[i] << "\t";
    cout << endl;

    for(int j=0; j<b; j++){
        for(int i=0; i<r; i++){
            if(i!=stopi) cout << worst[i][j] << "\t";
            else break;
        }
        cout << endl;
    }

    return 0;
}

/*
10
100 10 35 15 23 6 25 55 88 40
5
50 200 70 115 15
*/
