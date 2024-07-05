#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[10000];
    cin >> n;
    memset(a, 0, sizeof(a));
    int max = INT_MIN;
    for (int i = 1; i <= n ; i++)
        {
            int x;
            cin >> x;
            a[x]++;
            if (max < x) max = x;
        }
    for (int i = 1; i <= max; i++)
        {
            if (a[i] != 0) 
                for(int j = 1; j <= a[i]; j ++) cout << i << " ";
        }
    return 0;
}