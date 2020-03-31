
// Superb question -> awesome idea for finding string by ashish
// Harsha(pro coder) solved it without using dp
import java.util.*;
import java.io.*;

public class Solution {

  static void solve(String s, int n) {
    int cnt = 0;
    char c, c1;
    char ch[] = new char[n];
    ch[0] = s.charAt(0);
    for (int i = 1; i < n; i++) {
      c = s.charAt(i);
      c1 = (i != n - 1) ? s.charAt(i + 1) : s.charAt(i - 1);
      if (s.charAt(i) == ch[i - 1]) {
        cnt++;
        c = s.charAt(i);
        c1 = (i != n - 1) ? s.charAt(i + 1) : s.charAt(i - 1);
        if (c == 'R') {
          ch[i] = (c1 == 'G') ? 'B' : 'G';
        } else if (c == 'G') {
          ch[i] = (c1 == 'R') ? 'B' : 'R';
        } else
          ch[i] = (c1 == 'G') ? 'R' : 'G';
      } else
        ch[i] = s.charAt(i);
    }
    System.out.println(cnt);
    for (int i = 0; i < n; i++)
      System.out.print(ch[i] + "");

    System.out.println();
  }

  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine());
    String s = bf.readLine();
    solve(s, n);
  }
}
