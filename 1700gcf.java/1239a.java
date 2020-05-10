import java.util.*;
import java.io.*;

public class CF {

  static int n, m;
  static int ans[] = new int[100001];

  static void solve() {
    ans[0] = 0;
    ans[1] = ans[2] = 1;
    for (int i = 3; i < 100001; i++)
      ans[i] = ans[i - 1] + ans[i - 2];
  }

  public static void main(String[] arg) {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    n = Integer.parseInt(s[0]);
    m = Integer.parseInt(s[1]);
    solve();
    System.out.println(2 * (ans[n] + ans[m] - 1));
  }
}
