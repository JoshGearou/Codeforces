#include <iostream>
#include <vector>

const int N = 3e5 + 50;

int v[2][N];

bool dfs(int i, int j, int col, int bCount) {
    if (bCount == 0) {
        return true;
    }
    bool valid = false;
    v[i][j] = 1;
    if (i == 0 && v[i + 1][j] == 0) {
        valid = dfs(i+1, j, col, bCount - 1);
    } else if (i == 1 && v[i-1][j] == 0) {
        valid = dfs(i-1, j, col, bCount - 1);
    } else if (j < col && v[i][j+1] == 0) {
        valid = dfs(i, j+1, col, bCount - 1);
    }
    return valid;
}

void canPaint() {
    int c;
    std::cin >> c;
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    int bCount = 0;
    for (int k=0; k<c; k++) {
        if (str1[k] == 'B') {
            bCount++;
        }
        if (str2[k] == 'B') {
            bCount++;
        }
        v[0][k] = str1[k] == 'B' ? 0 : 1;
        v[1][k] = str2[k] == 'B' ? 0 : 1;
    }
    bool valid = false;
    if (v[0][0] == 0) {
        valid = dfs(0, 0, c, bCount - 1);
    }
    for (int k=0; k<c; k++) {
        v[0][k] = str1[k] == 'B' ? 0 : 1;
        v[1][k] = str2[k] == 'B' ? 0 : 1;
    }
    if (!valid && v[1][0] == 0) {
        valid = dfs(1, 0, c, bCount - 1);
    }
    if (valid) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        canPaint();
    }
}