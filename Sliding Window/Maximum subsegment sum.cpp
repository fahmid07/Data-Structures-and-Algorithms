// Maximum subsegment sum of any size
// Window Sliding Technique

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t, n, sum, mx, x, mn;
    vector<lli> vec;
    vector<lli> csum;

    cin >> t;
    while(t--){
        cin >> n;
        sum = 0;
        while(n--){
            cin >> x;
            sum += x;
            vec.push_back(x);
            csum.push_back(sum);
        }
        n = vec.size();
        mn = INT_MAX;
        mx = mn * (-1);
        sum = 0;
        for(lli i=0; i<n; i++){
            if(i==0 || mn>=0) sum = csum[i];
            else sum = csum[i] - mn;

            mx = max(mx, sum);
            mn = min(mn, csum[i]);
        }
        cout << mx << endl;
        vec.clear();
        csum.clear();
    }
    return 0;
}
