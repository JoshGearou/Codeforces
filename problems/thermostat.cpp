#include <iostream>

int solve(long long l, long long r, long long x, long long a, long long b) {
    if (a == b) {
        return 0;
    }
    if (((l + x) > b && (r - x) < b) || ((l + x) > a && (r - x) < a)) {
        return -1;
    }

    if (b - a >= x) {
        return 1;
    }
    if ((b - a < x && (r - b >= x) || (a - l >= x))) {
        return 2;
    }
    return 3;
}

void minOperations() {
    long long l, r, x, a, b;
    std::cin >> l >> r >> x >> a >> b;
    if (a > b) {
        long long temp = a;
        a = b;
        b = temp;
    }
    int ans = solve(l, r, x, a, b);
    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        minOperations();
        t--;
    }
    return 0;
}