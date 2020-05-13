/*package whatever //do not write package name here */

// Easy -> achieved O(n2)
// Failed to noticed the monotonicity -> binary search

import java.io.*;
import java.util.*;

public class GFG {

  static String t, p;
  static int n, m;
  static boolean erase[];
  static int a[];

  static boolean isMatch(int inx) {
    Arrays.fill(erase, false);
    for (int i = 0; i <= inx; i++)
      erase[a[i] - 1] = true;

    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
      if (erase[i])
        continue;

      if (t.charAt(i) == p.charAt(j))
        j++;
    }
    if (j == m)
      return true;

    return false;
  }

  static void solve() {
    int ans = 0;
    erase = new boolean[n];
    Arrays.fill(erase, false);
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) >>> 1;
      if (isMatch(mid)) {
        ans = mid + 1;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    System.out.println(ans);
  }

  public static void main(String[] args) throws Exception {

    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    t = bf.readLine();
    p = bf.readLine();
    String s[] = bf.readLine().trim().split("\\s+");
    n = t.length();
    m = p.length();
    a = new int[n];
    for (int i = 0; i < n; i++)
      a[i] = Integer.parseInt(s[i]);
    solve();
  }
}
