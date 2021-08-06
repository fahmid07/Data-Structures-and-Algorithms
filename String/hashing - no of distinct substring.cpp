#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ul;

#define pii  pair<lli, lli>
#define PI acos(-1.0)
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define en "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const lli N = 2000007;
const lli A = 1e9 + 9;
const lli B = 31;

lli pw[N];

void power_calculate(){
    pw[0] = 1;
    for (lli i = 1; i < N; i++) pw[i] = (pw[i-1] * B) % A;
}

void hash_calculate(lli h[], string s){
    h[0] = 0;
    for (lli i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'A' + 1) * pw[i]) % A;
}

void solve(){
    lli t, n;
    string s;
    power_calculate();

    cin >> t;
    while(t--){
        cin >> s;
        n = s.size();
        lli hs[n+2]={0};
        hash_calculate(hs, s);

        lli cnt = 0;
        for (lli l = 1; l <= n; l++) {
            set<lli> st;
            for (lli i = 0; i <= n - l; i++) {
                lli cr = (hs[i + l] + A - hs[i]) % A;
                cr = (cr * pw[n-i-1]) % A;
                st.insert(cr);
            }
            cnt += st.size();
        }
        cout << cnt << en;
    }
}

int main()
{
    FAST
    solve();
    return 0;
}
