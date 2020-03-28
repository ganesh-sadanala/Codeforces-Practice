import java.util.*;
import java.io.*;

public class Solution {
  static long mod = (long) 1e9 + 7;

  static long solve(int s, int d, int step, long dp[][][], boolean vis[][][]) {
    if (step == 0) {
      if (s == d)
        return 1;

      return 0;
    }
    if (vis[s][d][step])
      return dp[s][d][step];

    vis[s][d][step] = true;
    long ans = 0;
    for (int i = 0; i < 4; i++) {
      if (i == s)
        continue;

      ans += solve(i, d, step - 1, dp, vis) % mod;
    }
    return dp[s][d][step] = ans % mod;
  }

  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine());
    long dp[][][] = new long[4][4][n + 1];
    boolean vis[][][] = new boolean[4][4][n + 1];
    System.out.println(solve(3, 3, n, dp, vis));

  }
}
