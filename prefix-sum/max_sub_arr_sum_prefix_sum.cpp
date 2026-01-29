#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("in.txt", "r", stdin);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<int> pf(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    pf[i] = pf[i - 1] + a[i];
  }

  int ans = LLONG_MIN;  // Handle first element (non-empty subarray)
  int mn = 0;      // Minimum prefix sum seen so far

  for (int r = 1; r <= n; ++r) {
    ans = max(ans, pf[r] - mn);  // Max subarray ending at r
    mn = min(mn, pf[r]);         // Update minimum prefix sum
  }

  cout << ans << endl;
  // return 0;
}
