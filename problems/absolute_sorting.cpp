#include <iostream>
#include <limits>

void printNeg() {
    std::cout << -1 << std::endl;
}


void absoluteSorting() {
    int n;
    std::cin >> n;
    long long prev;
    std::cin >> prev;
    long long min = 0;
    long long max = std::numeric_limits<int>::max();
    int i = 1;
    for (i=i; i<n; i++) {
        long long next;
        std::cin >> next;
        if (prev < next) {
            max = std::min(max, (prev + next) / 2);
            if (max < min) {
                printNeg();
                break;
            }
        } else if (prev > next) {
            if ((prev + next) % 2 == 0) {
                min = std::max(min, ((prev + next) / 2));
                if (min > max) {
                    printNeg();
                    break;
                }
            } else {
                min = std::max(min, ((prev + next) / 2) + 1);
                if (min > max) {
                    printNeg();
                    break;
                }
            }
        }
        prev = next;
    }
    if (i < n) {
        while (i < n-1) {
            long long temp;
            std::cin >> temp;
            i++;
        }
        return;
    }
    std::cout << min << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        t--;
        absoluteSorting();
    }
}