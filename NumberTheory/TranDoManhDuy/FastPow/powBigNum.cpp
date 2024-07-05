#include <iostream>
#define ll long long
using namespace std;

int main() {
	ll a, n, p = 1e9 + 7, rs = 1;
	cin >> a >> n;
	while (n) {
		if (n & 1) rs = (rs * a) % p;
		a = (a * a) % p;
		n /= 2;
	}
	cout << rs % p;
}

