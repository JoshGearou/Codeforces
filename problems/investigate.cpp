#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>

void permutations(std::vector<int> arr) {
    std::set<int> s1;
    std::set<int> s2;
    std::unordered_set<int> s3;
    std::vector<int> a1;
    std::vector<int> a2;
    for (int i=1; i<=arr.size(); i++) {
        s1.insert(i);
        s2.insert(i);
        a2.push_back(0);
        a1.push_back(0);
    }

    for (int i=0; i<arr.size(); i++) {
        if (s1.count(arr[i])) {
            s1.erase(arr[i]);
            a1[i] = arr[i];
            s3.insert(i);
        }
    }

    for (int i=0; i<arr.size(); i++) {
        if (!s3.count(i)) {
            if (!s2.count(arr[i])) {
                std::cout << "NO" << std::endl;
                return;
            } else {
                if (s1.empty()) {
                    std::cout << "NO" << std::endl;
                    return;
                }
                s2.erase(arr[i]);
                a2[i] = arr[i];
                auto lower = s1.lower_bound(arr[i]-1);
                int next_lower = *lower;
                if (arr[i] < next_lower) {
                    std::cout << "NO" << std::endl;
                    return;
                } else {
                    s1.erase(next_lower);
                    a1[i] = next_lower;
                }
            }
        }
    }
    for (int i=0; i<arr.size(); i++) {
        if (a2[i] == 0) {
            int val = a1[i];
            auto lower = s2.lower_bound(val-1);
            int next_lower = *lower;
            if (val < next_lower) {
                std::cout << "NO" << std::endl;
                return;
            } else {
                s2.erase(next_lower);
                a2[i] = next_lower;
            }
        }
    }
    std::cout << "YES" << std::endl;
    for (int i=0; i<a1.size(); i++) {
        std::cout << a1[i] << " ";
    }
    std::cout << std::endl;
    for (int i=0; i<a2.size(); i++) {
        std::cout << a2[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        std::vector<int> arr;
        int n;
        std::cin >> n;
        for (int j=0; j<n; j++) {
            int a;
            std::cin >> a;
            arr.push_back(a);
        }
        permutations(arr);
    }
    return 0;
}