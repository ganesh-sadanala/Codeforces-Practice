/* Why did i lose: overthinking (Don't think that f level questions are difficult )
   Where did i lose: No Applying the question.
   Solution: sometimes we have to blindly apply the english.
*/

//Adhoc Implementation: Try to stop the recurrence of substitution
import java.util.*;
import java.io.*;

public class Solution {
  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine());
    String s[] = new String[n];
    for (int i = 0; i < n; i++) {
      s[i] = bf.readLine();
    }
    for (int i = 0; i < n; i++) {
      String str = s[i];
      while (str.compareTo(str.replace("kh", "h")) != 0 || str.compareTo(str.replace("u", "oo")) != 0) {
        str = str.replace("kh", "h");
        str = str.replace("u", "oo");
      }
      s[i] = str;
    }
    Arrays.sort(s);
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
      if (!s[i].equals(s[i + 1]))
        cnt++;
    }
    System.out.println(cnt);
  }
}
