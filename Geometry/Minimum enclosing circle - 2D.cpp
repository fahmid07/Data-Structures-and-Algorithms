// Minimum enclosing circle - 2D

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

double dist(double a, double b) {
	return a*a + b*b;
}

int main() {
    FAST

    lli n;
    double x[1005], y[1005], X, Y, d, e;

	cin >> n;
	for (lli i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		X += x[i];
		Y += y[i];
	}
	X /= n;
	Y /= n;
	double P = 0.1;
	for (lli i = 0; i < 30000; i++) {
		lli f = 0;
		d = dist(X - x[0], Y - y[0]);
		for (lli j = 1; j < n; j++) {
			e = dist(X - x[j], Y - y[j]);
			if (d < e){
			     d = e;
			     f = j;
            }
		}
		X += (x[f] - X)*P;
		Y += (y[f] - Y)*P;
		P *= 0.999;
	}
	cout << fixed << setprecision(5) << X << " " << Y << " " << sqrt(d) << endl;
}
