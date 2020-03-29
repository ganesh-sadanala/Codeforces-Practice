
// Naive Dp
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

// Optimized Dp

// Refer : Rachit jain video in youtube

// 1-> refers to d and it is the number of ways of ending up at the same vertex
// (i.e; at d)
// f(1,steps)=0{d->d}+3*f(0,steps-1){from a,b,c to d}
// 0-> refers to a,b,c and it is the number of ways of ending up at different
// vertex (i.e; at from a or b or c to other) which is same as
// f(0,steps)=2*f(0,steps-1)+f(1,steps-1)
import java.util.*;
import java.io.*;

public class Solution {
  static long mod = (long) 1e9 + 7;

  static long solve(int s, int step, long dp[][], boolean vis[][]) {
    if (step == 0) {
      if (s == 1)
        return 1;

      return 0;
    }
    if (vis[s][step])
      return dp[s][step];

    vis[s][step] = true;
    long ans = 0;
    if (same == 1)
      ans = (3 * solve(1 - same, steps - 1)) % mod;
    else
      ans = (2 * solve(same, steps - 1) + solve(1 - same, steps - 1)) % mod;

    return dp[s][step] = ans;

  }

  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine());
    long dp[][] = new long[2][n + 1];
    boolean vis[][] = new boolean[2][n + 1];
    System.out.println(solve(1, n, dp, vis));

  }
}
// This still gives tle because of stackoverflow error

////////////////////////////// ---------------------

/* Top down dp */
import java.util.*;
import java.io.*;

public class Solution {
  static long mod = (long) 1e9 + 7;

  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine());
    long dp[][] = new long[2][n + 1];
    boolean vis[][] = new boolean[2][n + 1];
    dp[1][0] = 1;
    dp[1][1] = 0;
    for (int i = 1; i <= n; i++) {
      dp[1][i] = (3 * dp[0][i - 1]) % mod;
      dp[0][i] = (2 * dp[0][i - 1] + dp[1][i - 1]) % mod;
    }
    System.out.println(dp[1][n]);
  }
}
// This also gives heap space error
// Reason: try to allocate larger memory globally, not in the mathod because it
// adds to the stack space

// This gives AC
import java.util.*;
import java.io.*;

public class Solution {
  static long mod = (int) 1e9 + 7;
  static int dp[][] = new int[2][10000002];

  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine());
    dp[1][0] = 1;
    for (int i = 1; i < 10000002; i++) {
      dp[1][i] = (int) ((3L * dp[0][i - 1]) % mod);
      dp[0][i] = (int) ((2L * dp[0][i - 1] + dp[1][i - 1]) % mod);
    }
    System.out.println(dp[1][n]);
  }
}
