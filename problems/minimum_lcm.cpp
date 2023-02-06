#include <iostream>
#include <cmath>

// 1000

void findPair(int n) {
    bool inFor = false;
    for (int i=2; i<=sqrt(n)+1; i++) {
        if ((n % i) == 0) {
            inFor = true;
            std::cout << n/i << " " << (i-1) * (n / i) << std::endl;
            break;
        }
    }
    if (!inFor) {
        std::cout << 1 << " " << n-1 << std::endl;
    }
}


int main() {
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        std::cin >> n;
        findPair(n);
    }
    return 0;
}