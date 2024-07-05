#include <bits/stdc++.h>
using namespace std;
const int N = 150;
const long long MOD = 1000000000 + 7;
long long a[N][N];
long long result[N][N];
long long base[N][N];
void OutPut(long long a[][N],long long m)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void get(long long x[][N], long long y[][N], long long m)
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            x[i][j] = y[i][j];
}
void multiplication(long long x[][N], long long y[][N], long long m)
{
    long long tmp[N][N];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= m; k++)
                tmp[i][j] = (tmp[i][j] + (x[i][k] * y[k][j]) % MOD) % MOD;
    get(x, tmp, m);
}

void POWMATRIX(long long m, long long power)
{
    for (int i = 1; i <= m; i ++) 
        result[i][i] = 1;

    get(base, a, m);

    while (power > 0)
    {
        if (power % 2 == 1) 
            multiplication(result, base, m);
        multiplication(base, base, m);
        power /= 2;
    }
    OutPut(result, m);
}
int main()
{
    long long m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= m; j++)
        cin >> a[i][j];
    POWMATRIX(m, n);
    return 0;
}