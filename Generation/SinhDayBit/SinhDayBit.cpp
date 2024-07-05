#include <iostream>
#include <string>
#define ll long long 
using namespace std;

ll n, q = 0;
string rs =" ";

int main() {
	cin >> n;
	for (ll i = i; i <= n; ++i) {
		rs += '0';
	}
	cout << rs << endl; 
	ll index = 1;
	while (index > 0) {
		index = n;
		while (rs[index] == '1') {
			index--;
		}
		if (index > 0) {
			rs[index] = '1';
			for (ll j = index + 1; j <= n; ++j) {
				rs[j] = '0';
			}
			cout << rs << endl;		
			q++;	
		}
	}
	cout << ++q;
	return 0;
}
