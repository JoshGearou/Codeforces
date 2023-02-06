#include <iostream>


void createArray(int n) {
    int low = 1;
    int high = n * n;
    int arr[n][n];
    int last = low;
    for (int i=0; i<n; i++) {
        if (last == low) {
            arr[0][i] = low;
            std::cout << low << " ";
            low++;
            last = high;
        } else {
            arr[0][i] = high;
            std::cout << high << " ";
            high--;
            last = low;
        }
    }
    std::cout << std::endl;
    int diff = n * n;
    int max = n * n;
    for (int i=1; i<n; i++) {
        diff = diff  - n;
        for (int j=0; j<n; j++) {
            if (arr[i-1][j] > (max / 2)) {
                arr[i][j] = arr[i-1][j] - diff;
                std::cout << arr[i][j] << " ";
            } else {
                arr[i][j] = arr[i-1][j] + diff;
                std::cout << arr[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}


int main() {
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        std::cin >> n;
        createArray(n);
    }
    return 0;
}