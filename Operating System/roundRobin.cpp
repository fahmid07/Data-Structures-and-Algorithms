#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define pii  pair<lli, lli>


void solve(){
    lli n, art, brt, qt;
    string s;

    cin >> n >> qt;

    vector<pair<pii, lli>> vec;
    vector<pii> vec2(n+7);
    vector<pair<pii, pii>> ct_tat_wt_rt(n+7);
    queue<pair<pii, lli>> q;
    vector<pair<pii, lli>> gantt;
    vector<lli> visited(n+7, -1);

    while(n--){
        cin >> s >> art >> brt;
        vec.push_back({{art, brt}, s[1]-48});
        vec2[s[1]-48] = {art, brt};
    }

    sort(vec.begin(), vec.end());
    n = vec.size();

    lli cr = 0, j = 1, pr, p;
    double avg_tat = 0, avg_wt = 0;

    q.push(vec[0]);

    while(!q.empty()){
        p = q.front().second;
        art = q.front().first.first;
        brt = q.front().first.second;
        q.pop();

        if(visited[p]==-1){
            visited[p] = cr;
        }

        pr = cr;
        if(brt>=qt){
            brt -= qt;
            cr += qt;
            gantt.push_back({{pr, cr}, p});
        }
        else{
            cr += brt;
            brt = 0;
            gantt.push_back({{pr, cr}, p});
        }

        while(j<n && vec[j].first.first <= cr){
            q.push(vec[j]);
            j++;
        }

        lli rt, ct, tat, wt;

        if(brt==0){
            tat = cr - vec2[p].first;
            wt = tat - vec2[p].second;
            rt = visited[p] - vec2[p].first;
            ct_tat_wt_rt[p] = {{cr, tat}, {wt, rt}};

            avg_tat += tat;
            avg_wt += wt;
        }
        else{
            q.push({{art, brt}, p});
        }
    }

    cout << "\n";
    for(auto it:gantt){
        cout << "    P" << it.second << "\t";
    }
    cout << "\n";
    cout << "0";
    for(auto it:gantt){
        cout << "\t" << it.first.second;
    }
    cout << "\n\n";

    cout << "Process no.  Arrival  Burst Completing  TAT    WT \tRT\n";

    avg_tat /= n;
    avg_wt /= n;

    for(lli i=1; i<=n; i++){
        cout << "P" << i << " \t\t ";
        cout << vec2[i].first << " \t " << vec2[i].second << " \t ";
        cout << ct_tat_wt_rt[i].first.first << "\t" << ct_tat_wt_rt[i].first.second << "\t";
        cout << ct_tat_wt_rt[i].second.first << "\t" << ct_tat_wt_rt[i].second.second;
        cout << "\n";
    }

    cout << "\nAverage turn around time: " << avg_tat << "\n";
    cout << "Average waiting time: " << avg_wt << "\n";

}
int main()
{
    solve();
    return 0;
}

/*

4 2
P1 0 5
P2 1 4
P3 2 2
P4 4 1

5 2
P1 0 5
P2 1 3
P3 2 1
P4 3 2
P5 4 3
*/
