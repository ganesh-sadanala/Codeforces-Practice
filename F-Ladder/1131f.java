// simple ga alochinchu....point antha aa ichina union order lo undi
// u should take advantage of it.....if that particular union/removal of kittens
// is psbl....aa two kittens
// adj ga unnayani...adj means not nnecessarily next to each other...rather
// pressent in adj disjoint sets...anthe
// so adi left unda...right unda anavasaram.....since we are asked to print any
// one of the psbl orders...
// well consider any one..left/ryt...nee ishtam ill consider ryt...so
// NO BIG CHANGES AT ALL
// just union method lo....normal ga how we do itself is enough
// just add one more small step...update parent of lesser-rank ds to parent of
// greater-rank ds...and...and..and
// push all the children of lesser-rank ds to the vector of greater-rank ds
// ikkada no need to check any order...refer points 1 2 3 again
// last ki since all the nodes will turn into one big dsu....just find the
// parent of any of the nodes....
// parent of all the nodes will be same...endukante just only one single dsu
// now print all its children...anthe

// Simply follow the question
// push lower rank elements into root because previous elements who are children
// to this are already merged into this parent
// Awesome idea -> Use list for each node to store while merging itself
// nlogn time complexity
// The idea i got traversal -> fails
// Union find -> better store in lists
import java.util.*;
import java.io.*;

public class Solution {
  static int parent[] = new int[150001];
  static int rank[] = new int[150001];
  static int v, e;
  static ArrayList<ArrayList<Integer>> child = new ArrayList<>();

  static int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);

    return parent[x];
  }

  static void union(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if (rank[xset] < rank[yset]) {
      xset ^= yset;
      yset = xset ^ yset;
      xset ^= yset;
    }
    parent[yset] = xset;
    rank[xset]++;
    ArrayList<Integer> l = child.get(yset);
    ArrayList<Integer> l1 = child.get(xset);
    for (int i : l)
      l1.add(i);
  }

  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    v = Integer.parseInt(bf.readLine());
    for (int i = 0; i <= v; i++) {
      child.add(new ArrayList<>());
      parent[i] = i;
      rank[i] = 0;
    }
    for (int i = 1; i <= v; i++)
      child.get(i).add(i);

    String s[];
    for (int i = 1; i < v; i++) {
      s = bf.readLine().trim().split("\\s+");
      union(Integer.parseInt(s[0]), Integer.parseInt(s[1]));
    }
    ArrayList<Integer> l = child.get(find(1));
    for (int i : l)
      System.out.print(i + " ");

    System.out.println();
  }
}
