// Maximum subsegment sum of size k
// Window Sliding Technique

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t, n, k, sum, mx, x;
    vector<lli> vec;

    cin >> t;
    while(t--){
        cin >> n >> k;
        while(n--){
            cin >> x;
            vec.push_back(x);
        }
        n = vec.size();

        sum = 0;

        for(lli i=0; i<k; i++) sum += vec[i];

        mx = sum;
        for(lli i=k; i<n; i++){
            sum += vec[i];
            sum -= vec[i-k];
            mx = max(mx, sum);
        }
        cout << mx << endl;
        vec.clear();
    }
    return 0;
}
