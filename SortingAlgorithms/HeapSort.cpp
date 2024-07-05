#include <iostream>
#define ll long long
using namespace std;


// Luu y, n la vi tri phan tu cuoi cung trong mang
// phan tu bat dau tu tu so 0
void heap(ll arr[], ll index, ll n) {
	
	// tim vi tri cua phan tu node con ben trai v� phan tu node con b�n phai cua ph�n tu index
	ll l = 2 * index + 1;
	ll r = 2 * index + 2;
	
	// tim ra vi tri so lon nhat giua c�c node. node chinh index, node con b�n tr�i v� ben phai
	ll max = index; // max luu vi tri cua ptu lon nhat
	
	// luuu y, chi so cua node con 2 ben phai nho hon or bang n
	if (arr[max] < arr[l] and l <= n) max = l;
	if (arr[max] < arr[r] and r <= n) max = r;
	
	// neu co xay ra su thay doi
	if (max != index) {
		// doi gia tri cua ptu index va max
		swap(arr[max], arr[index]);
		heap(arr, max, n);
	} 
}

void heapSort(ll arr[], ll n) {
	ll mid = n / 2;
	// heap tu phan tu chinh giua ve ptu dau tien.
	for (ll i = mid; i >= 0; --i) {
		heap(arr, i, n);
	}
	
	for (ll i = n; i > 0; --i) {
		swap(arr[0], arr[i]);
		heap(arr, 0, i - 1);
	}
}

int main() {
	ll arr[] = {9,8,7,6,5,4,3,2,1,0};
	heapSort(arr, 9);
	for (ll i = 0; i <= 9; ++i) {
		cout << arr[i] << " ";
	}
	return 0;
}
