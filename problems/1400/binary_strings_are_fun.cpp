#include <iostream>
#include <vector>
#include <utility>

void solve(int n, std::string& s) {
    long long MOD = 998244353;
    std::vector<long long > v;
    for (int i=0; i<4; i++) {
        v.push_back(0);
    }
    if (s[0] == '0') {
        v[0] = 1;
        v[1] = 1;
    } else {
        v[2] = 1;
        v[3] = 1;
    }
    long long ans = 1;
    for (int i=1; i<n; i++) {
        if (s[i] == '0') {
            v[1] = ((v[1] * 2) + v[2]) % MOD;
            v[0] = 1;
            ans = (ans + v[1]) % MOD;
            v[2] = 0;
            v[3] = 0;
        } else if (s[i] == '1') {
            v[3] = ((v[3] * 2) + v[0]) % MOD;
            v[2] = 1;
            ans = (ans + v[3]) % MOD;
            v[0] = 0;
            v[1] = 0;
        }
    }
    std::cout << ans << std::endl;
}

void goodExtensions() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin>>std::ws;
    std::getline(std::cin, s);
    solve(n, s);
}

int main() {
    int t;
    std::cin>> t;
    while (t > 0) {
        goodExtensions();
        t--;
    }
}