#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

class Elem {
public:
    int val;
    int index;
    Elem(int vall, int indexx) {
        val = vall;
        index = indexx;
    }
};

struct compareElem {
    bool operator()(Elem const & m1, Elem const & m2) {
        return m1.val > m2.val;
    }
};


void permutations(std::vector<int> arr) {
    std::vector<int> a1;
    std::vector<int> a2;
    std::set<int> s1;
    std::set<int> s2;
    std::vector<Elem> v;
    for (int i=0; i<arr.size(); i++) {
        a1.push_back(0);
        a2.push_back(0);
        s1.insert(i+1);
        s2.insert(i+1);
        Elem elem(arr[i], i);
        v.push_back(elem);
    }
    std::sort(v.begin(), v.end(), compareElem());
    for (int i=0; i<v.size(); i++) {
        Elem elem = v[i];
        int val = elem.val;
        int index = elem.index;
        if (s1.count(val)) {
            a1[index] = val;
            s1.erase(val);
        } else if (s2.count(val)) {
            a2[index] = val;
            s2.erase(val);
        } else {
            std::cout << "NO" << std::endl;
            return;
        }
    }
    for (int i=0; i<v.size(); i++) {
        Elem elem = v[i];
        int val = elem.val;
        int index = elem.index;
        if (a1[index] != 0) {
            auto it = s2.end();
            it--;
            if (val < *it) {
                std::cout << "NO" << std::endl;
                return;
            }
            a2[index] = *it;
            s2.erase(*it);
        } else {
            auto it = s1.end();
            it--;
            if (val < *it) {
                std::cout << "NO" << std::endl;
                return;
            }
            a1[index] = *it;
            s1.erase(*it);
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