#include <iostream>
int getSlope(int x1, int y1, int x2, int y2) {
    if (std::abs(x2 - x1) == 0) {
        return -2;
    } else if (std::abs(y2 -y1) == 0 || std::abs(y2-y1) == std::abs(x2 - x1)) {
        return (y2 -y1) / (x2 -x1);
    }
    return -3;
}

void printAns(int x1, int y1, int x2, int y2) {
    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
}

void createCoordinates() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int slope = getSlope(x1, y1, x2, y2);
    if (slope == 0) {
        int len = std::abs(x1 - x2);
        int x3 = x1;
        int y3 = y1 + len;
        int x4 = x2;
        int y4 = y2 + len;
        printAns(x3, y3, x4, y4);
    } else if (slope == -2) {
        int len = std::abs(y2 - y1);
        int x3 = x1 + len;
        int y3 = y1;
        int x4 = x2 + len;
        int y4 = y2;
        printAns(x3, y3, x4, y4);
    } else if (slope == 1) {
        int len = std::abs(y2 - y1);
        int x3, y3, x4, y4;
        if (x2 < x1) {
            x3 = x2;
            y3 = y2 + len;
            x4 = x1;
            y4 = y1 - len;
        } else {
            x3 = x1;
            y3 = y1 + len;
            x4 = x2;
            y4 = y2 - len;
        }
        printAns(x3, y3, x4, y4);
    } else if (slope == -1) {
        int len = std::abs(y2 - y1);
        int x3, y3, x4, y4;
        if (x2 < x1) {
            x3 = x2;
            y3 = y2 - len;
            x4 = x1;
            y4 = y1 + len;
        } else {
            x3 = x1;
            y3 = y1 - len;
            x4 = x2;
            y4 = y2 + len;
        }
        printAns(x3, y3, x4, y4);
    } else {
        std::cout << -1 << std::endl;
    }
}

int main() {
    createCoordinates();
}
