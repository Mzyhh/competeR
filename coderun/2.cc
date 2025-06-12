#include <limits.h>
#include <iostream>
#include <vector>


int N, M;
std::vector<std::vector<int>> table;

int min_sum(int i, int j) {
    if (i > N - 1 || j > M - 1) return INT_MAX;
    int current = table[i][j];
    if (i == N - 1 && j == M - 1) return current;
    int down = min_sum(i + 1, j);
    int right = min_sum(i, j + 1);
    return std::min(down, right) + current;
}

int main() {
    std::cin >> N >> M;

    for (int v, i = 0; i < N; ++i){
        table.push_back(std::vector<int>());
        for (int j = 0; j < M; ++j) {
            std::cin >> v;
            table.back().push_back(v);
        }
    }

    std::cout << min_sum(0, 0);

    return 0;
}
