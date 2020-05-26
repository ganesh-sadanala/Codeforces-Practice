// Everything is good initially
// Only point i did not get greedily is
// If we can recharge the accumulator (the current segment is exposed and the current charge of accumulator is lower than its initial charge), let's do it
// If the accumalator is full no matter what the sun status is, if the battery has some power increase it

import java.util.*;
import java.io.*;

public class Solution {
  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    int n = Integer.parseInt(s[0]);
    int b = Integer.parseInt(s[1]);
    int a = Integer.parseInt(s[2]);
    int sun[] = new int[n];
    s = bf.readLine().trim().split("\\s+");
    for (int i = 0; i < n; i++)
      sun[i] = Integer.parseInt(s[i]);

    int amax = a;
    int cnt = 0;
    int inx = 0;
    while ((b > 0 || a > 0) && inx < n) {
      if (sun[inx] == 0) {
        if (a > 0)
          a--;
        else
          b--;
      } else if (sun[inx] == 1) {
        // This point i missed
        if (b > 0 && a < amax) {
          a = a + 1;
          b--;
        } else {
          a--;
        }
      } else
        a--;

      inx++;
      cnt++;

      // System.out.println("b: "+b+" a: "+a);
    }
    System.out.println(cnt);
  }
}
