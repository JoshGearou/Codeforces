#include <iostream>

// 1000

int* construct(int k, int n) {
    int k_temp = k;
    int n_temp = n;
    int curr = 1;
    int diff = 1;
    int index = 0;
    int* arr = new int[k];
    while (index < k) {
        arr[index] = curr;
        k_temp--;
        n_temp = n - curr;
        index++;
        curr = std::min(curr+diff, curr+(n_temp-k_temp+1));
        diff++;
    }
    return arr;
}

int main() {
    std::string temp;
    std::getline(std::cin, temp);
    for (int j=0; j< std::stoi(temp); j++) {
        std::string str;
        std::getline(std::cin, str);
        int k = std::stoi(str.substr(0, str.find(" ")));
        int n = std::stoi(str.substr(2));
        int *arr;
        arr = construct(k, n);
        for (int i = 0; i < k; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
