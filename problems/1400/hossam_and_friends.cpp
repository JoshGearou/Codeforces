#include <iostream>
#include <map>
#include <unordered_map>

void goodFriends() {
    int n, m;
    std::cin >> n >> m;
    std::unordered_map<int, int> ends;
    std::map<int, int> map;
    long long ans = 0;
    for (int i=0; i<m; i++) {
        int x, y;
        std::cin >> x >> y;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        if (!ends.count(y)) {
            ends[y] = x;
        }
        ends[y] = std::max(ends[y], x);
    }

    for (int i=1; i<=n; i++) {
        if (ends.count(i)) {
            map[ends[i]] = i;
        }
        if (!map.empty()) {
            auto itr = map.end();
            itr--;
            int largest = itr->first;
            ans += (i - largest);
        } else {
            ans+=i;
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        goodFriends();
        t--;
    }
}