#include <iostream>
#define ll long long 
using namespace std;

ll euler(ll n) {
	ll ans = n;
	for (ll i = 2; i * i <= n; ++i) {
		if ( n % i == 0 ) {
			while (n % i == 0) {
				n /= i;
			}
			ans = ans - ans / i; 
		}
	}
	if (n > 1) // Tuc la n la 1 so nguyen to
	{
		ans = ans - ans / n;
	}
	return ans;
}

int main() {
	ll n, a;
	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		cin >> a;
		cout << euler(a) << endl;
	}
}
