// Refer editorial
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
  public static void main(String[] args) throws Exception {
    HashMap<Long, Long> map = new HashMap<>();
    map.put(2l, 2l);
    map.put(3l, 3l);
    map.put(4l, 322l);
    map.put(5l, 5l);
    map.put(6l, 53l);
    map.put(7l, 7l);
    map.put(8l, 7222l);
    map.put(9l, 7332l);
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    ArrayList<Long> list = new ArrayList<>();
    int n = Integer.parseInt(bf.readLine());
    long a = Long.parseLong(bf.readLine());
    while (a > 0) {
      long rem = a % 10;
      a = a / 10;
      if (rem == 0 || rem == 1)
        continue;
      else {
        long p = map.get(rem);
        while (p > 0) {
          long r = p % 10;
          list.add(r);
          p /= 10;
        }
      }
    }
    Collections.sort(list, Collections.reverseOrder());
    int sz = list.size();
    for (int i = 0; i < sz; i++)
      System.out.print(list.get(i));

    System.out.println();
  }
}
