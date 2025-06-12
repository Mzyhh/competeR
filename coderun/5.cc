#include <vector>
#include <iostream>
using namespace std;
constexpr int MIN_PRICE = 100;

//35
//75
//176
//235 64
//298 127

int main() {
    int N, v;
    cin >> N;
    if (N == 0) cout << 0 << endl << 0 << " " << 0 << endl;
    cin >> v;
    vector<vector<int>> t = {vector(1, v)};
    int ks = int(v > MIN_PRICE);
    for (int i = 1; i < N; ++i) {
        cin >> v;
        t.push_back(vector(ks + 1, 0));
        ks += int(v > MIN_PRICE);
        for (int j = 0; j < t.back().size(); ++j) {
            if (j == 0) {
                t[i][j] = t[i - 1][j] + v;
            }
            else {
                if (j >= t[i - 1].size()){
                    t[i][j] = t[i - 1][j - 1];
                }
                else {
                    if (t[i - 1][j]  + v < t[i - 1][j - 1])
                        t[i][j] = t[i - 1][j] + v;
                    else
                        t[i][j] = t[i - 1][j - 1];
                }

            }
        }
    }
    cout << endl;
    for (auto& row : t) {
        for (auto item : row)
            cout << item << " ";
        cout << endl;
    }
    cout << endl << ks << endl;
    //for (auto v : t.back()) 
    //    cout << v << " ";
    return 0;
}
