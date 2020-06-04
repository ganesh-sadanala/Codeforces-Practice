// Learned a lesson that 

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef {
  static int n, m, x, y;
  static StringBuffer str = new StringBuffer("");
  static long dp[][][] = new long[1001][1001][2];
  static long bw[][] = new long[2][1001];

  // static int ans=Integer.MAX_VALUE;
  static long solve(int col, int cnt, int color) {

    if (col == m) {
      if ((cnt - 1 >= x && cnt - 1 <= y) || cnt == 1) {
        return 0;
      }
      return Integer.MAX_VALUE;
    }

    if (dp[col][cnt][color] != -1)
      return dp[col][cnt][color];

    long ans = 0;
    if (cnt < x) {
      long val = bw[1 - color][col];
      ans = val + solve(col + 1, cnt + 1, color);
    } else if (cnt >= x && cnt < y) {
      ans = Math.min(bw[1 - color][col] + solve(col + 1, cnt + 1, color),
          bw[1 - color][col] + solve(col + 1, 1, 1 - color));
    } else if (cnt >= y) {
      long val = bw[1 - color][col];
      ans = val + solve(col + 1, 1, 1 - color);
    }

    return dp[col][cnt][color] = ans;
  }

  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    n = Integer.parseInt(s[0]);
    m = Integer.parseInt(s[1]);
    x = Integer.parseInt(s[2]);
    y = Integer.parseInt(s[3]);

    for (int i = 0; i < n; i++) {
      s = bf.readLine().trim().split("");
      for (int j = 0; j < m; j++) {
        if (s[j].charAt(0) == '#')
          bw[0][j]++;
        else
          bw[1][j]++;
      }
    }
    for (int i = 0; i <= 1000; i++) {
      for (int j = 0; j <= 1000; j++) {
        for (int k = 0; k < 2; k++) {
          dp[i][j][k] = -1;
        }
      }
    }
    System.out.println(Math.min(solve(0, 1, 0), solve(0, 1, 1)));
    // System.out.println(ans);
  }
}
