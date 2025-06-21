/* You are given a teleportation system with N nodes, where each node teleports to exactly one other node (forming a functional graph). Starting from node 1, you will perform k teleportations following the links.

Your task is to determine the node you will reach after exactly k teleportations.
  n — the number of nodes (1 ≤ n ≤ 2×10⁵)

k — the number of teleportations (1 ≤ k ≤ 10¹⁸)

A list of n integers where the i-th integer represents the node that node i teleports to (1-based indexing).*/

// Problem: Find the k-th node in a teleportation graph starting from node 1
// Tags: Functional Graph, Cycle Detection, Large K, Modulo Arithmetic

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> teleport(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> teleport[i];
    }

    vector<int> path;
    set<int> visited;
    int current = 1;

    while (!visited.count(current)) {
        visited.insert(current);
        path.push_back(current);
        current = teleport[current];
    }

    int cycle_start = find(path.begin(), path.end(), current) - path.begin();
    int cycle_len = path.size() - cycle_start;

    if (k < path.size()) {
        cout << path[k] << "\n";
    } else {
        k -= cycle_start;
        cout << path[cycle_start + (k % cycle_len)] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

