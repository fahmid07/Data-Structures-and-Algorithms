#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ul;

#define pii  pair<lli, lli>
#define PI acos(-1.0)
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define YES cout << "YES" << "\n";
#define NO cout << "NO" << "\n";
#define yes cout << "Yes" << "\n";
#define no cout << "No" << "\n";
#define mnp cout << "-1" << "\n";
#define en "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SORT(vec) sort(vec.begin(),vec.end())
#define CLR(vec) vec.clear()
#define REV(vec) reverse(vec.begin(),vec.end())
#define min3(a,b,c) min(a,min(b,c))

#define N 32


void solve(){
    lli n, art, brt;
    string s;

    cin >> n;

    vector<pair<pii, lli>> vec;
    vector<pair<pii, pii>> tat_wt(n+7);

    while(n--){
        cin >> s >> art >> brt;
        vec.pb({{art, brt}, s[1]-48});
    }

    SORT(vec);

    lli cr = 0;
    double avg_tat = 0, avg_wt = 0;

    for(auto it:vec){
        lli st, ct, tat, wt;

        art = it.first.first;
        brt = it.first.second;

        st = max(cr, art);
        ct = st + brt;
        cr = ct;

        tat = ct - art;
        wt = tat - brt;

        avg_tat += tat;
        avg_wt += wt;

        tat_wt[it.second] = {{tat, wt}, {st, ct}};
    }

    cout << "Process no.  Arrival  Burst  Starting  Completing  TAT  WT" << en;

    n = vec.size();
    avg_tat /= n;
    avg_wt /= n;

    for(lli i=1; i<=n; i++){
        cout << "P" << i << " \t\t ";
        cout << tat_wt[i].second.first-tat_wt[i].first.second << " \t " << tat_wt[i].second.second-tat_wt[i].second.first << " \t ";
        cout << tat_wt[i].second.first << " \t " << tat_wt[i].second.second << " \t    ";
        cout << tat_wt[i].first.first << " \t " << tat_wt[i].first.second << " \t ";
        cout << en;
    }

    cout << "Average turn around time: " << avg_tat << en;
    cout << "Average waiting time: " << avg_wt << en;
}
int main()
{
    FAST
    solve();
    return 0;
}

/*

4
P3 5 3
P1 0 2
P2 1 2
P4 6 4


5
P1 2 6
P2 5 2
P3 1 8
P4 0 3
P5 4 4

*/
