// Got the idea but missed a small observation
// Refer: Editorial
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

const int N = 2e5 + 5;
void solve()
{
  int n;
  cin >> n;
  vector<int> adj[n + 1];
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  for (int i = 1; i <= n; i++)
  {
    if (adj[i].size() == 2)
    {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
