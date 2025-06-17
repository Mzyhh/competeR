#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;


using Graph = vector<vector<int>>;
bitset<100000> is_processed(0);
int N, M;

void dfs(const Graph& g, vector<int>& vs, int v) {
    if (is_processed[v]) { return; }
    is_processed.set(v);
    vs.push_back(v);
    for (int i = 0; i < N; ++i)
    for (auto i : g[v])
        dfs(g, vs, i);
}

// this is faster
void bfs(const Graph& g, vector<int>& vs, int v) {
    queue<int> q; 
    q.push(v);
    while(!q.empty()) {
        v = q.front();
        q.pop();
        if (is_processed[v]) continue;
        vs.push_back(v);
        is_processed.set(v);
        for (auto i : g[v])
            q.push(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    Graph g(N, vector<int>());
    for (int i = 0, j, k; i < M; ++i) {
        cin >> j >> k;
        g[--j].push_back(--k);
        g[k].push_back(j);
    }

    vector<vector<int>> components;
    for (int i = 0; i < N; ++i) {
        if (is_processed[i]) continue;
        components.push_back(vector<int>());
        bfs(g, components.back(), i); 
    }

    cout << components.size() << endl;
    for (auto& c : components) {
        cout << c.size() << endl;
        for (auto i : c) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

