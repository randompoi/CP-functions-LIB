#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Precompute factorials up to MAX_N
const int MAX_N = 21; // 20! is about 2.4e18, still fits in ll
ll fact[MAX_N];

// Call this before using kth_permutation
void compute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

// Returns the k-th permutation (1-based) of numbers 1..n
vector<int> kth_permutation(int n, ll k) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) nums.push_back(i);

    vector<int> result;
    k--; // convert to 0-based index

    for (int i = n; i >= 1; i--) {
        ll block_size = fact[i - 1];
        int index = k / block_size;
        result.push_back(nums[index]);
        nums.erase(nums.begin() + index);
        k %= block_size;
    }

    return result;
}

int main() {
    compute_factorials(); // Always call this first

    int n;
    ll k;
    cin >> n >> k;

    vector<int> perm = kth_permutation(n, k);

    for (int x : perm) cout << x << " ";
    cout << "\n";
}
