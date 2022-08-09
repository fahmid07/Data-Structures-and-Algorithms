//there are n types of coins of value A1, A2 ... An. You have to find the number of ways you can make K using the coins.
//You can use any coin at most K times.

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




void solve(){
    lli t, n, k, x;
    cin >> t;
    for(lli i=1; i<=t; i++){
        cin >> n >> k;
        vi coin;
        for(lli j=0; j<n; j++){
            cin >> x;
            coin.pb(x);
        }
        lli ways[10007]={0};
        ways[0] = 1;
        lli m = 100000007;
        for(lli q=0; q<n; q++){
            for(lli c=coin[q]; c<=k; c++){
                ways[c] += ways[c - coin[q]];
                ways[c] %= m;
            }
        }
        cout << "Case " << i << ": " << ways[k] << en;
    }
}
int main()
{
    FAST
    solve();
    return 0;
}
