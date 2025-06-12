#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M;
    vector<vector<int>> dp(N, vector(N, 0));
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        dp[x - 1][y - 1] = 1;
        dp[y - 1][x - 1] = 1;
    }
    vector<int> res(N, 0);
    vector<int> tmp = {0};
    int count = 0;
    while (!tmp.empty()) {
        int curr = tmp.back();
        tmp.pop_back();
        if (res[curr]) continue;
        res[curr] = 1;
        count++;
        for (int i = 0; i < N; ++i) {
            if (dp[curr][i]) tmp.push_back(i);
        }
    }
    cout << count << endl;
    for (int i = 0; i < N; ++i)
        if (res[i]) cout << i + 1 << " ";
}
