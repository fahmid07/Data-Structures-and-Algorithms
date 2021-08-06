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
const lli A = 1000000021;
const lli B = 29;
const lli AA = 1e9+7;
const lli BB = 137;

lli pw[N];
lli pww[N];

void power_calculate(){
    pw[0] = 1;
    for (lli i = 1; i < N; i++) pw[i] = (pw[i-1] * B) % A;
}
void power_calculate2(){
    pww[0] = 1;
    for (lli i = 1; i < N; i++) pww[i] = (pww[i-1] * BB) % AA;
}


void hash_calculate(lli h[], string s){
    h[0] = 0;
    for (lli i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * pw[i]) % A;
}

void hash_calculate2(lli hs[], string s){
    hs[0] = 0;
    for (lli i = 0; i < s.size(); i++) hs[i+1] = (hs[i] + (s[i] - 'a' + 1) * pww[i]) % AA;
}

void solve(){
    lli t, n, k;
    string s;
    power_calculate();
    power_calculate2();

    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        lli hs[n+2]={0};
        lli h[n+2]={0};
        hash_calculate(h, s);
        hash_calculate2(hs, s);

        set<pii> st;
        for (lli i = 0; i <= n - k; i++) {
             lli cr = (h[i + k] + A - h[i]) % A;
             cr = (cr * pw[n-i-1]) % A;

             lli cr2 = (hs[i + k] + AA - hs[i]) % AA;
             cr2 = (cr2 * pww[n-i-1]) % AA;

             st.insert({cr, cr2});
        }
        cout << st.size() << en;
    }
}

int main()
{
    FAST
    solve();
    return 0;
}
