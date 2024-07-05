#include <iostream>
#define ll long long
using namespace std;

int main() {
	ll arr[100], n, k;
	cin >> n >> k;
	for (ll i = 1; i <= k; ++i) {
		arr[i] = i;
	}
	for (ll i = 1; i <= k; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	ll index = 1;
	while (index > 0) {
		index = k;
		
		while (arr[index] == n - k + index) {
			--index;
		}
		
		if (index > 0) {
			arr[index]++;
			for (ll j = index + 1; j <= n; ++j) {
				arr[j] = arr[j - 1] + 1; 
			}
			for (ll i = 1; i <= k; ++i) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
}
