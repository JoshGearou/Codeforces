#include <iostream>
#include <vector>

void inversions(const std::vector<long long>& v) {
    std::vector<int> zeros;
    std::vector<int> ones;
    for (int i=0; i<v.size(); i++) {
        zeros.push_back(0);
        ones.push_back(0);
    }
    int zeroCount = 0;
    int oneCount = 0;
    for (int i=v.size()-2; i>=0; i--) {
        long long val = v[i+1];
        if (val == 0) {
            zeroCount++;
            zeros[i] = zeroCount;
        } else {
            zeros[i] = zeroCount;
        }
    }

    for (int i=1; i<v.size(); i++) {
        long long val = v[i-1];
        if (val == 1) {
            oneCount++;
            ones[i] = oneCount;
        } else {
            ones[i] = oneCount;
        }
    }

    long long initial = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i] == 1) {
            initial+=zeros[i];
        }
    }

    long long max = initial;
    for (int i=0; i<v.size(); i++) {
        if (v[i] == 0) {
            long long flipToOne = (initial - ones[i]) + zeros[i];
            max = std::max(max, flipToOne);
        } else {
            long long flipToZero = (initial - zeros[i]) + ones[i];
            max = std::max(max, flipToZero);
        }
    }
    std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        std::cin >> n;
        std::vector<long long> v;
        for (int j=0; j<n; j++) {
            int a;
            std::cin >> a;
            v.push_back(a);
        }
        inversions(v);
    }
}