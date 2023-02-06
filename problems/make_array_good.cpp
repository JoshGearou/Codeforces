#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

// 1100

void printOperations(std::vector<long long> arr) {
    std::unordered_map<long long, std::queue<int> > map;
    std::vector<std::pair<int, int> > ans;
    for (int i=0; i<arr.size(); i++) {
        std::queue<int> indices;
        if (map.count(arr[i])) {
            indices = map[arr[i]];
        }
        indices.push(i);
        map[arr[i]] = indices;
    }

    std::sort(arr.begin(), arr.end());
    long long last = arr[0];
    for (int i=1; i<arr.size(); i++) {
        long long val = arr[i];
        if (val >= last) {
            long long rem = val % last;
            if (rem > 0) {
                int index = map[arr[i]].front();
                map[arr[i]].pop();
                std::pair<int, int> p(index, last - rem);
                ans.push_back(p);
                last = arr[i] + (last - rem);
            } else {
                last = arr[i];
            }
        } else {
            int index = map[arr[i]].front();
            map[arr[i]].pop();
            std::pair<int, int> p(index, last - arr[i]);
            ans.push_back(p);
        }
    }
    std::cout << ans.size() << std::endl;
    for (std::pair<int, int> p: ans) {
        std::cout << p.first+1 << " " << p.second << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        std::vector<long long> arr;
        int n;
        std::cin >> n;
        for (int j=0; j<n; j++) {
            int a;
            std::cin >> a;
            arr.push_back(a);
        }
        printOperations(arr);
    }
    return 0;
}