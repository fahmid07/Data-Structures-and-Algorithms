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
vector<string> vec = {"in", "input", "out", "output", "puton", "one"};
map<string, int> m;


lli f = 0;
lli mx = 1e9+7;
void rec(lli pos, lli len){
    if(len >= mx) return;
    if(pos == s.size()){
        f = 1;
        if(len<mx) mx = len;
        return;
    }
    string temp;
    for(lli i = pos; i < s.size(); i++){
        temp += s[i];
        if(m.find(temp)!=m.end()) rec(i + 1, len + 1);
    }
}

void solve(){
    for(auto i:vec) m[i] = 1;
    lli n;
    cin >> n;
    while(n--){
        cin >> s;
        rec(0, 0);
        if(f) yes
        else no
        f = 0;
        mx = 1e9+7;
    }
}

int main()
{
    FAST
    solve();
    return 0;
}
