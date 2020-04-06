/*
Nice question
I did not get the idea that i should use dfs to solve this
Manchiga chesadu
Dfs tho cycle untey oka vertex nunchi -> 0
I not -> 1

*/

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Grpah {
  static int v, e;
  static boolean flag;
  static ArrayList<ArrayList<Integer>> edg = new ArrayList<>();
  static char color[];

  static void dfs(int u, int p) {
    color[u] = 'g';
    ArrayList<Integer> list = edg.get(u);
    for (int ver : list) {
      char c = color[ver];
      if (c == 'b' || ver == p)
        continue;
      if (c == 'g')
        flag = true;
      if (c == 'w')
        dfs(ver, u);
    }
    color[u] = 'b';
  }

  static void addEdge(int s, int d) {
    edg.get(s).add(d);
    edg.get(d).add(s);
  }

  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    v = Integer.parseInt(s[0]);
    e = Integer.parseInt(s[1]);
    color = new char[v + 1];
    Arrays.fill(color, 'w');
    for (int i = 0; i <= v; i++)
      edg.add(new ArrayList<>());
    while (e-- > 0) {
      s = bf.readLine().trim().split("\\s+");
      addEdge(Integer.parseInt(s[0]), Integer.parseInt(s[1]));
    }
    int res = 0;
    for (int i = 1; i <= v; i++) {
      flag = false;
      if (color[i] == 'w') {
        dfs(i, i);
        res += (flag) ? 0 : 1;
      }
    }
    System.out.println(res);
  }
}
