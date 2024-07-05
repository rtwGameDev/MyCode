#include <iostream>
#define ll long long 
using namespace std;

void quickSort(ll arr[], ll l, ll r) {
	ll p = arr[r], i = l - 1, j = l;
	while (j <= r) {
		if (arr[j] > p) ++j;
		else swap(arr[++i], arr[j++]);
	}
	if (i > l + 1) quickSort(arr, l, i - 1);
	if (i < r - 1) quickSort(arr, i + 1, r); 
} 

int main() {
	ll arr[100], n, sum = 0;
	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		arr[i] = i;
	}
	for (ll i = 1; i <= n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	ll i = 1;
	while (i > 0) {
		i = n - 1;
		while (arr[i] > arr[i + 1]) {
			--i;
		}
		if (i > 0) {
		ll j = n;
		while (arr[j] < arr[i]) {
			--j;
		}
		swap(arr[i], arr[j]);
		quickSort(arr, i + 1, n);
		for (ll i = 1; i <= n; ++i) {
			cout << arr[i] << " ";
		}
		sum++;
		cout << endl;
		}
	}
	cout << endl << "So luong hoan vi! "<< ++sum;
	return 0;
}



