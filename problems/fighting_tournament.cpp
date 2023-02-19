#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <utility>
int count = 0;

void solve(std::vector<int>& v, std::vector<std::pair<int, int> >& questions) {
    std::stack<std::pair<int, int> > stack;
    std::unordered_map<int, int> greatestBefore;
    std::unordered_map<int, int> nextLargerIndex;
    int max = v[0];
    greatestBefore[1] = max;
    stack.push(std::make_pair(1, v[0]));
    for (int j=1; j<v.size(); j++) {
        greatestBefore[j+1] = max;
        max = std::max(max, v[j]);
        while (!stack.empty() && stack.top().second < v[j]) {
            nextLargerIndex[stack.top().first] = j+1;
            stack.pop();
        }
        stack.push(std::make_pair(j+1, v[j]));
    }

    for (int i=0; i<questions.size(); i++) {
        count++;
        std::pair<int, int> question = questions[i];
        int player = question.first;
        int rounds = question.second;
        if (count == 111) {
            for (int j=0; j<v.size(); j++) {
                std::cout << v[j] << "#";
            }
            std::cout << player << "#" << rounds;
            std::cout << std::endl;
        }
        if (greatestBefore[player] > v[player - 1]) {
            std::cout << 0 << std::endl;
        } else {
            rounds-=std::max(0, (player - 2));
            if (rounds <= 0) {
                std::cout << 0 << std::endl;
                return;
            }
            if (!nextLargerIndex.count(player)) {
                std::cout << rounds << std::endl;
            } else {
                int ans = 0;
                if (player > 1) {
                    ans = 1;
                    rounds--;
                }
                ans+= std::min(rounds, nextLargerIndex[player] - player - 1);
                std::cout << ans << std::endl;
            }
        }
    }
}

void player_wins() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> v;
    std::vector<std::pair<int, int> > questions;
    for (int i=0; i<n; i++) {
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    for (int j=0; j<q; j++) {
        int i, k;
        std::cin >> i >> k;
        questions.push_back(std::make_pair(i, k));
    }
    solve(v, questions);
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        player_wins();
        t--;
    }
}