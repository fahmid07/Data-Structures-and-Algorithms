#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define pii  pair<lli, lli>


void solve(){
    lli n, art, brt, qt, prio;
    string s;

    cin >> n;
    qt = 1;

    vector<pair<pii, pii>> vec;
    vector<pii> vec2(n+7);
    vector<pair<pii, pii>> ct_tat_wt_rt(n+7);
    priority_queue<pair<pii, pii>> pq;
    vector<pair<pii, lli>> gantt;
    vector<lli> visited(n+7, -1);

    while(n--){
        cin >> prio >> s >> art >> brt;
        vec.push_back({{art, brt}, {prio, s[1]-48}});
        vec2[s[1]-48] = {art, brt};
    }

    sort(vec.begin(), vec.end());
    n = vec.size();

    lli temp = vec[0].first.first;
    lli j = 0;
    lli cr = 0, pr, p, cnt = 0;
    double avg_tat = 0, avg_wt = 0;

    for(lli i=0; i<n; i++){
        if(vec[i].first.first != temp) break;
        prio = vec[i].second.first;
        art = vec[i].first.first;
        brt = vec[i].first.second;
        p = vec[i].second.second;

        pq.push({{prio, p},{art, brt}});

        temp = art;
        j++;
    }

    while(!pq.empty()){
        prio = pq.top().first.first;
        art = pq.top().second.first;
        brt = pq.top().second.second;
        p = pq.top().first.second;

        if(visited[p]==-1){
            visited[p] = cr;
            cnt++;
        }

        if(cnt == n) qt = brt;

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

        lli rt, ct, tat, wt;

        pq.pop();
        if(brt==0){
            tat = cr - vec2[p].first;
            wt = tat - vec2[p].second;
            rt = visited[p] - vec2[p].first;
            ct_tat_wt_rt[p] = {{cr, tat}, {wt, rt}};

            avg_tat += tat;
            avg_wt += wt;
        }
        else{
            pq.push({{prio, p}, {art, brt}});
        }

        while(j<n && vec[j].first.first <= cr){
            prio = vec[j].second.first;
            art = vec[j].first.first;
            brt = vec[j].first.second;
            p = vec[j].second.second;

            pq.push({{prio, p},{art, brt}});
            j++;
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

4
10 P1 0 5
20 P2 1 4
30 P3 2 2
40 P4 4 1

7
3 P1 0 8
4 P2 1 2
4 P3 3 4
5 P4 4 1
2 P5 5 6
6 P6 6 5
1 P7 10 1
*/
