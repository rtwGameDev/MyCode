#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int N = 1e5+5;
bool cmp(int a,int b){ return a<b;}
int a[10] = {5,2,6,1,10};

int main(){
    int n = 5;
    sort(a,a+n); // sap xep tu [0,n) tang dan  {1, 2, 5, 6, 10}
    sort(a,a+n,greater<int>()); // sap xep tu [0,n) giam dan {10, 6, 5, 2, 1}
    sort(a,a+n,cmp); // sap xep tu [0,n) theo cmp {1, 2, 5, 6, 10}


    return 0;
}
