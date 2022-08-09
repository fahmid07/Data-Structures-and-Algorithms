//Lightoj 1068 - Investigation
//the number of integers in the range [A, B] which are divisible by K and the sum of its digits is also divisible by K

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ul;

#define pii  pair<lli, lli>
#define PI acos(-1.0)
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define YES cout << "YES" << "\n";
#define NO cout << "NO" << "\n";
#define yes cout << "Yes" << "\n";
#define no cout << "No" << "\n";
#define mnp cout << "-1" << "\n";
#define en "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SORT(vec) sort(vec.begin(),vec.end())
#define CLR(vec) vec.clear()
#define REV(vec) reverse(vec.begin(),vec.end())
#define min3(a,b,c) min(a,min(b,c))

lli kk;
lli dp[20][180][2][180];

lli getDigits(lli x, vi &digit){
	while (x){
		digit.pb(x%10);
		x /= 10;
	}
}

lli digitSum(lli ss, lli moded, lli idx, lli sum, lli isSmall, vi &digit){
	if (idx == -1) return sum%kk==0 && moded==0 && ss>0;

	if (dp[idx][sum][isSmall][moded] != -1 and isSmall == 1) return dp[idx][sum][isSmall][moded];

	lli val = 0;

	lli k = (isSmall)? 9 : digit[idx];
    ss *= 10;
	for (lli i = 0; i <= k ; i++){
		lli newIsSmall = isSmall | (i<k);
		val += digitSum(ss+i, (ss+i)%kk, idx-1, sum+i, newIsSmall, digit);
	}

	if (isSmall) dp[idx][sum][isSmall][moded] = val;

	return val;
}

lli rangeDigit(lli a, lli b){
	memset(dp, -1, sizeof(dp));

	vi digitA;
	getDigits(a-1, digitA);

	lli ans1 = digitSum(0, 0, digitA.size()-1, 0, 0, digitA);

	vi digitB;
	getDigits(b, digitB);

	lli ans2 = digitSum(0, 0, digitB.size()-1, 0, 0, digitB);

	return (ans2 - ans1);
}

int main()
{
	lli a, b, t;
	cin >> t;
	for(lli i=1; i<=t; i++){
        cin >> a >> b >> kk;
        lli ans = rangeDigit(a, b);
        if(ans<0) ans*= (-1);
        if(kk>90) ans = 0;
        cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}

