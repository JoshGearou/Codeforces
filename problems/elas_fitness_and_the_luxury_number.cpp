#include <iostream>
#include <unordered_map>
#include <cmath>

std::unordered_map<long long, long long> map;

long long findMinLuxuryCount(long long x) {
    long long sr = std::sqrt(x);
    long long ans = (sr * 3) - 2;
    if (((sr * sr) + sr) < x) {
        ans++;
    }
    if (((sr * sr) + (2 * sr)) < x) {
        ans++;
    }
    if (sr * sr == x) {
        ans--;
    }
    return ans;
}

long long findMaxLuxuryCount(long long x) {
    long long sr = std::sqrt(x);
    long long ans = (sr * 3) - 2;
    if (((sr * sr) + sr) <= x) {
        ans++;
    }
    if (((sr * sr) + (2 * sr)) <= x) {
        ans++;
    }
    return ans;
}

void findLuxuryCount() {
    long long l, r;
    std::cin >> l >> r;
    long long first = findMinLuxuryCount(l);
    long long second = findMaxLuxuryCount(r);
    long long ans = second - first;
    std::cout << ans << std::endl;
}



int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        t--;
        findLuxuryCount();
    }
    return 0;
}
