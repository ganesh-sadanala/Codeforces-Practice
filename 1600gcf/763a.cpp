// Nice Question
// Takling an edge
// Refer: Editorial
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

const int N = 2e5 + 5;
int n;
vector<int> v[N];
int color[N];
int root1 = -1, root2 = -1;
bool ok = true;
int cur_col;

void dfs(int u, int p)
{
  if (color[u] != cur_col)
    ok = false;

  for (int x : v[u])
  {
    if (x != p)
      dfs(x, u);
  }
}

void solveUtil(int root)
{
  for (int u : v[root])
  {

    cur_col = color[u];
    dfs(u, root);
  }
}

void solve()
{
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  for (int i = 1; i <= n; i++)
    cin >> color[i];

  for (int i = 1; i <= n; i++)
  {
    for (int u : v[i])
    {
      if (color[u] != color[i])
      {
        root1 = i;
        root2 = u;
      }
    }
  }
  if (root1 == -1)
  {
    cout << "YES\n1";
    return;
  }

  solveUtil(root1);
  if (ok)
  {
    cout << "YES\n";
    cout << root1 << endl;
    return;
  }
  ok = true;
  solveUtil(root2);
  if (ok)
  {
    cout << "YES\n";
    cout << root2 << endl;
    return;
  }

  cout << "NO\n";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
