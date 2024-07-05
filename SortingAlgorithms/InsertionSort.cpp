#include <iostream>
using namespace std;

void srt(int arr[], int n) {
    int X, j;
    for (int i = 1; i < n; ++i) {
        X = arr[i];
        j = i;
        while (j - 1 >= 0 and arr[j - 1] > X) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = X;
    }
}

int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    srt(arr, 10);
    for (int i = 0; i <= 9; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}