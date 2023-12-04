#include <bits/stdc++.h>
#define ll long long
#define EPS 1e-8
#define prev dsfs
using namespace std;
 
const int MOD = 998244353;
const int MAX = 6e5 + 111;
const ll INF = 1e18 + 10;
 
const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, a[MAX], b[MAX];

string s;

int main() {
#ifdef LOCAL
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    chrono::steady_clock::time_point timestamp_begin = std::chrono::steady_clock::now();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
    }
#ifdef LOCAL
    chrono::steady_clock::time_point timestamp_end = std::chrono::steady_clock::now();
    fprintf(stderr, "%.4f", 0.001 * std::chrono::duration_cast<std::chrono::milliseconds> (timestamp_end - timestamp_begin).count());
#endif
    return 0;
}
