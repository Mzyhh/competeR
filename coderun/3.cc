#include <limits.h>
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

const int MAXNROW = 100, MAXNCOL = 100;

using matrix = std::array<std::array<int, MAXNCOL>, MAXNROW>;

int N, M;
matrix table;

int main() {
    std::cin >> N >> M;

    // input and creating prefix max table
    for (int v, i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j) {
            std::cin >> v;
            table[i][j] = v;
            if (i == 0 && j == 0) continue;
            if (i == 0) table[i][j] += table[i][j - 1];
            else if (j == 0) table[i][j] += table[i - 1][j];
            else table[i][j] += std::max(table[i - 1][j], table[i][j - 1]);
        }
    }

    std::cout << table[N - 1][M - 1] << std::endl; // max sum
    
    std::string way;
    // way reconstruction
    for (int i = N - 1, j = M - 1, cnt = 0; cnt < N + M - 2; ++cnt) {
        if (i == 0) {
            way += std::string(N + M - 2 - cnt, 'R');
            break;
        } 
        if (j == 0) {
            way += std::string(N + M - 2 - cnt, 'D');
            break;
        }
        if (table[i - 1][j] > table[i][j - 1]) {
            way += 'D';
            --i;
        } else {
            way += 'R';
            --j;
        }
    }
    std::for_each(way.rbegin(), way.rend(), [](const char c) { std::cout << c << " "; });
    std::cout << std::endl;
    return 0;
}
