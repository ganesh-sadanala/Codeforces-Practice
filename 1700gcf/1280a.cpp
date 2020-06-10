// The only i have learned in this question is
// how to handle mod with negative numbers
// simply my add mod num with the val
// (a-b+c)%c is safer
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

void solve()
{
  int x;
  cin >> x;
  string s;
  cin >> s;
  int t = 1;
  ll ans = 0;
  while (s.size() < x && t <= x)
  {
    string c = s.substr(t);
    int n = s[t - 1] - '1';
    for (int i = 0; i < n; i++)
      s += c;
    t++;
  }
  if (t > x)
    cout << s.size() << endl;
  else
  {
    ll prev = s.size();
    ll cur = 0;
    ll mod = 1e9 + 7;
    while (t <= x)
    {
      cur = (prev + (prev - t + mod) % mod * (s[t - 1] - '1')) % mod;
      prev = cur;
      t++;
    }
    cout << cur % mod << endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
}
