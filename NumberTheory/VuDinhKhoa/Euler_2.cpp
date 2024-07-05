#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll n = 1000000;
ll phi[n + 1];
void sive()
{
    for (int i = 1; i <= n; i++ ) phi[i] = i;
    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
            {
                phi[i] = i - 1;
                for (int j = 2 * i; j <= n; j+=i)   
                    phi[j] = phi[j] - phi[j] / i;
            }
}
int main()
{
    ll t;
    cin >> t;
    sive();
    for (int i = 1; i <= t; i++)
        {
            int x;
            cin >> x;
            cout << phi[x] << endl;
        }
    return 0;
}