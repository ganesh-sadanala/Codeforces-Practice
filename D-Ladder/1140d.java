
// Forgot the Galactic question of codechef
//simple greedy choice -> choose one as '1' vertex
import java.util.*;
import java.io.*;

class Solution {
  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    long n = Long.parseLong(bf.readLine());
    long a = 2, b = 3;
    long res = 0;
    for (int i = 3; i <= n; i++) {
      res += (a * b);
      a++;
      b++;
    }
    System.out.println(res);
  }
}
