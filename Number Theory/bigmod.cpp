#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

lli bigmod(lli b, lli p, lli m){
    if(p==0) return 1 % m;
    lli x = bigmod(b, p/2, m);
    x = (x*x) % m;
    if(p%2==1) x = (x*b) % m;
    return x;
}

void solve(){
    lli b, p, m;
    while(cin >> b >> p >> m){
        lli ans = bigmod(b, p, m);
        cout << ans << endl;
    }
}

int main()
{
    FAST
    solve();
    return 0;
}
