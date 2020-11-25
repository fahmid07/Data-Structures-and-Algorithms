// UVA 13054 - Hippo Circus
// Sliding Window

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli c, n, h, ta, td, x, j, i, cnt;
    vector<lli> vec;

    cin >> c;
    for(lli k=1; k<=c; k++){
        cin >> n >> h >> ta >> td;
        while(n--){
            cin >> x;
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        n = vec.size();

        i = 0;
        j = n-1;
        cnt = 0;

        while(i<=j){
            if((vec[i]+vec[j] < h) && (2*ta)>=td && i!=j){
                cnt += td;
                j--;
                i++;
            }
            else{
                cnt += ta;
                j--;
            }
        }
        cout << "Case " << k << ": " << cnt << endl;
        vec.clear();
    }
    return 0;
}
