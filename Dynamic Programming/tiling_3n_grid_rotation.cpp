// Given a 3n grid, number of ways to cover the whole grid using tiles
// 3*1, 3*2 , rotation allowed

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli dp[100007];
lli func(lli pos){
    if(pos==1) return 1;
    else if(pos==2) return 2;
    if(dp[pos]!=-1) return dp[pos];

    return dp[pos] = func(pos-1) + func(pos-2) + (3 * func(pos-3));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli n, t;
    for(lli i=0; i<100007; i++) dp[i] = -1;
    cin >> t;
    while(t--){
        cin >> n;
        cout << func(n) << endl;
    }
    return 0;
}
