#include <iostream>
#include <vector>

// 1200

void swapGame(std::vector<int> arr) {
    int first = arr[0];
    int min = arr[1];
    for (int i=1; i<arr.size(); i++) {
        min = std::min(arr[i], min);
    }
    if (min < first) {
        std::cout << "Alice" << std::endl;
    } else {
        std::cout << "Bob" << std::endl;
    }
}


int main() {
    int t;
    std::cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        std::vector<int> arr;
        std::cin >> n;
        for (int j=0; j<n; j++) {
            int x;
            std::cin >> x;
            arr.push_back(x);
        }
        swapGame(arr);
    }
    return 0;
}