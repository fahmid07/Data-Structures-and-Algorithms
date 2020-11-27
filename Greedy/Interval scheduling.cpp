// Activity selection - meeting scheduling
// maximum number of meeting

#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long int lli;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t, n, x, cnt, y, f, cr;
    vector<pair<lli, lli>> ara;
    pair<lli, lli> p;
    cin >> t;
    for(lli k=1; k<=t; k++){
        cin >> n;

        while(n--){
            cin >> x >> y;
            ara.push_back(make_pair(x, y));
        }
        sort(ara.begin(), ara.end(), sortbysec);
        n = ara.size();
        cnt = 0;
        f = 0;
        cr = ara[0].second;
        for(lli i=0; i<n; i++){
            p = ara[i];
            if(p.second <= cr) cnt++;
            if(i!=n-1){
                for(lli j=i+1; j<n; j++){
                    p = ara[j];
                    if(p.first > cr){
                        cr = ara[j].second;
                        i = j - 1;
                        break;
                    }
                    if(j==n-1) f = 1;
                }
            }
            if(f) break;
        }
        cout << "Case " << k << ": ";
        cout << cnt << endl;

        ara.clear();
    }
    return 0;
}
