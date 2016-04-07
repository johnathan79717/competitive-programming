import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while(t-- > 0) {
      BigInteger a = sc.nextBigInteger();
      BigInteger prev = BigInteger.valueOf(0);
      BigInteger curr = BigInteger.valueOf(1);
      while(curr.compareTo(a) < 0) {
        BigInteger temp = curr.add(prev);
        prev = curr;
        curr = temp;
      }
      if(curr.equals(a))
        System.out.println("YES");
      else
        System.out.println("NO");
    }
    // BigInteger fac = BigInteger.valueOf(1);
    // for(int i = 2; i <= 25; i++)
    //   fac = fac.multiply(BigInteger.valueOf(i));
    // System.out.println(fac);
  }
}