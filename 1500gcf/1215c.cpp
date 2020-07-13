// Refer: Editorial
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

void solve()
{
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> v01;
  vector<int> v10;
  for (int i = 0; i < n; i++)
  {
    if (s1[i] != s2[i])
    {
      if (s1[i] == 'a')
        v01.pb(i);
      else
        v10.pb(i);
    }
  }
  if (v01.size() % 2 != v10.size() % 2)
  {
    cout << -1 << endl;
    return;
  }
  int cnt = 0;
  if (v01.size() % 2)
    cnt = 2;
  cnt += v01.size() / 2 + v10.size() / 2;
  cout << cnt << endl;
  for (int i = 0; i + 1 < v01.size(); i += 2)
    cout << (v01[i] + 1) << " " << (v01[i + 1] + 1) << endl;
  for (int i = 0; i + 1 < v10.size(); i += 2)
    cout << (v10[i] + 1) << " " << (v10[i + 1] + 1) << endl;

  if (v01.size() % 2)
  {
    cout << (v01[v01.size() - 1] + 1) << " " << (v01[v01.size() - 1] + 1) << endl;
    cout << (v01[v01.size() - 1] + 1) << " " << (v10[v10.size() - 1] + 1) << endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
