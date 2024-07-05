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
	ll arr[100] = {9,8,7,6,5,4,3,2,1,0};
	quickSort(arr, 0, 9);
	for (ll i = 0; i <= 9; ++i) cout << arr[i] << " ";	
}
