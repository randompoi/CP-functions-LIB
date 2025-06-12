// Prob: https://leetcode.com/problems/flood-fill/
//       https://www.techiedelight.com/flood-fill-algorithm/

// Ref: https://www.youtube.com/watch?v=C-2_uSRli8o&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=9&ab_channel=takeUforward

/*******************************************************************************************************************************************************************/

/* # Flood Fill Algorithm is a simple variant of BFS or DFS that can be used to label(colour) the various 
     connected components present in a graph.

   # It is generally performed on implicit graphs(2D matrices).

   # Starting from a particular cell we call DFS on the neighbouring cells to colour them.
     Neighbours can be '4' (up, down, left, right) or '8' if we include diagonals also.
*/

/*******************************************************************************************************************************************************************/

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

vi dx = {-1, 0, 1, 0};
vi dy = {0, 1, 0, -1};

bool is_valid(int x, int y, int n, int m) {
    return (x >= 0) and (x < n) and (y >= 0) and (y < m);
}

void dfs(int row, int col, char old, char replacement, int n, int m, vvc &v) {
    v[row][col] = replacement;
    
    for(int d = 0; d < 4; d++) {
        int nx = row + dx[d], ny = col + dy[d];
        if(is_valid(nx, ny, n, m) and (v[nx][ny] == old)) {
            dfs(nx, ny, old, replacement, n, m, v);
        }
    }
}

void flood_fill_algorithm(vvc &v, int sr, int sc, char replacement) {
    int n = sz(v);
    if(n == 0) return;
    
    int m = sz(v[0]);
    
    if(v[sr][sc] == replacement) return;
    
    char old = v[sr][sc];
    
    dfs(sr, sc, old, replacement, n, m, v);
}

void print_grid(vvc &v) {
    for(int i = 0; i < sz(v); i++) {
        for(int j = 0; j < sz(v[i]); j++) {
            cout << v[i][j];
        }
        
        cout << "\n";
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    vvc v(n, vc(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> v[i][j];
    }
    
    int sr, sc; cin >> sr >> sc;
    
    char replacement; cin >> replacement;

    flood_fill_algorithm(v, sr, sc, replacement);

    print_grid(v);
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

/*Sample I/P:
  
15 30
..............................
...............#####..........
...............#...#..........
.......#########...#######....
......###......######....###..
.....##....................##.
....##......................##
.....##....................##.
......##..................##..
.......##................##...
........##..............##....
.........###...........###....
...........####......####.....
.............##########.......
.........A..P..P..L..E........
8 20
K

SAMPLE O/P:
..............................
...............#####..........
...............#...#..........
.......#########...#######....
......###KKKKKK######KKKK###..
.....##KKKKKKKKKKKKKKKKKKKK##.
....##KKKKKKKKKKKKKKKKKKKKKK##
.....##KKKKKKKKKKKKKKKKKKKK##.
......##KKKKKKKKKKKKKKKKKK##..
.......##KKKKKKKKKKKKKKKK##...
........##KKKKKKKKKKKKKK##....
.........###KKKKKKKKKKK###....
...........####KKKKKK####.....
.............##########.......
.........A..P..P..L..E........

*/

// TC: O(n x m)
// SC: O(n x m)

/*******************************************************************************************************************************************************************/

// FOR IMPLEMENTATION USING "BFS" REFER: https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/