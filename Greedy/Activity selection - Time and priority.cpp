// Activity selection - Time and priority

// List of all the tasks that you need to complete today
// Time that is required to complete each task
// Priority (or weight ) to each work.
// Maximize the priority within given time

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli x, y, c = 0, ct = 0;
    lli n, t; // number of task, given time
    vector<lli> T; // Time
    vector<lli> P; // Priority
    vector<pair<double, lli>> s;

    cin >> n >> t;

    while(n--){
        cin >> x >> y;
        T.push_back(x);
        P.push_back(y);
    }
    n = T.size();

    for(lli i=0; i<n; i++){
        s.push_back(make_pair(((P[i] * 1.0) / (T[i] * 1.0)), i));
    }
    sort(s.begin(), s.end());

    for(lli i=n-1; i>=0; i--){
        if(ct+T[s[i].second] <= t){
            ct = ct + T[s[i].second];
            c += P[s[i].second];
        }
    }
    cout << c << endl; // maximized priority
    return 0;
}
