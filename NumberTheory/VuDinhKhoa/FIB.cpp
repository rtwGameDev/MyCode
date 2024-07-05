#include <bits/stdc++.h>
using namespace std;
long long P[3][3];
long long result[3][3];
long long base[3][3];
long long p;
void OutPut(long long a[][3])
{
    int m = 2;
    cout << endl;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void get(long long x[][3], long long y[][3])
{
    for (int i = 1; i <= 2; i ++)
        for (int j = 1; j <= 2; j++) x[i][j] = y[i][j];
}
void multiplication(long long x[][3], long long y[][3])
{
    long long tmp[3][3];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <=2 ; j++)
            for (int k = 1; k <= 2; k++) tmp[i][j] = (tmp[i][j] + (x[i][k] * y[k][j]) % p) % p;
    get(x, tmp);
}
void FIB(long long n)
{
    long long fibo[2][3];
    if (n <= 2) cout << 1;
    else
    {
        fibo[1][1] = 1;
        fibo[1][2] = 1;
        multiplication(fibo, P);
        if (n % 2 == 1) cout << fibo[1][2];
        else cout << fibo[1][1];
    }
}

void FASTPOWER(long long power)
{
    for (int i = 1; i <= 2; i ++) 
        result[i][i] = 1;
    get(base, P);
    while (power > 0)
    {
        if (power % 2 == 1) 
            multiplication(result, base);
        multiplication(base, base);
        power /= 2;
    }
}
int main()
{
    long long n;
    cin >> n >> p;
    P[1][1] = 0;
    P[1][2] = 1;
    P[2][1] = 1;
    P[2][2] = 1;
    FASTPOWER(n);
    get(P, result);
    FIB(n + 1);
    return 0;
}