#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ul;

#define pii  pair<lli, lli>
#define PI acos(-1.0)
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define en "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

string s;
bool check(string p, lli l, lli r){
    lli len = r-l+1;
    if(len!=p.size()) return false;
    for(lli i=l; i<=r; i++){
        if(s[i]!=p[i-l]) return false;
    }
    return true;
}

void solve(){
    lli n, f;
    vector<string> vec = {"in", "input", "inputon", "inputone", "out", "output", "outputon", "outputone", "puton", "one"};
    REV(vec);
    cin >> n;
    while(n--){
        cin >> s;
        f = 1;
        for(lli i=0; i<s.size(); ){
            lli fl = 0;
            for(lli j=0; j<vec.size(); j++){
                if(check(vec[j], i, i+vec[j].size()-1)){
                    fl = 1;
                    i += vec[j].size();
                    break;
                }
            }
            if(fl==0){
                f = 0;
                break;
            }
        }
        if(f) yes
        else no
    }
}

int main()
{
    FAST
    solve();
    return 0;
}
