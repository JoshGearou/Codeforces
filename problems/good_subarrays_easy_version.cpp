#include <iostream>
#include <vector>

long long computeCount(long long n) {
    return (n * (n+1)) / 2;
}

void solve(std::vector<int>& v) {
    long long count = 0;
    int s = 0;
    int e = 0;
    int index = 1;
    while (s <= e && e < v.size()) {
        if (v[e] >= index) {
            e++;
            index++;
        } else {
            count+=computeCount(index-1);
            int diff = std::abs(v[e] - index);
            s+=diff;
            count-= computeCount((e - s));
            index = (e - s) + 1;
        }
    }
    if (v[e-1] >= index - 1) {
        count+= computeCount(index-1);
    }
    std::cout << count << std::endl;
}

void goodSubarrays() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (int i=0; i<n; i++) {
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    solve(v);
}


int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        t--;
        goodSubarrays();
    }
}