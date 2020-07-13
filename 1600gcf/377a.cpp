// Refer: Editorial
// you are on 1600 .... think more.. it is easy
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"

int n, m, k;
int net = 0;
bool vis[500][500];
int r[] = {1, -1, 0, 0};
int c[] = {0, 0, 1, -1};
char mat[500][500];

bool isValid(int x, int y)
{
  return (x >= 0 && x < n && y >= 0 && y < m);
}
void dfs(int x, int y)
{
  if (net == 0)
    return;
  vis[x][y] = true;
  net--;
  for (int i = 0; i < 4; i++)
  {
    if (net == 0)
      return;
    int xx = x + r[i];
    int yy = y + c[i];
    if (isValid(xx, yy) && (!vis[xx][yy]) && mat[xx][yy] == '.')
      dfs(xx, yy);
  }
}
void solve()
{
  cin >> n >> m >> k;
  int x = 0, y = 0;
  int s = 0;
  bool flag = true;
  forn(i, n)
  {
    forn(j, m)
    {
      cin >> mat[i][j];
      vis[i][j] = false;
      if (mat[i][j] == '.')
        s++;
      if (mat[i][j] == '.' && flag)
      {
        x = i;
        y = j;
        flag = false;
      }
    }
  }

  net = s - k;
  dfs(x, y);
  forn(i, n)
  {
    forn(j, m)
    {
      if (vis[i][j])
        cout << '.';
      else if (mat[i][j] == '#')
        cout << '#';
      else
        cout << 'X';
    }
    cout << endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
