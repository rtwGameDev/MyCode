#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000000 + 7;
int fastpow(long long base, long long power)
{
    long long result = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        power /= 2;
    } 
    return result;
}
int main()
{
    long long a, n;
    cin >> a >> n;
    cout << fastpow(a, n);
    return 0;
}