#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

void construct() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    std::unordered_map<int, int> map1;
    std::unordered_map<int, int> map2;
    for (int i=0; i<n; i++) {
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    std::sort(v.begin(), v.end());
    int minDiff = v.size();
    int index = -1;
    for (int i=0; i<v.size()-1; i++) {
        if (v[i] != v[i + 1]) {
            if (std::abs((i + 1) - (n - (i + 1))) < minDiff) {
                minDiff = std::abs((i + 1) - (n - (i + 1)));
                index = i;
            }
        }
    }
    long long ans = ((long long) (index+1)) * (n - (index +1));
    if (index != -1) {
        std::cout << ans << std::endl;
    } else {
        std::cout << n / 2 << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        construct();
        t--;
    }
}