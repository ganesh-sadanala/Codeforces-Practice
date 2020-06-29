// Leaerned how to count edges and vertices using dfs in each components of a graph
// That counting is not possible using dsu

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define N 2e5 + 5
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"
#define mp make_pair

const int mx = 150001;
int n, m;
vector<int> edge[mx];
bool vis[mx];
void dfs(int x, ll &cnt_nodes, ll &cnt_edges)
{
  cnt_nodes++;
  vis[x] = true;
  cnt_edges += edge[x].size();
  for (auto v : edge[x])
  {
    if (!vis[v])
      dfs(v, cnt_nodes, cnt_edges);
  }
}
void solve()
{
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    edge[a].pb(b);
    edge[b].pb(a);
  }
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      ll cnt_nodes = 0, cnt_edges = 0;
      dfs(i, cnt_nodes, cnt_edges);
      if (cnt_edges != cnt_nodes * (cnt_nodes - 1))
      {
        cout << "NO";
        return;
      }
    }
  }
  cout << "YES";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  solve();
}
