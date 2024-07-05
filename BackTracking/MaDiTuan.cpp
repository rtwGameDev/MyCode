#include <iostream>
#include <iomanip>
using namespace std;

int X[9] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
int Y[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int n;
int Free[100][100];

void INIT() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            Free[i][j] = 0;
        }
    }
}

void show() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << setw(2) << Free[i][j] << " ";
        }
        cout << endl;
    }
}

void Try(int x, int y, int index) {
    for (int i = 1; i <= 8; ++i) {
        int u = x + X[i];
        int v = y + Y[i];
        if (Free[u][v] == 0) { // Khi th ta dang thu, chua dc di qua
            if (u >= 1 and u <= n and v >= 1 and v <= n) { // O thu nam trong ban co
                Free[u][v] = index;
                if (index == n * n) {
                    show();
                    exit(0);
                }
                else {
                    Try(u, v, index + 1);
                    Free[u][v] = 0;
                }
            }
        }
    }
}
int main() {
    int x, y;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;
    cout << "Nhap diem khoi dau: ";
    cin >> x >> y;
    INIT();
    Free[x][y] = 1;
    Try(x, y, 2);
    cout << "Khong co con duong nao!";
    return 0;
}