#include <iostream>
#include <map>
#include <unordered_set>

// 1000

bool valid(int len, const std::string& str) {
    std::map<std::string, std::unordered_set<int> > map;
    for (int i=0; i<len; i++) {
        std::string temp = str.substr(i, 2);
        if (map.count(temp)) {
            if ((map[temp].count(i-1) && map[temp].size() >= 2) || (!map[temp].count(i-1) && !map[temp].empty())) {
                return true;
            }
        }
        map[temp].insert(i);
    }
    return false;
}

int main() {
    std::string num_cases;
    std::getline(std::cin, num_cases);
    for (int j=0; j< std::stoi(num_cases); j++) {
        std::string len;
        std::getline(std::cin, len);
        std::string str;
        std::getline(std::cin, str);
        if (valid(std::stoi(len), str)) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
        std::cout << std::endl;
    }
    return 0;
}
