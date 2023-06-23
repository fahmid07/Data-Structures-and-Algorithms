// Minimum enclosing circle - 3D

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

double dist(double a, double b, double c) {
	return a*a + b*b + c*c;
}

int main() {
    FAST

    lli n;
    double x[105], y[105], z[105], X, Y, Z, d, e;

	cin >> n;
	for (lli i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> z[i];
		X += x[i];
		Y += y[i];
		Z += z[i];
	}
	X /= n;
	Y /= n;
	Z /= n;
	double P = 0.1;
	for (lli i = 0; i < 70000; i++) {
		lli f = 0;
		d = dist(X - x[0], Y - y[0], Z - z[0]);
		for (lli j = 1; j < n; j++) {
			e = dist(X - x[j], Y - y[j], Z - z[j]);
			if (d < e) {
				d = e;
				f = j;
			}
		}
		X += (x[f] - X)*P;
		Y += (y[f] - Y)*P;
		Z += (z[f] - Z)*P;
		P *= 0.998;
	}
	cout << fixed << setprecision(6) << X << " " << Y << " " << Z << endl;
}
