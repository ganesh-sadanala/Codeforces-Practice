// Awesome question based on chainings
// Refer the editorial
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

int n, k;

void solve()
{
  int a[n];
  map<int, bool> vis;
  forn(i, n)
  {
    cin >> a[i];
    vis[a[i]] = 1;
  }
  sort(a, a + n);
  vi ans(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (vis[a[i]])
    {
      ans[i]++;
      int temp = a[i];
      while (vis[temp * k])
      {
        ans[i]++;
        temp *= k;
        vis[temp] = 0;
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++)
    mx += ((ans[i] + 1) / 2);
  cout << mx << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  solve();
}
