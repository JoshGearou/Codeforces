#include <iostream>
#include <vector>
#include <queue>

// 1300


void goodIndices(std::vector<long long> arr) {
    int numIndices = 0;
    std::vector<int> indices;
    long long sum = 0;
    std::priority_queue<long long, std::vector<long long> > pq;
    for (int i=0; i<arr.size(); i++) {
        sum+=arr[i];
        pq.push(arr[i]);
    }
    for (int i=0; i<arr.size(); i++) {
        long long num = arr[i];
        long long last = pq.top();
        if (num == last) {
            pq.pop();
            last = pq.top();
            pq.push(num);
        }
        long long temp = (sum - num) - last;
        if (temp == last) {
            numIndices++;
            indices.push_back(i);
        }
    }

    std::cout << numIndices << std::endl;
    for (int val: indices) {
        std::cout << val+1 << " ";
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> arr;
    for (int i=0; i<n; i++) {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }
    goodIndices(arr);
    return 0;
}