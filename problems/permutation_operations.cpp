#include <iostream>
#include <vector>

class Difference {
public:
    int index;
    long long diff;
    Difference(int temp_index, long long temp_diff) {
        index = temp_index;
        diff = temp_diff;
    }
};

struct compareDifference {
    bool operator()(Difference const & m1, Difference const & m2) {
        if (m1.diff < m2.diff) {
            return m1.diff;
        } else if (m1.diff > m2.diff) {
            return m2.diff;
        }
        return m1.index - m2.index;
    }
};

void permutation_operations() {
    int n;
    std::cin >> n;
    std::vector<long long> data;
    std::vector<Difference> diffs;
    std::vector<long long> operations;
    for (int i = 1; i <= n; i++) {
        operations.push_back(((long long) i * (i+1))/ 2);
        long long x;
        std::cin >> x;
        data.push_back(x);
    }

    for (int i = n - 2; i >= 0; i--) {
        long long diff = data[i] - data[i + 1];
        std::vector<int> v;
        if (diff > 0) {
            Difference difference(i+1, diff);
            diffs.push_back(difference);
        }
    }
    std::sort(diffs.begin(), diffs.end(), compareDifference());

    int operationsIndex = 0;
    long long ops = 0;
    int used = 0;
    for (int i=0; i<diffs.size(); i++) {
        int index = diffs[i].index;
        long long diff = diffs[i].diff;
        int prev = operationsIndex;
        while (operations[operationsIndex] - ops < diff) {
            used++;
            std::cout << index + 1 << " ";
            operationsIndex++;
        }
        std::cout << index + 1 << " ";
        used++;
        ops = operations[operationsIndex];

    }
    while (used < n) {
        std::cout << 1 << " ";
        used++;
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        permutation_operations();
        t--;
    }
}
