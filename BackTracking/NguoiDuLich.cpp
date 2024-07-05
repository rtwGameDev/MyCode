#include <iostream>
using namespace std;

int C[1000][1000], X[1000], T[1000], BestConfig[1000];
bool Free[1000];
int m, n, minSpending, maxC = 1e6;

void enter() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) C[i][j] = 0;
            else C[i][j] = maxC;
        }
    }

    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        C[x][y] = z;
        C[y][x] = z;
    }
}

void INIT() {
    for (int i = 1; i <= n; ++i) Free[i] = true;
    Free[1] = false;
    X[1] = 1;
    T[1] = 0;
    minSpending = maxC;
}

void TRY(int i) {
    for (int j = 2; j <= n; ++j) {
        if (Free[j] == true) {
            X[i] = j;
            T[i] = T[i - 1] + C[X[i - 1]][j];
            if (T[i] < minSpending) {
                if (i < n) {
                    Free[j] = false;
                    TRY(i + 1);
                    Free[j] = true;
                }
                else {
                    if (T[n] + C[X[n]][1] < minSpending) {
                        for (int k = 1; k <= n; ++k) {
                            BestConfig[k] = X[k];
                        }
                        minSpending = T[n] + C[X[n]][1];
                    }
                }
            }
        }
    }
}

void pr() {
    if (minSpending == maxC) {
        cout << "NO SOLUTION";
    }
    else {
        for (int i = 1; i <= n; ++i) {
            cout << BestConfig[i] << " -> ";
        }
        cout << 1 << endl << minSpending;
    }
}
int main() {
    enter();
    INIT();
    TRY(2);
    pr();
    return 0;
}