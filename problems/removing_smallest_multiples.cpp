#include <iostream>

void minimumCost(std::string &str, int n) {
    long long ans = 0;
    long long cost[n];
    for (int i=0; i<n; i++) {
        cost[i] = 0;
    }
    for (int i=n; i>0; i--) {
        for (int j=i; j<=n; j+=i) {
            if (str[j-1] == '0') {
                cost[j-1] = i;
            } else {
                break;
            }
        }
    }
    for (int i=0; i<n; i++) {
        ans+=cost[i];
    }
    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        std::cin >> n;
        std::string str;
        std::cin >> str;
        minimumCost(str, n);
    }
    return 0;
}