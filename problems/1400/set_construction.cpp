#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void construct_sets() {
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int> > adj;
    unordered_map<int, unordered_set<int> > sets;
    int num = 1;
    for (int i=1; i<=n; i++) {
        cin >> ws;
        string str;
        getline(cin, str);
        for (int j=1; j<=n; j++) {
            if (str[j-1] == '1') {
                unordered_set<int> set;
                if (adj.count(i)) {
                    set = adj[i];
                }
                set.insert(j);
                adj[i] = set;
            }
        }
    }
    for (int u=1; u<=n; u++) {
        unordered_set<int> s1;
        if (sets.count(u)) {
            s1 = sets[u];
        }
        s1.insert(num);
        sets[u] = s1;
        if (adj.count(u)) {
            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                int v = *it;
                unordered_set<int> s2;
                if (sets.count(v)) {
                    s2 = sets[v];
                }
                s2.insert(num);
                sets[v] = s2;
            }
        }
        num++;
    }
    for (int i=1; i<=n; i++) {
        cout << sets[i].size() << " ";
        for (auto it = sets[i].begin(); it != sets[i].end(); it++) {
            int v = *it;
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        construct_sets();
        t--;
    }
}