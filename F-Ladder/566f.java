// Brute force - O(n^3)-> for every element form a list of divisors and take
// maximum common

// Efficient -> Use LIS ( for chaining related questions it should strike to
// your mind from the next time)
import java.util.*;
import java.io.*;

public class Solution {
  static int N = (int) 1e6 + 5;
  static int dp[] = new int[N];
  static int a[] = new int[N];

  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine());
    String s[] = bf.readLine().trim().split("\\s+");
    for (int i = 0; i < n; i++) {
      a[i] = Integer.parseInt(s[i]);
      dp[a[i]] = 1;
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 2 * a[i]; j < N; j += a[i]) {
        dp[a[i]] = Math.max(dp[a[i]], dp[j] + 1);
        ans = Math.max(ans, dp[a[i]]);
      }
    }
    System.out.println(ans);
  }
}
