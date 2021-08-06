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


string T , P;
lli LP , LT;

bool match(lli L , lli R)
{
	for(lli i=0;i<LP;i++){
        if(T[L+i] != P[i]) return false;
	}
	return true;
}

int main()
{
    FAST
	lli t;

	while(cin >> t){
	    //if(t==0) break;
		cin >> P;
		cin >> T;
		LP = P.size();
		LT = T.size();
		lli c = 0;
		for(lli L=0 , R=LP-1; R<LT; L++ , R++){
            if(match(L , R)){
                cout<<L<<en;
                c++;
            }
		}
		if(c==0) cout << en;
	}
}
