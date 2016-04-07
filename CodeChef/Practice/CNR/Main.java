import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    while(t-- > 0) {
      int n = in.nextInt();
      int k = in.nextInt();
      BigInteger m = in.nextBigInteger();
      if(c(n, k).compareTo(m) < 0)
        System.out.println(1);
      else {
        while(n > 0) {
          n--;
          if(c(n, k).compareTo(m) >= 0) {
            System.out.print(0);
          } else {
            System.out.print(1);
            m = m.subtract(c(n, k));
            k--;
          }
        }
        System.out.println();
      }
    }
  }

  public static BigInteger c(int n, int k) {
    if(k == 0)
      return BigInteger.valueOf(1);
    else if (n == 0)
      return BigInteger.valueOf(0);
    else
      return c(n-1, k-1).multiply(BigInteger.valueOf(n)).divide(BigInteger.valueOf(k));
  }
}