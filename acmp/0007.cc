#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> a(3);
    for (auto& s : a) cin >> s;
    auto maxlen = max_element(a.begin(), a.end(), [](auto& a, auto& b) { return a.size() < b.size(); })->size();
    auto new_end = remove_if(a.begin(), a.end(), [maxlen](auto& s) { return s.size() < maxlen; });
    a.erase(new_end, a.end());
    int i = 0;
    while (a.size() > 1 && i < maxlen) {
        auto max_elem = max_element(a.begin(), a.end(), [i](auto& l, auto& r) { return l[i] < r[i]; })[0][0];
        new_end = remove_if(a.begin(), a.end(), [max_elem](auto& s) { return s[0] < max_elem; });
        a.erase(new_end, a.end());
    }
    cout << a[0];
}
