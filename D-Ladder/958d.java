/*package whatever //do not write package name here */
// Awesome question to be solved. Learned how to handle fraction number in map

import java.io.*;
import java.util.*;

class GFG {
  static int gcd(int a, int b) {
    if (b == 0)
      return a;

    return gcd(b, a % b);
  }

  static void evaluate(HashMap<String, Integer> map, String s, String[] aux, int inx) {
    int a, b, c;
    int n = s.length();
    String sa = "";
    int i = 0;
    for (i = 1; i < n; i++) {
      if (s.charAt(i) == '+')
        break;

      sa = sa + s.charAt(i);
    }
    a = Integer.parseInt(sa);
    String sb = "";
    int j = 0;
    for (j = i; j < n; j++) {
      if (s.charAt(j) == ')')
        break;

      sb = sb + s.charAt(j);
    }
    b = Integer.parseInt(sb);
    j++;
    c = Integer.parseInt(s.substring(j + 1, n));
    int ner = (a + b);
    int der = c;
    int gcd = gcd(ner, der);
    ner /= gcd;
    der /= gcd;
    aux[inx] = ner + " " + der;
    if (!map.containsKey(aux[inx]))
      map.put(aux[inx], 1);
    else
      map.put(aux[inx], map.get(aux[inx]) + 1);
  }

  public static void main(String[] args) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine().trim());
    String s[] = new String[n];
    HashMap<String, Integer> map = new HashMap<>();
    String aux[] = new String[n];
    for (int i = 0; i < n; i++) {
      s[i] = bf.readLine().trim();
      evaluate(map, s[i], aux, i);
    }
    for (int i = 0; i < n; i++)
      System.out.print(map.get(aux[i]) + " ");

    System.out.println();
  }
}
