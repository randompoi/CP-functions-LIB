#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 305;
ll fact[MAX];
//O(n^2)
// Precompute factorials up to 300
void compute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

// Return the 0-based lexicographic rank of a permutation
ll get_rank(const vector<int>& perm) {
    int n = perm.size();
    ll rank = 0;
    set<int> remaining;
    for (int i = 1; i <= n; i++) remaining.insert(i);

    for (int i = 0; i < n; i++) {
        int x = perm[i];
        // Count how many numbers in remaining set are < x
        int count = distance(remaining.begin(), remaining.lower_bound(x));
        rank += count * fact[n - i - 1];
        remaining.erase(x);
    }
    return rank;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute_factorials();

    int n;
    cin >> n;
    vector<int> P(n), Q(n);
    for (int i = 0; i < n; i++) cin >> P[i];
    for (int i = 0; i < n; i++) cin >> Q[i];

    ll rankP = get_rank(P);
    ll rankQ = get_rank(Q);
    cout << abs(rankP - rankQ) << "\n";
}
