/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Graph
{
    static ArrayList<ArrayList<Integer>> edg=new ArrayList<>();
    static boolean vis[];
    static int intime=0;
    static int nchild[];
    static ArrayList<Integer> ans=new ArrayList<>();
    static void dfs(int i)
    {
        nchild[i]=intime;
        ans.add(i);
        vis[i]=true;
        ArrayList<Integer> adj=edg.get(i);
        for(int v:adj)
        {
            if(!vis[v]){
              intime++;        
              dfs(v);}
        } 
        nchild[i]=intime-nchild[i]+1;
    }
    static void addEdge(int src,int dest)
    {
        edg.get(src).add(dest);
	edg.get(dest).add(src);
    }
    public static void main (String[] args) throws java.lang.Exception
	{
	   BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
	   String s[]=bf.readLine().trim().split("\\s+");
	   int n=Integer.parseInt(s[0]);
	   int q=Integer.parseInt(s[1]);
	   vis=new boolean[n+1];
	   nchild=new int[n+1];
	   Arrays.fill(vis,false);
	   s=bf.readLine().trim().split("\\s+");
	   for(int i=0;i<n+1;i++)
	      edg.add(new ArrayList<>());
	   
	   for(int i=0;i<n-1;i++)
	      addEdge(Integer.parseInt(s[i]),i+2);
	      
	   StringBuffer str=new StringBuffer("");
	   dfs(1);
	   //for(int i=1;i<=n;i++)
	   //{
	   //    ArrayList<Integer> l=edg.get(i);
	   //    for(int j=0;j<l.size();j++)
	   //      System.out.print(l.get(j)+" ");
	         
	   //    System.out.println();
	   //}
	   int idx[]=new int[n+1];
	   for(int i=0;i<n;i++)
	   {
	       idx[ans.get(i)]=i;
	   }
	   while(q-->0)
	   {
	       s=bf.readLine().trim().split("\\s+");
	       int u=Integer.parseInt(s[0]);
	       int k=Integer.parseInt(s[1]);
	       k--;
	       int p=(k<nchild[u])?ans.get(idx[u]+k):-1;
	       str.append(p+"\n");
	   }
	   System.out.println(str);
	}
}
