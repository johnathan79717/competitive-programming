/*
ID: johnath2
PROG: fact4
LANG: JAVA
*/
import java.util.*;
import java.math.*;
import java.io.*;

public class fact4 {
  public static void main(String[] args) {
    try {
      BufferedReader in = new BufferedReader(new FileReader("fact4.in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fact4.out")));
      int N = Integer.parseInt(in.readLine());
      BigInteger ans = BigInteger.valueOf(1);
      for(int i = 1; i <= N; i++) {
        ans = ans.multiply(BigInteger.valueOf(i));
      }
      while(ans.mod(BigInteger.TEN).equals(BigInteger.ZERO))
        ans = ans.divide(BigInteger.TEN);
      out.println(ans.mod(BigInteger.TEN));
      out.close();
      System.exit(0);
    } catch(FileNotFoundException e) {
      System.out.println(e.getMessage());
    } catch(IOException e) {
      System.out.println(e.getMessage());
    }
  }
}