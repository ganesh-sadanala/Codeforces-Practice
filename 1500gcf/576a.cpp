// Refer: Editorial
// Every number can be expressed as product of prime factors
// To guess a number you need to ask all the powers of primes
// A = p1^k1  * p2^k2 * ....

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
  vi ans;
  bool prime[1001];
  for (int i = 0; i <= 1000; i++)
    prime[i] = true;
  for (int i = 2; i * i <= 1000; i++)
  {
    if (prime[i])
    {
      for (int j = i * i; j <= 1000; j += i)
        prime[j] = false;
    }
  }
  for (int i = 2; i <= 1000; i++)
    if (prime[i])
      ans.pb(i);

  vi res;
  for (int i = 0; i < ans.size(); i++)
  {
    if (ans[i] > n)
      break;
    for (int j = 1; pow(ans[i], j) <= n; j++)
      res.pb(pow(ans[i], j));
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
