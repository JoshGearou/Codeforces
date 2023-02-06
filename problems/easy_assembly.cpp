#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

void addToMap(int val, int index, std::unordered_map<int, std::unordered_set<int> >& val_to_indices) {
    std::unordered_set<int> set;
    if (val_to_indices.count(val)) {
        set = val_to_indices[val];
    }
    set.insert(index);
    val_to_indices[val] = set;
}

int split(std::list<int>& lst, std::vector<std::list<int> >& v, std::unordered_map<int, std::unordered_set<int> >& val_to_indices) {
    int prev = *(lst.begin());
    auto it = lst.begin();
    int splits = -1;
    while (it != lst.end()) {
        splits++;
        std::list<int> temp;
        int curr = *it;
        while (it != lst.end() && curr <= prev) {
            temp.push_back(curr);
            it++;
            prev = curr;
            curr = *it;
        }
        v.push_back(temp);
        prev = *it;
        int val = *(v[v.size() - 1].begin());
        addToMap(val, v.size() - 1, val_to_indices);
    }
    return splits;
}

int split(std::list<int>& lst, std::list<int>::iterator& itr, std::vector<std::list<int> >& v, std::unordered_map<int, std::unordered_set<int> >& val_to_indices) {
    std::list<int> new_lst;
    new_lst.splice(new_lst.end(), lst, itr, lst.end());
    v.push_back(new_lst);
    int val = *(new_lst.begin());
    addToMap(val, v.size() - 1, val_to_indices);
    return 1;
}

int combine(std::list<int>& lst1, int next, std::unordered_map<int, std::unordered_set<int> >& val_to_indices, std::vector<std::list<int> >& v) {
    int index = *(val_to_indices[next].begin());
    std::list<int>* lst2 = &v[index];
    int largest = *(v[index].begin());
    val_to_indices[largest].erase(index);
    lst1.splice(lst1.end(), *lst2);
    return 1;
}

void assemble(std::vector<std::list<int> >& temp, std::vector<int>& sorted) {
    int splits = 0;
    int combines = 0;
    std::vector<std::list<int> > v;
    std::unordered_map<int, std::unordered_set<int> > val_to_indices;
    for (int i=0; i<temp.size(); i++) {
        splits+=split(temp[i], v, val_to_indices);
    }
    int in = *(val_to_indices[sorted[sorted.size() - 1]].begin());
    std::list<int>* first = &v[in];
    auto itr = first->begin();
    itr++;
    val_to_indices[sorted[sorted.size() - 1]].erase(in);
    for (int i=sorted.size() - 2; i>=1; i--) {
        if (itr != (*first).end() && *itr == sorted[i]) {
            itr++;
        } else {
            std::list<int> second = v[*(val_to_indices[sorted[i]].begin())];
            if (itr != (*first).end()) {
                splits += split(*first, itr, v, val_to_indices);
            }
            first = &v[in];
            itr = v[*(val_to_indices[sorted[i]].begin())].begin();
            combines+=combine(*first, sorted[i], val_to_indices, v);
            itr++;
        }
    }

    if ((*first).size() != sorted.size()) {
        combines++;
    }
    std::cout << splits << " " << combines;
}


int main() {
    int t;
    std::cin >> t;
    std::vector<std::list<int> > v;
    std::vector<int> sorted;
    while (t > 0) {
        int size;
        std::list<int> lst;
        std::cin >> size;
        for (int i=0; i<size; i++) {
            int x;
            std::cin >> x;
            lst.push_front(x);
            sorted.push_back(x);
        }
        v.push_back(lst);
        t--;
    }
    std::sort(sorted.begin(), sorted.end());
    assemble(v, sorted);
}