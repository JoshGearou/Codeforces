#include <vector>
#include <iostream>

class Tuple {
public:
    int first;
    int second;
    int third;
    Tuple(int t_first, int t_second, int t_third) {
        first = t_first;
        second = t_second;
        third = t_third;
    }
};


Tuple minOperations(std::vector<int> &v, int s, int e) {
    if (s == e) {
        return Tuple(v[s], v[s], 0);
    }
    int m = (e - s)/2 + s;
    Tuple left = minOperations(v, s, m);
    Tuple right = minOperations(v, m+1, e);
    if ((left.first == -1 && left.second == -1) || (right.first == -1 || right.second == -1)) {
        return Tuple(-1, -1, -1);
    } else if ((left.first > right.first && left.first < right.second) || (right.first > left.first && right.first < left.second)) {
        return Tuple(-1, -1, -1);
    } else {
        int swaps = left.third + right.third;
        if (left.first > right.second) {
            swaps++;
        }
        return Tuple(std::min(left.first, right.first), std::max(left.second, right.second), swaps);
    }
}

void minOperations() {
    std::vector<int> v;
    int m;
    std::cin >> m;
    for (int i=0; i<m; i++) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    Tuple res = minOperations(v, 0, v.size()-1);
    if (res.first == -1 && res.second == -1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << res.third << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        minOperations();
        t--;
    }
}