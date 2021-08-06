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
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

lli n = 1e8;
vector<bool> is_prime(n+1, true);
void sieve(){
    is_prime[0] = is_prime[1] = false;
    for (lli i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (lli j = i * i; j <= n; j += i) is_prime[j] = false;
        }
    }
}

void solve(){
    sieve();
    vi vec;
    for(lli i=1; i<=n; i++){
        if(is_prime[i]) vec.pb(i);
    }
    for(lli i=0; i<vec.size(); i+=100) cout << vec[i] << en;
}

int main()
{
    FAST
    solve();
    return 0;
}
