#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// this algorithm work if M is coprime with 10
// Counts how many substrings of s are divisible by M
ll count_divisible_substrings(const string& s, int M) {
    unordered_map<int, ll> count;
    count[0] = 1;

    int cur = 0;
    int power = 1;
    ll result = 0;

    // Traverse string from right to left
    for (int i = s.size() - 1; i >= 0; i--) {
        int digit = s[i] - '0';
        cur = (cur + digit * power) % M;
        result += count[cur];
        count[cur]++;
        power = (power * 10) % M;
    }

    return result;
}
