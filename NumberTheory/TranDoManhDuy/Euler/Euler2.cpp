#include <iostream>
#include <iomanip>
#define ll long long
using namespace std;
ll ar[1000000 + 1], res, dex; 
bool snt[1000001];
void initial() {
	
	// khoi tao cac mang
	for (ll i = 1; i <= 1000001; ++i) {
		snt[i] = true;
		ar[i] = i;
	}
	snt[1] = false;
	
	// Sang nguyen to
	for (ll i = 2; i <= 1000001; ++i) {
		// duyet lan luot tung so
		
		if (snt[i]) {
			// Neu i la 1 so nguyen to
			// phi ham euler cua i = i - 1;
			ar[i] = ar[i] - 1;
			
			// Cac ptu = k * i se khong phai la so nguyen to
			for (ll j = 2*i; j <= 1000001; j += i) {
				snt[j] = false;
			}
			
			// Cac phan tu mang gia tri pow(i, a) se co phi ham euler i ^ a - i ^ (a - 1)
			for (ll k = i * i; k <= 1000001; k = k * i) {
				ar[k] = k - k / i;
			}
		}
	}
	
	// 1 so bat ki ngoai cac so la so nto, va cac so co gia tri = pow(x, y)
	// vd 24 ko la so nguyen to. 24 != pow(x, y) 
	// 24 = 8 * 3 => 8 va 3 chac chan la 2 so nguyen to cung nhau
	for (ll i = 2; i <= 1000001; ++i) {
		if (ar[i] == i) {
			res = 1;
			dex = 2;
			while (i % dex != 0) {
				dex++;
			}
			ll k = i;
			while (k % dex == 0) {
				res *= dex;
				k /= dex;
			}
			ar[i] = ar[res] * ar[i / res];
		}
	}
}

int main() {
	initial();
	ll n, k; 
	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		cin >> k;
		cout << ar[k] << endl;
	}
	return 0;
}
