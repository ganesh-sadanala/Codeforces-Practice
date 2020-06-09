// Refer: Editorial

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define N 3e5 + 5
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
  string s, temp;
  cin >> s;
  temp = s;
  for (int i = k; i < n; i++)
    temp[i] = temp[i - k];

  cout << n << endl;
  if (temp >= s)
  {
    cout << temp << endl;
    return;
  }

  for (int i = k - 1; i >= 0; i--)
  {
    if (temp[i] == '9')
      temp[i] = '0';
    else
    {
      temp[i] += 1;
      break;
    }
  }
  for (int i = k; i < n; i++)
    temp[i] = temp[i - k];
  cout << temp << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  solve();
}
