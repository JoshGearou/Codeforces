#include <iostream>

// 1300


void numWins(std::string str) {
    int count = 1;
    int arr[str.size()];
    for (int i=0; i<str.size(); i++) {
        arr[i] = str.at(i) - '0';
    }
    int last = arr[0];
    std::cout << count << " ";
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i=1; i<len; i++) {
        if (arr[i] == 0) {
            if (last == 0) {
                std::cout << count << " ";
            } else {
                count = i+1;
                std::cout << count << " ";
            }
            last = 0;
        } else {
            if (last == 1) {
                std::cout << count << " ";
            } else {
                count = i+1;
                std:: cout << count << " ";
            }
            last = 1;
        }
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        int x;
        std::cin >> x;
        std::string temp;
        std::cin >> temp;
        numWins(temp);
    }
    return 0;
}