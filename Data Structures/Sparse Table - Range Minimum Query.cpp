// Sparse Table - Range Minimum Query

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define N 100007
lli ara[N][60];

void buildSparse(vector<lli> vec, lli n){
    for(lli i=0; i<n; i++) ara[i][0] = vec[i];

    for(lli j=1; (1 << j) <= n; j++){
        for(lli i=0; (i + (1 << j) - 1) < n; i++){
            ara[i][j] = min(ara[i][j-1], ara[i + (1 << (j - 1))][j-1]);
        }
    }
}

lli rmq(lli l, lli r){
    lli j = (lli)(log2(r - l + 1));
    return min(ara[l][j], ara[r - (1 << j) + 1][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli n, x, y, q;
    vector<lli> vec;
    cin >> n;
    while(n--){
        cin >> x;
        vec.push_back(x);
    }
    n = vec.size();

    buildSparse(vec, n);
    cin >> q;
    while(q--){
        cin >> x >> y;
        cout << rmq(x, y) << "\n";
    }

    return 0;
}
