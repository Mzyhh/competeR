#include <iostream>
#include <unordered_map>

int main() {
    using namespace std;

    unordered_map<int, bool> hash;
    int result{0}, n, item;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> item;
        auto it = hash.find(item);
        if (it == hash.end()) {
            hash.emplace(item, true);
            result++;
        } else {
            if (it->second) result--;
            it->second = false;
        }
    }
    cout << result << endl;
    return 0;
}
