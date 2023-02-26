#include <iostream>
#include <vector>
#include <utility>

void shuffle() {
    int n;
    std::cin >> n;
    std::vector<long long> v;
    std::vector<std::pair<int, int> > ans;
    for (int i=0; i<n; i++) {
        long long a;
        std::cin >> a;
        v.push_back(a);
    }
    if (n == 1) {
        std::cout << 0 << std::endl;
        return;
    }
    int end = v.size() - 1;
    if ((v[0] + v[end]) % 2 == 0) {
        v[0] = v[end];
    } else {
        v[end] = v[0];
    }
    ans.push_back(std::make_pair(1, end+1));
    for (int i=1; i<v.size()-1; i++) {
        if ((v[i] + v[0]) % 2 == 0) {
            ans.push_back(std::make_pair(i+1, end+1));
        } else {
            ans.push_back(std::make_pair(1, i+1));
        }
    }
    std::cout << ans.size() << std::endl;
    for (int i=0; i<ans.size(); i++) {
        std::cout << ans[i].first << " " << ans[i].second << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        t--;
        shuffle();
    }
}