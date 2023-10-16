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
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

// reverse binary -> lli res = 0; while(n>0){ res <<= 1; res = res|(n & 1); n >>= 1;}
// decimal to binary string -> string s = bitset<N>(n).to_string();
// binary string to decimal -> lli n = bitset<N>(s).to_ullong();
// Case output -> cout << "Case " << j << ": " << mx << en;

template <typename T> inline T Ceil(T a, T b) { return ((a % b == 0) ? (a / b) : (a / b + 1)); }
template <typename T> inline T Floor(T a, T b) { return a / b; }

template <typename T> inline T intersect(T a, T b, T c, T d) { return ((max(a,c) <= min(b,d)) ? 1 : 0); }

template <typename T> inline T Power (T a, T p) { T res = 1, x = a; while ( p ) { if ( p & 1 ) res = ( res * x ); x = ( x * x ); p >>= 1;}return res; }

template <typename T> inline T gcd ( T a, T b ) { a = abs(a); b = abs(b); while ( b ) { a = a % b; swap ( a, b ); } return a; }
template <typename T> inline T lcm(T x,T y) { return (((x)/__gcd((x),(y)))*(y)); }
template <typename T> inline T isPrime(T n){ if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (lli i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true;}

bool cmp(const pii &v1, const pii &v2)
{
    return ((v1.first>v2.first) ||  (v1.first==v2.first) && (v1.second<v2.second));
}

template <typename T> inline T Power (T a, T p) { T res = 1, x = a; while ( p ) { if ( p & 1 ) res = ( res * x ); x = ( x * x ); p >>= 1;}return res; }

lli lp(lli N){
    N = N| (N>>1);
    N = N| (N>>2);
    N = N| (N>>4);
    N = N| (N>>8);
    return (N+1)>>1;
}

stringstream ss;
ss << a;
string str = ss.str();


/*

index of elements in set

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
  pair<lli,lli>,
  null_type,
  less<pair<lli,lli> >,
  rb_tree_tag,
  tree_order_statistics_node_update>ordered_set;

  ordered_set s;

  auto pos=s.find({x,0});
                auto start=s.begin();

  cntleft=s.order_of_key(*pos)-s.order_of_key(*start);
*/

void solve(){
    lli t, n, k, x, z = 2;
    cin >> t;
    while(t--){
        cin >> n >> k;
        x = Power(z, k);
        x--;
        x *= 3;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
