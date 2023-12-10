#include <iostream>
using namespace std;

bool a[1000], b[1000], c[1000];
int X[1000], n;
void INIT() {
    cin >> n;
    for (int i = - n + 1; i <= n - 1; ++i) c[i] = true;
    for (int i = 2; i <= 2 * n; ++i) b[i] = true;
    for (int i = 1; i <= n; ++i) a[i] = true;
}

void TRY(int i) {
    for (int j = 1; j <= n; ++j) {
        if (a[j] == true and b[i + j] == true and c[i - j] == true) {
            X[i] = j;
            if (i == n) {
                for (int k = 1; k <= n; ++k) {
                    cout << X[k] << " ";
                }
                cout << endl;
            }
            else {
                a[j] = false; b[i + j] = false; c[i - j] = false;
                TRY(i + 1);
                a[j] = true; b[i + j] = true; c[i - j] = true;
            }
        }
    }
}
int main() {
    INIT();
    TRY(1);
    return 0;
}