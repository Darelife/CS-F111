#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;

const int inf = 1e9 + 5;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  vint a(n);
  forr(i, n) cin >> a[i];
  sort(allEle(a));
  vint diff;
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] > x) {
      diff.pba(a[i] - a[i - 1]);
    }
  }
  sort(allEle(diff));
  int ans = diff.size() + 1;
  for (int i = 0; i < diff.size(); i++) {
    if (diff[i] % x == 0) {
      int req = diff[i] / x - 1;
      if (req <= k) {
        k -= req;
        ans--;
      }
    }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}