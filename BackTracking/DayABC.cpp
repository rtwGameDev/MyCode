#include <iostream>
using namespace std;

char arr[1000], BestConfig[1000];
int T[1000], MinC = 1000, n;

bool same(int i, int l) {
    int j = i - l;
    for (int k = 0; k < l; ++k) {
        if (arr[i - k] != arr[j - k]) {
            return false;
        }
    }
    return true;
    // Tra ve false neu nhu 2 day co do dai l, ke nhau, day thu 2 ket thuc o X[i] la khac nhau
}

bool check(int i) {
    for (int j = 1; j <= i / 2; ++j) {
        if (same(i, j)) return false;
    }
    return true;
    // False nghia la phan tu thu i lam hong day
    // True la ko lam hong day
}

void Keep() {
    for (int i = 1; i <= n; ++i) {
        BestConfig[i] = arr[i];
    }
    MinC = T[n];
}
void show() {
    for (int i = 1; i <= n; ++i) {
        cout << BestConfig[i] << " ";
    }
}
void TRY(int i) {
    for (char j = 'A'; j <= 'C'; ++j) {
        arr[i] = j;
        if (check(i)) {
            if (j == 'C') {
                T[i] = T[i - 1] + 1;
            }
            else T[i] = T[i - 1];
            if (T[i] + (n - i) / 4 < MinC) {
                if (i < n) {
                    TRY(i + 1);
                }
                else {
                    Keep();
                }
            }
        }
    }
}
int main() {
    cin >> n;
    TRY(1);
    show();
    return 0;
}