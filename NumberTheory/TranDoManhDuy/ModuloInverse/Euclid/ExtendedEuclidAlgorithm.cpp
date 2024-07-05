#include <iostream>
#define ll long long 
using namespace std;


ll exEuclid(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll rs = exEuclid(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return rs;
}

int main() {
	ll a, b, x, y;
	cin >> a >> b;
	cout << exEuclid(a, b, x, y);
	cout << endl << x << " " << y;
	return 0;
}
