// Refer: https://www.youtube.com/watch?v=4GNUt5unEnM
// Got another idea but failed
// Learned that you have no limits in thinking
// prefix sum array can be used to cnt number of zeros
// Simple brute force
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define N 2e5 + 5
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = l; i < r; i++)
#define sz(a) (int)((a).size())
#define ll long long
#define ar array
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"
#define mp make_pair

int n, q;

void solve()
{
  vpii intervals(q);
  vector<int> cnt(n + 1);
  for (int i = 0; i < q; i++)
  {
    int fr, t;
    cin >> fr >> t;
    intervals[i].f = fr;
    intervals[i].s = t;
    for (int j = fr; j <= t; j++)
      cnt[j]++;
  }

  int ans = 0;
  for (int k = 0; k < q; k++)
  {
    int cnt_pos = 0;
    vector<int> ones(n + 1);
    for (int i = intervals[k].f; i <= intervals[k].s; i++)
      cnt[i]--;
    for (int i = 1; i <= n; i++)
    {
      if (cnt[i] > 0)
        cnt_pos++;
      if (cnt[i] == 1)
        ones[i]++;
    }
    for (int i = 2; i <= n; i++)
      ones[i] += ones[i - 1];
    for (int j = k + 1; j < q; j++)
      ans = max(ans, cnt_pos - (ones[intervals[j].s] - ones[intervals[j].f - 1]));

    for (int i = intervals[k].f; i <= intervals[k].s; i++)
      cnt[i]++;
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  solve();
}
