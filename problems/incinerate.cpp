#include <iostream>
#include <queue>

// 1200

class Monster {
public:
    int h;
    int p;
    Monster(int t1, int t2) {
        h = t1;
        p = t2;
    }
    Monster() {}
};

struct comparePower {
    bool operator()(Monster const & m1, Monster const & m2) {
        return m1.p > m2.p;
    }
};

void willDestroy(std::priority_queue<Monster, std::vector<Monster>, comparePower>& pq, int temp) {
    int k = temp;
    int count = k;
    while (!pq.empty() && count > 0) {
        Monster curr;
        curr.h = pq.top().h;
        curr.p = pq.top().p;
        if (pq.top().h > k) {
            k+=(count-pq.top().p);
            count-=pq.top().p;
        } else {
            pq.pop();
        }
    }

    if (count <= 0) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }
}


int main() {
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        int k;
        std::cin >> n >> k;
        int h[n];
        int p[n];
        std::priority_queue<Monster, std::vector<Monster>, comparePower> pq;
        for (int j=0; j<n; j++) {
            int x;
            std::cin >> x;
            h[j] = x;
        }
        for (int j=0; j<n; j++) {
            int x;
            std::cin >> x;
            p[j] = x;
        }
        for (int j=0; j<n; j++) {
           pq.push(Monster(h[j], p[j]));
        }
        willDestroy(pq, k);
    }
    return 0;
}