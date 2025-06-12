#include <array>
#include <iostream>

using namespace std;

constexpr int N_MAX{50};
int main() {
    array<array<int, N_MAX>, N_MAX> table;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            table[i][j] = i == 0 && j == 0 ? 1 : 0;  
            if (i - 2 >= 0 && j - 1 >= 0)
                table[i][j] += table[i - 2][j - 1];
            if (i - 1 >= 0 && j - 2 >= 0)
                table[i][j] += table[i - 1][j - 2];
        }
    }
    cout << table[N - 1][M - 1] << endl;
    return 0;
}
