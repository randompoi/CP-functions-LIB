// Reference(s): https://www.youtube.com/watch?v=lFBpH_Mt_LI
//               https://www.youtube.com/watch?v=CvPIX0HBZbQ
//               https://www.youtube.com/watch?v=i7xZ4Yd_jN8

/***************************************************************************************************************/

// Problem: Pongal Bunk
// Contest: CodeChef - Practice(Extcontest)
// URL: https://www.codechef.com/problems/COWA19B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 04-02-2021 09:09:32 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

void solve()
{
  	int n, q; cin >> n >> q;
  	int a[n+2] = {0}, b[n+2] = {0};
  	while(q--) {
  		int l, r; cin >> l >> r;
  		a[l] += 1; a[r+1] -= 1;
  		b[r+1] -= r - l + 1;
  	} 
  	
  	for(int i = 1; i <= n; i++) a[i] += a[i-1];
  	for(int i = 1; i <= n; i++) a[i] += a[i-1];
  	for(int i = 1; i <= n; i++) b[i] += b[i-1];
  	for(int i = 1; i <= n; i++) b[i] += a[i];
  	
  	int m; cin >> m;
  	while(m--) {
  		int idx; cin >> idx;
  		cout << b[idx] << "\n";
  	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}