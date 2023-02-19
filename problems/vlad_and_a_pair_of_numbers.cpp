#include <iostream>


void solve() {
    long long x;
    std::cin >> x;
    long long a = (long long) x;
    long long b = 0ll;
    for (int i=31; i>=0; i--) {
        if ((x & (1ll << i)) > 0) {
            continue;
        }
        long long nextA = a + (1ll << i);
        long long nextB = b + (1ll << i);
        if (nextA + nextB <= (2 * x)) {
            a = nextA;
            b = nextB;
        }
    }
    if ((a + b == (2 * x)) && (a ^ b) == x) {
        std::cout << a << " " << b << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}