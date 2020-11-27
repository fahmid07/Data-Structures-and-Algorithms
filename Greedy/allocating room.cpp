// Activity selection - allocating room
// minimum number of rooms

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli n, x, y, z, cnt = 0, mx = 0;
    vector<pair<lli, pair<lli, lli>>> ara;
    pair<lli, lli> q;

    cin >> n;
    for(lli i = 0; i<n; i++){
        cin >> x >> y;
        ara.push_back(make_pair(x, make_pair(1, i)));  // 1 if starting
        ara.push_back(make_pair(y, make_pair(-1, i))); // -1 if ending
    }

    sort(ara.begin(), ara.end());
    for(lli i=0; i<ara.size(); i++){
        q = ara[i].second;
        cnt += q.first;
        mx = max(mx, cnt);
    }

    cout << mx << endl;
    return 0;
}
