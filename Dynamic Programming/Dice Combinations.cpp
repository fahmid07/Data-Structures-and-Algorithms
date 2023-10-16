// https://cses.fi/problemset/task/1633/
// CSES - Dice Combinations
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long lli;
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
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SORT(vec) sort(vec.begin(),vec.end())
#define CLR(vec) vec.clear()
#define REV(vec) reverse(vec.begin(),vec.end())
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define display(vec) for(auto it:vec){cout << it << " ";}cout << endl;

#define mod 1000000007
void solve(lli t){
    lli n;
    cin >> n;
    lli dp[n+7] = {0};
    dp[0] = 1;

    for(lli i=1; i<=n; i++){
        for(lli j=1; j<=6; j++){
            if(j>i) break;
            dp[i] = dp[i-j] + dp[i];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << endl;
}
 
int main()
{
    FAST
 
    lli t = 1;
    //cin >> t;
    for(lli i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}