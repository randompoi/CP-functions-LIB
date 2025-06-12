/* PROBLEM: Given an array arr[0...(n-1)] containing n integers, a subsequence of arr[] is called 
            Bitonic if it is first increasing, then decreasing. Write a function that takes an array 
            as argument and returns the length of the longest bitonic subsequence.
            
            NOTE: A sequence, sorted in increasing order is considered Bitonic with the decreasing part 
                  as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part 
                  as empty.

   Link: https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/

   Problem based on similar concept: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
*/

/* UNDERLYING CONCEPT :----->

   # This problem is a variation of standard Longest Increasing Subsequence (LIS) problem.
   # We need to construct two arrays lis[] and lds[] using Dynamic Programming solution of LIS problem. 
   # lis[i] stores the length of the Longest Increasing subsequence 𝑬𝒏𝒅𝒊𝒏𝒈 with arr[i]. 
   # lds[i] stores the length of the longest Decreasing subsequence 𝑺𝒕𝒂𝒓𝒕𝒊𝒏𝒈 from arr[i]. 
   # Finally, we need to return the max value of (lis[i] + lds[i] – 1) where i is from 0 to n-1.

   # For example, consider sequence [4, 2, 5, 9, 7, 6, 10, 3, 1]. The contents of LIS and LDS array are

             |lis[i] |lds[i] |
    (i = 0)  |   1   |   3   |
    (i = 1)  |   1   |   2   |
    (i = 2)  |   2   |   3   |
    (i = 3)  |   3   |   5   |
    (i = 4)  |   3   |   4   |
    (i = 5)  |   3   |   3   |
    (i = 6)  |   4   |   3   |
    (i = 7)  |   2   |   3   |
    (i = 8)  |   1   |   1   |

    Longest Bitonic Subsequence length is 7 [4, 5, 9, 7, 6, 3, 1]
    Longest Bitonic Subsequence is formed by (lis[3] + lds[3] - 1)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vset(v, n, val) v.clear(); v.resize(n, val)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T> void _print(stack <T> s);

// modify it's definition below as per need such as it can be used for STL containers with custom args passed
template <class T> void _print(T v); 

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(multimap <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.front()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(priority_queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(T v) {  }

/*******************************************************************************************************************************************************************/

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

int LBS_length(vi &v) {
    int n = (int)v.size();
    if(n == 0) return 0;
    
    vi lis(n), lds(n);
    
    // initialisation of dp matrices lis[] & lds[]
    // longest increasing subsequence ending with v[0] has length 1
    lis[0] = 1;
    
    // longest decreasing subsequence starting with v[n-1] has length 1
    lds[n-1] = 1;

    // choice diagram iterative code 
    // for lis[]
    // start from second element in the vector v[]
    for (int i = 1; i < n; i++) {
        // do for each element in subarray/subvector v[0...(i-1)]
        for(int j = 0; j < i; j++) {
            // find longest increasing subsequence that ends with v[j]
            // where v[j] is less than the current element v[i]
            if (v[i] > v[j] and lis[i] < lis[j]) lis[i] = lis[j];
        }

        // include v[i] in LIS, since for each i we are finding lisLength
        // which ends with v[i]
        lis[i]++;
    }
    
    // for lds[]
    // start from second last element in the vector v[]
    for (int i = (n - 2); i >= 0; i--) {
        // do for each element in subarray/subvector v[(i+1)....(n-1)]
        for(int j = (n - 1); j > i; j--) {
            // find longest decreasing subsequence that starts with v[j]
            // where v[j] is less than the current element v[i]
            if (v[i] > v[j] and lds[i] < lds[j]) lds[i] = lds[j];
        }

        // include v[i] in LDS, since for each i we are finding ldsLength
        // which starts with v[i]
        lds[i]++;
    }

    // find the maximum value of lis[i] + lds[i] - 1
    int mx = lis[0] + lds[0] - 1; 
   
    for(int i = 1; i < n; i++) {
        mx = max(mx, lis[i] + lds[i] - 1);
    } 
     
    // return the final answer calculated
    return mx;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    cout << LBS_length(v) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
    // #endif
    
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(n)