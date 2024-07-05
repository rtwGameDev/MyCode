#include <iostream>
#define ll long long 
using namespace std;
const ll N = 1e6 + 7;
ll itAr[N]; 
void InitarrEuler() {
	for (ll i = 1; i <= N; ++i) {
		itAr[i] = i;	
	}
	for (ll i = 2; i <= N; ++i) {
		if (itAr[i] == i) {
			itAr[i] = itAr[i] - 1;
			for (ll j = 2 * i; j <= N; j += i) {
				itAr[j] = itAr[j] - itAr[j] / i;
			}
		}
	}
}
int main() {
	InitarrEuler();
	ll n, k;
	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		cin >> k;
		cout << itAr[k] << endl;
	}
}
