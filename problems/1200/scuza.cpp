#include <iostream>
#include <unordered_map>
#include <vector>

int binarySearch(long long question, std::vector<long long> &v, int end) {
    int start = 0;
    while (start <= end) {
        int mid = (end-start)/2 + start;
        if (v[mid] == question) {
            return mid;
        } else if (v[mid] > question) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return end;
}

void scuza() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> v;
    std::vector<long long> questions;
    std::vector<long long> prefix;
    std::unordered_map<long long, int> map;
    std::vector<long long> maxAt;
    long long sum = 0;
    for (int i=0; i<n; i++) {
        long long x;
        std::cin >> x;
        v.push_back(x);
        if (i == 0) {
            maxAt.push_back(x);
        } else {
            if (x > maxAt[maxAt.size() - 1]) {
                map[maxAt[maxAt.size() - 1]] = i-1;
                maxAt.push_back(x);
            }
        }
        sum+=x;
        prefix.push_back(sum);
    }
    map[maxAt[maxAt.size()-1]] = v.size() - 1;
    for (int i=0; i<q; i++) {
        long long x;
        std::cin >> x;
        questions.push_back(x);
    }
    for (long long question: questions) {
        int index = binarySearch(question, maxAt, maxAt.size()-1);
        if (index < 0) {
            std::cout << 0 << " ";
            continue;
        }
        if (maxAt[index] == question) {
            int lastIndex = map[question];
            std::cout << prefix[lastIndex] << " ";
        } else {
            long long val = maxAt[index];
            int lastIndex = map[val];
            std::cout << prefix[lastIndex] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        scuza();
        t--;
    }
}