#include <iostream>
#define ll unsigned long long
using namespace std;
const int N = 150;
ll Matrix[N][N], result[N][N], n, m, p = 1e9 + 7;
void initialization(ll arr[][N], ll n) {
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
        result[i][i] = 1;
    }
}

void powMatrix(ll strMatrix[][N], ll endMatrix[][N], ll Des[][N], ll n) {
    ll temp[N][N], s;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            s = 0;
            for (ll k = 1; k <= n; ++k) s += (strMatrix[i][k] * endMatrix[k][j]) % p;
            temp[i][j] = s % p;
        }
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) Des[i][j] = temp[i][j];
    }
}

void pr() {
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    cin >> n >> m;
    initialization(Matrix, n);
    while (m) {
        if (m % 2 == 1)
            powMatrix(Matrix, result, result, n);
        powMatrix(Matrix, Matrix, Matrix, n);
        m /= 2;
    }
    pr();
    return 0;
}
