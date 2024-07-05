#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    int h = 1, X, j;
    while (h <= n / 3) {
        h = 3 * h + 1;
    } 
    while (h > 0) {
        for (int i = h; i < n; ++i) {
            X = arr[i];
            j = i;
            while (j >= h and arr[j - h] > X) {
                arr[j] = arr[j - h];
                j -= h;
            } 
            arr[j] = X;
        }
        h = (h - 1) / 3;
    }
}

int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1};
    shellSort(arr, 9);
    for (int i = 0; i <= 8; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}